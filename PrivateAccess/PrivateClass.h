#pragma once

#include <iostream>

class FPrivateClass
{
public:
	FPrivateClass(int InNumber) : Number(InNumber) {}
	int GetNumber() const { return Number; }

private:
	int Number = 0;
	int MultipleNumber() const { return Number * Number; }
};
