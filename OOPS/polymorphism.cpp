#include <iostream>

using namespace std;

class Shape{
  public:
    virtual void draw(){
      cout << "draw a generic shape!" << endl;
    }
};

class Circle : public Shape{
  public:
    void draw() override{
      cout << "drawing a circle!" << endl; 
    }
};

class Ractangle: public Shape{
  public:
    void draw() override{
      cout << "drawing a ractangle!" << endl;
    }
};

int main(){
  Shape* shape;
  Ractangle ractangle;
  Circle circle;
  
  shape = &circle;
  shape->draw();

  shape = &ractangle;
  shape->draw();
  return 0;
}
