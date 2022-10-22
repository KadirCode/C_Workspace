#include <iostream>
#include <fstream>
#include <string>
#include "SparseVector.h"
#include "SparseMatrix.h"



using namespace std;

int main()
{

ofstream outfile;

outfile.open("output.txt", ios::out | ios::trunc );

//Creating a SparseVector from file
SparseVector a1("a1.txt");

outfile << "a1" << endl << a1 <<endl;

//Binary operations and assignment
a1 = a1 + a1;

outfile << "a1" << endl << a1 <<endl;

//outfile << "-a1" << endl << -a1 <<endl;

//a1 = a1 - a1;

outfile << "a1" << endl << a1 <<endl;

outfile << "dot is: " << dot(a1,a1) <<endl;

SparseMatrix m1("m1.txt");

outfile << m1 << endl;

return 0;

}