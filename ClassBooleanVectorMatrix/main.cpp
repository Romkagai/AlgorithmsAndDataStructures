#include <iostream>
#include "ClassBooleanVectorMatrix.h"
int main() {
    setlocale(LC_ALL, "Russian");
        BoolMatrix B1(4, 20);
        cout << "B1: " << endl <<B1 << endl;

        B1.Invert(0, 8, 10);
        B1.SetUp1(1, 6, 14);
        B1.SetUp1(2, 6, 8);
        for (int i = 0; i < 20; i ++)
        {
            if (i % 2 != 0) {
                B1.SetUp1(3, i);
            }
        }
        cout << "New B1:" << endl << B1 << endl;

        BoolMatrix B2(B1);
        cout << "B2 = B1: " << endl << B2;
        if (B1 == B2) {
            cout << endl <<"B1 == B2" << endl << endl;
        }
        else { cout << endl << "B1 != B2" << endl << endl; }

        B2.ShiftRightEq(0, 6);
        B2.ShiftLeftEq(2, 6);
        B2.SetUp0(1, 16); B2.SetUp0(1, 18);
        for (int i = 0; i < 20; i+=2)
        {
            B2.Invert(3, i);
        }
        cout << "New B2:" << endl << B2 << endl;

        BoolMatrix B3(4, 20);
        cout << "Enter B3: " << endl;
    /*
11111111111111111111
00000000000000000000
10101010101010101010
11110000111100001111
    */
        cin >> B3;
        cout << "B3: " << endl << B3 << endl;
        if (B2 == B3) {
            cout << "B2 = B3" << endl << endl;
        }
        else { cout << "B2 != B3" << endl << endl; }

        cout << "Enter four strings: " << endl;
/*
11111111111111111111
1010101010
1111111111
111100001111
*/
        int rows = 4;
        char** arr = new char* [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new char[100];

        for (int i = 0; i < rows; i++)
            cin >> arr[i];

        BoolMatrix B4(arr, 4);
        cout << endl << "B4: " << endl << B4 << endl;

        for (int i = 0; i < rows; i++)
            delete[] arr[i];

        delete[] arr;

        BoolMatrix C1, C2, C3, C4;
        cout << "C1: " << C1;
        if (C1 == B1) {
            cout << "C1 = B1" << endl << endl;
        }
        else { cout << "C1 != B1" << endl << endl; }

        C1 = B1 & B2; C2 = B1 | B2; C3 = B1 ^ B2; C4 = ~B4;
        cout << "C1 = B1 & B2: " << endl << C1 << endl;
        cout << "C2 = B1 | B2: " << endl << C2 << endl;
        cout << "C3 = B1 ^ B2: " << endl << C3 << endl;
        cout << "C4 = ~B4: " << endl <<C4 << endl;

        B1 &= B2;
        cout << "B1 &= B2: " << endl << B1 << endl;
        if (C1 == B1) {
            cout << "C1 == B1" << endl << endl;
        }
        else { cout << "C1 != B1" << endl << endl; }

        cout << "B1[1]: " << B1[1] << endl;
    int xtemp = B1[1][19];
        cout << "B1[1][19]: " << xtemp << endl;
    xtemp = B1[1][18];
        cout << "B1[1][18]: " << xtemp << endl << endl;

        cout << "B1.Disj(): ";
        BoolVector temp;
        temp = B1.Disj();
        cout << temp << endl;
        temp = B1.Xor();
        cout << "B1.XOR: " << temp << endl;
}
