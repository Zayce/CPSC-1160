
int* MergeInOrder(int* left, int lSize, int* right, int rSize) {
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

bool IsSorted(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i+1]) { // items out of place
			return false;
		}
	}

	return true;
}

int GenerateRandomValue(int min, int max){
	return min + (rand() % (max - min + 1));
}

int** GenerateRandomArray(int rows, int cols, int min, int max){
	int** arr2D = new int*[rows];
	for(int i = 0; i < rows; i++){
		arr2D[i] = new int[cols];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			arr2D[i][j] = GenerateRandomValue(min, max);
		}
	}

	return arr2D;
}

void Randomize(int* arr, int size){
	for(int i = 0; i < size; i++){
		int randomIndex = GenerateRandomValue(0, size - 1);
		Swap(arr, i, randomIndex);
	}	
}

void Display(int** arr, int rows, int cols) {
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "--------------\n";
	cout << "--------------\n";
}

void Swap(int* a, int leftIndex, int rightIndex) {
	int temp = a[leftIndex];
	a[leftIndex] = a[rightIndex];
	a[rightIndex] = temp;
}
