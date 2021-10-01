/**
 *  @author Zulhelmi (Zoella) Zayce
 *  
 * 
 **/

#include <iostream>
#include <string>

//TODO: Do tail end recursive reverse string and recursive palindrome after homework.

void recusiveReverseStr(char*);
void recusiveReverseStr(char*, int&, int&);

using namespace std;

int main(){
    string str; 
    cout << "Please enter a string: " ;
    getline(cin, str, '\n');
    char *cstr = &str[0];

    cout << "Reversing: " << str << " => " << recusiveReverseStr(str) << endl;
}

void recusiveReverseStr(char* str){
    recusiveReverseStr(str, 0, str.length() - 1);
}

void recusiveReverseStr(char* str, int& f, int& l){
    if(f < l){
        str
    }
}

