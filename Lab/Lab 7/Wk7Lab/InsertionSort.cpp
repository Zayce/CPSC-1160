#include <iostream>
using namespace std;


void Swap(int* arr, int index1, int index2){
		int temp = arr[index2];
		arr[index2] = arr[index1];
		arr[index1] = temp;
}

void Inserting(int*& array, int index, int size){
  for (int i = 1; i < listSize; i++) 
  {
    // Insert list[i] into a sorted sublist list[0..i-1] so that
    //  list[0..i] is sorted. 
    int currentElement = list[i];
    int k;
    for (k = i - 1; k >= 0 && list[k] > currentElement; k--) 
    {
      list[k + 1] = list[k];
    }

    // Insert the current element into list[k+1]
    list[k + 1] = currentElement;
    
  }
  Inserting(array, index+1, size-1);
}


void RecInsertionSort(int*& array, int size) 
{

  if(size == 1){
    return;
  }

  Inserting(array, 1, size-1);

  RecInsertionSort(array, size-1);
}

int main()
{
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  int* arr = list;
  cout << "Before: ";
    for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";
  cout << endl << "After :";
  insertionSort(arr, SIZE);
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";

  return 0;
}  
