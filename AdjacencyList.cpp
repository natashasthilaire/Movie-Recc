#include <iostream>
#include <string>
#include <map>
#include "AdjacencyList.h"
#include "primary.h"
#include "movie.h"

//original
void AdjacencyList::buildoutgoing(string from, string to, string wt) {
    //gets outgoing nodes
    /*graph[from].push_back(make_pair(to, stoi(wt)));

    if (graph.find(to) == graph.end()) {
        graph[to] = {};
    }*/

    graph[from].push_back(make_pair(to, stoi(wt)));
    graphingoing[to].push_back(make_pair(from, stoi(wt)));

    if (graph.find(to) == graph.end()) {
        graph[to] = {};
    }

    if (graphingoing.find(to) == graphingoing.end()) {
        graphingoing[to] = {};
    }

}
//
//void AdjacencyList::buildingoing(string from, string to, string wt) {
//    //gets incoming nodes
//    graphingoing[from].push_back(make_pair(to, stoi(wt)));
//    if (graphingoing.find(to) == graphingoing.end()) {
//        graphingoing[to] = {};
//    }
//}

int AdjacencyList::Rating(string from) {

    for (auto i = graphingoing.begin(); i != graphingoing.end(); i++) {
        review.insert(make_pair(i->first, 0));
    }
    double avgReview = 0;

    if (graphingoing.find(from) == graphingoing.end()) {
        return 1;
    }

    for (auto it = graphingoing[from].begin(); it != graphingoing[from].end(); ++it) {
        avgReview += (it->second);
    }

    int size = graphingoing[from].size();
    avgReview /= size;
    int avg = (int)(avgReview + 0.5);

    review[from] = avg;
    return avg;
}

void AdjacencyList::Print() {
    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        cout << it->first << " ->";
        for (int j = 0; j < it->second.size(); j++)
            cout << " " << it->second[j].first << " " << it->second[j].second << " |";
        cout << "\n";
    }
}