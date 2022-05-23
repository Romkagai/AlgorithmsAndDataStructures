#include <iostream>
#include "BoolVector.h"
int main() {

    BoolVector B1, B2(10), B3("111011101110"), B4("111011101110", 10), B5("111011101110", 16);
    cout << "1-----------------------"<<endl;
    cout << "B1: " << B1 << endl;
    cout << "B2: " << B2 << endl;
    cout << "B3: " << B3 << endl;
    cout << "B4: " << B4 << endl;
    cout << "B5: " << B5 << endl;
    cout << "2------------------------"<<endl;
    cout << "Weight of В3: " << B3.Weight() << endl;
    cout << "Weight of В5: " << B5.Weight() << endl;
    if (B3 != B5) {
        cout << "В3 != В5" << endl;
    }
    else { cout << "В3 == В5" << endl; }
    cout << "3------------------------"<<endl;
    BoolVector B6(B5);
    cout << "В5: " << B5 << endl;
    cout << "В6: " << B6 << endl;
    cout << "4------------------------"<<endl;
    cout << "В2: ";
    cin >> B2;
    cout << "B2: " << B2 << endl;
    cout << "5------------------------"<<endl;
    B1 = B2;
    cout << "В1: " << B1 << endl;
    if (B1 == B2) {
        cout << "B1 == B2" << endl;
    }
    else { cout << "B1 != B2" << endl; }
    cout << "6------------------------"<<endl;
    BoolVector V1, V2, V3;
    V1 = B1 & B3; V2 = B1 | B3; V3 = B1 ^ B3;
    cout << "V1 = B1 & B3: " << V1 << endl;
    cout << "V2 = B1 | B3: " << V2 << endl;
    cout << "V3 = B1 ^ B3: " << V3 << endl;
    cout << "7------------------------"<<endl;
    B1 = B1 &= B3;
    cout << "B1&=B3: " << B1 << endl;
    if (B1 == V1) {
        cout << "B1 == V1" << endl;
    }
    else { cout << "B1 != V1" << endl; }
    cout << "8------------------------"<<endl;
    B2 = B2 |= B3;
    cout << "B2|=B3: " << B2 << endl;
    if (B2 == V2) {
        cout << "B2 == V2" << endl;
    }
    else { cout << "B2 != V2" << endl; }
    cout << "9------------------------"<<endl;
    cout << "В1:" << B1 << endl;
    B1 = ~B1;
    cout << "~В1: " << B1 << endl;
    int x = B1[4];
    cout << "B1[4]: " << x << endl;
    x = B1[5];
    cout << "B1[5]: " << x << endl;
    cout << "10-----------------------"<<endl;
    cout << "Put 1 to 11 element of В1: ";
    B1.SetUp1(11); cout << "B1: " << B1 << endl;
    cout << "Put 0 to 7 element of В1: ";
    B1.SetUp0(7);
    cout << B1 << endl;
    cout << "Invert 9 element of В1: ";
    B1.Invert(9);
    cout << B1 << endl;
    cout << "11-----------------------"<<endl;
    cout << "Put 3 '1' to В1, starting from 5: ";
    B1.SetUp1(3, 5);
    cout << B1 << endl;
    cout << "Inver 3 element of В1, starting from 1: ";
    B1.Invert(3, 1);
    cout << B1 << endl;
    cout << "12-----------------------"<<endl;
    BoolVector V4;
    V4 = B1 << 4;
    B1 = B1 >> 4;
    cout << "B1: " << B1 << endl;
    cout << "V4: " << V4 << endl;
    if (V4 == B1) {
        cout << "V4 == B1" << endl;
    }
    else { cout << "V4 != B1" << endl;}
}
