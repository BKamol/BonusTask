#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Comp.h"

using namespace std;

int main()
{
    int size1;
    int size2;
    /*cout << "Input sizes of vectors: " << endl;
    cin >> size1 >> size2;
    Vector<double> a(size1);
    Vector<double> b(size2);

    cout << "Input " << size1 << " elements of first vector: " << endl;
    cin >> a;
    cout << "Input " << size2 << " elements of second vector: " << endl;
    cin >> b;
    cout <<"a = " << a << "b = " << b << endl;

    cout << endl;
    Vector<double> c = (a + b) * a;
    cout << "c = " << c << endl;*/


    cout << "Input sizes of vectors: " << endl;
    cin >> size1 >> size2;
    Vector<Comp> compA(size1);
    Vector<Comp> compB(size2);

    ifstream in("in.txt");
    for (int i = 0; i < size1; i++)
        in >> compA[i];
    for (int i = 0; i < size2; i++)
        in >> compB[i];
    in.close();

    cout << "compA = " << compA << endl;
    cout << "compB = " << compB << endl;

    Vector<Comp> compC = (compA + compB) * compA;
    cout <<"compC = " << compC;

}
