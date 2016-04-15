/*******************************************************************
* Divide - and-Conquer Homework
* Programmer: Tyler S.Stinson
* Date : 10 - April - 2015
*
* CSCI 48400 Spring 2016       Instructor : Dr.Judy Gersting
* Description :
*Find the peak value in the array.
* Read the input values(i.e., the array values as a series of
* integers, one per line, from a text file called peak.txt
******************************************************************/
#include <iostream>
#include <fstream>
using namespace std;



int main()
//main function of program
//connects to input file and populates array a with input from matrix.txt

{

	ifstream in_stream;
	in_stream.open("peak.txt");
	if (in_stream.fail())
	{
		cout << "Error: unable to find input file";  //error message
		exit(1);  //exits the program
	}//end if

	while (in_stream >> n)
	{
		a[i++] = n;
	}

	//read the file – see below
	in_stream.close();

	p = peak(a, start, i - 1);
	ofstream out_stream;
	out_stream.open("peak.txt", ios::app);
	if (out_stream.fail())
	{
		cout << "Error: unable to find output file"; //error message
		exit(1); //exit the program
	}//end if
	out_stream << "the peak value is, " << p;

	return 0;

}