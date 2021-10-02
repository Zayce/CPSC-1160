/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int* slice(int* arr, int size, int start, int end, int &newSize);
void displayArray(int* arr, int length);


int main(){
    int size, start, end, newSize;

    cout << "How many values would you like your array? ";
    cin >> size;
    const int SIZE = size;

    int* arr = new int[SIZE];

    int tempVal;
    for(int i = 0; i < size; i++){
        cout << "Enter value for index: " << i + 1 << " ";
        cin >> tempVal;
        arr[i] = tempVal;
    }
    
    cout << "Please enter starting index of new array: ";
    cin >> start;
    cout << "Please enter ending index of new array: ";
    cin >> end;

    newSize = end - start + 1;

    int* newArr = slice(arr, size, start, end, newSize);
    delete[] arr;
    arr = nullptr;

    displayArray(newArr, newSize);

    delete[] newArr;
    newArr = nullptr;

    return 0;
}

int* slice(int* arr, int size, int start, int end, int &newSize){
    int* newArr = new int[newSize];

    for(int i = start, j = 0; i <= end; i++, j++){
        newArr[j] = arr[i];
    }

    return newArr;
}

void displayArray(int* arr, int length){
    cout << "{";
    for(int i = 0; i < length - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[length - 1];
    cout << "}" << endl;
}