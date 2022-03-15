#pragma once

#include "..\SimplexTable\SimplexTable.hpp"
#include "..\MethodSolveSimplexTable\MethodSolveSimplexTable.hpp"
#include "..\utility\utility.hpp"

using namespace utility;

namespace simplexMethod
{

	class SolveSimplexTable
	{
	public:
		SolveSimplexTable(SimplexTable * const &simplexTable, MethodSolveSimplexTable *const &method);
		~SolveSimplexTable();

		void setSimplexTable(SimplexTable *const &simplexTable);
		void setMethodSolveSimplexTable(MethodSolveSimplexTable *const &method);

		vector<BaseType> solve();

	private:
		SimplexTable *simplexTable_;
		MethodSolveSimplexTable *method_;
	};

}