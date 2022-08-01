#include <iostream>
#include <string>
#include <map>
#include "AdjacencyList.h"
#include "primary.h"
#include "movie.h"

void AdjacencyList::buildoutgoing(string from, string to, string wt) {
    graph[from].push_back(make_pair(to, stoi(wt)));

    if (graph.find(to) == graph.end()) {
        graph[to] = {};
    }
}

int AdjacencyList::Rating(string from) {
    
    double avgReview = 0;
    if (cont.find(from) == cont.end()) {
        return 1;
    }

    for (auto it = cont[from].begin(); it != cont[from].end(); ++it) {
        avgReview += (it->second);
    };

    int size = cont[from].size();
    avgReview /= size;
    int avg = (int)(avgReview + 0.5);

    return avg;
}
