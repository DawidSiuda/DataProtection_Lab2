#include <iostream>

#include "FiniteField.h"

using namespace std;

int main()
{
	//return 0;
	//int x = 0, y = 7, p = 2, m = 3;
	//cout << "( " << p << "^" << m << ") "
	//	<< x << " * " << y << " = " << FiniteField::add(x, y, p, m) << endl;


	//FiniteField::generateAddingTableLog(2, 3);
	//cout << endl;

	//return 0; 

	//FiniteField::generateMultiplicationTableLog(2, 2);
	//cout << endl;

	//FiniteField::generateMultiplicationTableLog(2, 3);
	//cout << endl;

	//FiniteField::generateMultiplicationTableLog(2, 4);
	//cout << endl;

	//return 0;

	while (1)
	{
		cout << "=================================== " << endl;
		cout << "1) zad 1 " << endl;
		cout << "2) zad 2 adding" << endl;
		cout << "3) zad 2 multiply" << endl;
		cout << "4) zad 3" << endl;
		cout << "5) zad 4 policz wielomian" << endl;
		cout << "0) exit" << endl;

		int a = 0;
		cin >> a;

		switch (a)
		{
		case 1:
		{
			FiniteField::generateMultiplicationTable(2, 3);
			cout << endl;
			FiniteField::generateMultiplicationTable(2, 4);
			cout << endl;
			break;
		}
		case 2:
		{
			int x, y, p, m;

			cout << "type first number: ";
			cin >> x;

			cout << "type second number: ";
			cin >> y;

			cout << "tyoe p: ";
			cin >> p;

			cout << "tyoe m: ";
			cin >> m;

			cout << "( " << p << "^" << m << ") " << endl;
			cout << x << " + " << y << " = " << FiniteField::addElements(x, y, p, m) << endl;
			break;
		}

		case 3:
		{
			int x, y, p, m;

			cout << "type first number: ";
			cin >> x;

			cout << "type second number: ";
			cin >> y;

			cout << "tyoe p: ";
			cin >> p;

			cout << "tyoe m: ";
			cin >> m;

			cout << "( " << p << "^" << m << ") "
				 << x << " * " << y << " = " << FiniteField::multiplyElements(x, y, p, m) << endl;

			break;
		}
		case 4:
		{
			FiniteField::generateMultiplicationTableLog(2, 2);
			cout << endl;
			FiniteField::generateAddingTableLog(2, 2);
			cout << endl;

			FiniteField::generateMultiplicationTableLog(2, 3);
			cout << endl;
			FiniteField::generateAddingTableLog(2, 3);
			cout << endl;

			FiniteField::generateMultiplicationTableLog(2, 4);
			cout << endl;
			FiniteField::generateAddingTableLog(2, 4);
			cout << endl;

			break;
		}
		case 5:
		{
			FiniteField::calculatePolynomial(1, 2, 3, 4);
			break;
		}
		case 0:
			exit(0);
		}
	}

	return 0;
}