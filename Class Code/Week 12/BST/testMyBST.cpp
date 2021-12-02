#include <iostream>
#include "MyBST.h"

using namespace std;

int main(){

    BST tree;

    tree.AddNode(100);
    tree.AddNode(50);
    tree.AddNode(75);
    tree.AddNode(25);

    // cout << tree.root->element << endl;

    // cout << tree.root->right << endl;

    // cout << tree.root->left->left->element << endl;

    cout << tree.Search(25)->element << endl;
    return 0;
}