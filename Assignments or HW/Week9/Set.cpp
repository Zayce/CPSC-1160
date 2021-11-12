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
    }
    
    Set(int array[], int size){
        values = vector<int>();

        if(size < 0 || array == nullptr){
            cout << "Array is null or size of array is zero" << endl;
            exit(-1);
        }
        else{
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(values[i] == values[j]){
                        continue;
                    }
                }
                values.push_back(values[i]);
            }
        }
    }

    Set(const Set& set){
        for(int i = 0; i < (int) (set.values.size()); i++){
            values[i] = set.values[i];
        }
    }

    ostream& operator<<(ostream& out, const Set& set){
        Set temp = set;
        int randomIndex;
        out << "{";
        while(temp.values.size() > 1){
            randomIndex = rand() % (temp.values.size() - 1);
            out << temp.values[randomIndex] << ", ";
            temp.values.erase(temp.values.begin() + randomIndex);
        }
        out << temp.values.at(temp.values.begin()) << ", ";
        temp.values.pop_back();
        out << "}" << endl;

        return out;
    }

    const Set& operator>>(const Set& set){
        
    }

    const Set& operator+(const Set& set){

    }

    const Set& operator-(const Set& set){
        
    }

    const Set& operator*(const Set& set){
        
    }

    const Set& operator/(const Set& set){
        
    }

    Set GenerateRandom(const int n, int min, int max){
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] =  (min + (rand() % (max - min + 1)));
        }
        Set s = Set(arr,n);
        delete[] arr;
        arr = nullptr;
        return s;
    }


    bool ItemInSet(int item){
        for(int i; values.size(); i++){
           if(item == values[i]){
               return true;
           } 
        }
        return false;
    }
};



