/***********
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * 4 / 20 / 17
 * Project 1 : Subarray with Max Sum
 ***********/

#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Result {
    int sum;
    int low_idx;
    int high_idx;
};

int max(int a, int b);                  // Gets the larger of two numbers

Result badMSS(vector<int>& nums);       // max sum subarray w/ 3 for loops
Result betterMSS(vector<int>& nums);    // MSS w/ 2 for loops
Result recursiveMSS(vector<int>& nums); // MSS w/ recursion
Result dpMSS(vector<int>& nums);        // MSS w/ dynamic programming

// RAII: ifstream (get contents of a file; convert to int)
class ReadFromFile {
    friend void getline(ReadFromFile&, string&);
    friend void getrow(ReadFromFile&, vector<int>&);
    friend ReadFromFile& operator>>(ReadFromFile&, int&);
    
public:
    ReadFromFile(const string& filename);
    ~ReadFromFile();
    
    operator bool();
    
private:
    ifstream fin;
};

// RAII: ofstream (make/update a file)
class OutputToFile{
    friend OutputToFile& operator<<(OutputToFile&, int);
    friend OutputToFile& operator<<(OutputToFile&, const string&);
    
public:
    OutputToFile(const string& filename);
    ~OutputToFile();
    
private:
    ofstream fout;
};


#endif /* functions_hpp */