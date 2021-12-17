#ifndef FINAL_H 
#define FINAL_H

#include <iostream>

using namespace std;

struct Cell{
public:
   char ch;
   int count;
};

struct Node{
public:
   Cell* data;
   Node* next;
};

class Final {
   private:
      Node* head;

      Node* copyList(Node* p){
         
      }

      Node* deleteList(Node *p){
         
      }

   public:


      Final(){
         head = nullptr;
      }

      Final(const Final& other){
         char newChar;
         int newCount;
         Node temp = other.head;
         while(other.head != nullptr){
            newChar = temp.data->ch;            

         }
      }

      ~Final(){
         
      }

      int length() const{
         int len = 0;
         Node* temp = head;

         while(head != nullptr){
            len++;
            temp = temp->next;
         }
         return len;
      }

      void insert(char c){ 
         Node temp = head;

         while(head != nullptr){
            if(c == temp.data->ch){
               temp.data->count += 1;
               break;
            }
            else{
               temp = temp->next;
            }
         }



         Cell* dt = new Cell();
         data->ch = c;
         data->count = 1;

         Node* nd = new Node();
         nd->data = dt;
         nd->next = nullptr;
         temp->next = nd;
      }

      bool operator==(const Final& b){
         // this method is partially complete

         Node* p = this->head;
         Node* q = b.head;


         

      }
   
      Final& operator=(const Final& other){
         // this method is partially complete

         if (this != &other) {
            
         }
         return *this;

      }

      friend std::ostream& operator<<(std::ostream&, const Final& f);
};

ostream& operator<<(std::ostream& out, const Final& f) {

   // this function is partially complete, you only have to add some lines below to fix/complete it.

   char chr; // use this variable BELOW to hold the ch value from inside of a Cell (which is inside of a Node in the linked list f)
   int cnt;  // use this variable BELOW to hold the count value from inside of a Cell (which is inside of a Node in the linked list f)
   
   out << '[' << ' ';

   // loop through the linked list f - add missing lines of code below for the loop
   
      chr = f.head->data->ch; // replace the ??? with appropriate member from object f
      out << chr;
      out << ":";
      cnt = f.head->data->count // replace the ??? with appropriate member from object f
      out << cnt;
      out << ' ';
      
   
   out << ']';
   
   return out;
}

#endif 
