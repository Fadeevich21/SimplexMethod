#include "test.hpp"

#include "..\..\..\..\..\Libraries\simplexMethod\MethodSolveSimplexTable\MethodSolveSimplexTable.hpp"
#include "..\..\..\..\..\Libraries\simplexMethod\SolveSimplexTable\SolveSimplexTable.hpp"
#include "..\..\..\..\..\Libraries\simplexMethod\MethodArtificialBases\MethodArtificialBases.hpp"
#include "..\..\..\..\..\Libraries\simplexMethod\MethodLargeFines\MethodLargeFines.hpp"
#include "..\..\..\..\..\Libraries\simplexMethod\utility\utility.hpp"


using namespace simplexMethod;

namespace test
{

	using BaseType = long double;

	template<class T>
	typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
		almost_equal(T x, T y, int ulp)
	{
		// the machine epsilon has to be scaled to the magnitude of the values used
		// and multiplied by the desired precision in ULPs (units in the last place)
		return std::fabs(x - y) <= std::numeric_limits<T>::epsilon() * std::fabs(x + y) * ulp
			// unless the result is subnormal
			|| std::fabs(x - y) < std::numeric_limits<T>::min();
	}

#define writeStatus(status) {cout << "Status: " << (status == true ? "ok" : "false") << "\n\n";}

	bool test_method(SimplexTable * const &simplexTable, const vector<BaseType> &vecResult, MethodSolveSimplexTable * const &method)
	{
		SolveSimplexTable solver(simplexTable, method);
		vector<BaseType> vec = solver.solve();

		bool check = true;
		if (vec.size() != vecResult.size())
		{
			check = false;
		}

		for (size_t i = 0; check && i < vec.size(); i++)
		{
			check = almost_equal(vec[i], vecResult[i], 2);
		}

		return check;
	}

	void test_methodArtificialBases(SimplexTable * const &simlexTable, const vector<BaseType> &vecResult)
	{
		cout << "Test name: test_methodArtificialBases\n";

		MethodSolveSimplexTable * const method = new MethodArtificialBases;
		bool check = test_method(simlexTable, vecResult, method);
		writeStatus(check);
	}

	void test_methodLargeFines(SimplexTable * const &simplexTable, const vector<BaseType> &vecResult)
	{
		cout << "Test name: test_methodLargeFines\n";

		MethodLargeFines * const method = new MethodLargeFines;
		bool check = test_method(simplexTable, vecResult, method);
		writeStatus(check);
	}

	void test_methodArtificialBases_exampleFromTrainingManual()
	{
		cout << "Test name: test_methodArtificialBases_exampleFromTrainingManual\n";

		size_t countVariable = 3;
		size_t countEquation = 2;
		vector<vector<BaseType>> matr =
		{
			{{10},   {1},   {1}, {0}},
			{{4},    {1},   {0}, {-1}},
			{{-100}, {-19}, {0}, {20}}
		};

	
		SimplexTable *const simplexTable = new SimplexTable(matr, countVariable, countEquation);
		vector<BaseType> matrRes = {-24, 4, 6, 0};

		test_methodArtificialBases(simplexTable, matrRes);
	}

	void test_methodLargeFines_exampleFromTrainingManual()
	{
		cout << "Test name: test_exampleFromTrainingManual\n";

		size_t countVariable = 3;
		size_t countEquation = 2;
		vector<vector<BaseType>> matr =
		{
			{{10},   {1},   {1}, {0}},
			{{4},    {1},   {0}, {-1}},
			{{-100}, {-19}, {0}, {20}}
		};

		SimplexTable *const simplexTable = new SimplexTable(matr, countVariable, countEquation);
		vector<BaseType> matrRes = {-24, 4, 6, 0};

		test_methodLargeFines(simplexTable, matrRes);
	}

	void test_methodArtificialBases_variant20()
	{
		cout << "Test name: test_methodArtificialBases_variant20\n";

		size_t countVariable = 6;
		size_t countEquation = 3;
		vector<vector<BaseType>> matr =
		{
			{2, -1, 3, 1, -1, 36},
			{-1, 2, 1, 2, 2, 20},
			{3, -1, 2, -1, 3, 1, 30},
			{-5, 1, -8, -10, 5, -1}
		};

		SimplexTable *const simplexTable = new SimplexTable(matr, countVariable, countEquation);
		vector<BaseType> matrRes = {};

		test_methodArtificialBases(simplexTable, matrRes);
	}

}
