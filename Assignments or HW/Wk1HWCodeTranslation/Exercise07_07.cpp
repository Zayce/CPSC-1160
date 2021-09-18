#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));

    const int SIZE = 10;

    int* counts = new int[SIZE];

    for (int i = 0; i < 100; i++) {
      int value = rand() % 10;
      counts[value]++;
    }

    for (int i = 0; i < SIZE; i++) {
        cout << "Count for " << i << " is " << counts[i] << endl;
    }
}