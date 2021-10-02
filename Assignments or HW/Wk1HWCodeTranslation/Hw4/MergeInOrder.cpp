/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int* mergeInOrder(int* left, int leftSize, int* right, int rightSize);

int main(){
    return 0;
}

int* mergeInOrder(int* left, int leftSize, int* right, int rightSize){
    int mergedSize = leftSize + rightSize;
    int* merged = new int[mergedSize];

    if(leftSize == rightSize){
        return
    }
    else{
        for(int i  = 0, l = 0, r = 0; i < mergedSize; i++){
            if(left[i] <= right[i]){
                merged[i] = left[l]
                l++;
            }
            else{
                merged[i] = right[l];
                r++;
            }
    }
    }

}