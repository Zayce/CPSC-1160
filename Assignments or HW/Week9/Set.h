#ifndef SET_H
#define SET_H



class Set{
private:
    vector<int> values;

public:
    Set();
    Set(vector<int> val);
    Set(const Set& set);

    ostream& operator<<(ostream& out , const Set& set);
    // friend istream& operator>>(istream& in, )
    // Set& operator+(const Set& set)
    // const Set& operator-(const Set& set)
    // const Set& operator*(const Set& set)
    // const Set& operator/(const Set& set)

    bool ItemInSet(int item);
};

friend ostream& operator<<(ostream& out, const Set& set);
friend istream& operator>>(istream& in, Set& set);

Set GenerateRandom(const int n, int min, int max);




#endif