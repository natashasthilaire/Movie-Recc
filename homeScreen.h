#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Value_Slider.H>
//#include <FL/Fl_Text_Display.H>
#include <string>
#include <iostream>
#include <vector>;
using namespace std;

class homeScreen {
public:
	static void title();
	static void keyword();
	static void genre();
	static void year();
	static void rating();
	static void numResults();
	static void SearchButton();
	static bool getSearch() {return search;}
	static string getGenre(){return genreInput;}
	static int getStars(){return starsInput;}
	static int getYearMin() {if (yearMinInput == 0) { return 1995; } return yearMinInput;}
	static int getYearMax(){if (yearMinInput == 0) { return 2017; } return yearMaxInput;}
	static int getNumResults(){return numResultsInput;}

private:	
	static void keywordCB(Fl_Widget* input);
	static void boxCB(Fl_Widget* input, void* data);
	static void genreCB(Fl_Widget* input);
	static void yearCB(Fl_Widget* input, void* data);
	static void starOn(Fl_Widget* starx, void* data);
	static void stars(Fl_Widget* starX, void* data);
	static void sliderCB(Fl_Widget* slider);
	static void searchCB(Fl_Widget* search, void* data);
	static vector <Fl_Toggle_Button*> buttons;
	static vector <string> genres; 
	static bool search;
	static int toggle;
	static int starsInput;
	static string genreInput;
	static int yearMinInput;
	static int yearMaxInput;
	static int numResultsInput;
};

