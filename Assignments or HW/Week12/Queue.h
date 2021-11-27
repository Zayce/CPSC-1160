/**
 * @file Queue.h
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

#ifndef QUEUE_H
#define QUEUE_H

class Queue{
    private:
        LinkedList items;
    public:
        Queue(){
            items = LinkedList(); //Front is head, Rear is tail
        }

        int Dequeue(){
            if (IsEmpty()){
                cout << "Queue is empty, the -1 value is not a value in the queue" << endl;
                return -1;
            }
            int dequeued = items.head->element;
            items.RemoveFirst();
            return dequeued;
        }

        void Enqueue(int val){
            items.AddNodeLast(val);
        }

        bool IsEmpty(){
            return items.IsEmpty();
        }

        void Display(){
            if(IsEmpty()){
                cout << "Queue is empty." << endl;
            }
            else{
                cout << "Front-> - ";
                items.ShowForward();
                cout << "<-Rear" << endl;
            }
        }
};

#endif