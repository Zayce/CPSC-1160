/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int getNthItem(int* arr, int size, int &start, int n);
void displayArray(int* arr, int length);

/**
 * Main function to test getNthItem function. 
 */
int main(){
    int size, startIndex, indexOfInterest;
    int arr[] = {4, 5, 3, 2, 1, 6, 7};
    size = 7;
    startIndex = 0;

    cout << "Please enter a value: ";
    cin >> indexOfInterest;

    cout << "The " << indexOfInterest << "th index value is: ";
    cout << getNthItem(arr, size, startIndex, indexOfInterest) << endl;
    return 0;
}


/**
 * Finds the nth item or nth value of an array recursively.
 * 
 * @param   arr: array
 *          size: length/size of array
 *          start: pass by reference of the starting index
 *          n: Index of interest that we want to know the vakue of
 * 
 * @return  Returns the value of index n
 *          Returns -1 if indexOfInterest is more than or equal to size.
 * 
 **/
int getNthItem(int* arr, int size, int &start, int n){
    if(start == n){
        return arr[start];
    }
    else if(n >= size){
        return -1;
    }
    else{
        start++;
        return getNthItem(arr, size, start, n);
    }
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