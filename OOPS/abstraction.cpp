#include <iostream>

using namespace std;

class abstractVechicle{
  public:
    virtual void start() = 0;
    virtual void stop() = 0;

};

class car : public abstractVechicle{
  public:
    void start() override{
      cout << "car is starting!" << endl;
    }

    void stop() override{
      cout << "car is stoped!" << endl;
    }
};

class bike : public abstractVechicle{
  public:
    void start() override{
      cout << "bike is starting!" << endl;
    }

    void stop() override{
      cout << "bike is stoped!" << endl;
    }
};


int main(){

  abstractVechicle* vechicle;
  car myCar;
  bike myBike;
  
  vechicle = &myCar;
  vechicle->start();
  vechicle->stop();
  
  vechicle = &myBike;
  vechicle->start();
  vechicle->stop();
  return 0;
}
