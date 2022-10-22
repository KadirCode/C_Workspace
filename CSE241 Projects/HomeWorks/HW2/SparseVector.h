#ifndef _SPARSEVECTOR_H
#define _SPARSEVECTOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct vectorElement
{
    int index;
    double data;    
};


class SparseVector
{
private:
    vector<vectorElement> vData;
    int size;
public:
    SparseVector(string fileName);  //constructor with parameter
    SparseVector(); //default constructor

    SparseVector & operator=(const SparseVector&rhs);   //overload assignment operator
    SparseVector & operator+(const SparseVector&);
    SparseVector & operator-(); //negate overload
    SparseVector & operator-(const SparseVector&); // subtrack overload

    friend ostream& operator<<(ostream& os, const SparseVector& vData);

    friend double dot(const SparseVector&,const SparseVector&);

    int MySize() const;
    void setSize(const int newSize);

    vector<vectorElement> myData() const;
    void setData(vector<vectorElement> newData);

};


#endif