#include "Set.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    Set temp, temp2;
    temp.GenerateRandom(5, 0, 100);
    temp2 = temp;
    temp2.AddElement(-23);
    cout << temp << endl;
    cout << temp2 << endl;

    cout << temp + temp2 << endl;

    // cin >> temp;
    // cout << "Size " << temp.size() << endl;
    // cout << temp << endl;
    // cout << temp << endl;
    return 0;
}