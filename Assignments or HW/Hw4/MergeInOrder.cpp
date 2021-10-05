/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int* mergeInOrder(int* left, int leftSize, int* right, int rightSize);
void displayArray(int* arr, int length);
void deleteArray(int*);

/**
 * Main function that tests the mergeInOrder function, displays and then deletes the dynamically created array.
 */
int main(){
    int left[] = {2, 3, 6};
    int right[] = {4, 6, 8};
    int* merge = mergeInOrder(left, 3, right, 3);
    displayArray(merge, 6);
    deleteArray(merge);
    return 0;
}

/**
 * Merges two sorted arrays by comparing values in left and 
 * right index and inserts them to the merged array in order.
 * 
 * @param   left: Left array, it is assumed to already be sorted.
 *          leftSize: Size/length of left array.
 *          right: Right array, it is assumed to already be sorted.
 *          rightSize: Size/length of right array.
 * 
 * @return  Merged array sorted ascendingly that is created from contents from left and right array.
 */
int* mergeInOrder(int* left, int leftSize, int* right, int rightSize){
    const int MERGED_SIZE = leftSize + rightSize;
    int* merged = new int[MERGED_SIZE];
    for(int i  = 0, leftIndex = 0, rightIndex = 0;  i < MERGED_SIZE; i++){
        if(left[leftIndex] <= right[rightIndex]){
            merged[i] = left[leftIndex];
            leftIndex++;
        }
        else{
            merged[i] = right[rightIndex];
            rightIndex++;
        }
    }
    return merged;
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