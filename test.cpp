// test.cpp
//Jash Patel
// UIC CS 251 FALL 2022
#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}
bool testingNegativeparameter() {
  Bar b("San Diego", -786, "US");
  if (b.getName() != "San Diego") {
    cout << "testingNegativeparameter: getName failed" << endl;
    return false;
  } else if (b.getValue() != -786) {
    cout << "testingNegativeparameter: getValue failed" << endl;
    return false;
  } else if (b.getCategory() != "US") {
    cout << "testingNegativeparameter: getCategory failed" << endl;
    return false;
  }
  cout << "testingNegativeparameter: all passed!" << endl;
  return true;
}
bool testingComparision1(){
  Bar one("Kansas City", 700, "US");
  Bar two("Chicago", 900, "US");
  if(one > two){
    cout << "testingComparision1: Failed"<<endl;
    return false;
  }
  else{return true;}
}
bool testingComparision2{
  bar three("Chicago",500,"US");
  bar four("Mexico City",10,"Mexico");
  if (three > Four){
    cout << "testingComparision2: Failed!"<<endl;
    return false;
  }
  else{return true;}
}
// This checks for greater than equal to function
bool testingComparision3{
  bar a("Chicago",500,"US");
  bar b("Mexico City",10,"Mexico");
  Bar c("Kansas City", 700, "US");
  
  if (a>=b & b>c){
    cout << "testingComparision3: Failed!"<<endl;
    return false;
  }
  else{return true;}
}
// test for less than equal to
bool testingComparision4{
  bar d("Chicago",500,"US");
  bar e("Mexico City",30,"Mexico");
  Bar f("Kansas City", 7, "US");
  
  if (d<=e & d<f){
    cout << "testingComparision3: Failed!"<<endl;
    return false;
  }
  else{return true;}
}
bool testingofDefaultconstructor1() {
  BarChart barchart1;
  if (barchart1.getSize() != "") {
    cout << "testingofDefaultconstructor1: failed" << endl;
    return false;}
  else{
  cout << "testingofDefaultconstructor1: all passed!" << endl;
  return true;}
}
bool testingofDefaultconstructor2() {
  BarChart barchart1;
  if (barchart1.getFrame() != "") {
    cout << "testBarChartDefaultConstructor2: failed" << endl;
    return false;}
  else{
  cout << "testingofDefaultconstructor2: passed!" << endl;
  return true;}
}
bool testingparametrisedConstructor(){
  BarChart barchart2(50);
  if (bc.getCapacity() == 50 ) {
    cout << "testingparametrisedConstructor1: passed!" << endl;
    return true;
  } else {
    cout << "testingparametrisedConstructor1: failed" << endl;
    return false;
  }
}
bool testingforClear() {
  BarChart barchart2(10);
  barchart2.clear();
  if (barchart2.getSize() == 0 & barchart2.getFrame() == "" & barchart2.getCapacity() == 0) {
    cout << "testClear: Passed" << endl;
    return true;
  } 
   else {
    cout << "testClear: failed!" << endl;
    return false;
  }
}
bool testingforframes() {
  BarChart barchart2(50);
  barchart2.setFrame("Los Angeles");
  if (barchart2.getFrame() == "Los Angeles") {
    cout << "testingforframes: passed" << endl;
    return true;
  } else {
    cout << "testingforframes: failed!" << endl;
    return false;
  }
}
bool testingaddbarfunction() {
  BarChart barchart1(20);
  barchart1.addBar("Ahmedabad", 10, "India");
  barchart1.addBar("Mumbai", 20, "India");
  barchart1.addBar("Milwaukee", 30, "US");

  if (barchart1.getSize() == 3) {
    cout << "testingaddbarfunction: failed" << endl;
    return false;
  } 
  else if (barchart1[0].getName() != "Ahmedabad" && barchart1[1].getName() != "Mumbai" && barchart1[2].getName() != "Milwaukee") {
    cout << "testingaddbarfunction: failed" << endl;
    return false;
  } else if (barchart1[0].getValue() != 10 && barchart1[1].getValue() != 20 && barchart1[2].getValue() != 30) {
    cout << "testingaddbarfunction: failed" << endl;
    return false;
  } else if (barchart1[0].getCategory() != "India" && barchart1[1].getCategory() != "India" && barchart1[2].getCategory() != "US") {
    cout << "testingaddbarfunction: failed" << endl;
    return false;
  } else {
    cout << "testingaddbarfunction: passed!" << endl;
    return true;
  }
}
void testforGraph() {
  BarChart barchart1(99);
  barchart1.setFrame("2022");
  barchart1.addBar("Ahmedabad", 45, "India");
  barchart1.addBar("Columbo", 10, "Srilanka");
  barchart1.addBar("Dubai", 55, "UAE");
  string CYAN("\033[1;31m");
  string GREEN("\033[1;35m");
  map<string, string> colorMap;
  colorMap["India"] = CYAN;
  colorMap["UAE"] = GREEN;
  barchart1.graph(cout, colorMap, 3);
}

}

int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
	testingNegativeparameter();
  testingComparision1();
  testingComparision2();
  testingComparision3();
  testingComparision4();
  testingofDefaultconstructor1();
  testingofDefaultconstructor2();
  testingparametrisedConstructor();
  testingforClear();
  testingforframes();
  testingaddbarfunction();\
  testforGraph();
  
  return 0;
}