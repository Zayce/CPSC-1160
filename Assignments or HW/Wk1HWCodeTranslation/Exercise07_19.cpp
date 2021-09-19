#include <iostream>

using namespace std;

bool isSorted(int*, int);

//TODO: Test this out
int main(){
    // Enter values for list1
    cout << "Enter a list: ";
    int SIZE;
    cin >> SIZE;
    int* list = new int[SIZE];    
    for (int i = 0; i < SIZE; i++){
        cin >> list[i];
    }

    if (isSorted(list, SIZE)){
      cout << "The list is already sorted" << endl;
    }    
    else{
      cout << "The list is not sorted" << endl;
    }
}

bool isSorted(int* list, int LENGTH){
    for (int i = 0; i < LENGTH - 1; i++) {
        if (list[i] > list[i + 1]) {
            return false;
        }
    }

    return true;
}