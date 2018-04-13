/***********
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * 6/6/17
 * Project 3 : TSP
 ***********/

#include "functions.hpp"

/** Constructor: open file and check that file is readable
    @param filename is the name of the file to open
    @writes "Couldn't open file!" to console if failed to open file */
ReadFromFile::ReadFromFile(const string& filename) : fin(filename) {
    if (fin.fail()){
        cout << "Couldn't open file!\n";
        exit(1);
    }
};

bool ReadFromFile::checkEnd(){
    return fin.eof();
}

/** Destructor automatically closes file */
ReadFromFile::~ReadFromFile(){
    fin.close();
}


void getline(ReadFromFile& file, string& s){
    getline(file.fin, s);
}

void getrow(ReadFromFile& file, vector<int>& v){
    string row;
    getline(file, row);
    
    istringstream str(row);
    int temp = 0;
    
    while (str >> temp) {
        v.push_back(temp);
    }
}


ReadFromFile& operator>>(ReadFromFile& input_file, int& a){
    input_file.fin >> a;
    return input_file;
}

ReadFromFile::operator bool(){
    return !fin.fail();
}



OutputToFile::OutputToFile(const string& filename) : fout(filename) { }

OutputToFile& operator<<(OutputToFile& output_file, int a){
    output_file.fout << a;
    return output_file;
}

OutputToFile& operator<<(OutputToFile& output_file, const string& s){
    output_file.fout << s;
    return output_file;
}

OutputToFile::~OutputToFile(){
    fout.close();
}