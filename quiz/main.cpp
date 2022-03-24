#include<iostream>
//using namespace std;
class A {
   int data_A;
   virtual char f();    // Pure Virtual Function
   char f()
        { 
         return 'A';
        }
};

class B:public A {
   int data_B;
   char f()
        { 
         return 'B';
        }
};

int main() {
   B B1;
   //cout << B1 << endl;
}