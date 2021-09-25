/**
 *  @author Zulhelmi (Zoella) Zayce
 *  
 *  This program creates an array called books, that contains an array of pages, which contains an array of 
 *  rows, which contains an array of columns. And then displays and sorts them by the total value sum of the 
 *  contents.
 * 
 **/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int*** create3DArray(int, int, int);
int randomValueGenerator();
void display3DArray(int***,int, int, int);
void delete3DArray(int***,int, int);
void swapArr(int***, int, int);
int getPageSum(int***, int, int, int);
void sort(int***, int, int, int);

int main(){

    //Initialize psuedo-random seed
    srand(time(0));

    //Initializing values.
    int pages = 0;
    int lines = 0;
    int columns = 0;

    //Asks for input to put value in..
    cout << "To create a book, please enter the number of: " << endl;
    cout << "Pages = ";
    cin >> pages;
    cout << "Lines = ";
    cin >> lines;
    cout << "Columns = ";
    cin >> columns;


    //Creates 3D Array
    int***book = create3DArray(pages, lines, columns);

    //Displays the book or 3D Array before and after sorting
    cout << "Before Sort" << endl;
    display3DArray(book, pages, lines, columns);

    cout << "===============================================" << endl << endl;

    cout << "After Sort" << endl;
    sort(book, pages, lines, columns);
    display3DArray(book, pages, lines, columns);

    //Cleans out 3D Array
    delete3DArray(book, pages, lines);
    return 0;
}
/**
 *  Dynamically creates a new 3D array and assigns a random number to it
 * 
 *  @param(p: Total number of pages in the book
 *         l: Total number of lines/rows in a page
 *         c: Total number of columns in a line)
 *  @return: Returns a dynamically created 3D Array
 **/
int*** create3DArray(int p, int l, int c){
    int*** array = new int**[p];
        for(int i = 0; i < p; i++){
            array[i] = new int*[l];
            for(int j = 0; j < l; j++){
                array[i][j] = new int[c];
                for(int k = 0; k < c; k++){
                    array[i][j][k] = randomValueGenerator();
                }
            }
        }
    return array;
}

/**
 *  Generates a random integer between FIRST and LAST inclusive, in this case it is 5 to 55 inclusive.
 * 
 *  @param: none/void
 *  @return: Returns a random integer between FIRST (5) AND LAST(55).
 **/
int randomValueGenerator(){
    const int FIRST = 5;
    const int LAST = 55;
    const int DIFFERENCE = LAST - FIRST + 1;

    return (FIRST + (rand() % DIFFERENCE)); 
}

/**
 *  Displays the pages and it's contents of a book in an organized format. Also displays the total sums of
 *  values
 * 
 *  @param(array: 3D array
 *         p: Total number of pages in the book
 *         l: Total number of lines/rows in a page
 *         c: Total number of columns in a line)
 *  @return: void
 **/
void display3DArray(int*** array, int p, int l, int c){
    for(int i = 0; i < p; i++){
    cout << "Page " << i << " || Total sum = " << getPageSum(array, i, l, c) << endl;
    cout << "----------------------------" << endl;
    for(int j = 0; j < l; j++){
        for(int k = 0; k < c; k++){
            cout << array[i][j][k] << ", ";
        }
        cout << endl;
    }
    cout << endl;
    }
}

/**
 *  Goes to each dynamically created array frees up the memory, and point the arrays in each level to nullptr.
 * 
 *  @param(array: 3D array
 *         p: Total number of pages in the book
 *         l: Total number of lines/rows in a page
 *  @return: void
 **/
void delete3DArray(int*** array, int p, int l){
    for(int i = 0; i < p; i++){
        for(int j = 0; j < l; j++){
            delete[] array[i][j];
            array[i][j] = nullptr;
        }
    delete[] array[i];
    array[i] = nullptr;
    }

    delete[] array;
    array = nullptr;
}

/**
 *  Calculates the total sum of integer values in each page.
 * 
 *  @param(array: 3D array
 *         pageIndex: Page that is accessed to calculate the total sum of integer values
 *         l: Total number of lines/rows in a page
 *         c: Total number of columns in a line)
 *  @return: Returns the total sum of integer values in a given page.
 **/
int getPageSum(int*** array, int pageIndex, int l, int c){
    int sum = 0;
    for(int j = 0; j < l; j++){
        for(int k = 0; k < c; k++){
            sum += array[pageIndex][j][k];
        }
    }
    return sum;
}

/**
 *  Uses bubble sort to sort pages by their total sum of values in each page
 * 
 *  @param(array: 3D array 
 *         p: Total number of pages in the book
 *         l: Total number of lines/rows in a page
 *         c: Total number of columns in a line)
 *  @return: void
 **/
void sort(int*** array, int p, int l, int c){
    for(int i = 0; i < p; i++){
        for(int j = 0; j < p-i-1; j++){
            if(getPageSum(array, j, l, c) > getPageSum(array, j + 1, l, c)){
                swap(array[j], array[j+1]);
            }
        }
    }
}
