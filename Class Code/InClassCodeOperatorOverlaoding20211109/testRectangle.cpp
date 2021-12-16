#include "calebRectangle.h"
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

int main(){

    Rectangle r1 = Rectangle(6,2);
    Rectangle r2, r3, r4(r1);

    r2 = r1++; // increase width by 1 and length by 1

    cout << r1 << endl;
    cout << r2 << endl;

    // cin >> r2;

    // cout << r2;

    // r3 = r2;

    // cout << r3;

    //r2 = r3 = r4 = r1;

    // cout << r1 << endl;
    //cout << r2 << endl << r3 << endl << r4 << endl;

    // Rectangle* r3 = r1 + r2;

    // r2.Show();
    // rCopy.Show();

    // cout << r2 << endl;
    // cout << r2.ptr << endl;

    // cout << (r1 == r2) << endl;

    // r1 = r2;

    // cout << r1; 
    // r1++;
    // r1 > r2


    // Rectangle r = Rectangle();
    // // r.Show();

    // Rectangle r2 = Rectangle(10, 20);
    // // r2.Show();

    // Rectangle* rPtr = new Rectangle(1, 2);
    // // rPtr->Show();
    // // (*rPtr).Show();
    // int* arr = new int[10];

    // int size = 10;
    // Rectangle* rArr = new Rectangle[size];

    // for(int i = 0; i < size; i++){
    //     // create a default rectangle
    //     rArr[i] = Rectangle(1,1);
    // }

    // Rectangle arr2[] = {Rectangle(), Rectangle(1,1)};

    // // show all rectangles in rArr
    // for(int i = 0; i < size; i++){
    //     (rArr+i)->Show();
    // }

    // if(rArr != nullptr){
    //     delete[] rArr;
    //     rArr = nullptr;
    // }
    return 0;
}