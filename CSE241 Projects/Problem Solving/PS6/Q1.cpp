#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class DynamicStringArray
{
private:
    string *dynamicArray;
    int size;
public:
    DynamicStringArray();
    DynamicStringArray(const DynamicStringArray& otherObj);
    ~DynamicStringArray();
    DynamicStringArray& operator=(const DynamicStringArray& rightSide);
    void addEntry(string newEntry);
    bool deleteEntry(string newEntry);
    string getEntry(int index);
    int getSize();
};

DynamicStringArray::DynamicStringArray()
{
    dynamicArray = NULL;
    size = 0;
}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& otherObj)
{
    size = otherObj.size;
    if(size == 0)
    {
        dynamicArray = NULL;
    }
    else{
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++)
        {
            dynamicArray[i] = otherObj.dynamicArray[i];
        }
    }
}

DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& rightSide)
{
    if(dynamicArray != NULL)
    {
        delete[] dynamicArray;
    }
    if(rightSide.size == 0)
    {
        size = 0;
        dynamicArray = NULL;
    }
    else
    {
        size = rightSide.size;
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++)
        {
            dynamicArray[i] = rightSide.dynamicArray[i];
        }
        
    }
    return *this;
}

DynamicStringArray::~DynamicStringArray()
{
    if(dynamicArray != NULL)
        delete[] dynamicArray; 
}

int DynamicStringArray::getSize()
{
    return size;
}

void DynamicStringArray::addEntry(string newEntry)
{
    string *newArray = new string[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = dynamicArray[i];
    }
    delete[] dynamicArray;
    dynamicArray = newArray;
    newArray[size++] = newEntry;
}

bool DynamicStringArray::deleteEntry(string entry)
{
    string *result = NULL;
    int pos = -1;

    for(int i = 0; (i < size) && (pos == -1); i++)
    {
        if(dynamicArray[i] == entry)
            pos = i;
    }
    if(pos == -1)
        return false;

    if(size > 1)
        result = new string[size -1];
    
    for(int i = 0, j = 0; i < size; i++)
    {
        if(i != pos)
            result[j++] = dynamicArray[i];
    }
    size--;
    delete[] dynamicArray;
    dynamicArray = result;

    return true;
}

string DynamicStringArray::getEntry(int index)
{
    if((index < 0) || (index >= size))
        return NULL;
    return dynamicArray[index];
}

int main()
{
    DynamicStringArray names;
    // List of names
    names.addEntry("Ahmet");
    names.addEntry("Abdulrezzak");
    names.addEntry("Ayse");
    names.addEntry("Fatma");
    names.addEntry("Hayriye");

    // Output list
    cout << "List of names:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;

    cout << endl;

    // Add and remove some names
    names.addEntry("Mustafa");
    cout << "After adding a name:" << endl;

    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Fatma");
    cout << "After removing a name:" << endl;

    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.deleteEntry("Skinner");
    cout << "After removing a name that isn't on the list:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.addEntry("Emre");
    cout << "After adding another name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    
    // Remove all of the names by repeatedly deleting the last one
    while(names.getSize() > 0) 
    {
        names.deleteEntry(names.getEntry(names.getSize() - 1));
    }
    cout << "After removing all of the names:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    names.addEntry("Fuat");
    cout << "After adding a name:" << endl;
    for(int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;
    cout << "Testing copy constructor" << endl;
    DynamicStringArray names2(names);
    // Remove Burns from names
    names.deleteEntry("Emre");
    cout << "Copied names:" << endl;
    for(int i = 0; i < names2.getSize(); i++)
        cout << names2.getEntry(i) << endl;
    cout << endl;
    cout << "Testing assignment" << endl;
    DynamicStringArray names3 = names2;
    // Remove Burns from names2
    names2.deleteEntry("Emre");
    cout << "Copied names:" << endl;
    for(int i = 0; i < names3.getSize(); i++)
        cout << names3.getEntry(i) << endl;
    cout << endl;
    cout << "Enter a character to exit." << endl;
    char wait;
    cin >> wait;

    return 0;
    }



