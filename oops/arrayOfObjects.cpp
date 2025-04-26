#include<iostream>
using namespace std;

class Cricketer{
public:
  char name;
  int age;
  int noOfTestMatches;
  int avgScore;

};

int main(){
  
  Cricketer virat;
  virat.name = 'V';
  virat.age = 30;
  virat.noOfTestMatches = 100;
  virat.avgScore = 80;
  Cricketer dhoni;
  dhoni.name = 'D';
  dhoni.age = 40;
  dhoni.noOfTestMatches = 140;
  dhoni.avgScore = 50;
  Cricketer cricketers[2] = {virat, dhoni};
  
  cout<<cricketers[0].name<<endl;
}