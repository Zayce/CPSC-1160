
#include <iostream>
#include <string>
#include "Final.h"
using namespace std;

int main(){

   // DO NOT MAKE ANY CHANGES TO THIS MAIN FUNCTION

   // TEST CASES - expected outputs in comments next to the cout statements for each test below. As well the whole program's output is at the end altogether inside a block comment.
   
   // Each scope below represents a different test. Your code's output has to match mine (shown to the right of cout statements inside each scope/test below).
   
   cout << "test: no-arg constructor\n";
   {
      Final f = Final(); 
      cout << f.length() << endl; // 0
      cout << f << endl; // [ ]
   }

   cout << "test: insert different chars, one occurrence\n";
   {
      Final f;
      f.insert('m');
      cout << f << endl; // [ m:1 ]
   }

   {
      Final f;
      f.insert('m');
      f.insert('a');
      
      cout << f << endl; // [ a:1 m:1 ]
   }
   
   {
      Final f;
      f.insert('m');
      f.insert('a');
      f.insert('z');
      
      cout << f << endl; // [ a:1 m:1 z:1 ]
   }

   cout << "test: insert same char more than once\n";
   {
      Final f;
      f.insert('m');
      f.insert('m');      
      cout << f << endl; // [ m:2 ]

      f.insert('m'); 
      cout << f << endl; // [ m:3 ]

      f.insert('m');
      cout << f << endl; // [ m:4 ]
   }

   cout << "test: insert same char more than once, measure length\n";
   {
      Final f;
      f.insert('m');
      cout << f.length() << endl; // 1
      f.insert('m');
      cout << f.length() << endl; // 1
      f.insert('m');
      cout << f.length() << endl; // 1
   }

   cout << "test: insert different chars, different occurrences\n";
   {
      Final f;
      f.insert('m');
      f.insert('a');
      f.insert('x');
      
      cout << f << endl; // [ a:1 m:1 x:1 ]
      
      f.insert('m');
      cout << f << endl; // [ a:1 m:2 x:1 ]
   }
   {
      Final f;
      f.insert('a');
      f.insert('b');
      f.insert('c');
      f.insert('d');
      
      cout << f << endl; // [ a:1 b:1 c:1 d:1 ]
     
      f.insert('d');
      cout << f << endl; // [ a:1 b:1 c:1 d:2 ]
   }

   {
      Final f;
      f.insert('a');
      f.insert('b');
      f.insert('c');
      f.insert('d');
      
      cout << f << endl; // [ a:1 b:1 c:1 d:1 ]
      
      f.insert('a');
      cout << f << endl; // [ a:2 b:1 c:1 d:1 ]
   }

   cout << "test: double equals operator with various content\n";
   {
      Final x;
      cout << x << endl; // [ ]
      Final y;
      cout << y << endl; // [ ]
      cout <<  (x == y) << endl ; // 1
   }
   
   {
      Final x;
      x.insert('A');
      x.insert('B');
      x.insert('C');
      x.insert('D');
      x.insert('A');
      x.insert('B');
      x.insert('C');
      x.insert('A');
      x.insert('B');
      x.insert('C');
      cout << x << endl; // [ A:3 B:3 C:3 D:1 ]
      Final y;
      y.insert('A');
      y.insert('A');
      y.insert('A');
      y.insert('B');
      y.insert('B');
      y.insert('B');
      y.insert('C');
      y.insert('C');
      y.insert('C');
      y.insert('D');
      cout << y << endl; // [ A:3 B:3 C:3 D:1 ]
      cout << (x == y ) << endl; // 1
   }

   {
      Final x;
      x.insert('W');
      x.insert('C');
      x.insert('N');
      x.insert('W');
      cout << x << endl; // [ C:1 N:1 W:2 ]
      Final y;
      y.insert('N');
      y.insert('C');
      y.insert('W');
      cout << y << endl; // [ C:1 N:1 W:1 ]
      cout << ( x == y ) << endl; // 0
   }
   {
      Final x;
      x.insert('A');
      x.insert('B');
      x.insert('C');
      cout << x << endl; // [ A:1 B:1 C:1 ]
      Final y;
      y.insert('N');
      y.insert('C');
      y.insert('W');
      cout << y << endl; // [ C:1 N:1 W:1 ]
      cout << ( x == y ) << endl; // 0
   }

   cout << "test: double equals operator with differently lengthed lists\n";
   {
      Final x;
      x.insert('A');
      x.insert('B');
      cout << x << endl; // [ A:1 B:1 ]
      Final y;
      y.insert('N');
      y.insert('C');
      y.insert('W');
      cout << y << endl; // [ C:1 N:1 W:1 ]
      cout << ( x == y ) << endl; // 0
   }
   {
      Final x;
      x.insert('A');
      x.insert('B');
      x.insert('C');
      cout << x << endl; // [ A:1 B:1 C:1 ]
      Final y;
      y.insert('A');
      y.insert('B');
      y.insert('C');
      y.insert('D');
      cout << y << endl; // [ A:1 B:1 C:1 ]
      cout << ( x == y ) << endl; // 0
   }

   cout << "test: copy constructor\n";
   {
      Final x; 
      x.insert('A');
      x.insert('B');
      x.insert('C');
      cout << x << endl; // [ A:1 B:1 C:1 ]
      Final xCopy(x);
      cout << xCopy << endl; // [ A:1 B:1 C:1 ]
      xCopy.insert('D');
      cout << xCopy << endl; // [ A:1 B:1 C:1 D:1 ]
      cout << x << endl; // [ A:1 B:1 C:1 ]
      cout << ( x == xCopy ) << endl; // 0
   }

   cout << "test: assignment operator (single equal to operator)\n";
   {
      Final x; 
      x.insert('P');
      x.insert('Q');
      x.insert('R');
      cout << x << endl; // [ P:1 Q:1 R:1 ]
      Final xCopy = x;
      cout << xCopy << endl; // [ P:1 Q:1 R:1 ]
      xCopy.insert('S');
      cout << xCopy << endl; // [ P:1 Q:1 R:1 S:1 ]
      cout << x << endl; // [ P:1 Q:1 R:1 ]
      cout << ( x == xCopy ) << endl; // 0
   }

   return 0;
}

