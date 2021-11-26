#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(){
    LinkedList list(5);

    list.ShowForward();
    list.ShowReverse();

    list.AddNode(2, 100);

    // list.AddNodeFirst(100);
    // list.AddNodeFirst(200);

    list.ShowForward();
    list.ShowReverse();
    
    return 0;
}