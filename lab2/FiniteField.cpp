#include "FiniteField.h"
#include <iostream>
#include <math.h> 
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

namespace
{
    int intPow(int a, int b)
    {
        return int(pow(double(a), double(b)));
    }

    void printElement(vector<string>& elementsArrray, uint32_t index)
    {
        cout << std::setfill(' ') << std::setw(4) << elementsArrray[index];
    }

    int inverseElement(int x, int p, int q)
    {
        if (x != 0 && p > 2)
            return (x + (q - 1) / 2) % (q - 1);
        else if (x != 0 && p == 2)
            return x;
        else if (x == 0)
            return 0;
    }
}

const map<int, vector<int>> FiniteField::zechTable = {
    { 4, {2, 1} },
    { 8, {3, 6, 1, 5, 4, 2} },
    { 16, {4, 8, 14, 1, 10, 13, 9, 2, 7, 5, 12, 11, 6, 3} }
};

void FiniteField::generateMultiplicationTable(int p, int m)
{
    vector<string> elementsArrray;
    
    //
    // Create vector.
    //

    int size = intPow(p, m);
    elementsArrray.reserve(size);

    elementsArrray.push_back("0");
    elementsArrray.push_back("1");
    elementsArrray.push_back("a");

    for (int i = 2; i < size; i++)
        elementsArrray.push_back("a" + to_string(i));

    //
    // Print array.
    //

    for (auto s : elementsArrray)
        cout << std::setfill(' ') << std::setw(4) << s;
    cout << endl;

    cout << "------";
    for (auto s : elementsArrray)
        cout << "----";
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << std::setfill(' ') << std::setw(4) << elementsArrray[i];
        cout << "|";

        for (int j = 0; j < size; j++)
        {
            if (i == 0 || j == 0)
                printElement(elementsArrray, 0);
            else
                printElement(elementsArrray, ((i - 1) + (j - 1)) % (size - 1) + 1);
        }
        cout << endl;
    }
}

int FiniteField::addElements(int x, int y, int p, int m)
{
    int q = intPow(p, m);
    
    //if (zechTable.count(q) == false)
    //{
    //    cout << "Wrong parameters!!!" << endl;
    //    return;
    //}

    if (y > x)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }

    int inversedElementValue = inverseElement(x, p, q);

    int result = 0;

    if (x != 0 && y != 0 && x > y)
    {
        result = (y + zechTable.find(q)->second[x - y - 1] - 1) % (q - 1) + 1;
    }
    else if (y == 0 || x == 0)
    {
        result = x + y;
    }
    else if (x != 0 && y == inversedElementValue)
    {
        result = 0;
    }

    return result;
}

int FiniteField::multiplyElements(int x, int y, int p, int m)
{

    int q = intPow(p, m);

    if (x > 0 && y > 0)
    {
        return 1 + (x + y - 2) % (q - 1);
    }
    else
    {
        return 0;
    }
}

void FiniteField::generateMultiplicationTableLog(int p, int m)
{
    cout << "Multiplication for " << p << "^" << m << endl;

    int q = intPow(p, m);

    cout << "     ";
    for (int i = 0; i < q; i++)
        cout << std::setfill(' ') << std::setw(4) << i;
    cout << endl;

    cout << "-----";
    for (int i = 0; i < q; i++)
        cout << "----";
    cout << endl;

    for (int i = 0; i < q; i++)
    {
        cout << std::setfill(' ') << std::setw(4) << i;
        cout << "|";

        for (int j = 0; j < q; j++)
        {
            cout << std::setfill(' ') << std::setw(4) << multiplyElements(i, j, p, m);
        }
        cout << endl;
    }
}

void FiniteField::generateAddingTableLog(int p, int m)
{
    cout << "Adding for " << p << "^" << m << endl;

    int q = intPow(p, m);

    cout << "     ";
    for (int i = 0; i < q; i++)
        cout << std::setfill(' ') << std::setw(4) << i;
    cout << endl;

    cout << "-----";
    for (int i = 0; i < q; i++)
        cout << "----";
    cout << endl;

    for (int i = 0; i < q; i++)
    {
        cout << std::setfill(' ') << std::setw(4) << i;
        cout << "|";

        for (int j = 0; j < q; j++)
        {
            cout << std::setfill(' ') << std::setw(4) << addElements(i, j, p, m);
        }
        cout << endl;
    }
}

void FiniteField::calculatePolynomial(int x1, int x2, int x3, int x4)
{
    cout << " x1 = " << x1
        << ", x2 = " << x2
        << ", x2 = " << x3
        << ", x3 = " << x4
        << endl;
    
    const int valuesSize = 5;
    int values[valuesSize];

    values[0] = multiplyElements(x1, x2, 2, 4);

    values[1] = addElements(
        addElements(x1, x2, 2, 4),
        addElements(x3, x4, 2, 4)
        , 2, 4);

    values[2] = addElements(
        addElements(
            multiplyElements(
                addElements(x1, x2, 2, 4),
                addElements(x3, x4, 2, 4), 2, 4),
            multiplyElements(x1, x2, 2, 4), 2, 4),
        multiplyElements(x3, x4, 2, 4)
        , 2, 4);

    values[3] = addElements(
        multiplyElements(
            addElements(x3, x4, 2, 4),
            multiplyElements(x1, x2, 2, 4), 2, 4),
        multiplyElements(
            addElements(x1, x2, 2, 4),
            multiplyElements(x3, x4, 2, 4), 2, 4),
        2, 4);

    values[4] = 1;

    for (int i = 4; i >= 0; i--)
    {
        string pref;

        if (values[i] == 1)
        {
            if (i != 4)
            {
                cout << " + ";
            }
            if (i == 0)
            {
                cout << "1";
            }
            else if (i == 1)
            {
                cout << "x";
            }
            else
            {
                cout << "x^" << i;
            }
        }
        else if (values[i] != 0)
        {
            if (i != 4)
            {
                cout << " + ";
            }
            if (values[i] == 2)
            {
                pref = "a";
            }
            else
            {
                pref = "a" + to_string(values[i]);
            }

            if (i == 0)
            {
                cout << pref;
            }
            else if (i == 1)
            {
                cout << pref << "x";
            }
            else
            {
                cout << pref << "x^" << i;
            }
        }
    }

    cout << endl;
}