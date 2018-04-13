/********************************
* Joanna Lew, Daniel Olivas, Nathan Stauffer
* CS325 project 2 algorithm run time comparison
*********************************/
#include "functions.hpp"

using namespace std;

//function prototypes
void runSlow(vector<int> V, ofstream &fout);
void runGreedy(vector<int> V, ofstream &fout);
void runDP(vector<int> V, ofstream &fout);
void timeSlow( vector<vector<int>> Vectors, ofstream &fout);
void timeGreedy( vector<vector<int>> Vectors, ofstream &fout);
void timeDP( vector<vector<int>> Vectors, ofstream &fout);

int main() {

	vector<int> V1 {1, 2, 12, 24, 48, 60};
	vector<int> V2 {1, 5, 10, 25, 50};
	vector<int> V3 {1, 6, 13, 37, 150};
    // Vector of vectors with denominations
	vector<vector<int>> Vectors {V1, V2, V3};
    vector<int> A;

    ofstream fout;
    //open files changeSlowAmount.txt
	fout.open("changeSlowAmount.txt");
	//ALGORITHM #1: changeslow
	fout << "changeslow\n" << "A, Coins\n";

    //loops passes vectors of denominations and passes to runSlow function
	for (int i = 0; i < Vectors.size(); i++) {
		runSlow(Vectors.at(i), fout);
		fout << "\n";
	}
    //closes changeSlowAmount.txt
	fout.close();

    //open changegreedyAmount.txt
	fout.open("changegreedyAmount.txt");
	//ALGORITHM #2: changegreedy
	fout << "changegreedy\n" << "A, Coins\n";
    //loops through vectors of denominations and passes to runGreedy function
	for (int i = 0; i < Vectors.size(); i++) {
		runGreedy(Vectors.at(i), fout);
		fout << "\n";
	}

    //closes changegreedyAmount.txt
	fout.close();

    //opens file chagedpAmount.txt
	fout.open("chagedpAmount.txt");
	//ALGORITHM #3: changedp
	fout << "changedp\n" << "A, Coins\n";
    //loops through vectors of denominations and passes to runDP function
	for (int i = 0; i < Vectors.size(); i++) {
		runDP(Vectors.at(i), fout);
		fout << "\n";
	}
    //closes chagedpAmount.txt
	fout.close();

    //opens changeSlowTime.txt
	fout.open("changeSlowTime.txt");
	//ALGORITHM #1: changeslow timing
	fout << "changeslow\n" << "A, Coins\n";
    //timeSlow function call passing Vector of vectors
	timeSlow(Vectors, fout);
	fout << "\n";
    //closes changeSlowTime.txt
	fout.close();

    //open changegreedyTime.txt
	fout.open("changegreedyTime.txt");
	//ALGORITHM #2: changegreedy timing
	fout << "changegreedy\n" << "A, Coins\n";
    //timeGreedy function call passing Vector of vectors
	timeGreedy(Vectors, fout);
	fout << "\n";
    //closes changegreedyTime.txt
	fout.close();

    //open chagedpTime.txt
	fout.open("chagedpTime.txt");
	//ALGORITHM #3: changedp timing
	fout << "changedp\n" << "A, Coins\n";
    //timeDP function call passing Vector of vectors
	timeDP(Vectors, fout);
	fout << "\n";
    //close chagedpTime.txt
	fout.close();

	return 0;
}
/*
 * runSlow passes vector of denominations and
 * integer A set values 1 - 45. Minimum number of
 * coins for each set is writen to changeSlowAmount.txt
 * */
void runSlow(vector<int> V, ofstream &fout)
{
	int size = 45;
	vector<int> A {};
	vector<int> change(V.size(), 0);
	for (int i = 1; i <= size; i++)
	{
		A.push_back(i);
	}
	fout << "[";
	for (int i = 0; i < V.size(); i++)
	{
		fout << V.at(i);
		if(i == V.size() -1 )
			break;
		else fout << ", ";
	}
	fout << "]\n";
	for (int i = 0; i < A.size(); i++)
	{
		int sum = 0;
		change = changeslow(V, A.at(i));

		for(int j = 0; j < change.size(); j++)
			sum += change.at(j);

		fout << A.at(i) << " , " << sum << " \n";
	}
}
/*
 * runGreedy passes vector of denominations and
 * integer A set values 2000 - 2200. Minimum number of
 * coins for each set is writen to changegreedyAmount.txt
 * */
