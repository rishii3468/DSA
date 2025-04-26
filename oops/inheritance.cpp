#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Vehicle{ // Base class, Parent class
  public:
  int tyreSize;
  int engineSize;
  int lights;
  string companyName;

};

class Car : public Vehicle{ // Dervided class
  public:
  int steeringSize;
};

class Bike : public Vehicle{
  public:
  int handleSize;

  
};

class A{
  private: // can't be accesssed, can't be inherited
  int a_private;
  protected: // can't be accesssed, can be inherited
  int a_protected;
  public: // both
  int a_public;
  A(){
    cout<<"a"<<endl;
  }
};

class B : public A{
  public:
  int b_public;
  B(){
    cout<<"b"<<endl;
  }
};

int main(){
  B v;
  

}