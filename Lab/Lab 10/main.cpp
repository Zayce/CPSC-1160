//Templates

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename someType>
someType Max(someType a, someType b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    Rectangle r1(20,10);
    Rectangle r2(6,2);

    cout << Max<Rectangle>(r1, r2) << endl;

    return 0;
}