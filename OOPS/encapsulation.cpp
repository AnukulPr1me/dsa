#include <iostream>

using namespace std;

class BankAccount{
  private:
    double balance;

  public:
    BankAccount(double initial_balance){
      if(initial_balance < 0){
        balance = 0;
      }else{
        balance = initial_balance;
      }
    }
  
  void deposit(double amount){
    if(amount > 0){
      balance += amount;

    }
  }
  void withdraw(double amount){
    if(amount > 0 && amount<=balance){
      balance -= amount;
    }else{
      cout << "Insufficient funds!"<<endl;
    }
  }
  double getBalance() const {
    return balance;
  }
};

int main(){
  BankAccount account(1000);
  account.deposit(100);
  account.withdraw(30);
  cout << "current balance:" << account.getBalance() <<endl;
  return 0;
}
