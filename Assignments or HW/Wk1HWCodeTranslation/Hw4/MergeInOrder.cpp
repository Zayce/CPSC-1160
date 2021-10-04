/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

void displayArray(int* arr, int length);
int* mergeInOrder(int* left, int leftSize, int* right, int rightSize);

int main(){
    int leftTemp[] = {2, 3, 6};
    int* left = leftTemp;
    int rightTemp[] = {4, 6, 8};
    int* right = rightTemp;

    int* merge = mergeInOrder(left, 3, right, 3);
    displayArray(merge, 6);

    return 0;
}


void displayArray(int* arr, int length){
    cout << "{";
    for(int i = 0; i < length - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[length - 1];
    cout << "}" << endl;
}


int* mergeInOrder(int* left, int leftSize, int* right, int rightSize){
    const int mergedSize = leftSize + rightSize;
    int* merged = new int[mergedSize];
    for(int i  = 0, l = 0, r = 0;  i < mergedSize; i++){
        if(left[l] <= right[r]){
            merged[i] = left[l];
            l++;
        }
        else{
            merged[i] = right[r];
            r++;
        }
    }

    return merged;

}