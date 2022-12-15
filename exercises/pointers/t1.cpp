// from the link "https://youtu.be/zuegQmMdy8M"
// ---------------------------------------------
// for better understanding
// open "t1.png" while reading comments/codes
// ---------------------------------------------
#include <iostream>
using namespace std;
int main() {

  //------------DEFINITIONS--------------------
  // define variable a
  int a = 10;

  // define pointer-to-int called p
  int *p;

  // store a's address in p
  p = &a;

  // define a pointer to an int-pointer
  int **q;

  // store p's address in q
  q = &p;

  //--------------END OF DEFINITIONS-------------

  // there is 10 in variable a
  cout << "a = " << a << endl;

  // shows a's address in variable p
  cout << "p = " << p << endl;

  // this shows what is in the address that is stored in p
  // which shows what is stored in a's address
  // or what is in a
  cout << "*p = " << *p << endl;

  // shows address of p which is sotred inside of q
  cout << "q = " << q << endl;

  // shows what is stored in side of the
  // address that is stored in q ( which is p's address )
  // what is is p's address ? a's adress
  cout << "*q = " << *q << endl;

  // so at first
  // 1- what is inside of () ?
  // answer : what stored inside of the address that is sotred in q, so it
  // shows a's address
  //      more explainings : ( ( (address of p) is in q ) and (adress of a) is
  //      in p)
  // now is (*q) = a's address
  // 2- what does *(*q) means ?
  // answer : what is stored in a's address
  cout << "**q = " << *(*q) << endl;

  //-------------------------
  // an  understandable output:
  // a = 10
  // p = 0x7ffd82098614
  // *p = 10
  // q = 0x7ffd82098618
  // *q = 0x7ffd82098614
  //-------------------------

  return 0;
}
