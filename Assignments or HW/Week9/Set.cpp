#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Set.h"

using namespace std;

bool Set::ItemInSet(int item){
    for(int i = 0; values.size(); i++){
        if(item == values[i]){
            return true;
        } 
    }
    return false;
}

Set::Set(){
    this->values = vector<int>();
}

Set::Set(vector<int> val){
    this->values = val;

    if(val.empty() ){
        cout << "Array is null or size of array is zero" << endl;
        exit(-1);
    }
    else{
        for(int i = 0; i < val.size() - 1; i++){
            for(int j = i + 1; j < val.size(); j++){
                if(this->values.at(i) == this->values.at(j)){
                    this->values.erase(values.begin() + j) ;
                }
            }
            //TODO test this out
            // values.push_back(values.at(i));
        }
    }
}

Set::Set(const Set& set){
    for(int i = 0; i < (int) (set.values.size()); i++){
        values.at(i) = set.values.at(i);
    }
}

// const Set& operator+(const Set& set){

// }

// const Set& operator-(const Set& set){
    
// }

// const Set& operator*(const Set& set){
    
// }

// const Set& operator/(const Set& set){
    
// }

void Set::GenerateRandom(const int n, int min, int max){
    int tempElement;
    for(int i = 0; i < n-1; i++){
        do{
            tempElement = (min + (rand() % (max - min + 1)));
        } while(ItemInSet(tempElement));
        Set::values.push_back(tempElement);
    }
    return;
}


ostream& operator<<(ostream& out , const Set& set){
    Set temp = Set(set);
    int randomIndex;
    out << "{";
    while(temp.values.size() > 1){
        randomIndex = rand() % (temp.values.size() - 1);
        out << temp.values.at(randomIndex) << ", ";
        temp.values.erase(temp.values.begin() + randomIndex);
    }
    out << temp.values.at(0);
    temp.values.pop_back();
    out << "}" << endl;

    return out;
}

// istream& operator>>(istream& in, ){
    
// }








