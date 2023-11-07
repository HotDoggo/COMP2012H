/** 
 * @file parse.tpp
 *
 * @brief Template functions for parsing definitions.
 * 
 * This file defines: 
 *   1. a template function parse to parse a string into an expression of Expr.
 *   2. a template function parse_term to parse a string into an term of Expr.
 *   3. a template function parse_factor to parse a string into an factor of Expr.
 *   4. a template function parse_primary to parse a string into an primary of Expr.
 *   5. a template function parse_literal to parse a string into an literal of Expr.
 *   
 */


/**
 * Parse str into an expression of type T.
 * Check if trimmed str is a string of an expression of type T.
 * Construct the corresponding Expr<T> and return its address if so.
 * Return nullptr otherwise.
 * 
 * Rules for a string of an expression of type T:
 *   1. A string of term of type T is a string of an expression of type T.
 *   2. A string of expression of type T + "+"/"-" +  a string of an expression of type T 
 *        is a string of an expression of type T. It means applying add/sub to them in order.
 *   3. Otherwise it is not.
 * 
 * Remember add and sub are left-to-right associative in the context of this file.
 */
template <typename T>
Expr<T>* parse(const string& str) {
	string trimmed_str = trim(str);
	Expr<T>* out;

	//Try rule 1:
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------

	//Try rule 2:
	//Remember add and sub are left-to-right associative in the context of this file.
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------

	//Rule 3:
	return nullptr;
}

/**
 * Parse str into a term of type T.
 * Check if trimmed str is a string of a term of type T.
 * Construct the corresponding Expr<T> and return its address if so.
 * Return the adderss of Expr<T> if success
 * Return nullptr otherwise.
 * 
 * Rules for a string of a term of type T:
 *   1. A string of factor of type T is a string of a term of type T.
 *   2. A string of term of type T + "*" or "/" +  a string of a term of type T 
 *        is a string of a term of type T. It means applying mul/div to them in order.
 *   3. Otherwise it is not.
 * 
 * Remember mul and div are left-to-right associative in the context of this file.
 *  
 */
template <typename T>
Expr<T>* parse_term(const string& str) {
	string trimmed_str = trim(str);
	Expr<T>* out;

	//Try rule 1:
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------

	//Try rule 2:
	//Remember mul and div are left-to-right associative in the context of this file.
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------

	//Rule 3:
	return nullptr;
}

/**
 * Parse str into a factor of type T.
 * Check if trimmed str is a string of a factor of type T.
 * Construct the corresponding Expr<T> and return its address if so.
 * Return nullptr otherwise.
 * 
 * Rules for a string of a factor of type T:
 *   1. A string of primary is a string of a factor of type T.
 *   2. "+" or "-" + a string of a factor of type T 
 *        is a string of a factor of type T. It means applying pos/neg to it.
 *   3. Otherwise it is not.
 */
template <typename T>
Expr<T>* parse_factor(const string& str) {
	string trimmed_str = trim(str);
	Expr<T>* out;

	//Try rule 1:
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------

	//Try rule 2:
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------

	//Rule 3:
	return nullptr;
}

/**
 * Parse str into a primary of type T.
 * Check if trimmed str is a string of a primary of type T.
 * Construct the corresponding Expr<T> and return its address if so.
 * Return nullptr otherwise.
 * 
 * Rules for a string of a primary of type T:
 *   1. A string of literal is a string of a primary of type T.
 *   2. "(" + a string of an expression of type T + ")" 
 *        is a string of a primary of type T.
 *   3. Otherwise it is not.
 */
template <typename T>
Expr<T>* parse_primary(const string& str) {
	string trimmed_str = trim(str);
	Expr<T>* out;

	//Try rule 1:
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------
	
	//Try rule 2:
//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------

	
	//Rule 3:
	return nullptr;
}



/**
 * Parse str into a literal of type T.
 * Check if trimmed str is a string of a literal of type T.
 * Construct the corresponding LitExpr<T> and return its address if so.
 * Return nullptr otherwise.
 * 
 * A string of a literal of type T must be a string of type T.
 */
template <typename T>
Expr<T>* parse_literal(const string& str) {
	string trimmed_str = trim(str);

//================ TODO =================================================================

//Your Code Here


//---------------------------------------------------------------------------------------
	
	return nullptr;
}
