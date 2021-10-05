/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int* slice(int*, int, int, int, int&);
void displayArray(int*, int);
void deleteArray(int*);

/** 
 * Main method
 */
int main(){
    int size, start, end, newSize;

    //Asking for size
    cout << "How many values would you like your array? ";
    cin >> size;
    const int SIZE = size;

    int* arr = new int[SIZE];

    int tempVal;
    for(int i = 0; i < SIZE; i++){
        cout << "Enter value for index " << i << ": ";
        cin >> tempVal;
        arr[i] = tempVal;
    }

    cout << "Please enter starting index of new array: ";
    cin >> start;
    cout << "Please enter ending index of new array: ";
    cin >> end;

    newSize = end - start + 1;

    int* newArr = slice(arr, size, start, end, newSize);
    deleteArray(arr);
    displayArray(newArr, newSize);
    deleteArray(newArr);

    return 0;
}

/**
 * Sices an array to a new array
 * 
 * @param   arr: array
 *          size: length or size of the array
 *          start: new start index
 *          end: new end index
 *          newSize: new length or size of the new array
 * @return newArray with size newSize.
 */
int* slice(int* arr, int size, int start, int end, int &newSize){
    bool invalidStartIndex = ((start < 0) || (start >= size));
    bool invalidEndIndex = ((start > end) || (end >= size));

    if(invalidStartIndex || invalidEndIndex){
        cout << "Illegal argument." << endl;
        exit(0);
    }

    int* newArr = new int[newSize];
    for(int i = start, j = 0; i <= end; i++, j++){
        newArr[j] = arr[i];
    }

    return newArr;
}

/**
 * Displays arrays in a nice format.
 * 
 * @param   arr: array to be displayed
 *          length: length of array.
 */
void displayArray(int* arr, int length){
    cout << "{";
    for(int i = 0; i < length - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[length - 1];
    cout << "}" << endl;
}

/**
 * Deletes dynamically created array and point it to nullptr.
 * 
 * @param   arr: array to be deleted
 */
void deleteArray(int* arr){
    delete[] arr;
    arr = nullptr;
}