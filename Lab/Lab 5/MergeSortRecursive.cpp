#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayArray(int* arr, int length);
void deleteArray(int* arr);
int* generateRandomArray(int numItems, int min, int max);
int* MergeInOrder(int* left, int lSize, int* right, int rSize)
int* recMergeSort(arr, size);
void Swap(int* a, int leftIndex, int rightIndex);

int main(){
    srand(time(0));
    int size = 10;
    int start = 0;
    int end = size - 1;

    int* arr = generateRandomArray(size, 1, 30); // function returns an array with 5 integers where each integer is between 20 and 30
    
    cout << "Before sorting: ";
    displayArray(arr, start, size);

    recMergeSort(arr, start, end);

    cout << "After sorting" << endl;
    displayArray(arr, start, size);

    deleteArray(arr);

    return 0;
}

/**
 * Displays the array in a nicer format
 * 
 * @param   arr: array
 *          length: length of array
 * @return  void, but the array values are outputed to the terminal
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
 * Merges two sorted arrays by comparing values in "left" and 
 * "right" index and inserts them to the merged array in order. Only left index and right index is passed
 * instead of creating new arrays in memory to avoid tedious deleting and unallocating dynamic memor.
 * 
 * @param   left: Left array, it is assumed to already be sorted.
 *          right: Right array, it is assumed to already be sorted.
 * 
 * @return  Not returning anything, but left and right "arrays" are sorted
 */
void mergeInOrder(int* arr, int start, int mid, int end){
    bool isLeftArrayEnd, isRightArrayEnd;
    int leftIndex = start, rightIndex = mid;

    //If base case start and end index is same, do nothing and return void.
    if(start == end){
        return;
    }
    else{
        isLeftArrayEnd = (leftIndex >= mid);
        isRightArrayEnd = (rightIndex >= end);

        if(isLeftArrayEnd){

        }
        else if (isRightArrayEnd){

        }
        else{
            if(arr[leftIndex] <= arr[rightIndex]){
                leftIndex++
            }
            else{
                rightIndex++;
            }

        }
        }
    }




    }
}

void recMergeSort(int* arr, int size, int start, int end){
    int mid = size/2;

    //Base case when size of array is 1 is
    if(size > 1){
        recMergeSort(arr, start, mid-1);
        recMergeSort(arr, mid, end);

        MergeInOrder(arr, )
    }
    return;
}


int* generateRandomArray(int numItems, int min, int max){
    int* a = new int[numItems];

    for(int i = 0; i < numItems; i++ ){
        a[i] = min + rand() % (max - min + 1);
    }

    return a;
}

int* MergeInOrder(int* left, int lSize, int* right, int rSize) {
	int i, j, k;
	int* merged = new int[lSize + rSize];
	i = j = k = 0;

    if(lSize )

	while (i < lSize && j < rSize) {
		if (left[i] <= right[j]) {
			merged[k++] = left[i++];
		}
		else {
			merged[k++] = right[j++];
		}
	}
	//remaining items in left, just put in merge since left is already sorted
	while (i < lSize) {
		merged[k++] = left[i++];
	}
	// similarly do for right, in case right has items remaining to place in the merged array
	while (j < rSize) {
		merged[k++] = right[j++];
	}

	if(left){
		delete[] left;
		left = nullptr;
	}
	if(right){
		delete[] right;
		right = nullptr;
	}
	return merged;
}

void Swap(int* a, int leftIndex, int rightIndex) {
	int temp = a[leftIndex];
	a[leftIndex] = a[rightIndex];
	a[rightIndex] = temp;
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
