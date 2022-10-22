#include <iostream>
#include "SparseMatrix.h"


SparseMatrix::SparseMatrix()
{
    rowCount = 0;
    vectorElement tmp;
    tmp.data = 0;
    tmp.index = 0;
    SparseVector tempVector;

    tempVector.setSize(0);

    tempVector.myData().push_back(tmp);

}

SparseMatrix::SparseMatrix(string fileName)
{
    ifstream file;
    file.open(fileName.c_str());

    string line;
    int colonIdx;
    int counter = 0;
    int row;
    vector<vectorElement> tmp;

    matrixElement tempMatrixElement;

    vector<matrixElement> tempRow;

    SparseVector tmpSpars;

    rowCount = 0;

    string subLine;

    while(getline(file,line,'\n'))
    {

        row = stoi(line.substr(0,line.find(' ')));  //get first word and turn it into integer
        line = line.substr(line.find(' ')+1);   //remove first word and get to data part   

        tempMatrixElement.row = row;    //set row index to our temporary struct

        istringstream iss(line);
        
        while(iss >> subLine)
        {
            
            colonIdx = subLine.find(':');

            tmp.push_back(vectorElement()); //push.back new vector element with default constructor

            tmp[counter].index = stoi(subLine.substr(0,colonIdx)); //index is part before ':' and transform string to int
            subLine = subLine.substr(colonIdx+1);

            tmp[counter].data = stod(subLine);    //data is after ':' and before next ' '    and transform string to double

            counter++;  //increment counter for vector index
                       
        }

        tempMatrixElement.rData.setData(tmp);

        mData.push_back(tempMatrixElement);


        rowCount++;

        counter = 0;
        tmp.clear();
        tmp.shrink_to_fit();
        
    }


}

vector<vectorElement> SparseMatrix::myDataMat(int index) const
{
    return mData[index].rData.myData();
}

ostream& operator <<(ostream& os, const SparseMatrix& rhs)
{
    int vectorItemCount;

    for(int i = 0; i < rhs.rowCount; i++)
    {
        vectorItemCount = rhs.myDataMat(i).size();

        for(int y = 0; y < vectorItemCount ;y++)
        {
            os << i << " " << rhs.myDataMat(i).at(y).index << ":" << rhs.myDataMat(i).at(y).data;
        }
        os << endl;
    }
    return os;
}

SparseMatrix& SparseMatrix::operator=(const SparseMatrix & rhs)
{
    if(this != &rhs)    //Checks for self-assignment
    {   

        rowCount = rhs.rowCount;

        for(int i = 0; i < rowCount; i++)
        {
            mData[i].rData = rhs.mData[i].rData;
        }


    }

    return *this;   //return lhs

}

