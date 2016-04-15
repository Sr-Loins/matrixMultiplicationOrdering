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
#include <vector>
using namespace std;

int findMinCost(vector<int>& m, int size)
//function finds the minimum cost of matrix multiplications
{
	const int n = 10;
	int bigM[n][n]; //represents the 2d nxn table



}

int main()
//main function of program
//connects to input file and populates array a with input from matrix.txt


{
	std::vector<int> m; //declare a vector
	m.reserve(10); //make room for 10 elements
	//int m[11]; //declare an array of size 11. 11 is the max size of the array
	int n; //this will be the array elements from the input file
	int i = 0; // array index varriable

	//access datafile and read in elements, eliments in datafile are on seperate lines
	ifstream in_stream;
	in_stream.open("matrix.txt");
	if (in_stream.fail())
	{
		cout << "Error: unable to find input file";  //error message
		exit(1);  //exits the program
	}//end if

	while (in_stream >> n) //fill in the array
	{
		m.push_back(int(n));
		//i++;
		//m[i++] = n;
	}

	//read the file – see below
	in_stream.close();
	findMinCost(m, m.size()); //pass vector and size to findMinCost

	/* will need this to output the results
	ofstream out_stream;
	out_stream.open("peak.txt", ios::app);
	if (out_stream.fail())
	{
		cout << "Error: unable to find output file"; //error message
		exit(1); //exit the program
	}//end if
	out_stream << "the peak value is, " << p;
	*/
	return 0;

}