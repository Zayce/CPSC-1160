#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int PlacePivot(int* arr, int len);
int* GenerateRandomArray(int numItems, int min, int max);
void DisplayArray(int* arr, int &start, int len);
int** Split(int* arr, int arrLen, int splitIndex, int &leftSize, int &rightSize);
int* Merge(int* leftArr, int leftSize, int pivot, int* rightArr, int rightSize);
void QuickSort(int* arr, int len);
void deleteArray(int* arr);

int PlacePivot(int* arr, int len) {
    int pivot, low, high;

    pivot = 0;
    low = 1;
    high = len - 1;

    // place pivot.
    while (low <= high) {
        if (arr[low] <= arr[pivot]) {
            low++;
        }
        else if (arr[high] > arr[pivot]) {
            high--;
        }
        else if(low <= high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high]= temp;
        }
    }
    //swap item @ pivot with item @ high
    int temp = arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = temp;

    return high;
}

int* GenerateRandomArray(int numItems, int min, int max){
    int* a = new int[numItems];

    for(int i = 0; i < numItems; i++ ){
        a[i] = min + rand() % (max - min + 1);
    }

    return a;
}

void DisplayArray(int* arr, int &start, int len){
    // recursively display: item at 0, item at 1, item at 2, ...
    // for example: 5, 6, 3, 1, ....

    if(start < len){
        // recursive case
        cout << arr[start] << ", ";
        start++;

        DisplayArray(arr, start, len);

        return;
    }
    else{
        // start >= len
        return;
    }

        
}

int** Split(int* arr, int arrLen, int splitIndex, int &leftSize, int &rightSize){
    /*
    // MEMORY LEAKS ????

    splits arr into two pieces, left and right which ar kept in arr2D[0] and arr2D[1] respectively.

    left contains arr[0] to arr[splitIndex - 1] (both inclusive)
    right contains arr[splitIndex + 1] to arr[arrLen - 1] (both inclusive)

    leftSize wil be set to number of items in arr2D[0]
    rightSize will be set to number of items in arr2D[1]
    */

    int** arr2D = new int*[2];

    leftSize = splitIndex;
    rightSize = arrLen - leftSize - 1;

    // allocating memory for left array
    arr2D[0] = new int[leftSize];
    // allocating memory for right array
    arr2D[1] = new int[rightSize];

    // transfer contents from arr to left array
    for(int i = 0; i < leftSize; i++){
        arr2D[0][i] = arr[i];
    }

    // transfer contents from arr to right array
    for(int i = 0; i < rightSize; i++){
        arr2D[1][i] = arr[splitIndex + 1 + i];
    }

   return arr2D;
}

int* Merge(int* leftArr, int leftSize, int pivot, int* rightArr, int rightSize){

    int* temp = new int[leftSize + rightSize + 1];

    int mergedIndex = 0;

    for(int i = 0; i < leftSize; i++){
        temp[mergedIndex] = leftArr[i];
        mergedIndex++;
    }

    temp[mergedIndex] = pivot;
    mergedIndex++;

    for(int i = 0; i < rightSize; i++){
        temp[mergedIndex] = rightArr[i];
        mergedIndex++;
    }

    return temp;

}


void QuickSort(int* &arr, int len){
    // sorts arr in ascending order in place (no new array is returned, arr is modified)

    if(len == 0 || len == 1){
        return;
    }

    int pivotIndex = PlacePivot(arr, len);
    int pivot = arr[pivotIndex];

    int leftSize, rightSize;
    leftSize = pivot - 1;
    rightSize = len - (pivot + 1);
    int** splits = Split(arr, len, pivotIndex, leftSize, rightSize);

    QuickSort(splits[0], leftSize);

    QuickSort(splits[1], rightSize);

    arr = Merge(splits[0], leftSize, pivot, splits[1], rightSize);

    return;
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

int main(){
    srand(time(0));
    int size = 10;
    int start = 0;
    int** test;

    int lSize, rSize, pivotIndex;

    int* arr = GenerateRandomArray(size, 20, 30); // function returns an array with 5 integers where each integer is between 20 and 30
    // pivotIndex = PlacePivot(arr, size);
    // lSize = pivotIndex - 1;
    // rSize = size - (pivotIndex + 1);

    cout << "original" << endl;
    DisplayArray(arr, start, size);

    cout << endl;

    QuickSort(arr, size);

    cout << "\nAfter sorting" << endl;
    start = 0;
    DisplayArray(arr, start, size);

    return 0;
}

