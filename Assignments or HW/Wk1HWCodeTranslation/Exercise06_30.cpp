#include <iostream>
#include <ctime>
#include <cstdlib>


//TODO: WHY THE FUCK DOES C++ BEHAVE DIFFERENTLY IN DIFFERENT COMPILERS
using namespace std;

int getDice();

int main(){
    srand(time(0));
    int dice = getDice();

    if (dice == 7 || dice == 11) {
      cout << " You win" << endl;
      exit(1);
    }
    else if (dice == 2 || dice == 3 || dice == 12) {
      cout << " You lose" << endl;
      exit(2);
    }
    int point = dice;
    cout << "point is " << point << endl;

    do{
      dice = getDice();
    } while ((dice != 7 ) && (dice != point));
    
    if (dice == 7){
      cout << " You lose" << endl;
    }
    else{
      cout << " You win" << endl;
    }
   }

int getDice() {
  int i1 = (1 + (rand() % 6));
  int i2 = (1 + (rand() % 6));

  cout << "You rolled " << i1 << " + " << i2 << " = " << (i1+i2) << endl;
  return (i1 + i2);
}
