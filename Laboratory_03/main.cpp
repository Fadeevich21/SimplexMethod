#include <iostream>
#include <Windows.h>

#include "test\test.hpp"

using namespace std;
using namespace test;

void test_();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Привет, Мир!\n\n";

	test_();

	return 0;
}

void test_()
{
	test_methodArtificialBases_exampleFromTrainingManual();
	test_methodLargeFines_exampleFromTrainingManual();
	test_methodArtificialBases_variant20();
}
