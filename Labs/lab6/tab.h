/**
 * @file tab.h
 * @brief Tab class and related alias declarations and definitions.
 *
 * This file declares and defines a Tab class and aliases string as Url type.
 * TODO:
 *   This file is completed. You need to finish the member functions defined in
 *   tab.cpp
 */
#ifndef __TAB_H__
#define __TAB_H__
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

using Url = string;

/**
 * The Tab class.
 * you need to use it to open web pages.
 */
class Tab {
	private:
		//The id indicate this tab.
		int id;

		//Url stack keeps browsed urls in order allowing you to go
	  //foward and backward on your history on this tab.
		//Using list to support forward rather than actual stack.
		list<Url> url_stack;

		//Iterator indicates position of your current page location in stack.
		list<Url>::iterator current_url;

	public:
		//Construct a tab with id and initial page.
		Tab(int id, Url init_url);

		//Destructor
		~Tab();

		//return its id.
		int get_id() const;

		//Open a url.
		void open(Url url);

		//Go to the next page you have "opened" since current one.
		void forward();

		//Go to the previous page you have "opened" before current one.
		void backward();
};

#endif //__TAB_H__
