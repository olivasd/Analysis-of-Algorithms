/*********************************
 
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * Project 2: Coin Change
 
 **********************************/

#include "functions.hpp"

/** Helper function for recursive approach to coin change
 @param values is a vector of available coin values
 @param amount is the (remaining) amount being converted to coin change
 @param coins is the total coins needed for amounts [1 ... specified amount]
 @param subcoins is the # of each coin needed for amounts [1 ... specified amount]
 @returns minimum total coins needed for amount specified
 @returns @coins and @subcoins are passed by reference, and changed */
int slowHelper(vector<int>& values, int amount, vector<int>& coins, vector<int>& subcoins){
    int size = values.size();               // number of coins available
    
    if (amount < 0)                         // trivial cases
        return -1;
    else if (amount == 0)
        return 0;
    
    // calculate the least number of coins by
    // finding the minimum # of coins needed to make (amount - coin) cents
    int min = amount + 1;
    for (int i=0; i < size; i++){
        int res = slowHelper(values, amount - values[i], coins, subcoins);
        if (res >= 0 && res < min){
            min = res + 1;
            // save the individual coin count
            for (int j=0; j < size; j++)
                subcoins[amount * size + j] = subcoins[(amount - values[i]) * size + j];
            subcoins[amount * size + i]++;
        }
    }
    coins[amount - 1] = min;
    return coins[amount - 1];
}

/** Recursive approach to coin change
 @param values is a vector of available coin values
 @param amount is the amount being converted to coin change
 @returns vector of coin count  */
vector<int> changeslow(vector<int>& values, int amount){
    int subSize = values.size() * (amount + 1);
    vector<int> coins(amount, -123);                // total count of all coins for the amount
    vector<int> subcoins(subSize, 0);               // count of each coin for the amount
    
    // if amount is 0, return 0 coins each
    // otherwise, see helper function
    if (amount == 0)
        return subcoins;
    slowHelper(values, amount, coins, subcoins);
    
    // return the individual coin count for amount specified
    vector<int> result;
    for (int i = subSize - values.size(); i < subSize; i++){
        result.push_back(subcoins[i]);
    }
    return result;
}


/** Greedy approach to coin change
 @param values is a vector of available coin values
 @param amount is the amount being converted to coin change
 @returns vector of coin count  */
vector<int> changegreedy(vector<int>& values, int amount){
    int i = values.size() - 1;              // largest coin value
    vector<int> coins(values.size(), 0);    // number of each coin
    
    while (i >= 0 && amount != 0){
        if (values[i] <= amount){           // subtract largest coin
            amount -= values[i];            // from amount
            coins[i]++;
        }
        else                                // if amount < coin value
            --i;                            // go down a coin size
    }
    return coins;
}

/** Dynamic programming approach to coin change
 @param values is a vector of available coin values
 @param amount is the amount being converted to coin change
 @returns vector of coin count */
vector<int> changedp(vector<int>& values, int amount){
    int max = amount + 1;                   // arbritary large value
    int size = values.size();               // number of available coins
    int csize = size * max;
    vector<int> coins(csize, 0);            // holds coin count for every amount
    vector<int> dp(max, max);               // holds sum(coin count) for every amount
    dp[0] = 0;                              // initial condition
    
    // go through every amount from [1 ... given amount]
    // and test each coin combination
    for (int i=1; i <= amount; ++i){
        for (int j=0; j < size; ++j){
            // if value subtractable, must be previous number of coins + 1
            // save the coin count subvector
            if (values[j] <= i){
                dp[i] = min(dp[i], dp[i - values[j]] + 1);
                if (dp[i] == dp[i - values[j]] + 1){
                    for (int k=0; k < size; ++k)
                        coins[i * size + k] = coins[(i - values[j]) * size + k];
                    coins[i * size + j]++;
                }
            }
        }
    }
    
    // return only the coin count subvector for amount given
    vector<int> subCoins;
    for (int i = csize - size; i < csize; i++){
        subCoins.push_back(coins[i]);
    }
    return subCoins;
}




/** Constructor: open file and check that file is readable
 @param filename is the name of the file to open
 @writes "Couldn't open file!" to console if failed to open file */
ReadFromFile::ReadFromFile(const string& filename) : fin(filename) {
    if (fin.fail())
        cout << "Couldn't open file!\n";
    
};

/** Checks for end of file
 @returns true if end, false if not end **/
bool ReadFromFile::checkEnd(){
    return fin.eof();
}

/** Return to beginning of file */
void ReadFromFile::beginAnew(){
    fin.clear();
    fin.seekg(0, ios::beg);
    return;
}

/** Destructor automatically closes file */
ReadFromFile::~ReadFromFile(){
    fin.close();
}

/** Get string values from file until line break
 @param file is file to get values from
 @param s is the string to get */
void getline(ReadFromFile& file, string& s){
    getline(file.fin, s);
}

/** Get first integer value in line
 @param file is the file to get values from
 @param a is the integer to store value in */
void getrow(ReadFromFile& file, int& a){
    string row;
    getline(file, row);
    
    istringstream str(row);
    str >> a;
}

/** Get integer values from file until line break
 @param file is the file to get values from
 @param v is the vector to store integers in */
void getrow(ReadFromFile& file, vector<int>& v){
    string row;
    getline(file, row);
    
    istringstream str(row);
    int temp = 0;
    
    while (str >> temp) {
        v.push_back(temp);
    }
}

/** Overload >> for readability --> same as cin >>
 @param input_file is the file to read from
 @param a is the integer to store value in
 @returns input_file for chaining */
ReadFromFile& operator>>(ReadFromFile& input_file, int& a){
    input_file.fin >> a;
    return input_file;
}

/** Make sure file is readable */
ReadFromFile::operator bool(){
    return !fin.fail();
}


/** Constructor: open file to write to */
OutputToFile::OutputToFile(const string& filename) : fout(filename) { }

/** Overload << for readability --> same as cout <<
 @param output_file is the file to write to
 @param a is the integer to write
 @returns output_file for chaining */
OutputToFile& operator<<(OutputToFile& output_file, int a){
    output_file.fout << a;
    return output_file;
}

/** Overload << for readability --> same as cout <<
 @param output_file is the file to write to
 @param s is the string to write
 @returns output_file for chaining */
OutputToFile& operator<<(OutputToFile& output_file, const string& s){
    output_file.fout << s;
    return output_file;
}

/** Destructor: automatically close file */
OutputToFile::~OutputToFile(){
    fout.close();
}


