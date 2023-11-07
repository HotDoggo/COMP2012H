/**
 * @file tab.cpp
 * @brief Tab class member functions definitions
 *
 * This file defines following member functions of Browser:
 *   1. Tab::Tab:      the constructor.
 *   2. Tab::~Tab:     the denstructor.
 *   3. Tab::get_id:   return the id of tab.
 *   4. Tab::open:     open a new page.
 *   5. Tab::forward:  go to the next page opened after the current one.
 *   6. Tab::backward: go to the previous page opened before the current one.
 *
 *   TODO: You need to finish:
 *     1. Tab::Tab
 *     2. Tab::open
 *     3. Tab::forward
 *     4. Tab::backward
 */
#include "tab.h"
#include <string>

/**
 * Construct a tab with given id and initial url specified as init_url.
 */
Tab::Tab(int id, Url init_url) {
	string prefix = "Tab_" + to_string(id) + " Create:";
	cout << left << setw(20) << prefix << "Hello! The first page is \"" << init_url << "\"" << endl; 

	//Initialize
	//=========== TODO ===================================================

	//--------------------------------------------------------------------
}


Tab::~Tab() {
	string prefix = "Tab_" + to_string(id) + " Close:";
	cout << left << setw(20) << prefix << "Goodbye" << endl;
}


/**
 * Open url.
 * Check if already at site indicated by url, if so do nothing.
 * If not, open url.
 * Add url to your stack.
 *
 * TODO: Finish the code.
 * Remember: There is no way to go forward after you open a new url.
 */
void Tab::open(Url url) {
	string prefix = "Tab_" + to_string(id) + " Open:";
	bool already;
	//check if you already at url.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------

	if (already) {
		cout << left << setw(20) << prefix << "Already at \"" << url << "\"" << endl; 
		return;
	}
	cout << left << setw(20) << prefix << "Open \"" << url << "\"" << endl; 

	//Go to url.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------
}

/**
 * Go backward to the previous page.
 *
 * TODO: Finish the code.
 */
void Tab::backward() {
	string prefix = "Tab_" + to_string(id) + " Backward:";
	bool is_bottom;
	//Check if already at bottom of url stack.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------
	
	if (is_bottom) {
		cout << left << setw(20) << prefix << "No tabs for backward!" << endl; 
		return;
	}

	//Go previous one.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------
	cout << left << setw(20) << prefix << "Backward to \"" << *current_url << "\"" << endl; 
}

/**
 * Go forward to the next page.
 *
 * TODO: Finish the code.
 */
void Tab::forward() {
	string prefix = "Tab_" + to_string(id) + " Forward:";
	bool is_top;
	//Check if already at top of url stack.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------
	
	if (is_top) {
		cout << left << setw(20) << prefix << "No tabs for forward!" << endl; 
		return;
	}

	//Go next one.
	//=========== TODO ===================================================

	//--------------------------------------------------------------------
	cout << left << setw(20) << prefix << "Forward to \"" << *current_url << "\"" << endl; 
}

int Tab::get_id() const {
	return id;
}
