#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Set{
    private:
        vector<int>* values;

        bool ItemInSet(int item){
            for(int i = 0; i < values->size(); i++){
                if(item == values->at(i)){
                    return true;
            } 
            }
            return false;
        }

    public:
        Set(){
            values = new vector<int>();
        }
        
        Set(vector<int>* val){
            this->values = val;

            if(val->empty()){
                cout << "Values are empty" << endl;
                exit(-1);
            }
            for(int i = 0; i < val->size() - 1; i++){
                for(int j = i + 1; j < val->size(); j++){
                    if(this->values->at(i) == this->values->at(j)){
                        this->values->erase(values->begin() + j);
                    }
                }
            }
            
        }

        Set(const Set &set){
            this->values = new vector<int>();

            for(int i = 0; i < set.values->size(); i++){
                values->push_back(set.values->at(i));
            }
        }

        ~Set(){
            if(values != nullptr){
                while(values->size() > 0){
                    values->pop_back();
                }
                delete values;
                values = nullptr;
            }
        }

        vector<int>* getValue(){
            return this->values;
        }

        int size(){
            return this->values->size();
        }

        bool AddElement(int elem){
            if(!(this->ItemInSet(elem))){
                this->values->push_back(elem);
                return true;
            }
            return false;
        }

        void GenerateRandom(const int n, const int min, const int max){
            int tempElement;
            for(int i = 0; i < n; i++){
                do{
                    tempElement = (min + (rand() % (max - min + 1)));
                } while(ItemInSet(tempElement));
                values->push_back(tempElement);
            }
            return;
        }

        Set& operator=(const Set& set){
            while(values->size() > 0){
                values->pop_back();
            }

            this->values = new vector<int>();

            for(int i = 0; i < set.values->size(); i++){
                values->push_back(set.values->at(i));
            }
            
            return *this;
        }

        const Set& operator+(const Set& set){

            Set* temp = new Set(*this);
            int element;

            if( this != &set){

                for(int i = 0; i < set.values->size(); i++ ){
                    element = set.values->at(i);
                    if(!ItemInSet(element)){
                        temp->values->push_back(element);
                    }
                }
            }
            return *temp;
        }

        const Set& operator-(const Set& set){
            Set* newSet = new Set();

            int i, j;
            for(i = 0; i < this->size(); i++){
                for(j = 0; j < set->size(); j++){
                    if(this->values->at(i) == set.values->at(j)){
                        break;
                    }
                }
                newSet->values->push_back(this)
            }
        }

        // const Set& operator*(const Set& set){
            
        // }

        // const Set& operator/(const Set& set){
            
        // }

        const bool operator==(const Set& set){
            for(int i = 0; i < set.values->size(); i++){
                if(!ItemInSet(set.values->at(i))){
                    return false;
                }
            }
            return true;
        }

        const bool operator!=(const Set& set){
            return !(*this == set);
        }

        friend ostream& operator<<(ostream& out , const Set& set);
        friend istream& operator>>(istream& in, Set& set);
};

ostream& operator<<(ostream& out , const Set& set){
            Set temp = Set(set);
            int randomIndex;
            out << "{";
            while(temp.values->size() > 1){
                randomIndex = rand() % (temp.values->size() - 1);
                out << temp.values->at(randomIndex) << ", ";
                temp.values->erase(temp.values->begin() + randomIndex);
            }
            out << temp.values->at(0);
            temp.values->pop_back();
            out << "}" << endl;

            return out;
}

istream& operator>>(istream& in, Set& set){
    cout << "Enter values, please enter without values to exit:  ";
    int elem;
    bool isContinue = true;

    do{
        in >> elem;
        if(!set.ItemInSet(elem)){
            cout << ",";
            set.values->push_back(elem);
        }
        else{
            isContinue = false;
            cout << "}" << endl << "Reapeated element found, ending entry." << endl;
        }
    } while(isContinue);
    return in;
}

#endif