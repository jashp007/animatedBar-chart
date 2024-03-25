// barchartanimate.h
//Jash Patel
// UIC CS 251 FALL 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string label;
    string source;

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
    this->title = title;
    this->label = xlabel;
    this->source = source;
    capacity = 4;
    barcharts = new BarChart[capacity];
    size = 0;
        
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        
    if (barcharts != nullptr) {
      delete[] barcharts;
    }
        
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
    string line;
    string emptyLine;
    string stngRecords;
    int records;
    string year, name, country, value, category;
    int xValue;
    int colorIndex = 0;
    getline(file, emptyLine, '\n');

    getline(file, stngRecords, '\n');  // get the number of records in group

    if (stngRecords != "") {
      records = stoi(stngRecords);
    } else {
      return;
    }

    BarChart bc(records);
    for (int i = 0; i < records; i++) {
      getline(file, line, '\n');
      stringstream ss(line);

      getline(ss, year, ',');      // get the year
      getline(ss, name, ',');      // get the name of city
      getline(ss, country, ',');   // get the name of country
      getline(ss, value, ',');     // get the value
      getline(ss, category, ',');  // get the category
      // Building the color map: after reading the category field
      // check if category if already in colorMap
      xValue = stoi(value);
      bc.addBar(name, xValue, category);

      if (colorMap.count(category) == 0) {
        colorMap[category] = COLORS[colorIndex];
        colorIndex++;
        if (colorIndex == 7) {
          colorIndex = 0;
        }
      }

      bc.setFrame(year);
    }
    // build a barchart object for every group of line

    if (size == capacity) {
      int newCapacity = capacity * 2;
      BarChart* newBar = new BarChart[newCapacity];

      for (int i = 0; i < size; i++) {
        newBar[i] = barcharts[i];
      }
      delete[] barcharts;
      capacity = newCapacity;
      barcharts = newBar;
    }
    barcharts[size] = bc;
    size++;
  }
        
    

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
    if (endIter == -1) {  // if the endIter is -1, set it to the array size
      endIter = size;
    }
    int i = 0;
    while ( i < endIter) {
      usleep(3 * microsecond);
      output << CLEARCONSOLE;
      output << BLACK << title << endl;  // print the tile, then source in black
      output << BLACK << source << endl;
      // print the graph of the BarChart
      barcharts[i].graph(output, colorMap, top);
      output << BLACK << label << endl;
      output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
      i++
    }
  }

			
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;  // TO DO:  update this, it is only here so code compiles.
        
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        BarChart bc;
        if (i >= size || i < 0) 
        {
          throw out_of_range("BarChartAnimate: i out of bounds");
        }
      return barcharts[i]; // TO DO:  update this, it is only here so code compiles.
    }
};