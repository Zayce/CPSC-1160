#include <iostream>
 #include <cstdlib>
 #include <ctime>

using namespace std;

bool IsSame(int* arr1, int* arr2, int arrLen);
int* generateRandomArray(int numItems, int min, int max);
void displayArray(int* arr, int length);

int main(){
    int arrLen = 7;
    //mostly likely return false;
    // int* arr1 = generateRandomArray(arrLen, 0, 24);
    // int* arr2 = generateRandomArray(arrLen, 0, 24);
    //===========

    //Will return true below
    int* arr1 = new int[arrLen];
    int* arr2 = new int[arrLen];


    int temp1[] = {7, 24, 23, 8, 5, 22, 19};
    int temp2[] = {24, 22, 8, 23, 19, 7, 5};

    arr1 = temp1;
    arr2 = temp2;

    displayArray(arr1, arrLen);
    displayArray(arr2, arrLen);

    if(IsSame(arr1, arr2, arrLen)){
        cout << "True" << endl;

    }
    else{
        cout << "False" << endl;
    }

    return 0;
}

/** Worst case scenario is that the two arrays are matching but the elements are opposite of each other.
 *  This algorithm below returns false the instant that it checks one element in arr1 is nowhere in arr2.
 *  
 *  So since n = arrLen, the first check must go through n items. Worst case scenario is the first item in arr1
 *  checks for the last item in arr2. So there will be n comparisons for the first pass.
 * 
 *  The second pass will start from the element of arr1 and will stop at the second to last element in arr2
 *  So this will then be (n - 2)
 * 
 *  So It will be n + (n - 2).... and so on.
 * 
 * The function is F(n) = n + F(n-2)
 *                 F(1) = 1
 *                 F(0) = 1
 *                 
 *                 So there for n items, it will be searched (n-1) times plus (-2n)
 *                 So for n length, we will have F(n) = n + n +.......+ n + -2n
 * 
 *              So at the end it wil be n(n-1) -2n
 *             
 * Since the leading coefficient is n^2.
 * 
 * Thus this algorithm is of size O(n^2) for the worst case running time.
*/
bool IsSame(int* arr1, int* arr2, int arrLen){
    bool sameVar = false;

    for(int i = 0; i < arrLen; i++){
        for(int j = 0; j < arrLen; j++){
            if(arr1[i] == arr2[j]){
                sameVar = true;
            }
        }

        //If at least one element in arr1 is searched throuhgout arr2 and nothing is the same,
        //then it the array must not be equal
        if(sameVar == false){
            return sameVar;
        }

    }

    //if it reaches the end, and it doesn't return false, it must be true.
    return sameVar;
}

/**
 * Displays the array in a nicer format
 * 
 * @param   arr: array
 *          length: length of array
 * @return  void, but the array values are outputed to the terminal
 */
void displayArray(int* arr, int length){
    cout << "{";
    for(int i = 0; i < length - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[length - 1];
    cout << "}" << endl;
}

int* generateRandomArray(int numItems, int min, int max){
    int* a = new int[numItems];

    for(int i = 0; i < numItems; i++ ){
        a[i] = min + rand() % (max - min + 1);
    }

    return a;
}