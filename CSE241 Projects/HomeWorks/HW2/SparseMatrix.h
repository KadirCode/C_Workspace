#ifndef _SPARSEMATRIX_H
#define _SPARSEMATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "SparseVector.h"

using namespace std;

struct matrixElement
{
    int row;
    SparseVector rData;    
};


class SparseMatrix
{
private:
    vector<matrixElement> mData;
    int rowCount;
public:
    SparseMatrix(string fileName);  //constructor with parameter
    SparseMatrix(); //default constructor

    SparseMatrix & operator=(const SparseMatrix&rhs);   //overload assignment operator
    //SparseMatrix & operator+(const SparseMatrix&);
    //SparseMatrix & operator-(); //negate overload
    //SparseMatrix & operator-(const SparseMatrix&); // subtrack overload

    friend ostream& operator<<(ostream& os, const SparseMatrix& mData);

    vector<vectorElement> myDataMat(int index) const;

};


#endif