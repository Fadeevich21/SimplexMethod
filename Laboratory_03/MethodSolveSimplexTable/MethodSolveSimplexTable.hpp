#pragma once

#include <vector>
#include "..\utility\utility.hpp"
#include "..\..\Matrix\Matrix.hpp"
#include "..\SimplexTable\SimplexTable.hpp"

using namespace std;
using namespace utility;
using namespace computationalMathematics;

namespace simplexMethod
{

	class MethodSolveSimplexTable : protected SimplexTable
	{
	public:
		MethodSolveSimplexTable() = default;
		virtual ~MethodSolveSimplexTable()
		{
		};

		virtual vector<BaseType> solve() = 0;
	};

}