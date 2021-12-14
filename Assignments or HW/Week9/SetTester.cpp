#include "Set.h"
#include "Set.cpp"

using namespace std;

int main(){
    srand(time(0));
    Set temp = Set();
    temp.GenerateRandom(12, 0, 100);

    cout << temp << endl;
    return 0;
}

// g++ -pedantic -Wall -Wextra -std=c++17 files -o sort