#ifndef NODE_H
#define NODE_H

class Node{
public:
    int element;
    Node* left;
    Node* right;

    Node(){
        element = 0;
        left = right  = nullptr;
    }

    Node(int i){
        element = i;
        left = right = nullptr;
    }

};

#endif