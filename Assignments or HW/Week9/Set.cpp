#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Set.h"

using namespace std;

int main(){
    srand(time(0));
    return 0;
}

class Set{
private:
    vector<int> values;

public:
    Set(){
        this->values = vector<int>();
    }
    
    Set(vector<int> val){
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

    Set(const Set& set){
        for(int i = 0; i < (int) (set.values.size()); i++){
            values.at(i) = set.values.at(i);
        }
    }

    Set::ostream& operator<<(ostream& out , const Set& set){
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

    // friend istream& operator>>(istream& in, ){
        
    // }

    // const Set& operator+(const Set& set){

    // }

    // const Set& operator-(const Set& set){
        
    // }

    // const Set& operator*(const Set& set){
        
    // }

    // const Set& operator/(const Set& set){
        
    // }




    bool ItemInSet(int item){
        for(int i; values.size(); i++){
           if(item == values[i]){
               return true;
           } 
        }
        return false;
    }
};

Set GenerateRandom(const int n, int min, int max){
    vector<int> temp = vector<int>(n);
    for(int i = 0; i < n; i++){
        temp.push_back((min + (rand() % (max - min + 1))));
    }
    return Set(temp);
}


