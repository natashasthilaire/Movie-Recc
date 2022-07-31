#pragma once
#include <Windows.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Toggle_Button.H>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "resultScreen.h"
#include "homeScreen.h"

class resultScreen {
public:
	static void init();
	static void title();
	static void topText();
	static void resultsOuput();

private:
	static Fl_Text_Buffer* buffer;
	static Fl_Text_Display* display;
};

