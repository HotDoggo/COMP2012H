/**
 * @file browser.cpp
 * @brief Browser class member functions definitions
 *
 * This file defines following member functions of Browser:
 *   1. Browser::Browser:   the constructor.
 *   2. Browser::~Browser:  the destructor.
 *   3. Browser::open_tab:  open a new tab.
 *   4. Browser::close_tab: close a tab.
 *   5. Browser::get_tab:   get the tab by id.
 *
 *   TODO: You need to finish:
 *     1. Browser::~Browser
 *     2. Browser::open_tab
 *     3. Browser::close_tab
 *     4. Browser::get_tab
 */

#include "browser.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

/**
 * Construct a browser. The default url when opening a new tab
 * is the home_url
 */
Browser::Browser(Url home_url) {
	cout << "Browser:    You have opened a browser." << endl; 
	this->home_url = home_url;
}

/**
 * Destruct a browser.
 *
 * TODO: Finish the code.
 */
Browser::~Browser() {
	//Clean stuff.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------

	cout << "Browser:    You have closed the browser." << endl; 
}

/**
 * Create a new tab.
 * Its id should be the number of tabs you currently have, start from 0.
 * The initial page should be home page.
 * Add a pointer of it to tabs.
 * Return this pointer for operations.
 *
 * TODO: Finish the code.
 */
Tab* Browser::open_tab() {
	//=========== TODO ===================================================

	//--------------------------------------------------------------------
}

/**
 * Close the tab pointed by tab.
 *
 * TODO: Finish the code.
 */
void Browser::close_tab(Tab* tab) {
	bool found;
	//Find the tab.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------

	if (!found) {
		cout << "Browser:    Cannot find this tab for closing, something must be wrong!" << endl;
		return;
	}

	cout << "Browser:    Closing Tab_" << tab->get_id() << endl;
	//Clean stuff.
//=========== TODO ===================================================

//--------------------------------------------------------------------

}

/**
 * get the tab with specified id.
 * return its address if find.
 * return nullptr if not find.
 *
 * TODO: Finish the code.
 */
Tab* Browser::get_tab(int id) {
	bool found=false;
	Tab* tab;

	//Find the tab.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------

	if (!found) {
		cout << "Browser:    Cannot find this tab, something must be wrong!" << endl;
		return nullptr;
	}

	cout << "Browser:    Find Tab_" << id << endl;
	return tab;
}
