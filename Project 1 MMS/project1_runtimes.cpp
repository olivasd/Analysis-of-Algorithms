/********************************
* Joanna Lew, Daniel Olivas, Nathan Stauffer
* CS325 project 1 algorithm run time comparison
*********************************/
#include "functions.hpp"
#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	Result result;            //returned by algorithms 1 - 4
	double timer = 0;            //accumulates time for three runs of each algorithm
	double avg_time = 0;     //holds average of three timing runs 
	int numEle = 0;
	vector<int> vlist;
	
	ofstream outputFile;

	// Open the output file
	outputFile.open("output.txt");

	// set the seed for random numbers   
	// 'rd' for non-deterministic 32-bit seed    
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(-99, 99);

	//ALGORITHM #1: badMSS

	//numele variable may need to start at different value for different algorithms  
	numEle = 50;
	outputFile << "Enumeration\n";
	outputFile << "n, seconds\n";
	//fill vector with first numEle elements
	for (int i = 0; i < numEle; ++i)
		vlist.push_back(dist(mt));

	//test 10 different vector lengths
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// fill the rest of larger vector with random numbers        
		for (int j = numEle; j < numEle +50; ++j)
			vlist.push_back(dist(mt));
		numEle += 50;
		
		// find max subarray using algorithm #1 and calculate run time
		// for increased accuracy, run three times and calculate average run time
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			result = badMSS(vlist);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
			
		}
		avg_time = timer / 3.0;

		//display result
		cout << "For vector size " << numEle << ", algorithm #1 took " << avg_time << " seconds" << endl;
		outputFile <<  numEle << ", " << avg_time << endl;

		//clear timer
		timer = 0;
	}

	//clear vector
	vlist.clear();
	
	
	//ALGORITHM #2: betterMSS    
	outputFile << "\nBetter Enumeration\n";
	outputFile << "n, seconds\n";
	//numele variable may need to start at different value for different algorithms    
	numEle = 400;

	//fill vector with first numEle elements  
	for (int i = 0; i < numEle; ++i)
		vlist.push_back(dist(mt));

	//test 10 different vector lengths  
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i + 1 << "\n";
		// fill the rest of larger vector with random numbers            
		for (int j = numEle; j < numEle +800; ++j)
			vlist.push_back(dist(mt));
		numEle += 800;

		// find max subarray using algorithm #2 and calculate run time    
		// for increased accuracy, run three times and calculate average run time    
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			result = betterMSS(vlist);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
		}
		avg_time = timer / 3.0;

		//display result    
		cout << "For vector size " << numEle << ", algorithm #2 took " << avg_time << " seconds" << endl;
		outputFile << numEle << ", " << avg_time << endl;

		//clear timer
		timer = 0;
	}

	//clear vector
	vlist.clear();
	
	//ALGORITHM #3: recursiveMSS    
	outputFile << "\nDivide and Conquer\n";
	outputFile << "n, seconds\n";
	//numele variable may need to start at different value for different algorithms    
	numEle = 10000;

	//fill vector with first numEle elements  
	for (int i = 0; i < numEle; ++i)
		vlist.push_back(dist(mt));

	//test 10 different vector lengths  
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// fill the rest of larger vector with random numbers            
		for (int j = numEle; j < numEle + 10000; ++j)
			vlist.push_back(dist(mt));
		numEle += 10000;

		// find max subarray using algorithm #3 and calculate run time    
		// for increased accuracy, run three times and calculate average run time    
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			result = recursiveMSS(vlist);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
		}
		avg_time = timer / 3.0;

		//display result    
		cout << "For vector size " << numEle << ", algorithm #3 took " << avg_time << " seconds" << endl;
		outputFile << numEle << ", " << avg_time << endl;

		//clear timer
		timer = 0;
	}

	//clear vector
	vlist.clear();
	
	//ALGORITHM #4: dpMSS    
	outputFile << "\nDynamic Programming\n";
	outputFile << "n, seconds\n";
	//numele variable may need to start at different value for different algorithms      
	numEle = 10000;

	//fill vector with first numEle elements    
	for (int i = 0; i < numEle; ++i)
		vlist.push_back(dist(mt));

	//test 10 different vector lengths    
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// fill the rest of larger vector with random numbers                
		for (int j = numEle; j < numEle + 10000; ++j)
			vlist.push_back(dist(mt));
		numEle += 10000;


		// find max subarray using algorithm #4 and calculate run time    
		// for increased accuracy, run three times and calculate average run time    
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			result = dpMSS(vlist);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
		}
		avg_time = timer / 3.0;

		//display result    
		cout << "For vector size " << numEle << ", algorithm #4 took " << avg_time << " seconds" << endl;
		outputFile << numEle << ", " << avg_time << endl;

		//clear timer
		timer = 0;
	}
	//close the output file
	outputFile.close();
	

	return 0;
}