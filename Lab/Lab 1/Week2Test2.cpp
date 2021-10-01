#include <iostream>

using namespace std;

void clearArray(int*, int);

int main(){
    const int SIZE = 100;
    const int DIGIT = 10;
    srand(time(0));

    int* arr = new int[SIZE];
    int* count = new int[DIGIT];

    clearArray(count, DIGIT);

    cout << "random = [";
    for(int i = 0; i < SIZE; i++){
        int value = rand() % 10;
        arr[i] = value;
        count[value]++;
        cout << arr[i] << ", ";
    }
        cout << "]" << endl;

    cout << "digitCount = [";
    for(int i = 0; i < DIGIT; i++){
        cout << count[i] << ", ";
    }
    cout << "]" << endl;


    cout << endl;

    return 0;
}

void clearArray(int* a, int length){
    for(int i = 0; i < length; i++){
        a[i] = 0;
    }
}