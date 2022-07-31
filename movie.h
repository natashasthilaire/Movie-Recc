#pragma once
#include <string>
#include <vector>
using namespace std;
#ifndef STRUCT_HEADER  //begin header guard
#define STRUCT_HEADER

struct Movie {
    string movieID;
    string title;
    string year;
    string genre;
    vector <string> genres;
    int avgRating;
};
#endif //STRUCT_HEADER //end header guard