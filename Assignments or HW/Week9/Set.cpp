#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Set;

int main(){
    srand(time(0));
    return 0;
}

class Set{
private:
    vector<int> values;

public:
    Set(){
        values = vector<int>();
    }
    
    Set(vector<int> val){
        values = val;

        if(val == nullptr || val.empty() ){
            cout << "Array is null or size of array is zero" << endl;
            exit(-1);
        }
        else{
            for(int i = 0; i < val.size() - 1; i++){
                for(int j = i + 1; j < val.size(); j++){
                    if(values.at(i) == values.at(j){
                        values.erase(j);
                    }
                }
                values.push_back(values.at(i));
            }
        }
    }

    Set(const Set& set){
        for(int i = 0; i < (int) (set.values.size()); i++){
            values.at(i) = set.values.at(i);
        }
    }

    ostream& operator<<(ostream& out, const Set& set){
        vector<int>* temp = set.values;
        int randomIndex;
        out << "{";
        while(temp.values.size() > 1){
            randomIndex = rand() % (temp.values.size() - 1);
            out << temp.values.at(randomIndex) << ", ";
            temp.values.erase(temp.values.begin() + randomIndex);
        }
        out << temp.values.at(temp.values.begin()) << ", ";
        temp.values.pop_back();
        out << "}" << endl;

        if(temp != nullptr){
            delete[] temp;
            temp = nullptr;
        }

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
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] =  (min + (rand() % (max - min + 1)));
    }

    if(arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }
    return Set(arr,n);
}



