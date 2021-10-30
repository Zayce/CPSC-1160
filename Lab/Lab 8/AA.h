#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#ifndef AA_h
#define AA_h

class AmazingArray{
    public:
        int* values;
        int length;

        AmazingArray(){
            values = nullptr;
            length = 0;
        }

        AmazingArray(int* arr, int len){
            values = new int[len];

            for(int i = 0; i < len; i++){
                values[i] = arr[i];
            }

            length = len;
        }

        ~AmazingArray(){
            if(values != nullptr){
                delete[] values;
                values = nullptr;
                length = 0;
            }
        }

        void Show(){
            cout << "{";
            for(int i = 0; i < length - 1; i++){
                cout << values[i] << ",";
            }
            cout << values[length - 1] << "}";
        }

        void Append(int val){
            //Appends (adds to the end of the item)
            int* newArr = new int[length+1];

            for(int i = 0; i < length; i++){
                newArr[i] = values[i];
            }

            if(values != nullptr){
                delete[] values;
                values = nullptr;
            }

            newArr[length] = val;

            values = newArr;
            length++;
        }

        int RemoveEnd(){
            int* newArr = new int[length-1];

            for(int i = 0; i < length - 1; i++){
                newArr[i] = values[i];
            }

            int deletedInt = values[length];

            if(values != nullptr){
                delete[] values;
            }

            values = newArr;
            length--;

            return deletedInt;
        }

        void Add(int item, int index){            
            if(index < 0 || index > length - 1){
                cout << "Invalid index." << endl;
                return;
            }
            
            int* newArr = new int[length + 1];

            for(int i = 0; i < index; i++){
                newArr[i] = values[i];
            }

            newArr[index] = item;

            for(int i = index + 1; i < length + 1; i++){
                newArr[i] = values[i];
            }

            if(values != nullptr){
                delete[] values;
            }

            length++;
            values = newArr;
        }
};

#endif