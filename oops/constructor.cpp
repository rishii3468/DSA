#include<iostream>
using namespace std;

class Bike{
  public:
  int tyreSize;
  int engineSize;
  Bike (int tyreSize,int engineSize = 100){
    this->tyreSize = tyreSize;
    this->engineSize = engineSize;
  }
};

int main(){
  Bike tvs(12);
  Bike honda(13,34);
  Bike royalEnfield(15,36);
  cout<<tvs.tyreSize<<" "<<tvs.engineSize;
}