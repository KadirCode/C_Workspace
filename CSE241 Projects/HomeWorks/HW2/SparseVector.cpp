#include <iostream>
#include "SparseVector.h"

SparseVector::SparseVector()
{
    size = 0;
    vectorElement tmp;
    tmp.data = 0;
    tmp.index = 0;

    vData.push_back(tmp);

}

SparseVector::SparseVector(string fileName)
{
    ifstream file;
    file.open(fileName.c_str());

    string line;
    int colonIdx;
    int counter = 0;
    vector<vectorElement> tmp;

    while(file >> line)
    {
        colonIdx = line.find(':');

        tmp.push_back(vectorElement()); //push.back new vector element with default constructor

        tmp[counter].index = stoi(line.substr(0,colonIdx)); //index is part before ':' and transform string to int
        tmp[counter].data = stod(line.substr(colonIdx+1,line.find(' ')));    //data is after ':' and before next ' '    and transform string to double
        counter++;  //increment counter for vector index
        line = line.substr(0,line.find(' '));   //delete first data part from main string
    }

    vData = tmp; //initialize out data
    size = vData.size();

    file.close();

}

SparseVector& SparseVector::operator+(const SparseVector & rhs)
{
    vector<vectorElement> tmp;

    int rhsIdx = 0;
    int lhsIdx = 0;

    bool lhsEnd = false;
    bool rhsEnd = false;

    vectorElement newElement;
    
    while(true)
    {
        if(lhsIdx == size)
            lhsEnd = true;

        if(rhsIdx == rhs.size)
            rhsEnd = true;

        if(lhsEnd && rhsEnd)
            break;

        if(vData[lhsIdx].index == rhs.vData[rhsIdx].index) //if current indexes are identical, sum them up and add them to new vector as new element.
        {
            newElement.data = vData[lhsIdx].data + rhs.vData[rhsIdx].data;  // add the values and add them to new element
            newElement.index = vData[lhsIdx].index; //index is identical with lhs and rhs so it doesn't matter which one we are adding to new element
            rhsIdx++;   //go to next index for lhs and rhs
            lhsIdx++;
        }
        else    //if the current indexes are not identical, add the index and data from lower index to new vector.
        {
            //add the value and index of the minimum of lhs and rhs to the newElement
            if(vData[lhsIdx].index < rhs.vData[rhsIdx].index && !lhsEnd) 
            {
                newElement.index = vData[lhsIdx].index;
                newElement.data = vData[lhsIdx].data;
                lhsIdx++;
            }

            if(vData[lhsIdx].index > rhs.vData[rhsIdx].index && !rhsEnd)
            {
                newElement.index = rhs.vData[rhsIdx].index;
                newElement.data = rhs.vData[rhsIdx].data;
                rhsIdx++;
            }           
        }

        tmp.push_back(newElement);    //push back to tmp vector
    }

    SparseVector q;
    q.vData = tmp;
    q.size = tmp.size();
    *this = q;
    return *this;
}

SparseVector& SparseVector::operator=(const SparseVector & rhs)
{
    if(this != &rhs)    //Checks for self-assignment
    {   
        vData.clear();  //clear the data within lhs

        size = rhs.size;    //assign rhs size to lhs size
        for(int i = 0; i < rhs.size ;i++)
        {
            vData[i].data = rhs.vData[i].data;  //copy all data from rhs to lhs
        }
    }

    return *this;   //return lhs

}

ostream& operator <<(ostream& os, const SparseVector& rhs)
{
    for(int i = 0; i < rhs.size; i++)
    {
        os << rhs.vData[i].index << ":" << rhs.vData[i].data << " ";
    }
    return os;
}

SparseVector& SparseVector::operator-() //negate overload
{
    for(int i = 0; i < size; i++)
    {
        vData[i].data = -vData[i].data;
    }
    return *this;
}

SparseVector& SparseVector::operator-(const SparseVector & rhs) //subtract overload
{
    vector<vectorElement> tmp;

    int rhsIdx = 0;
    int lhsIdx = 0;

    bool lhsEnd = false;
    bool rhsEnd = false;

    vectorElement newElement;
    
    while(true)
    {
        if(lhsIdx == size)
            lhsEnd = true;

        if(rhsIdx == rhs.size)
            rhsEnd = true;

        if(lhsEnd && rhsEnd)
            break;

        if(vData[lhsIdx].index == rhs.vData[rhsIdx].index) //if current indexes are identical, subtract them to new vector as new element.
        {
            newElement.data = vData[lhsIdx].data - rhs.vData[rhsIdx].data;  // add the values and add them to new element
            newElement.index = vData[lhsIdx].index; //index is identical with lhs and rhs so it doesn't matter which one we are adding to new element
            rhsIdx++;   //go to next index for lhs and rhs
            lhsIdx++;
        }
        else    //if the current indexes are not identical, add the index and data from lower index to new vector.
        {
            //add the value and index of the minimum of lhs and rhs to the newElement
            if(vData[lhsIdx].index < rhs.vData[rhsIdx].index && !lhsEnd) 
            {
                newElement.index = vData[lhsIdx].index;
                newElement.data = vData[lhsIdx].data;
                lhsIdx++;
            }

            if(vData[lhsIdx].index > rhs.vData[rhsIdx].index && !rhsEnd)
            {
                newElement.index = rhs.vData[rhsIdx].index;
                newElement.data = -rhs.vData[rhsIdx].data;  //add the negative of rhs since 0-<integer> = -<integer>
                rhsIdx++;
            }           
        }

        tmp.push_back(newElement);    //push back to tmp vector
    }

    SparseVector q;
    q.vData = tmp;
    q.size = tmp.size();
    *this = q;
    return *this;
}

double dot(const SparseVector & lhs, const SparseVector & rhs)
{
    vector<vectorElement> tmp;

    int rhsIdx = 0;
    int lhsIdx = 0;

    double result = 0;

    bool lhsEnd = false;
    bool rhsEnd = false;

    
    while(true)
    {
        if(lhsIdx == lhs.size)
            lhsEnd = true;

        if(rhsIdx == rhs.size)
            rhsEnd = true;

        if(lhsEnd && rhsEnd)
            break;

        if(lhs.vData[lhsIdx].index == rhs.vData[rhsIdx].index) //if current indexes are identical, do dot operation
        {
            result += lhs.vData[lhsIdx].data * rhs.vData[rhsIdx].data;  // multiplicate datas and add it to result
            rhsIdx++;   //go to next index for lhs and rhs
            lhsIdx++;
        }
        else    //if the current indexes are not identical, do nothing since 0*<double> = 0
        {
            //go to next index for whichever vectors data index is smaller
            if(lhs.vData[lhsIdx].index < rhs.vData[rhsIdx].index && !lhsEnd) 
            {
                lhsIdx++;
            }

            if(lhs.vData[lhsIdx].index > rhs.vData[rhsIdx].index && !rhsEnd)
            {
                rhsIdx++;
            }           
        }

    }
    
    return result;

}


int SparseVector::MySize() const
{
    return size;
}

vector<vectorElement> SparseVector::myData() const
{
    return vData;
}

void SparseVector::setSize(const int newSize)
{
    size = newSize;
}

void SparseVector::setData(vector<vectorElement> newData)
{
    vData = newData;
}