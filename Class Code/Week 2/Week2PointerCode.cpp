#include <iostream>

using namespace std;

int main(){
    int SIZE = 5;
    int* arr = new int[SIZE];

    for(int i = 0; i < SIZE; i++){
        //cout << arr[i] << endl;
        cout << (arr + i) << endl;
        cout << *(arr + i) << endl;
    }

    return 0;
}