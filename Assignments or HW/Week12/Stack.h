/**
 * @file Stack.h
 * @author Zulhelmi (Zoella) Mohamad
 * @studentID: 100366601
 * @version 0.1
 * @date 2021-11-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "LinkedList.h"

using namespace std;

#ifndef STACK_H
#define STACK_H

class Stack{
    private:
        LinkedList items;
    public:
        Stack(){
            items = LinkedList(); //Top is tail, Bottom is head
        }

        int Pop(){
            if (IsEmpty()){
                cout << "Stack is empty, the -1 value is not a value in the stack" << endl;
                return -1; 
            }
            int popped = items.tail->element;
            items.RemoveLast();
            return popped;
        }

        void Push(int val){
            items.AddNodeLast(val);
        }

        int GetTop(){
            if(IsEmpty()){
                cout << "Stack is empty, there is no top item, -1 is not in the stack" << endl;
                return -1; 
            }
            return items.tail->element;
        }

        bool IsEmpty(){
            return items.IsEmpty();
        }

        void Display(){
            if(IsEmpty()){
                cout << "Stack is empty." << endl;
            }
            else{
                cout << "Top-> - ";
                items.ShowReverse();
                cout << "<-Bottom" << endl;
            }
        }
};

#endif