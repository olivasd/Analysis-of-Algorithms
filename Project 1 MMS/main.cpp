/***********
* Daniel Olivas, Nathan Stauffer, Joanna Lew
* 4 / 20 / 17
* Project 1 : Subarray with Max Sum
***********/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "functions.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	ifstream inputFile;
	string content;
	vector<vector<int> > Vectors;
	//read file content
	inputFile.open("MSS_Problems.txt");
	//loops until end of file is reached 
	while (getline(inputFile, content))
	{
		vector<int> temp;
		stringstream ss(content);
		int nums;
		//parses each line into vector temp
		while (ss)
		{
			ss >> nums;
			temp.push_back(nums);
		}
		//pushes vector on top of Vector of vectors, clears temp
		Vectors.push_back(temp);
		temp.clear();
	}
	//closes inpuFile
	inputFile.close();
	//write result to file
	ofstream fout;
	fout.open("MSS_Results.txt");
	int vSize = Vectors.size();
	int vIndex = 0;
	while (vSize > 0)
	{
		vector<int> testVec = Vectors.at(vIndex);
		vIndex += 1;
		testVec.pop_back();
		int testSize = testVec.size();
		//display original array
		fout << "array from file: \n";
		for (int i = 0; i < testSize; i++)
		{
			fout << testVec.at(i) << " ";
		}
		fout << "\n";

		//run algorithm 1
		Result res = badMSS(testVec);

		fout << "max subarray for algorithm #1:\n";
		for (int i = res.low_idx; i <= res.high_idx; i++)
			fout << testVec[i] << " ";
		fout << "\n";
		fout << "sum: " << res.sum << "\n";

		//run algorithm 2
		res = betterMSS(testVec);
		//write result to file
		fout << "max subarray for algorithm #2:\n";
		for (int i = res.low_idx; i <= res.high_idx; i++)
			fout << testVec[i] << " ";
		fout << "\n";
		fout << "sum: " << res.sum << "\n";

		//run algorithm 3
		res = recursiveMSS(testVec);
		//write result to file
		fout << "max subarray for algorithm #3:\n";
		for (int i = res.low_idx; i <= res.high_idx; i++)
			fout << testVec[i] << " ";
		fout << "\n";
		fout << "sum: " << res.sum << "\n";

		//run algorithm 4
		res = dpMSS(testVec);
		//write result to file
		fout << "max subarray for algorithm #4:\n";
		for (int i = res.low_idx; i <= res.high_idx; i++)
			fout << testVec[i] << " ";
		fout << "\n";
		fout << "sum: " << res.sum << "\n";

		fout << "\n\n";
		vSize--;
	}
	fout.close();

	return 0;

}