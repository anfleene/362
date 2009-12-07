#ifndef UTILITY_H
#define UTILITY_H

/**
**NAME: Andrew Fleener
**Course: CSCI 362
**Assignment: Program 1
**Class: utility
**Description: This is the interface for the utility class
**/
//Gives ANSI version of standard includes
//Also defines enumerated type for error
//messages 

#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <ctime>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <list>
#include <stack>

using namespace std;


enum Error_code { success, fail, exceeds_range, 
not_present, duplicate_error, underflow, overflow };

#endif //UTILITY_H
// 
// ostream& operator << (ostream &stream, Error_code e){
// 	string error;
// 	switch(e){
// 		case success:
// 			error = "success";
// 			break;
// 		case fail:
// 			error = "fail";
// 			break;
// 		case exceeds_range:
// 			error = "exceeds range";
// 			break;
// 		case not_present:
// 			error = "not present";
// 			break;
// 		case duplicate_error:
// 			error = "duplicate error";
// 			break;
// 		case underflow:
// 			error = "underflow";
// 			break;
// 		case overflow:
// 			error = "overflow";
// 			break;
// 		default:
// 			error = "unknown";
// 	}
// 	
// 	stream << error;
// 	return stream;
// }