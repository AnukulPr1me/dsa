#include <iostream>

using namespace std;

int* num1 = new int(12);
int* num2 = num1;

int main(){
     cout << *num1 << endl;
     cout << * num2 << endl;
}