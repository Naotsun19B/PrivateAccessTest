#pragma once

#include "PrivateClass.h"

namespace Cpp15
{
	template<typename Tag>
	struct FPointer
	{
		typedef typename Tag::Type Type;
		static Type InternalPtr;
	};

	template<typename Tag>
	typename FPointer<Tag>::Type FPointer<Tag>::InternalPtr;

	template<typename Tag, typename Tag::Type Ptr>
	struct FHacker : FPointer<Tag>
	{
		struct FFiller
		{
			FFiller()
			{
				FPointer<Tag>::InternalPtr = Ptr;
			}
		};
		static FFiller Filler;
	};

	template<typename Tag, typename Tag::Type Ptr>
	typename FHacker<Tag, Ptr>::FFiller FHacker<Tag, Ptr>::Filler;

	// The classes for hack to private functions.
	struct FMultipleNumber
	{
		typedef int(FPrivateClass::* Type)() const;
	};
	template struct FHacker<FMultipleNumber, &FPrivateClass::MultipleNumber>;

	// The classes for hack to private members.
	struct FNumber
	{
		typedef int FPrivateClass::* Type;
	};
	template struct FHacker<FNumber, &FPrivateClass::Number>;

	static void Check()
	{
		FPrivateClass* PrivateClass = new FPrivateClass(15);

		std::cout << "------- Cpp 15 -------" << std::endl;

		std::cout << "GetNumber : " << PrivateClass->GetNumber() << std::endl;

		std::cout << "MultipleNumber : " << (PrivateClass->*FPointer<FMultipleNumber>::InternalPtr)() << std::endl;

		std::cout << "Hack to Number" << std::endl;
		PrivateClass->*FPointer<FNumber>::InternalPtr = 3;

		std::cout << "GetNumber : " << PrivateClass->GetNumber() << std::endl;

		std::cout << "----------------------" << std::endl;

		delete PrivateClass;
	}
}
