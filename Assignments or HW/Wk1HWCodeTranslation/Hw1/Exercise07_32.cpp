#include <iostream>

int partition(int*);

using namespace std;

int main(){
    // Enter values for list1
    cout << "Enter a list: ";
    int size;
    cin >> size;
    int* list = new int[size];    
    for (int i = 0; i < size; i++){
        cin >> list[i];
    }

    partition(list, size); //TODO: fix this, should be about c++ pass by reference problem
    
    cout << "After the partition, the list is ";
    for (int i = 0; i < size; i++){
        cout << list[i] << " ";
    }
}

int partition(int* list, int length){
    int first = 0;
  	int last = length - 1;
    int pivot = list[first]; // Choose the first element as the pivot
    int low = first + 1; // Index for forward search
    int high = last; // Index for backward search

    while (high > low) {
        // Search forward from left
        while ((low <= high) && (list[low] <= pivot)){
            low++;
        }

        // Search backward from right
        while ((low <= high) && (list[high] > pivot)){
            high--;
        }

        // Swap two elements in the list
        if (high > low) {
            int temp = list[high];
            list[high] = list[low];
            list[low] = temp;
        }
    }

    while (high > first && list[high] >= pivot){
        high--;
    }

    // Swap pivot with list[high]
    if (pivot > list[high]) {
      list[first] = list[high];
      list[high] = pivot;
      return high;
    }
    else {
      return first;
    }
}