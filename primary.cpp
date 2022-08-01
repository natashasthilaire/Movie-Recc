#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "movie.h"
#include "primary.h"
#include "AdjacencyList.h"
#include "homeScreen.h"
#include "resultScreen.h"
using namespace std; 

//sorry I'm not sure where you'd want this but I used the global variable on line 43 "cont" to calculate the rating
unordered_map<string, vector<pair<string, float>>> SetCont(string filename) {
    ifstream File(filename, ios::in);
    unordered_map<string, vector<pair<string, float>>> g;
    if (File.is_open()) {
        string line;
        string from, to, wt;  //userID, movieID, rating
        getline(File, line);
        int count = 0;
        while (getline(File, line)) {

            istringstream stream(line);
            stringstream ss(line);

            getline(stream, from, ',');
            getline(stream, to, ',');
            getline(stream, wt);

            g[to].push_back(make_pair(from, stoi(wt)));
            
        }
        File.close();
    }
    else {
        cout << "Error: " << filename << "could not be opened!" << endl;
    }
    return g;
}

unordered_map<string, vector<pair<string, float>>> cont = SetCont("ratings2.csv");
//std::random_device rd; // obtain a random number from hardware
//std::mt19937 gen(rd()); // seed the generator
//std::uniform_int_distribution<> distr(0, 5); // define the range

vector<Movie*> primary::m;
AdjacencyList primary::l;
priority_queue<Movie*, vector<Movie*>, Compare> primary::MovieRanker;

//bool operator>(const Movie& left, const Movie& right) {
//    return left.avgRating > right.avgRating;
//}

//bool operator<(const Movie& left, const Movie& right) {
//    return left.avgRating < right.avgRating;
//}


void primary::LoadData(string filename, vector<Movie>& movie, AdjacencyList& l) {
     ifstream File(filename, ios::in);

    if (File.is_open()) {
        string line;
        getline(File, line);
        int count = 0;
        while (getline(File, line)) {
            
            istringstream stream(line);
            stringstream ss(line);

            string s;
            Movie temp;

            getline(stream, temp.movieID, ',');
            getline(stream, temp.title, '(');
            getline(stream, temp.year, ')');
            getline(stream, temp.genre, ',');
            getline(stream, temp.genre, ',');

            temp.genres = getGenres(temp.genre, "|");
           
            temp.avgRating = l.Rating(temp.movieID);
            
            movie.push_back(temp);  

        }

        File.close();
    }
    else {
        cout << "Error: " << filename << "could not be opened!" << endl;
    }

    return;
    /*        if (year == "" || year == "no genres listed") {
                year = '0';
            }
            else {
                bool invalid = true;
                do {
                    if (year.size() != 4) {
                        getline(stream, year, '(');
                        getline(stream, year, ')');
                    } 
                    else if ((year.at(0) != '1' && year.at(1) != '9' && year.at(2) != '9') && (year.at(0) != '2' && year.at(1) != '0')) {
                        getline(stream, year, '(');
                        getline(stream, year, ')');
                    }
                    else {
                        invalid = false;
                    }
                } while (invalid);
            }
            
            
            //cout << "result year: " << year << endl;
            temp.year = year;
            getline(stream, temp.genre, ',');
            getline(stream, temp.genre, ',');


            temp.genres = getGenres(temp.genre, "|");
            //temp.avgRating = l.Rating(temp.movieID);
            temp.avgRating = distr(gen);
            m.push_back(&temp);

        }

        File.close();
    }
    else {
        cout << "Error: " << filename << "could not be opened!" << endl;
    }

    return; */
}

vector<string> primary::getGenres(string s, string delim) {
    size_t pos_start = 0, pos_end, delim_len = delim.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delim, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

void primary::Print(Movie& m) {
    cout << "Title: " << m.title << endl;
    cout << "Year: " << m.year << endl;
    cout << "Genre(s): ";
    int last = m.genres.size() - 1;
    for (int i = 0; i < last; i++) {
        cout << m.genres[i] << ", ";
    }
    cout << m.genres[last] << endl;
    cout << "Average rating: " << m.avgRating << "/5" << endl;
}

void primary::getResults() {
    string genre = homeScreen::getGenre();
    int start_year = homeScreen::getYearMin(); //1995 - 2019
    int end_year = homeScreen::getYearMax();
    int minStars = homeScreen::getStars();
    int numResults = homeScreen::getNumResults();
    //for (int i = 0; i < m.size(); i++) {
    /*for (int i = 0; i < 500; i++) {
        cout << "m[" << i << "]->year : " << m[i]->year << endl;
        if (stoi(m[i]->year) >= start_year && stoi(m[i]->year) <= end_year && m[i]->avgRating >= minStars
            && count(m[i]->genres.begin(), m[i]->genres.end(), genre)){
        /*if (m[i]->year >= start_year && m[i]->year <= end_year && m[i]->avgRating >= minStars
            && count(m[i]->genres.begin(), m[i]->genres.end(), genre)) {*/
            MovieRanker.push(m[i]);
        }
    }*/
        for (int i = 0; i < m.size(); i++) {
        if (m[i].year >= to_string(start_year) && m[i].year <= to_string(end_year) 
            && count(m[i].genres.begin(), m[i].genres.end(), genre))
        {
            MovieRanker.push(m[i]);
        }
       
    }

        
}



//void setBuff(Fl_Text_Buffer& buffer, priority_queue<Movie, vector<Movie>, greater<Movie>>& MovieRanker) {
//    int size = MovieRanker.size();
//    if (size == 0) {
//        buffer.text("No results found");
//    }
//    int numResults = homeScreen::getNumResults();
//    int index = 1;
//    while (numResults != 0 && size != 0) {
//
//        Movie temp = MovieRanker.top();
//
//        string result = to_string(index) + ". " + temp.title + "(" + temp.year + ") ";
//        for (int i = 0; i < temp.genres.size(); i++) {
//            result += temp.genres[i] + " ";
//        }
//
//        result += temp.avgRating;
//
//        buffer.append(result.c_str());
//        buffer.append("\n");
//
//        MovieRanker.pop();
//
//        numResults--;
//        size--;
//        index++;
//    }
//
//}

void primary::setBuff() {
    ofstream file;
    file.open("results.txt");

    int size = MovieRanker.size();
    if (size == 0) {
        file << "No results found";
    }
    int numResults = homeScreen::getNumResults();
    int index = 1;
    while (numResults != 0 && size != 0) {
        string result = "";
        Movie* temp = MovieRanker.top();

        result = to_string(index) + ". " + temp->title + "(" + temp->year + ") ";
        //result = to_string(index) + ". " + temp->title + "(" + to_string(temp->year) + ") ";
        for (int i = 0; i < temp->genres.size(); i++) {
            result += temp->genres[i] + " ";
        }

        result += temp->avgRating;

        file << result + "\n";
        MovieRanker.pop();
        numResults--;
        size--;
        index++;
    }
    file.close();
}
