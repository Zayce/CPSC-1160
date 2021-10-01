/**
 *  @author Zulhelmi (Zoella) Zayce
 *  
 * 
 **/

#include <iostream>
#include <string>

using namespace std;

int Fun(int* arr, int arrSize, int &i, int n){
    if(i == n){
        return arr[i];
    }
    else if(i == arrSize){
        return -1;
    }
    else{
        i+=1;
        int smallSolution = Fun(arr, arrSize, i, n);
        return smallSolution;
    }
}

int main(){
    int a[] = {5, 4, 1, 2, 3};
    int size = 5;
    int index = 0;
    int k = 1;

    cout << Fun(a, size, index, k) << endl;



    return 0;
}