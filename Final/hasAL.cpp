#include <iostream>

using namespace std;

//-----------------------------------------------------------------
// function prototype for the required function
//-----------------------------------------------------------------
bool hasAL(const char A[], int n, char ch, int occs); 

int main(){

   // DO NOT MAKE ANY CHANGES TO THIS MAIN FUNCTION

   // TEST CASES - expected outputs in comments next to the cout statements for each test below. As well the whole program's output is at the end altogether inside a block comment.
   
   // Each scope below represents a different test. Your code's output has to match mine (shown to the right of cout statements inside each scope/test below).
   
   cout << "number of elements n = 0\n";
   {
      int n = 0;
      char A[] = {'a', 'b', 'c'};
      char ch = 'x';
      int occs = 0;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 0;
      char A[] = {'a', 'b', 'c'};
      char ch = 'x';
      int occs = 3;
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   {
      int n = 0;
      char A[] = {'a', 'b', 'c'};
      char ch = 'a';
      ch = 'a';
      int occs = 1;
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   cout << "no occurrences\n";
   {
      int n = 3;
      char A[] = {'a', 'b', 'c'};
      char ch = 'a';
      int occs = 0;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 3;
      char A[] = {'a', 'b', 'c'};
      char ch = 'x';
      int occs = 0;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }
   
   cout << "varying number of elements n with exact occurrences\n";
   {
      int n = 5;
      char A[] = {'a', 'b', 'c', 'a', 'x', 'a'};
      char ch = 'a';
      int occs = 2;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }
   
   {
      int n = 2;
      char A[] = {'a', 'a', 'c', 'x', 'a', 'a'};
      char ch = 'a';
      int occs = 2;
      cout << hasAL(A, n, ch, occs) << endl; // 1
      n = 4;
      cout << hasAL(A, n, ch, occs) << endl; // 1
      n = 6;
      char B[] = {'x', 'b', 'c', 'a', 'x', 'a'};
      cout << hasAL(B, n, ch, occs) << endl; // 1
   }
   
   cout << "varying occurrences\n";
   {
      int n = 5;
      char A[] = {'a', 'b', 'c', 'd', 'e'};
      char ch = 'a';
      int occs = 1;
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 4;  // ONLY, NOT n = 5
      char ch = 'a';
      int occs = 2;
      char A[] = {'a', 'a', 'c', 'd', 'a'};
      cout << hasAL(A, n, ch, occs) << endl; // 1
      char B[] = {'a', 'x', 'a', 'd', 'a'};
      cout << hasAL(B, n, ch, occs) << endl; // 1
      char C[] = {'a', 'x', 'a', 'd', 'a'};
      cout << hasAL(C, n, ch, occs) << endl; // 1
      char D[] = {'a', 'x', 'x', 'a', 'a'};
      cout << hasAL(D, n, ch, occs) << endl; // 1
      char E[] = {'x', 'a', 'x', 'a', 'a'};
      cout << hasAL(E, n, ch, occs) << endl; // 1
      char F[] = {'w', 'x', 'a', 'a', 'a'};
      cout << hasAL(F, n, ch, occs) << endl; // 1
   }

   {
      int n = 5;
      char ch = 'x';
      int occs = 5;
      char A[] = {'x', 'x', 'x', 'x', 'x', 'a'};
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 3;
      char ch = 'x';
      int occs = 5;
      char A[] = {'x', 'x', 'x', 'x', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   cout << "not enough occurrences\n";
   {
      int n = 5;
      char ch = 'x';
      int occs = 3;
      char A[] = {'x', 'a', 'b', 'c', 'd', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   {
      int n = 4;
      char ch = 'x';
      int occs = 3;
      char A[] = {'x', 'x', 'a', 'a', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   {
      int n = 5;
      char ch = 'x';
      int occs = 5;
      char A[] = {'x', 'x', 'a', 'a', 'x', 'x', 'x', 'x', 'x', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   cout << "at least: there are more occurrences than what we are checking\n";
   {
      int n = 6;
      char ch = 'x';
      int occs = 1;
      char A[] = {'x', 'a', 'b', 'c', 'd', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 5;
      char ch = 'x';
      int occs = 2;
      char A[] = {'x', 'x', 'a', 'a', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 10;
      char ch = 'x';
      int occs = 4;
      char A[] = {'x', 'x', 'a', 'a', 'x', 'x', 'x', 'x', 'x', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   cout << "more occurrences than number of elements n\n";
   {
      int n = 2; // not n = 6
      char ch = 'x';
      int occs = 6;
      char A[] = {'x', 'a', 'b', 'c', 'd', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   {
      int n = 5;
      char ch = 'x';
      int occs = 4;
      char A[] = {'x', 'x', 'a', 'a', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   {
      int n = 8;
      char ch = 'x';
      int occs = 9;
      char A[] = {'x', 'x', 'a', 'a', 'x', 'x', 'x', 'x', 'x', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }

   cout << "some other cases \n";
   {
      int n = 6; // not n = 7
      char ch = 'b';
      int occs = 3;
      char A[] = {'a', 'b', 'c', 'd', 'b', 'b', 'b'};
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 6; // not n = 7
      char ch = 'x';
      int occs = 1;
      char A[] = {'a', 'b', 'c', 'd', 'e', 'x', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 1
   }

   {
      int n = 8;
      char ch = 'A';
      int occs = 2;
      char A[] = {'x', 'x', 'a', 'a', 'x', 'x', 'x', 'x', 'x', 'x'};
      cout << hasAL(A, n, ch, occs) << endl; // 0
   }
}

//-----------------------------------------------------------------
// CPSC 1160 final exam: fill in the solution below
//-----------------------------------------------------------------

bool hasAL(const char A[], int n, char ch, int occs) {

   if(occs <= 0){
      return true;
   }

   if(n <= 0 && (occs > 0)){ //missing n <= 0
      return false;
   }

   if(ch == A[n-1]){
         occs--;
   }   
   return hasAL(A, n-1, ch, occs);


   // complete this function as per instructions in exam booklet
   
}


/*
Output of the whole program below:

number of elements n = 0
1
0
0
no occurrences
1
1
varying number of elements n with exact occurrences
1
1 
1
1
varying occurrences
1 
1
1
1
1
1
1
1 
0
not enough occurrences
0
0
0
at least: there are more occurrences than what we are checking
1
1
1
more occurrences than number of elements n
0
0
0
some other cases
1
1
0
*/
