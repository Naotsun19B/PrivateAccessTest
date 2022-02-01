#pragma once

#include "PrivateClass.h"

namespace Cpp15Ex
{
	static int FPrivateClass::*NumberPtr;

	template<typename Tag, typename Tag::Type Ptr>
	struct FHacker
	{
		struct FFiller
		{
			FFiller() { NumberPtr = Ptr; }
		};
		static FFiller Filler;
	};

	template<typename Tag, typename Tag::Type Ptr>
	typename FHacker<Tag, Ptr>::FFiller FHacker<Tag, Ptr>::Filler;

	struct FNumber
	{
		typedef int FPrivateClass::* Type;
	};
	template struct FHacker<FNumber, &FPrivateClass::Number>;

	static void Check()
	{
		FPrivateClass* PrivateClass = new FPrivateClass(16);

		std::cout << "------ Cpp 15 Ex ------" << std::endl;

		std::cout << "GetNumber : " << PrivateClass->GetNumber() << std::endl;

		//std::cout << "MultipleNumber : " << (PrivateClass->*FPointer<FMultipleNumber>::InternalPtr)() << std::endl;

		std::cout << "Hack to Number" << std::endl;
		PrivateClass->*NumberPtr = 3;

		std::cout << "GetNumber : " << PrivateClass->GetNumber() << std::endl;

		std::cout << "----------------------" << std::endl;

		delete PrivateClass;
	}
}
