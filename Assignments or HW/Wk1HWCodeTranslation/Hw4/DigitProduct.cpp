/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int digitProduct(int value);

int main(){
    int value;

    cout << "Please enter an integer:"
    cin >> value;

    cout << digitProduct(value) << endl;
    return 0;
}

int digitProduct(int value){
    if((value/10) == 0){
        return value;
    }
    else{
        return ((value%10) * digitProduct(value/10));
    }
}