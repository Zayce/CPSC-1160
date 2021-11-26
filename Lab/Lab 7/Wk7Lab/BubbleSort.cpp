#include <iostream>
using namespace std;

// The function for sorting the numbers 

void Swap(int* arr, int index1, int index2){
		int temp = arr[index2];
		arr[index2] = arr[index1];
		arr[index1] = temp;
}

void bubbling(int*& arr, int i, int size){
	if(i == size){
		return;
	}

	if(arr[i] > arr[i+1]){
		Swap(arr, i, i+1);
	}

			bubbling(arr, i+1, size);

}

void RecBubbleSort(int*& arr, int size){
	if(size == 1){
		return;
	}

	bubbling(arr, 0, size-1);
	RecBubbleSort(arr, size-1);
}



int main()
{
	const int SIZE = 9;
	int array[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
	int* list = array;
	for (int i = 0; i < SIZE; i++){
		cout << list[i] << " ";
	}
	cout << endl;
	RecBubbleSort(list, SIZE);
	for (int i = 0; i < SIZE; i++){
		cout << list[i] << " ";
	}

	return 0;
}  
