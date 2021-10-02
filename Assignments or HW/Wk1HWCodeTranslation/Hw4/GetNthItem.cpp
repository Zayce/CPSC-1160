/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int getNthItem(int* arr, int size, int &start, int n);
int len(int[]);

//TODO:: Fix this horrible mess
int main(){
    int arr[] = {4, 5, 3, 2, 1, 6, 7, 0};
    int* pArr = arr;
    int s = len(arr);
    int startIndex = 0;
    startIndex = 0;

    int desiredIndex;
    cout << s << endl;
    cout << "Please enter a value: ";
    cin >> desiredIndex;

    cout << getNthItem(pArr, s, startIndex, desiredIndex) << endl;
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