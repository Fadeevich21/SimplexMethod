#pragma once

#include "..\MethodSolveSimplexTable\MethodSolveSimplexTable.hpp"
#include "..\utility\utility.hpp"

using namespace utility;

namespace simplexMethod
{

	class MethodLargeFines : public MethodSolveSimplexTable
	{
	public:
		MethodLargeFines() { }
		~MethodLargeFines() { }

		vector<BaseType> solve();
	};

}