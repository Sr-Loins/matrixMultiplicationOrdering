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
//function finds the minimum cost of matrix multiplications by traversing the 
{
	int min = 0; // setting it to 0 for now to make sure it builds, need to change
	int n = size - 1; //n to match up with the algorithm shown in lecture
	int j = 0; //to track columns
	int k = 0; //track index of m
	//int bigM[n][n]; //represents the 2d nxn table
	std::vector< std::vector<int> > bigM; //represents the 2d nxn table
	
	for (int md = 0; md <= n; md++) //declaired md for "main diagonal"
	{
		bigM[md][md] = 0; //set the main diagonal to all 0
	}//end i for
	for (int d = 1; d <= n - 1; d++) //d tracks current diagonal
	{
		for (int i = 0; i <= n - d; i++) //i tracks teh current row
		{
			j = i + d; //column on the diagonal
			for (k = i; k < j; k++) //calculate the minimum matrix cost for matrix at bigM[i][j]
			{
				min = bigM[i][k] + bigM[k + 1][j] + m[i - 1] * m[k] * m[j];
				if (min < bigM[i][j])//assign the min operation cost to bigM[i][j]
				{
					bigM[i][j] = min;
				}//end if
			}//end k for
		}//end i for
	}//end d for 

	return bigM[0][n];
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