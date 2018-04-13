/*********************************
 
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * Project 2: Coin Change
 * Takes an amount, coin values
 * Returns minimum number of coins needed for that amount
 
 **********************************/

#include <iostream>
#include <vector>
#include <string>
#include "functions.hpp"

using namespace std;

int main(int argc, char** argv) {
    // check for two command line arguments
    if (argc > 2){
        cout << "Too many arguments. \n";
        return 0;
    }
    else if (argc < 2){
        cout << "Please enter filename. \n";
        return 0;
    }
    
    // make output file name: [input_file_name]change.txt
    string outfile = argv[1];
    outfile = outfile.substr(0,outfile.size()-4);
    outfile += "change.txt";
    cout << "outfile: " << outfile << "\n";
    
    // open file for reading, file for writing
    ReadFromFile fin(argv[1]);
    OutputToFile fout(outfile);
    vector<int> coinValues;
    vector<int> result;
    int amount = 0;
    int sum;
    
    // print results of changeslow algorithm to file
    fout << "Algorithm changeslow: \n";
    while (true){
        sum = 0;
        getrow(fin, coinValues);        // get first line as coin values
        getrow(fin, amount);            // get second line as amount
        
        if (coinValues.empty())         // if getting a newline or empty space
            break;
        
        for (int& values : coinValues)
            fout << values << " ";
        fout << "\n";
        
        result = changeslow(coinValues, amount);
        for (int& count : result){      // print the number of each coin
            fout << count << " ";       // and total number of coins needed
            sum += count;
        }
        fout << "\n";
        fout << sum << "\n";
        
        coinValues.clear();             // stop at file end
        if (fin.checkEnd())
            break;
    }
    
    fin.beginAnew();                    // go back to beginning of file
    fout << "\n";                       // for next algorithm
    
    // print results of changegreedy algorithm to file
    fout << "Algorithm changegreedy: \n";
    while (true){
        sum = 0;
        getrow(fin, coinValues);
        getrow(fin, amount);
        
        if (coinValues.empty())
            break;
        
        for (int& values : coinValues)
            fout << values << " ";
        fout << "\n";
        
        result = changegreedy(coinValues, amount);
        for (int& count : result){
            fout << count << " ";
            sum += count;
        }
        fout << "\n";
        fout << sum << "\n";
        
        coinValues.clear();
        if (fin.checkEnd())
            break;
    }
    
    fin.beginAnew();
    fout << "\n";
    
    // print results of changedp algorithm to file
    fout << "Algorithm changedp: \n";
    while (true){
        sum = 0;
        getrow(fin, coinValues);
        getrow(fin, amount);
        
        if (coinValues.empty())
            break;
        
        for (int& values : coinValues)
            fout << values << " ";
        fout << "\n";
        
        result = changedp(coinValues, amount);
        for (int& count : result){
            fout << count << " ";
            sum += count;
        }
        fout << "\n";
        fout << sum << "\n";
        
        coinValues.clear();
        if (fin.checkEnd())
            break;
    }
    return 0;
}

