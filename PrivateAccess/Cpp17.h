#pragma once

#include "PrivateClass.h"

namespace Cpp17
{
	// The classes for hack to private functions.
	// Is it possible to hack a function in this form?
	// static int(FPrivateClass::* Type)() const;

	// The classes for hack to private members.
	static int FPrivateClass::*NumberPtr;

	template<int FPrivateClass::*Ptr>
	struct FHacker
	{
		inline static auto Dummy = (NumberPtr = Ptr);
	};
	template struct FHacker<&FPrivateClass::Number>;

	static void Check()
	{
		FPrivateClass* PrivateClass = new FPrivateClass(17);

		std::cout << "------- Cpp 17 -------" << std::endl;

		std::cout << "GetNumber : " << PrivateClass->GetNumber() << std::endl;
		
		//std::cout << "MultipleNumber : " << (PrivateClass->*FPointer<FMultipleNumber>::InternalPtr)() << std::endl;
		
		std::cout << "Hack to Number" << std::endl;
		PrivateClass->*NumberPtr = 41;
		
		std::cout << "GetNumber : " << PrivateClass->GetNumber() << std::endl;

		std::cout << "----------------------" << std::endl;

		delete PrivateClass;
	}
}