void runGreedy(vector<int> V, ofstream &fout)
{
	int start = 2000;
	int size = 2200;
	vector<int> A {};
	vector<int> change(V.size(), 0);
	for (int i = 1; i <= size; i++)
	{
		A.push_back(i);
	}
	fout << "[";
	for (int i = 0; i < A.size(); i++)
	{
		fout << V.at(i);
		if(i == V.size() -1 )
			break;
		else fout << ", ";
	}
	fout << "]\n";
	for (int i = start; i < A.size(); i++)
	{
		int sum = 0;
		change = changegreedy(V, A.at(i));
		for(int j = 0; j < change.size(); j++)
			sum += change.at(j);

		fout << A.at(i) << " , " << sum << " \n";
	}
}
/*
 * runDP passes vector of denominations and
 * integer A set values 2000 - 2200. Minimum number of
 * coins for each set is writen to changeDPAmount.txt
 * */
void runDP(vector<int> V, ofstream &fout)
{
	int start = 2000;
	int size = 2200;
	vector<int> A {};
	vector<int> change(V.size(), 0);
	for (int i = 1; i <= size; i++)
	{
		A.push_back(i);
	}
	fout << "[";
	for (int i = 0; i < A.size(); i++)
	{
		fout << V.at(i);
		if(i == V.size() -1 )
			break;
		else fout << ", ";
	}
	fout << "]\n";
	for (int i = start; i < A.size(); i++)
	{
		int sum = 0;
		change = changedp(V, A.at(i));

		for(int j = 0; j < change.size(); j++)
			sum += change.at(j);

		fout << A.at(i) << " , " << sum << " \n";
	}
}
/*
 * timeSlow clocks the speed of changeslow by passing
 * integer sets of size 5 - 50 in increments of 5.
 * results are writen onto changeSlowTime.txt
 */
void timeSlow( vector<vector<int>> Vectors, ofstream &fout)
{
	int size = 5;
	double time = 0;
	double avgTime = 0;
	for(int k = 0; k < 10; k++) {
		fout << "round " << k+1 << "\n";
		for (int i = 0; i < Vectors.size(); i++) {
			vector<int> change(Vectors.at(i).size(), 0);
			clock_t t1, t2;
			t1 = clock();
			change = changeslow(Vectors.at(i), size);
			t2 = clock();
			double diff = ((double) t2 - (double) t1);
			time += diff / CLOCKS_PER_SEC;
			change.clear();
		}
		avgTime = time / 3.0;
		fout << size << ", " << avgTime << "\n";
		time = 0;
		size += 5;
	}
}
/*
 * timeGreedy clocks the speed of changegreedy by passing
 * integer sets of size 0 - 180000000 in increments of 20000000.
 * results are writen onto changegreedyTime.txt
 */
void timeGreedy( vector<vector<int>> Vectors, ofstream &fout)
{
	int size = 0;
	double time = 0;
	double avgTime = 0;
	for(int k = 0; k < 10; k++) {
		fout << "round " << k+1 << "\n";
		for (int i = 0; i < Vectors.size(); i++) {
			vector<int> change(Vectors.at(i).size(), 0);
			clock_t t1, t2;
			t1 = clock();
			change = changegreedy(Vectors.at(i), size);
			t2 = clock();
			double diff = ((double) t2 - (double) t1);
			time += diff / CLOCKS_PER_SEC;
			change.clear();
		}
		avgTime = time / 3.0;
		fout << size << ", " << avgTime << "\n";
		time = 0;
		size += 20000000;
	}
}
/*
 * timeDP clocks the speed of changedp by passing
 * integer sets of size 0 - 900000 in increments of 100000.
 * results are writen onto changedpTime.txt
 */
void timeDP( vector<vector<int>> Vectors, ofstream &fout) {
	int size = 0;
	double time = 0;
	double avgTime = 0;
	for (int k = 0; k < 10; k++) {
		fout << "round " << k + 1 << "\n";
		for (int i = 0; i < Vectors.size(); i++) {
			vector<int> change(Vectors.at(i).size(), 0);
			clock_t t1, t2;
			t1 = clock();
			change = changedp(Vectors.at(i), size);
			t2 = clock();
			double diff = ((double) t2 - (double) t1);
			time += diff / CLOCKS_PER_SEC;
			change.clear();
		}
		avgTime = time / 3.0;
		fout << size << ", " << avgTime << "\n";
		time = 0;
		size += 100000;
	}
}

