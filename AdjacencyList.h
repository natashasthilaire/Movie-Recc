#pragma once
#include <map>
#include <string>
#include <vector>
//#include "movie.h"
using namespace std;

class AdjacencyList {
public:
    map<string, vector<pair<string, int>>> graph;
    map<string, float> review;
public:
    void buildoutgoing(string from, string to, string wt);
    int Rating(string from);
};