/*
the whole program's output below:

test: no-arg constructor
0
[ ]
test: insert different chars, one occurrence
[ m:1 ]
[ a:1 m:1 ]
[ a:1 m:1 z:1 ]
test: insert same char more than once
[ m:2 ]
[ m:3 ]
[ m:4 ]
test: insert same char more than once, measure length
1
1
1
test: insert different chars, different occurrences
[ a:1 m:1 x:1 ]
[ a:1 m:2 x:1 ]
[ a:1 b:1 c:1 d:1 ]
[ a:1 b:1 c:1 d:2 ]
[ a:1 b:1 c:1 d:1 ]
[ a:2 b:1 c:1 d:1 ]
test: double equals operator with various content
[ ]
[ ]
1
[ A:3 B:3 C:3 D:1 ]
[ A:3 B:3 C:3 D:1 ]
1
[ C:1 N:1 W:2 ]
[ C:1 N:1 W:1 ]
0
[ A:1 B:1 C:1 ]
[ C:1 N:1 W:1 ]
0
test: double equals operator with differently lengthed lists      
[ A:1 B:1 ]
[ C:1 N:1 W:1 ]
0
[ A:1 B:1 C:1 ]
[ A:1 B:1 C:1 D:1 ]
0
test: copy constructor
[ A:1 B:1 C:1 ]
[ A:1 B:1 C:1 ]
[ A:1 B:1 C:1 D:1 ]
[ A:1 B:1 C:1 ]
0
test: assignment operator (single equal to operator)
[ P:1 Q:1 R:1 ]
[ P:1 Q:1 R:1 ]
[ P:1 Q:1 R:1 S:1 ]
[ P:1 Q:1 R:1 ]
0
*/