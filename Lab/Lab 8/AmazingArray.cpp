#include <iostream>
#include <ctime>
#include <cstdlib>
#include "AA.h"

using namespace std;

int* genRanArr(int len, int min, int max);

int main(){
    
    // srand(time(0));

    int size = 3;
    int normArr[] = {40,30,10};
    AmazingArray* arr = new AmazingArray(normArr, size);

    arr->Show();
    arr->Append(42);
    arr->Show();
    arr->RemoveEnd();
    arr->RemoveEnd();
    arr->Show();

    return 0;
}



int* genRanArr(int len, int min, int max){
    int* arr = new int[len];
    for(int i = 0; i < len; i++){
        arr[i] =  (min + (rand() % (max - min + 1)));
    }
    return arr;
}