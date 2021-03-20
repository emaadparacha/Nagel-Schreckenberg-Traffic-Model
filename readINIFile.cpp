/**
 * @file readINIFile.cpp
 * @brief Functions that read a given .ini file. "readINIints" reads the .ini file at the specific path and 
 * returns integers given a string that defines the section and variable name as in the .ini file. 
 * "readINIdouble" reads the .ini file at the specific path and returns the double stored in variable "p".
 * "readINIstring" reads the .ini file at the specific path and returns the string stored in variable "outputfilename".
 * @author Emaad Paracha
 */

//Dependencies
#include "readINIFile.h"

//Namespaces
using namespace std;

/**
 * Reads the .ini file at the specific path and returns integers given a string that defines the section and variable name as in the .ini file. 
 *
 * @param inipath Path of .ini file
 * @param intstring String that defines the section and variable name of the integer as in the .ini file
 */
int readINIints(string inipath, string intstring)
{
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini(inipath, pt); //Initialize ini file reader

    int specificInt = pt.get<int>(intstring); //Get specific integer given the variable name from ini file
    return specificInt;                       //Return that specific integer
}

/**
 * Reads the .ini file at the specific path and returns the double stored in variable "p".
 *
 * @param inipath Path of .ini file
 */
double readINIdouble(string inipath)
{
    boost::property_tree::ptree ptdouble;
    boost::property_tree::ini_parser::read_ini(inipath, ptdouble); //Initialize ini file reader

    double prob = ptdouble.get<double>("Parameters.p"); //Get probability of slowing down
    return prob;                                        //Return probability
}

/**
 * Reads the .ini file at the specific path and returns the string stored in variable "outputfilename".
 *
 * @param inipath Path of .ini file
 */
string readINIstring(string inipath)
{
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini(inipath, pt); //Initialize ini file reader

    string filename = pt.get<string>("Parameters.outputfilename"); //Get output filename
    return filename;                                               //Return filename
}