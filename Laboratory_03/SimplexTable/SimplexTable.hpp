#pragma once

#include <vector>
#include "..\..\Matrix\Matrix.hpp"
#include "..\utility\utility.hpp"

using namespace std;
using namespace utility;

namespace simplexMethod
{

	using namespace computationalMathematics;

#define NON_RESULT (int) -1

	class SimplexTable
	{
	public:
		SimplexTable() = default;
		SimplexTable(const Matrix<BaseType> &matr, const int &countVariable, const int &countEquation);

		~SimplexTable();

	protected:
		Matrix<BaseType> data_;
		int countVariable_;
		int countEquation_;

		vector<bool> isBasicsVariable_;
		int countBasicsVariable_;

		vector<bool> equationContainsBasicsVariable_;
		vector<int> indexBasicsVariableInEquation_;
	};

}