#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>

using namespace std;
class Set{
private:
    vector<int> values;
    bool ItemInSet(int item);

public:
    Set();
    Set(vector<int> val);
    Set(const Set& set);

    friend ostream& operator<<(ostream& out, const Set& set);
    friend istream& operator>>(istream& in, Set& set);

    void GenerateRandom(const int n, int min, int max);

};






#endif