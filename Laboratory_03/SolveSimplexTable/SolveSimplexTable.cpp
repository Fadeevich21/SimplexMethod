#include "SolveSimplexTable.hpp"

namespace simplexMethod 
{

	SolveSimplexTable::SolveSimplexTable(SimplexTable *const &simplexTable, MethodSolveSimplexTable *const &method) :
		simplexTable_(simplexTable), method_(method)
	{
	};
	
	SolveSimplexTable::~SolveSimplexTable()
	{
		delete this->simplexTable_;
		delete this->method_;
	};

	void SolveSimplexTable::setSimplexTable(SimplexTable *const &simplexTable)
	{
		delete this->simplexTable_;
		this->simplexTable_ = simplexTable;
	}

	void SolveSimplexTable::setMethodSolveSimplexTable(MethodSolveSimplexTable *const &method)
	{
		delete this->method_;
		this->method_ = method;
	}

	vector<BaseType> SolveSimplexTable::solve()
	{
		return this->method_->solve();
	}

}
