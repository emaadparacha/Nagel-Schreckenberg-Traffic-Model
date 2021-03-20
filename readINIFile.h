/**
 * @file readINIFile.h
 * @brief Functions that read a given .ini file. "readINIints" reads the .ini file at the specific path and 
 * returns integers given a string that defines the section and variable name as in the .ini file. 
 * "readINIdouble" reads the .ini file at the specific path and returns the double stored in variable "p".
 * "readINIstring" reads the .ini file at the specific path and returns the string stored in variable "outputfilename".
 * @author Emaad Paracha
 */


#ifndef READINIFILE_H
#define READINIFILE_H

//Dependencies
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

//Namespaces
using namespace std;

/**
 * Reads the .ini file at the specific path and returns integers given a string that defines the section and variable name as in the .ini file. 
 *
 * @param inipath Path of .ini file
 * @param intstring String that defines the section and variable name of the integer as in the .ini file
 */
int readINIints(string inipath, string intstring);

/**
 * Reads the .ini file at the specific path and returns the double stored in variable "p".
 *
 * @param inipath Path of .ini file
 */
double readINIdouble(string inipath);

/**
 * Reads the .ini file at the specific path and returns the string stored in variable "outputfilename".
 *
 * @param inipath Path of .ini file
 */
string readINIstring(string inipath);

#endif