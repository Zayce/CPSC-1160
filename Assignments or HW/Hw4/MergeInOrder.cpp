/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int* mergeInOrder(int* left, int leftSize, int* right, int rightSize);
void displayArray(int* arr, int length);
void deleteArray(int* arr);

/**
 * Main function that tests the mergeInOrder function, 
 * then displays and then deletes the dynamically created array.
 */
int main(){

    // Dynamically created array 
    int* left = new int[4];
    left[0] = 2;
    left[1] = 3;
    left[2] = 6;
    left[3] = 54;
    int* right = new int[5];
    right[0] = 4;
    right[1] = 6;
    right[2] = 8;
    right[3] = 10;
    right[4] = 125;
    
    //==========

    //Statically created array
    // int leftTemp[] = {2, 3, 6, 54};
    // int rightTemp[] = {4, 6, 8, 10, 125};
    // int* left = leftTemp;
    // int* right = rightTemp;

    //==========

    int* merge = mergeInOrder(left, 4, right, 5);
    deleteArray(left);
    deleteArray(right);
    
    displayArray(merge, 9);
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
    bool isLeftLessOrEqualRight, isLeftArrayEnd, isRightArrayEnd;
    for(int i  = 0, leftIndex = 0, rightIndex = 0; i < MERGED_SIZE; i++){
        isLeftLessOrEqualRight = (left[leftIndex] <= right[rightIndex]);
        isLeftArrayEnd = (leftIndex >= leftSize);
        isRightArrayEnd = (rightIndex >= rightSize);

        if(isLeftArrayEnd){
            merged[i] = right[rightIndex];
            rightIndex += 1;
        }
        else if(isRightArrayEnd){
            merged[i] = left[leftIndex];
            leftIndex++;
        }
        else{
            if(isLeftLessOrEqualRight){
                merged[i] = left[leftIndex];
                leftIndex++;
            }
            else{
                merged[i] = right[rightIndex];
                rightIndex++;
            }
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