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
#include <string>
using namespace std;

void printParin(ofstream &out_stream, int kArray[10][10], int i, int j)
{

	if (i == j)
	{
		out_stream << "A"<<i<<" ";
	}
	else
	{
		out_stream << "(";
		printParin(out_stream, kArray, i, kArray[i][j]);
		printParin(out_stream, kArray, kArray[i][j] + 1, j);
		out_stream << ")";
	}
	
}

int findMinCost(const int m[], int n)
//function finds the minimum cost of matrix multiplications by traversing the 
{
	//int size = m.size();
	int min; // setting it to 0 for now to make sure it builds, need to change
	//int n = size; //n to match up with the algorithm shown in lecture
	int j = 0; //to track columns
	int k = 0; //track index of m
	//int bigM[n][n]; //represents the 2d nxn table
	//std::vector< std::vector<int> > bigM; //represents the 2d nxn table
	//bigM.resize(size, vector<int>(size));
	int bigM[10][10]; //represents the 2d nxn table
	int kArray[10][10]; // array that holds the k split value
	for (int i = 0; i <= n; i++)//set the first row and first column to 0
	{
		bigM[i][0] = 0;
		bigM[0][i] = 0;
	}
	for (int md = 0; md < n; md++) //declaired md for "main diagonal"
	{
		bigM[md][md] = 0; //set the main diagonal to all 0
	}//end i for
	for (int d = 1; d < n - 1; d++) //d tracks current diagonal
	{
		for (int i = 1; i < n - d; i++) //i tracks teh current row
		{
			j = i + d; //column on the diagonal
			bigM[i][j] = 10000000; //innitialize the position to some big base value so I don't have a mem addr here
			for (k = i; k < j; k++) //calculate the minimum matrix cost for matrix at bigM[i][j]
			{
				/*
				if (i == 0)
				{
					k, i = 1;
				}//end if
				*/
				min = bigM[i][k] + bigM[k + 1][j] + m[i - 1] * m[k] * m[j];
				if (min < bigM[i][j])//assign the min operation cost to bigM[i][j]
				{
					bigM[i][j] = min;
					kArray[i][j] = k;
				}//end if
			}//end k for
		}//end i for
	}//end d for 
	min = bigM[1][n - 1];
	ofstream out_stream;
	out_stream.open("matrix.txt", ios::app);
	if (out_stream.fail())
	{
		cout << "Error: unable to find output file"; //error message
		exit(1); //exit the program
	}//end if
	printParin(out_stream, kArray, 1, n - 1);
	out_stream << endl; 
	out_stream.close();
	return min;
}

int main()
//main function of program
//connects to input file and populates array a with input from matrix.txt


{
	//std::vector<int> m; //declare a vector
	//m.reserve(10); //make room for 10 elements
	int m[10]; //declare an array of size 10. 10 is the max size of the array
	string matrix[10]; // array of the matrix symbols
	//char symbol;
	//string line;
	int n; //this will be the array elements from the input file
	int i = 0; // array index varriable
	int p = 0; // matrix array index varriable
	int size = 0; //keeps track of the size of the array
	int min = 0;
	//int kArray[10][10]; //keeps track of k value
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

		//m.push_back(int(n));
		
		m[i] = n;
		i++;
	}
	//p = i;
/*	
	while ( getline (in_stream, line))
	{
		//in_stream.get(symbol);
		matrix[p] = line;
		p++;
		//in_stream.get(symbol);
		//p++;
	}
	*/
	//cout << m.size();//debugging just to see what the size of the vector is
	//read the file � see below
	in_stream.close();
	//size = i;
	min = findMinCost(m, i); //pass array and size to findMinCost

	
	ofstream out_stream;
	out_stream.open("matrix.txt", ios::app);
	if (out_stream.fail())
	{
		cout << "Error: unable to find output file"; //error message
		exit(1); //exit the program
	}//end if
	out_stream << "the peak value is, " << min;
	out_stream.close();
	return 0;

}