#include <iostream>

using namespace std;

int main(){
    double product = 1.0;

    //outputs 1.2599e-51%                                                                                                                                                                     
    for(double i = 5; i <= 123; i += 4){
        product *= ((1.0)/i);
    }

    /* outputs 1.2599e-51%                                                                                                                                                                       
    for(double i = 5; i <= 123; i += 4){
        product *= (i);
    }
    product = 1.0/product;
    */
                                                                                                                                                                      
    cout << product;
    return 0;
}