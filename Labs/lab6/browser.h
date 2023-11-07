/**
 * @file browser.h
 * @brief Browser class and related constant declarations and definitions.
 *
 * This file declares and defines a Browser class and the default_url constant.
 * TODO:
 *   This file is completed. You need to finish the member functions defined in
 *   browser.cpp
 */

#ifndef __BROWSER_H__
#define __BROWSER_H__
#include "tab.h"
#include <vector>

const string default_url = "https://cse.hkust.edu.hk/";

/**
 * The Browser class with basic operations
 * you can do with a browser.
 */
class Browser {
	private:
		//The home page url link.
		Url home_url;

		//All currently opened tabs.
		vector<Tab*> tabs;
	
	public:
		//Constructor. You can specify the home page here.
		Browser(Url home_url=default_url);

		//Destructor.
		~Browser();                   //TODO: Finish definition.

		//Create a tab, add to tabs and return its address.
		Tab* open_tab();               //TODO: Finish definition.

		//close the tab pointed by tab.
		void close_tab(Tab* tab);

		//return the address of the tab with specified id.
		//return nullptr if not find.
		Tab* get_tab(int id);          //TODO: Finish definition
};

#endif //__BROWSER_H__
