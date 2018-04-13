/*********************************
 
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * Project 2: Coin Change
 
 **********************************/

#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int slowHelper(vector<int>& values, int amount, vector<int>& coins, vector<int>& subcoins);
vector<int> changeslow(vector<int>& values, int amount);
vector<int> changegreedy(vector<int>& values, int amount);
vector<int> changedp(vector<int>& values, int amount);

// RAII: ifstream (get contents of a file; convert to int)
class ReadFromFile {
    friend void getline(ReadFromFile&, string&);
    friend void getrow(ReadFromFile&, int&);
    friend void getrow(ReadFromFile&, vector<int>&);
    friend ReadFromFile& operator>>(ReadFromFile&, int&);
    
public:
    ReadFromFile(const string& filename);
    void beginAnew();
    bool checkEnd();
    
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

