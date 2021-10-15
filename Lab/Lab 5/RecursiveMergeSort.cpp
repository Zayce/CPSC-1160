/**
 * @author Zoella (Zulhelmi) Mohamad
 * 
 * This program sorts an randomly generated array with recursive merge sort.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* recMergeSort(int* arr, int start, int end);
int* generateRandomArray(int numItems, int min, int max);
int* mergeInOrder(int* left, int lSize, int* right, int rSize);
void displayArray(int* arr, int length);
void deleteArray(int* arr);

int main(){
    srand(time(0));
    int size = 10;
    int start = 0;
    int end = size - 1;

    int* arr = generateRandomArray(size, 1, 30); // function returns an array with 5 integers where each integer is between 20 and 30

    cout << "Before sorting: ";
    displayArray(arr, size);

    arr = recMergeSort(arr, start, end);

    cout << "After sorting: ";
    displayArray(arr, size);

    deleteArray(arr);

    return 0;
}

/**
 * Recursive merge sort
 * 
 * @param   arr: array to be sorted
 *          start: start index of selected subarray
 *          end: end index of selected subarray
 * 
 * @return returns a sorted array 
 */ 
void recMergeSort(int* &arr, int start, int end){
    int size = end - start + 1;

    if(size == 1){
        int* baseCase = new int[1];
        baseCase[0] = arr[start];
        return baseCase;
    }
    else{
        int mid = start + (size/2);
        
        int leftSize = mid - start + 1;
        int* left = new int[leftSize];

        int rightSize = end - mid + 1;
        int* right = new int[rightSize];

        left = recMergeSort(arr, start, mid-1);
        right = recMergeSort(arr, mid, end);

        arr = mergeInOrder(left, leftSize, right, rightSize);

        return merged;

    }
}

/**
 * Generates random array given the input
 * 
 * @param   numItems: Number of int values in the array
 *          min: smallest number to be generated in array.
 *          max: highest number to be generated in array.
 * @return  Returns an array of size numItems, with random values ranging from min to max inclusive.
 */ 
int* generateRandomArray(int numItems, int min, int max){
    int* a = new int[numItems];

    for(int i = 0; i < numItems; i++ ){
        a[i] = min + rand() % (max - min + 1);
    }

    return a;
}

/**
 * Given two arrays, will sort the values one by one in ascending order.
 * 
 * @param   left: left array
 *          lSize: left array size
 *          right: right array
 *          rSize: right array size
 * @return returns a sorted array, and deleting the left and right array input.
 */
int* mergeInOrder(int* left, int lSize, int* right, int rSize) {
	int i, j, k;
	int* merged = new int[lSize + rSize];
	i = j = k = 0;

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

    //If below arrays exist, delete them to free up memory.
	if(left){
		deleteArray(left);
	}
	if(right){
		deleteArray(right);
    }
	return merged;
}

/**
 * Displays the array in the console in a neat format
 * 
 * @param   arr: array to be displayed
 *          length: length of the array
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
