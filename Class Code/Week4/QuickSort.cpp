#include <iostream>

using namespace std;

void placePivot(int* arr, int len);
void swap(int* arr, int a, int b);
void displayArray(int* arr, int length);

int main(){
    int arr[] = {4, 3, 5, 6, 9, 1, 2};
    int len = 7;
    displayArray(arr, len);
    placePivot(arr, len);
    displayArray(arr, len);
}

void placePivot(int* arr, int len){
    int pivot, low, high;

    pivot = 0;
    low = 1;
    high = len - 1;
    while(high > low){
        while(arr[low] < arr[pivot]){
            low++;
        }
        
        while(arr[pivot] < arr[high]){
            high++;
        }

        if(arr[low] > pivot && arr[high] < pivot){
            swap(arr, low, high);
        }
        cout << 3; //It stops hee
    }
    swap(arr, pivot, high);
}

void swap(int* arr, int a, int b){
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

void displayArray(int* arr, int length){
    cout << "{";
    for(int i = 0; i < length - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[length - 1];
    cout << "}" << endl;
}