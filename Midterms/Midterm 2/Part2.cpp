#include <iostream>

using namespace std;

bool isNum(char c);
bool IsPositiveFloat(string text);


/**
 * @brief Floating point numbers are numbers with a dot in them that may
 * be preceeded and/or followed by 0 or more digits. Here are examples of
 * positive floating point values
 * 11.23
 * 0.78
 * .78
 * 5. 
 * 
 * In this problem we are interested in knowing whether or not the string text
 * contains a positive floating point value inside it (we do not expect
 * the + sign to be ever used).
 * The string text will have no leading or trailing spaces however it may
 * contain any other letters and/or symbols.
 * 
 * RESTRICTIONS:
 * There can be NO LOOPS in your work. Hence, only recursion whenever necessary
 * The only string class methods you are allowed to use are substr and length
 * You may NOT use any other C++ built-in functions and/or classes.
 * You are welcome (encouraged) to add extra functions - no loops though
 * 
 * @param text, type string, contains characters but no leading or trailing spaces
 * @return true when text contains a floatingb point number; false otherwise
 */
bool IsPositiveFloat(string text){

    int len = text.size();

    if(len == 1){
        return false;
    }
    else if((text.at(0) == '.' && isNum(text.at(1))) || (isNum(text.at(0)) && text.at(1) == '.') ){
        return true;
    }
    else{
        return IsPositiveFloat(text.substr(1, len - 1));
    }
    return false;
}

bool isNum(char c){
    if (('0' <= c) && (c <= '9')){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    // test your function 
    string s1, s2, s3, s4, s5, s6;

    s1 = "dad11.23adad";
    s2 = "dad0.78adad";
    s3 = "dad.78adad";
    s4 = "da5.adad";

    s5 = "adaidnadan";
    s6 = "dmkamdoaodmaoimioke";

    cout << "Should output 1 below" << endl;
    cout << IsPositiveFloat(s1) << endl;
    cout << IsPositiveFloat(s2) << endl;
    cout << IsPositiveFloat(s3) << endl;
    cout << IsPositiveFloat(s4) << endl;

    cout << "Should output 0 below" << endl;
    cout << IsPositiveFloat(s5) << endl;
    cout << IsPositiveFloat(s6) << endl;

    return 0;
}