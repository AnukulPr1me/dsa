#include <iostream>

using namespace std;

class animal{
  public:
    void eat(){
      cout << "the animal eat food!!!" << endl;
    }
};

class Dog : public animal{
  public:
    void bark(){
      cout << "dog can bark!!!" << endl;
    }
};


int main(){

  Dog myDog;
  myDog.eat();
  myDog.bark();;;
  return 0;
}
