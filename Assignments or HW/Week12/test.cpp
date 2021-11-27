/**
 * @file test.cpp
 * @author Zulhelmi (Zoella) Mohamad
 * @studentID: 100366601
 * @version 0.1
 * @date 2021-11-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Stack.h"
#include "Queue.h"
#include <iostream>

using namespace std;

int main(){
    string isEmpty = "Displays 1 if Empty, 0 if not empty: ";

    //STACK TESTING
    Stack stk;
    cout << "=========\nStack Test" << endl;
    cout << isEmpty <<  stk.IsEmpty() << endl;
    cout << endl;

    for (int i = 1; i < 1000; i *= 2){
        cout << "Adding " << i << " to stack " << endl;
        stk.Push(i);
        stk.Display();
        cout << endl;
    }

    cout << isEmpty <<  stk.IsEmpty() << endl << endl;
    
    cout << "The top most part of this stack is: " << stk.GetTop() << endl;
    stk.Pop();
    cout << "The top most part now is of this stack after removing the top is: " << stk.GetTop() << endl;
    stk.Display();
    cout << endl << "-----------" << endl;

    while(!stk.IsEmpty()){
        cout << "Popped: " << stk.Pop() << " : from the stack." << endl;
        stk.Display();
        cout << endl;
    }

    cout << stk.Pop() << endl << endl;

    cout << isEmpty <<  stk.IsEmpty() << endl;
    stk.Display();
    cout << endl;

    //QUEUE TESTING
    Queue que;
    cout << "==================\n\nQueue Test" << endl;
    cout << isEmpty <<  que.IsEmpty() << endl;
    cout << endl;
    for (int i = 1; i < 1000; i *= 2){
        cout << "Adding " << i << " to queue " << endl;
        que.Enqueue(i);
        que.Display();
        cout << endl;
    }
    cout << isEmpty <<  que.IsEmpty() << endl;
    cout << endl << "-----------" << endl;

    while(!que.IsEmpty()){
        cout << "Dequeued: " << que.Dequeue() << " : from the queue." << endl;
        que.Display();
        cout << endl;
    }

    cout << que.Dequeue() << endl;
    cout << isEmpty <<  que.IsEmpty() << endl << endl;
    que.Display();
    
    return 0;
}
