#pragma once

#include <map>
#include <vector>

using namespace std;

class FiniteField
{
public:
	static void generateMultiplicationTable(int p, int m);

	static int addElements(int x, int y, int p, int m);

	static int multiplyElements(int x, int y, int p, int m);

	static void generateMultiplicationTableLog(int p, int m);

	static void generateAddingTableLog(int p, int m);

	static void calculatePolynomial(int x1, int x2, int x3, int x4);

private:
	static const map<int, vector<int>> zechTable;
};

