/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int* slice(int*, int, int, int, int&);
void displayArray(int*, int);
void deleteArray(int*);


int main(){
    int size, start, end, newSize;



    int* arr = new int[SIZE];

    int tempVal;
    for(int i = 0; i < SIZE; i++){
        cout << "Enter value for index " << i << ": ";
        cin >> tempVal;
        arr[i] = tempVal;
    }
    
    //Assuming start index and end index are invalid at the beginning as the worst case scenario.
    bool invalidStartIndex = true, invalidEndIndex = true;

    //Validating new starting index to be more than or equal to 0 and less than size - 1
    do{
        cout << "Please enter starting index of new array: ";
        cin >> start;
        invalidStartIndex = ((start < 0) || (start >= size));
        if(invalidStartIndex){
            cout << "Invalid start index. Please enter an index from index 0 to index " << size - 1 << "." << endl;
        }
    }while(invalidStartIndex);

    //Validating new end index to be more than or equal to new starting index and less than size - 1
    do{
        cout << "Please enter ending index of new array: ";
        cin >> end;
        invalidEndIndex = ((start > end) || (end >= size));
        if(invalidEndIndex){
            cout << "Invalid ending index. Please enter an index from index " << start <<
                    " to index " << size - 1 << "." << endl;
        }
    }while(invalidEndIndex);

    newSize = end - start + 1;

    int* newArr = slice(arr, size, start, end, newSize);
    deleteArray(arr);
    displayArray(newArr, newSize);
    deleteArray(newArr);

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

void deleteArray(int* arr){
    delete[] arr;
    arr = nullptr;
}