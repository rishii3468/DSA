#include<iostream>
using namespace std;

class Student {
  public: 
  int rollNumber;
  int age;

  Student(int r, int a) : rollNumber(r), age(a){}
  Student(int r) : rollNumber(r), age(100){}


  void calculateArea(int a, int b){
    cout<<a*b<<endl;
  }

  void calculateArea(int a){
    cout<<a*a<<endl;
  }

  void calculateArea(float a){
    cout<<3.14 * a *a<<endl;
  }
};

int main(){
  Student raj(19,1);
  raj.calculateArea(float(3.12));
  Student jay(12);
}