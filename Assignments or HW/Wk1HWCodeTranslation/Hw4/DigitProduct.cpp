/**
 *  @author Zoella (Zulhelmi) Mohamad
 **/

#include <iostream>

using namespace std;

int digitProduct(int value);

/**
 *  Main function to test the digitProduct recursive function. 
 *  Asks for input for value and will output the digitProduct to the terminal.
 */
int main(){
    int value;

    cout << "Please enter an integer:"
    cin >> value;

    cout << digitProduct(value) << endl;
    return 0;
}

/**
 * Finds the product of all digits in a number through recursion.
 * 
 * @param   value: The number value that we want to find the product of all digits of.
 * 
 * @return  Returns the product of all digits in value.
 */
int digitProduct(int value){
    if((value/10) == 0){
        return value;
    }
    else{
        return ((value%10) * digitProduct(value/10));
    }
}