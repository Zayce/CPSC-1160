/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

bool isSorted(int* arr, int size);

int main(){
    int arrTemp[] = {1, 1, 3, 4, 5};

    int* arr = arrTemp;

    if(isSorted(arr, 5)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}

bool isSorted(int* arr, int size){
    if(size == 0){
        return true;
    }
    else if(arr[size - 1] < arr[size - 2]){
        return false;
    }
    else{
        size--;
        return isSorted(arr, size);
    }
}