#include <iostream>

using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H


class Complex {
/*
Complex numbers are of the form a + bi where
a = real number
b = real number
i = square root of (-1)

These numbers may be produced when one tries to find the
square root of a negative number.
*/


private: 
  double a;
  double b;

public:
  Complex() {
      a = 0;
      b = 0;
  }

  Complex(double _a, double _b) {
    a = _a;
    b = _b;
  }

  double getA() const {
    return a;
  }

  double getB() const {
    return b;
  }

  Complex& operator+(const Complex& secondComplex) const {
    // returns the sum of this complex number and 
    // secondComplex number as a new complex number.
    // if complex number x and y are a + bi and c + di
    // respectively then their sum is (a+c) + (b+d)i

    Complex* temp = new Complex();

    temp->a = this->a + secondComplex.a;
    temp->b = this->b + secondComplex.b;

    return *temp;

  }

  Complex& operator-(const Complex& secondComplex) {
    // returns the difference between this complex number and 
    // secondComplex number as a new complex number.
    // if complex number x and y are a + bi and c + di
    // respectively then x-y  is (a-c) + (b-d)i

    Complex* temp = new Complex();

    temp->a = this->a - secondComplex.a;
    temp->b = this->b - secondComplex.b;

    return *temp;
  }

  Complex& operator++() {
    // increments this complex number's a component by 1
    // but leaves the b component unchanged.
    // this is post increment so beware of what you return!
    
    Complex* temp = new Complex();
    this->a += 1;
  
    return this;

  }

  // replace the ??? parts below with appropriate types
  // overloading the << operator as a friend
  friend ostream& operator<<(ostream& out, const Complex& right);
  // overloading the >> operator as a friend
  friend istream& operator>>(istream& in, Complex& right);
};

ostream& operator<<(ostream& out, const Complex& right){
    // output the complex number in the format a + bi
    out << right.getA() << " + " << right.getB() << "i";
    
    return out;
}

istream& operator>>(istream& in, Complex& right){
    // ask user to input real and imaginary parts (a and b)
    // of a complex number and set those values to right (second parameter)

    cout << "Please enter: " << endl;
    cout << "Real part: ";
    in >> right.a;
    cout << "Imaginary part: ";
    in >> right.b;

    return in;
}


#endif