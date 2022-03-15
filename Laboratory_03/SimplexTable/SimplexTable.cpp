#include "SimplexTable.hpp"

namespace simplexMethod
{

	bool isBasicsVariable(const Matrix<BaseType> &matr, const int &index, const int &countEquation)
	{
		int countNonZeroNumbers = int();
		for (int i = 0; countNonZeroNumbers <= 1 && i < countEquation; i++)
		{
			if (matr[i][index] != 0)
			{
				countNonZeroNumbers++;
			}
		}

		return countNonZeroNumbers == 1;
	}

	vector<bool> getVecBasicsVariable(const Matrix<BaseType> &matr, const int &maxCountBasicsVariable, const int &countEquation)
	{
		vector<bool> isBasicsVariableVec = vector<bool>(maxCountBasicsVariable, false);
		for (int i = 0; i < matr.sizeColumn() - 1; i++)
		{
			if (isBasicsVariable(matr, i, countEquation))
			{
				isBasicsVariableVec[i] = true;
			}
		}

		return isBasicsVariableVec;
	}

	vector<int> getIndexBasicsVariableInEquation(const Matrix<BaseType> &matr, const int &count, const vector<bool> &isBasicsVariable)
	{
		vector<int> indexBasicsVariableInEquationVec = vector<int>(count, NON_RESULT);

		auto iter = cbegin(isBasicsVariable);
		while ((iter = find(iter, cend(isBasicsVariable), true)) != cend(isBasicsVariable))
		{
			int i = distance(cbegin(isBasicsVariable), iter);
			int j = int();
			while (j < count)
			{
				if (matr[j][i] != 0)
				{
					break;
				}

				j++;
			}

			indexBasicsVariableInEquationVec[j] = i;

			iter = next(iter);
		}

		return indexBasicsVariableInEquationVec;
	}

	vector<bool> getEquationContainsBasicsVariable(const vector<int> &indexBasicsVariableInEquation, const int &countEquationContainsBasicsVariable)
	{
		vector<bool> EquationContainsBasicsVariableVec = vector<bool>(countEquationContainsBasicsVariable, false);
		for (int i = 0; i < countEquationContainsBasicsVariable; i++)
		{
			if (indexBasicsVariableInEquation[i] != NON_RESULT)
			{
				EquationContainsBasicsVariableVec[i] = true;
			}
		}

		return EquationContainsBasicsVariableVec;
	}

}

template <class T>
void writeVector(const vector<T> &vec)
{
	for (const auto &el : vec)
	{
		cout << el << ' ';
	}

	cout << "\n";
}

namespace simplexMethod
{

	SimplexTable::SimplexTable(const Matrix<BaseType> &matr, const int &countVariable, const int &countEquation) :
		data_(matr), countVariable_(countVariable), countEquation_(countEquation)
	{
		this->isBasicsVariable_ = getVecBasicsVariable(this->data_, this->countVariable_, this->countEquation_);
		this->countBasicsVariable_ = count(cbegin(this->isBasicsVariable_), cend(this->isBasicsVariable_), true);

		this->indexBasicsVariableInEquation_ = getIndexBasicsVariableInEquation(this->data_, this->countEquation_, this->isBasicsVariable_);
		this->equationContainsBasicsVariable_ = getEquationContainsBasicsVariable(this->indexBasicsVariableInEquation_, this->countEquation_);

		cout << "isBasicsVariable_:\n";
		writeVector(this->isBasicsVariable_);

		cout << "countBasicsVariable_: " << this->countBasicsVariable_ << "\n";

		cout << "indexBasicsVariableInEquation_:\n";
		writeVector(this->indexBasicsVariableInEquation_);

		cout << "equationContainsBasicsVariable_:\n";
		writeVector(this->equationContainsBasicsVariable_);
	}

	SimplexTable::~SimplexTable()
	{
	
	};

}