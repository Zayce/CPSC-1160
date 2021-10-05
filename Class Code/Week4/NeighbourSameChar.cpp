#include <iostream>

using namespace std;

int countNumNeighbours(string text);
int recCountNumNeighbours(string text, int len);

int main(){
    string text = "abccbaa";
    cout << countNumNeighbours(text) << endl;
    cout << recCountNumNeighbours(text, text.length()) << endl;

}

int countNumNeighbours(string text){
    int numOfTimes = 0;
    for(int i = 0, j = i + 1; i < (int)(text.length()) - 1; i++){
        if(text[i] == text[j]){
            numOfTimes++;
        }
    }
    return numOfTimes;
}

int recCountNumNeighbours(string text, int len){
    if(len == 0 || len == 1){
        return 0;
    }
    else if(text[len - 1] == text[len-2]){
        return 1 + recCountNumNeighbours(text, len - 1);
    }
    else{
        return recCountNumNeighbours(text, len - 1);
    }
}