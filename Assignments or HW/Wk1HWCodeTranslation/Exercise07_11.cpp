#include <iostream>
#include <cmath>

using namespace std;

double deviation(double*);
double deviation(int*);
double mean(double*);
double mean(int*);
void printArray(double*);

const int SIZE = 10;


int main(){
    double* number = new double[SIZE];

    cout << "Enter ten numbers: ";

    for(int i = 0; i < SIZE; i++){
        cin >> numbers[i];
    }

    cout << "The mean is " << mean(numbers) << endl;
    cout << "The standard deviation is " << deviation(numbers) << endl;

    return 0;
}

double deviation(double* x){
    double mean = mean(x);
    double squareSum = 0;

    for(int i = 0; i < SIZE; i++){
        squareSum += pow(x[i] - mean, 2);
    }

    return sqrt(squareSum / (SIZE - 1));
}

double deviation(int* x){
    
}