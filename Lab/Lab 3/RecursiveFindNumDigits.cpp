/**
 *  @author Zulhelmi (Zoella) Zayce
 *  
 * 
 **/

#include <iostream>
#include <string>

using namespace std;

int recursiveStrLen(string);
int recursiveStrLen(string, int, int);

int main(){
    string findNumDigit;
    cout << "Please enter a string: " ;
    getline(cin, findNumDigit, '\n');
    cout << "Number of digits in " << findNumDigit << " is: " << recursiveStrLen(findNumDigit) << endl;
}
/**
 * 
 * 
 */
int recursiveStrLen(string s){
    return recursiveStrLen(s, s.length() - 1, 0);
}

/**
 * @param s = string to be find the number of digits
 *        f = first index of a string that is being checked
 *        l = last index of a string that is being checked
 */

//Helped with Rastko's earlier function
int recursiveStrLen(string s, int l, int digitSum){
    if(l < 0){
        return digitSum;
    }
    else{
        if(s[l] >= '0' && s[l] <= '9'){
            return (recursiveStrLen(s, l - 1, digitSum + 1));
        }
        else{
            return recursiveStrLen(s, l - 1, digitSum);
        }
    }
}