/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

bool isSorted(int* arr, int size);

/**
 * Main method that tests if isSorted is working.
 */
int main(){
    int arrTemp1[] = {1, 1, 3, 4, 5};
    int arrTemp2[] = {1, 1, 5, 4, 5};

    int* arr1 = arrTemp1;
    int* arr2 = arrTemp2;

    if(isSorted(arr1, 5)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    if(isSorted(arr2, 5)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}

/**
 * Function that shows if an array is sorted in ascending order through recursion.
 * 
 * @param   arr: array
 *          size: size or length of the array
 * 
 * @return  true: If array is sorted in ascending order.
 *          false: If array is not sorted in ascending order.
 */

bool isSorted(int* arr, int size){
    if(size == 0){
        return true;
    }
    else if(arr[size - 1] < arr[size - 2]){
        return false;
    }
    else{
        size--;
        return isSorted(arr, size);
    }
}