#pragma once

#include "..\MethodSolveSimplexTable\MethodSolveSimplexTable.hpp"
#include "..\utility\utility.hpp"

using namespace utility;

namespace simplexMethod
{

	class MethodArtificialBases : public MethodSolveSimplexTable
	{
	public:
		MethodArtificialBases()	{ }
		~MethodArtificialBases() { }

		vector<BaseType> solve();
	};

}
