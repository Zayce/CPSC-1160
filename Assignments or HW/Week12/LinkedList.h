/**
 * @file LinkedList.h
 * @author Zulhelmi (Zoella) Mohamad, CPSC 1160 Section 3 Class
 * @studentID: 100366601
 * @version 0.2
 * @date 2021-11-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Node.h"
#include <iostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList(){
        // empty list
        head = nullptr;
        tail = nullptr;
    }

    LinkedList(int n){
        head = tail = nullptr;
        for(int i = 0; i < n; i++){
            AddNodeLast(i + 1);
        }
    }

    ~LinkedList(){

        Node* temp;
        Node* nextNode = nullptr;

        for(temp = head; temp != tail; temp = nextNode){
            
            if(temp != nullptr){
                nextNode = temp->next;
                delete temp;
            }
        }

        delete tail;
        head = tail = nullptr;
    }

    bool IsEmpty(){
        return ((tail == nullptr) && (head == nullptr));
    }

    int Size() const{
        int count = 0;
        Node* temp = tail;

        while(temp != nullptr){
            count++;
            temp = temp->prev;
        }

        return count;
    }

    void AddNodeFirst(int value = 0){
        // add a new node at the beginning of the list i.e. new node will become the new head
        if(IsEmpty()){
            head = new Node(value);
            tail = head;
        }
        else{
            head->prev = new Node(value);
            head->prev->next = head;
            head = head->prev;
        }
    }

    void AddNodeLast(int value = 0){
        // add a new node to the end to the end of the list
        if(IsEmpty()){
            head = new Node(value);
            tail = head;
        }else{
            Node* temp = new Node(value);

            tail->next = temp;
            temp->prev = tail;

            tail = temp;
        }    
    }

    void ShowForward(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->element << " - ";
            temp = temp->next;
        }  
    }

    void ShowReverse(){
        Node* temp = tail;

        while(temp != nullptr){
            cout << temp->element << " - ";
            temp = temp->prev;
        }  
    }

    // void AddNode(int index, int nodeValue){
    //     // add a new node at position index containing nodeValue
    //     int sz = Size();
    //     if(index == 0){
    //         AddNodeFirst(nodeValue);
    //     }
    //     else if(index == sz - 1){
    //         AddNodeLast(nodeValue);
    //     }
    //     else if(index < sz && !(index < 0)){
    //         // find the item currently at index first
    //         Node* temp = head;
    //         for(int i = 0; i < index; i++){
    //             temp = temp->next;
    //         }

    //         //cout << temp->element << endl;
    //         Node* oldPrev = temp->prev;
    //         Node* newNode = new Node(nodeValue);
    //         temp->prev->next = newNode;
    //         temp->prev = newNode;
    //         newNode->next = temp;
    //         newNode->prev = oldPrev;
    //     }
    //     else{
    //         cout << "Index out of bounds" << endl;
    //     }
    // }

    void RemoveFirst(){
        if(IsEmpty()){
            cout << "Nothing to remove in linkedlist. " << endl;
            return;
        }
        if(Size() == 1){
            if(tail != nullptr){
                tail = nullptr;
            }
            if(head != nullptr){
                delete head;
                head = nullptr;
            }
            return;
        }
        else{
            head = head->next;
            head->prev->next = nullptr;
            delete head->prev;
            head->prev = nullptr;
            return;
        }
    }

    void RemoveLast(){
        if(IsEmpty()){
            cout << "Nothing to remove in linkedlist. " << endl;
            return;
        }
        if(Size() == 1){
            if(head != nullptr){
                head = nullptr;
            }
            if(tail != nullptr){
                delete tail;
                tail = nullptr;
            }
            return;
        }
        else{
            tail = tail->prev;
            tail->next->prev = nullptr;
            delete (tail->next);
            tail->next = nullptr;
            return;
        }
    }

    // int Remove(int index){
    //     // // remove node at given index and return the value removed
    // }

    // void Swap(int index1, int index2){
    //     // validate indices first
    //     // swap nodes at indices index1 and index2
    //     // Rewire connections (prev and next links) to swap
    //     // do NOT use a temporary variable to swap
    // }

    // void QuickSort(){

    // }

    // void MergeSort(){

    // }

    // int FirstIndexOf(int item){
    //     // returns first index of item in list

    // }

    // int LastIndexOf(int item){
    //     // returns last index of item in list
    // }
};

#endif