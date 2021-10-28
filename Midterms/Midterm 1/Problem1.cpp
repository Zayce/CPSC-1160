#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int** GenerateMatrix(int rowSize, int colSize, int min, int max);
void Show(int** arr, int rowSize, int colSize);
int MainDiagonalSum(int** matrix, int r, int c);

int main(){
    srand(time(0));

    int rowSize = 10;
    int colSize = 10;

    int** arr2D = GenerateMatrix(rowSize ,colSize , 0, 9);
    Show(arr2D, rowSize, colSize);

    cout << MainDiagonalSum(arr2D, rowSize ,colSize) << endl;
    return 0;
}

int MainDiagonalSum(int** matrix, int r, int c){

    if(r == 0 || c ==0){
        return 0;
    }
    else if (r == 1 || c == 1){
        return matrix[0][0];
    }
    
    int sum = 0;
    //Make a rectangular matrix a square one as that is the only possible
    if(r < c){
        c = r;
    }
    else if(r > c){
        r = c;
    }

    int** reducedMatrix = new int*[r];

    for(int i = 0; i < r; i++){
        reducedMatrix[i] = new int[c];
    }

    for(int i = 0; i < r-1; i++){
        for(int j = 0; j < c-1; j++){
            reducedMatrix[r][c] = matrix[r+1][c+1];
        }
    }
    
    sum += matrix[0][0];
    r--;
    c--;
    return sum + MainDiagonalSum(reducedMatrix, r, c);

}

int** GenerateMatrix(int rowSize, int colSize, int min, int max){
    int** arr2D = new int*[rowSize];

    for(int i = 0; i < rowSize; i++){
        arr2D[i] = new int[colSize];
    }

    for(int i = 0; i < rowSize; i++ ){
        for(int j = 0; j < colSize;j++){
            arr2D[i][j] = min + rand() % (max - min + 1);
        }
    }

    return arr2D;
}

/**
 * Displays a 2D array in a nicer format
 * 
 * @param   arr: 2D array
 *          rowSize: length of row
 *          colSize: length of column
 * @return  void, but the array values are outputed to the terminal
 */
void Show(int** arr, int rowSize, int colSize){
    for(int i = 0; i < rowSize; i++ ){
        cout << "{";
        for(int j = 0; j < colSize;j++){
            cout << arr[i][j] << ", ";
        }
        cout << "}" << endl;
    }
}
