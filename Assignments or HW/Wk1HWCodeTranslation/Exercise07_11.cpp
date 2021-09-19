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
    double* numbers = new double[SIZE];

    cout << "Enter ten numbers: ";

    for(int i = 0; i < SIZE; i++){
        cin >> numbers[i];
    }

    // Display mean and deviation
    cout << "The mean is " << mean(numbers) << endl;
    cout << "The standard deviation is " << deviation(numbers) << endl;

    return 0;
}

/** Method for computing deviation of double values*/
double deviation(double* x){
    double meanVal = mean(x);
    double squareSum = 0;

    for(int i = 0; i < SIZE; i++){
        squareSum += pow(x[i] - meanVal, 2);
    }

    return sqrt(squareSum / (SIZE - 1));
}
  
/** Method for computing deviation of int values*/
double deviation(int* x){
    double meanVal = mean(x);
    double squareSum = 0;

    for (int i = 0; i < SIZE; i++) {
        squareSum +=  pow(x[i] - meanVal, 2);
    }

    return sqrt(squareSum / (SIZE - 1));
}

/** Method for computing mean of an array of double values*/
double mean(double* x) {
    double sum = 0;

    for (int i = 0; i < SIZE; i++){
        sum += x[i];
    }

    return (sum / SIZE);
}

/** Method for computing mean of an array of int values*/
double mean(int* x) {
    int sum = 0;

    for (int i = 0; i < SIZE; i++){
        sum += x[i];
    }

    return (sum / SIZE);
}

/** Method for printing array */
void printArray(double* x) {
    for (int i = 0; i < SIZE; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}