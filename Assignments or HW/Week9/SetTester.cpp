#include "Set.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    Set temp;
    temp.GenerateRandom(12, 0, 100);

    cout << temp << endl;
    cout << temp << endl;
    cout << temp << endl;

    return 0;
}