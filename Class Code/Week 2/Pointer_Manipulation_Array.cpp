#include <iostream>

using namespace std;

int main(){

    // int x[] = {23, 45, 1, 100, 0};
    // int sum = 0;
    // int* ptr = x;

    // while (*ptr != 0){
    //     sum += *(ptr++);
    // }

    // cout << sum << endl;
    /*
    int pages = 10;
    int rowsPerPage = 20;
    int colsPerRow = 30;

    int*** ptr = new int**[pages];
    for(int i = 0; i < pages; i++){
        ptr[i] = new int*[rowsPerPage];
        for(int j = 0; j < rowsPerPage; j++){
            ptr[i][j] = new int[colsPerRow];
            for(int k = 0; k < colsPerRow; k++){
                ptr[i][j][k] = 1;
            }
        }
    }

    //Prints the arrays
    for(int i = 0; i < pages; i++){
        cout << "Page " << i+1 << ": " << endl;
        cout << "=========================================================================================" << endl;
        for(int j = 0; j < rowsPerPage; j++){
            for(int k = 0; k < colsPerRow; k++){
                cout << ptr[i][j][k] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for(int i = 0; i < pages; i++){
        for(int j = 0; j < rowsPerPage; j++){
            delete[] ptr[i][j];
            ptr[i][j] = nullptr; //No need to nullpoint this because, we would delete the pointer to ptr[i][j] and array
        }
        delete[] ptr[i];
        ptr[i] = nullptr; //No need to nullpoint this because, we would delete the pointer to ptr[i] and array
    }

    delete[] ptr;
    ptr = nullptr;



    //Prints the arrays
    for(int i = 0; i < pages; i++){
        cout << "Page " << i+1 << ": " << endl;
        cout << "=========================================================================================" << endl;
        for(int j = 0; j < rowsPerPage; j++){
            for(int k = 0; k < colsPerRow; k++){
                cout << ptr[i][j][k] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }

    */

    cout << sizeof(long) << endl;

    return 0;
}