/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int getNthItem(int* arr, int size, int &start, int n);
void displayArray(int* arr, int length);


int main(){
    int* arr = new arr[7]{4, 5, 3, 2, 1, 6, 7};
    int s = sizeof(arr) / sizeof(int);
    int startIndex = 0;
    startIndex = 0;

    int desiredIndex;
    cout << "Length is " << s << endl;
    cout << "Please enter a value: ";
    cin >> desiredIndex;

    cout << getNthItem(arr, s, startIndex, desiredIndex) << endl;
    return 0;
}

int len(int arr[]){
    int i = 0, sum = 0;
    while(arr[i] != 0){
        sum++;
        i++;
    }
    return sum;
}

int getNthItem(int* arr, int size, int &start, int n){
    if(start == n){
        return arr[start];
    }
    else if(n > size){
        return -1;
    }
    else if(start == size){
        return -1;
    }
    else{
        start++;
        return getNthItem(arr, size, start, n);
    }
}

void displayArray(int* arr, int length){
    cout << "{";
    for(int i = 0; i < length - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[length - 1];
    cout << "}" << endl;
}