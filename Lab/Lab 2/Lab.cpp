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
void print3DArray(int***,int, int, int);
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
    cout << "Pages =  ";
    cin >> pages;
    cout << "Lines =  ";
    cin >> lines;
    cout << "Columns =  ";
    cin >> columns;

    int***book = create3DArray(pages, lines, columns);

    cout << "Before Sort" << endl;
    print3DArray(book, pages, lines, columns);

    cout << "===============================================" << endl << endl;

    cout << "After Sort" << endl;
    sort(book, pages, lines, columns);
    print3DArray(book, pages, lines, columns);

    delete3DArray(book, pages, lines);
    return 0;
}

int*** create3DArray(int p, int l, int c){
    int*** array3D = new int**[p];
        for(int i = 0; i < p; i++){
            array3D[i] = new int*[l];
            for(int j = 0; j < l; j++){
                array3D[i][j] = new int[c];
                for(int k = 0; k < c; k++){
                    array3D[i][j][k] = 5 + (rand() % 51); //Assisngs and random number between 5 and 55 inclusive
                }
            }
        }
    return array3D;
}


void print3DArray(int*** array, int p, int l, int c){
    for(int i = 0; i < p; i++){
    cout << "Page " << i << ": " << getPageSum(array, i, l, c) << endl;
    cout << "-----------------------" << endl;
    for(int j = 0; j < l; j++){
        for(int k = 0; k < c; k++){
            cout << array[i][j][k] << ", ";
        }
        cout << endl;
    }
    cout << endl;
    }
}

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

int getPageSum(int*** array, int pageIndex, int l, int c){
    int sum = 0;
    for(int j = 0; j < l; j++){
        for(int k = 0; k < c; k++){
            sum += array[pageIndex][j][k];
        }
    }
    return sum;
}

void sort(int*** array, int totalPageLength, int l, int c){
    for(int i = 0; i < totalPageLength; i++){
        for(int j = 0; j < totalPageLength-i-1; j++){
            if(getPageSum(array, j, l, c) > getPageSum(array, j + 1, l, c)){
                swap(array[j], array[j+1]);
            }
        }
    }
}
