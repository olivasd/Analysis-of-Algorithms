/***********
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * 6/6/17
 * Project 3 : TSP
 ***********/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include "functions.hpp"

using namespace std;

/** Finds the distance between two points (x, y)
    using distance formula: sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
    @param cities is a vector in format [city id, x, y, city id, x, y, ...]
    @param city1 & city2 are city id numbers
    @returns result of distance formula for two points rounded
    @0.5 is rounded up (i.e. 5.5 is rounded as 6)
 **/
int findDistance(vector<int> cities, int city1, int city2){
    double distance = sqrt( pow(cities[city2*3 + 1] - cities[city1*3 + 1], 2) +
                            pow(cities[city2*3 + 2] - cities[city1*3 + 2], 2) );
    int rounded = round(distance);
    
    return rounded;
}

/** Searches through a vector for an integer
    @param anyVector is a vector to search through
    @param search is the number to search for
    @returns true if vector contains search; false otherwise
 **/
bool vectorContains(vector<int>& anyVector, int search){
    for (auto& x : anyVector){
        if (search == x)
            return true;
    }
    return false;
}


int main(int argc, char* argv[]) {
    vector<int> cities;
    vector<int> distances;
    vector<int> visited;
    int distance;
    
    // clock_t start1 = clock();
    
    
    if (argc != 2){
        cout << "Invalid number of arguments.\n";
        exit(1);
    }
    
    string file = argv[1];
    ReadFromFile fin(file);

    
    // get the data from file; shove into vector called cities
    // format is [id, x, y, id, x, y, ...]
    while (true){
        getrow(fin, cities);
    
        if (fin.checkEnd())
            break;
    }
    
    // get the number of cities (vector size / 3)
    int num_cities = cities.size() / 3;
    
    // create a n*n sized vector with all the distances
    // format is [d00, d01, d02, ..., d0n, d10, d11, d12, ...]
    for (int i = 0; i < num_cities; i++){
        for (int j = 0; j < num_cities; j++){
            distance = findDistance(cities, i, j);
            distances.push_back(distance);
        }
    }

    
    // example 1: start = 11
    // example 2: start = 11
    int start = 11;                                     // starting city
    visited.push_back(start);                           // list of visited cities
    int min;
    int index;
    int dist_traveled = 0;                              // total distance traveled
    
    // for all cities
    while (visited.size() < num_cities){
        min = 999999;                                   // minimum distance
        index = 123456;                                 // city id
        
        // compare every possible path for a city
        // travel to the nearest neighbor
        for (int i = 0; i < num_cities; i++){
            if (distances[start*num_cities + i] < min &&        // find nearest
                !vectorContains(visited, i) ){                  // not already visited
                min = distances[start*num_cities + i];
                index = i;
            }
        }

        dist_traveled += min;                           // update total dist traveled
        visited.push_back(index);                       // update visited cities
        start = index;                                  // go to that city next
    }
    
    // loop back to start; update distance traveled
    dist_traveled += distances[visited[visited.size()-1] * num_cities + visited[0]];
    
    // clock_t end = clock();
    
    //Write to argument file .tour
    file += ".tour";
    OutputToFile fout(file);
    
    // print distance traveled
    fout << dist_traveled << "\n";
    
    // print tour
    for (auto& x : visited)
        fout << x << "\n";
    
    
    /** for checking time
    double duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<< "time: " << duration << "\n";
    **/
    
    return 0;
}