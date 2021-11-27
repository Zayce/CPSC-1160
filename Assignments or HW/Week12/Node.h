/**
 * @file Node.h
 * @author Zulhelmi (Zoella) Mohamad, CPSC 1160 Section 3 Class
 * @studentID: 100366601
 * @version 0.1
 * @date 2021-11-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int element;
    Node* next;
    Node* prev;

    Node(){
      element = 0;
      next = nullptr;
      prev = nullptr;
    }

    Node(int e){
      element = e;
      next = nullptr;
      prev = nullptr;
    }
};

#endif

