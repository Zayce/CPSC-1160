#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
    private:
        int width;
        int length;
        int* ptr;
        int ptrSize;

        void ClearPtr(){
            if(ptr){
                delete[] ptr;
                ptr = nullptr;

                ptrSize = 0;
            }
        }
    public:
        Rectangle(){
            width = 0;
            length = 0;
            ptrSize = 10;
            ptr = new int[ptrSize];
        }
        Rectangle(int w, int l){
            if(!setWidth(w)){
                cout << "Invalid input. Initilizing to 0" << endl;
                width = 0;
            }
            if(!setLength(l)){
                cout << "Invalid input. Initilizing to 0" << endl;
                length = 0;
            }

            ptrSize = 10;
            ptr = new int[ptrSize];
        }

        Rectangle(const Rectangle& source){
            ClearPtr();

            ptrSize = source.ptrSize;
            ptr = new int[ptrSize];

            for(int i = 0; i < ptrSize; i++){
                ptr[i] = source.ptr[i];
            }

            length = source.length;
            width = source.width;      
        }

        ~Rectangle(){
            ClearPtr();
        }
        int getWidth() const {
            return width;
        }

        int getLength() const {
            return length;
        }
        
        bool setWidth(int w){
            if(w < 0)
                return false;
            else{
                width = w;
                return true;
            }
        }
        
        bool setLength(int l){
            if(l < 0)
                return false;
            else{
                length = l;
                return true;
            }
        }
        
        int getArea() const {
            int a = width * length;
            return a;
        }
        
        int getPerimeter() const {
            int p = (2*width) + (2*length); // 2*(width + height)
            return p;
        }

        void Show(){
            cout << "width: " << width << ", length: " << length << ", Area: " << getArea() << ", perimeter: " << getPerimeter() << endl;  
        }

        Rectangle operator+(const Rectangle &right) const {
            Rectangle total = Rectangle();
            total.width = this->width + right.getWidth();
            total.length = this->length + right.length;

            return total;
        }

        bool operator==(const Rectangle &right) const {
            if(this->getArea() == right.getArea()){
                return true;
            }
            else{
                return false;
            }
        }

        Rectangle operator=(const Rectangle &right){
            ClearPtr();

            ptrSize = right.ptrSize;
            ptr = new int[ptrSize];

            for(int i = 0; i < ptrSize; i++){
                ptr[i] = right.ptr[i];
            }

            length = right.length;
            width = right.width;

            return *this;
        }

        Rectangle operator++(){
            width++;
            length++;
            return *this;
        }

        Rectangle operator++(int dummy){
            Rectangle old = *this;
            width++;
            length++;
            return old;
        }

        friend ostream& operator<<(ostream& out, const Rectangle& right);

        friend istream& operator>>(istream& in, Rectangle& right);
};

ostream& operator<<(ostream& out, const Rectangle & right){
    out << "width: " << right.width << ", length: " << right.length << ", Area: " << right.getArea() << ", perimeter: " << right.getPerimeter() << endl;
    return out;
}

istream& operator>> (istream& in, Rectangle& right){
    int len;
    cout << "enter the width of the rectangle: ";
    in >> right.width;
    cout << "enter the length of the rectangle: ";
    in >> len;
    right.setLength(len);
}

#endif
