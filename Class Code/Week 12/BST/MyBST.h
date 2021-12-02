#include "Node.h"
#include <iostream>

using namespace std;

#ifndef MYBST_H
#define MYBST_H

class BST{
    public:
    Node* root;

    public:

    BST(){
        root = nullptr;
    }

    void AddNode(int item){
        // add a new node to the BST
        // at the "correct spot" with value item
        if(root == nullptr){
            root = new Node(item);
        }
        else{
            // non-root nodes
            Node* temp = root;
            Node* parent = nullptr;
            // first find a suitable spot for item, track the spot's parent
            while(temp != nullptr){
                if(item < temp->element){
                    parent = temp;
                    temp = temp->left;
                }
                else if(item > temp->element){
                    parent = temp;
                    temp = temp->right;
                }
                else{
                    cout << "no duplicates allowed." << endl;
                    return;
                }
            }

            // add the item in the correct spot, either as a left child or a right
            if(item < parent->element){

                parent->left = new Node(item);

            }
            else{
                parent->right = new Node(item);
            }
            return;
        }
    }

    Node* Search(int item){
        Node* current = root;
        while(current != nullptr){
            if(item < current->element){
                current = current->left;
            }
            else if(item > current->element){
                current = current->left;
            }
            else{
                return current;
            }
        }
        return nullptr;
    }

    bool Delete(int item){
            Node* temp = root;
            Node* parent = nullptr;
            // first find a suitable spot for item, track the spot's parent
            while(temp != nullptr){
                if(item < temp->element){
                    parent = temp;
                    temp = temp->left;
                }
                else if(item > temp->element){
                    parent = temp;
                    temp = temp->right;
                }
                else{
                    cout << "Node found to delete" << endl;

                    if(temp->left == nullptr && temp->right == nullptr){
                        cout << "Case 0: This node has no children." << endl;
                        
                        if(parent->left == temp){
                            parent->left = nullptr;
                        }
                        else{
                            parent->right = nullptr;
                        }
                        delete temp;
                    }
                    
                    else if(temp->left == nullptr && temp->right != nullptr){
                        cout << "Case 1: This node has no left child but has a right child" << endl;

                        if(parent->left == temp){
                            parent->left = temp->right;
                        }
                        else{
                            parent->right = temp->right;
                        }
                        delete temp;
                    }

                    else if(temp-left != nullptr){
                        cout << 
                    }






                    return true;
                }
            }
            cout << item << " is not in the Binary Search Tree" << endl;
            return false;
    }

};

#endif