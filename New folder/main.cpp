#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "LogicGate.h"


using namespace std;

LogicGate* findGate(LogicGate**gates, string gateName, int gate_count)  //find the desired gate in gates array and return its address
{
    for(int i = 0; i < gate_count; i++)
    {
        if(gates[i]->getOutput() == gateName)
            return gates[i];        
    }
    return NULL;
}

int main() {

    ifstream fileC;
    string fileNameC = "circuit.txt";
    fileC.open(fileNameC.c_str());

    

    int gate_count = 0, inputCount = 0, outputCount = 0;

    string line,classType,subline,label;

    
    
    //read circuit file to get gate count
    while(getline(fileC,line))
    {
        classType = line.substr(0,line.find(' '));  //get the label part from line
        line = line.substr(line.find(' ')); //delete the label part from line

        if (classType == "INPUT")
        {
            istringstream iss(line);    //loop through words
            while(iss >> subline)
            {
                gate_count++;
                inputCount++;
            }
        } 
        else if (classType == "OUTPUT")
        {
            istringstream iss(line);    //loop through words
            while(iss >> subline)
            {
                gate_count++;
                outputCount++;
            }
        }               
        else{
            gate_count++;
        }                       
    }


    //---------------------------------------SECOND ITERATION------------------------------------------


    fileC.clear();
    fileC.seekg(0); //get cursor to start


    LogicGate ** gates = new LogicGate*[gate_count];

    int gateCounter = 0;

    while(getline(fileC,line))
    {
        classType = line.substr(0,line.find(' '));  //get the label part from line
        line = line.substr(line.find(' ')); //delete the label part from line

        if (classType == "INPUT")
        {
            istringstream iss(line);    //loop through words
            while(iss >> subline)
            {
                gates[gateCounter++] = new inputGate(subline);    //put inputs to first places
            }
            gateCounter += outputCount;
        } 
        else if (classType == "OUTPUT")
        {
            istringstream iss(line);    //loop through words
            while(iss >> subline)
            {              
                gates[inputCount++] = new outputGate(subline);    //put inputs to first places
            }
        }
        else if (classType == "AND")
        {
            istringstream iss(line);    //loop through words
            string output, input1, input2;
            iss >> output >> input1 >> input2;

            //find the desired gates to connect
            LogicGate* inputP1 = findGate(gates,input1,gate_count); 
            LogicGate* inputP2 = findGate(gates,input2,gate_count);
            gates[gateCounter++] = new andGate(output,input1,input2,inputP1,inputP2);
            
        }
        else if (classType == "OR")
        {
            istringstream iss(line);    //loop through words
            string output, input1, input2;
            iss >> output >> input1 >> input2;

            //find the desired gates to connect
            LogicGate* inputP1 = findGate(gates,input1,gate_count); 
            LogicGate* inputP2 = findGate(gates,input2,gate_count);
            gates[gateCounter++] = new orGate(output,input1,input2,inputP1,inputP2);
        }
        else if (classType == "NOT")
        {
            istringstream iss(line);    //loop through words
            string output, input;
            iss >> output >> input;

            //find the desired gates to connect
            LogicGate* inputP = findGate(gates,input,gate_count);
            gates[gateCounter++] = new notGate(output,input,inputP);
        }
        else if (classType == "FLIPFLOP")
        {
            istringstream iss(line);    //loop through words
            string output, input;
            iss >> output >> input;

            //find the desired gates to connect
            LogicGate* inputP = findGate(gates,input,gate_count);
            gates[gateCounter++] = new ffGate(output,input,inputP);
        }                         
        else if(classType == "DECODER")
        {
            istringstream iss(line);    //loop through words
            string output1, output2, output3, output4, input1, input2;
            iss >> output1 >> output2 >> output3 >> output4 >> input1 >> input2;

            //find the desired gates to connect
            LogicGate* inputP1 = findGate(gates,input1,gate_count); 
            LogicGate* inputP2 = findGate(gates,input2,gate_count);
            gates[gateCounter++] = new decoGate(output1, output2, output3, output4, input1,input2,inputP1,inputP2);
        }             
    }

    ifstream fileIn;
    string fileNameIn = "input.txt";
    fileIn.open(fileNameIn.c_str());

    string inputLine, subInLine;

    while(getline(fileIn,inputLine))
    {
        istringstream iss(inputLine);    //loop through words
        string strInput;
        for (int i = 0; i < inputCount-outputCount; i++)    //get the input values and put them in our inputGate objects as integers
        {
            iss >> strInput;
            gates[i]->setResult(stoi(strInput));

        }

        gates[gate_count-1]->eval();


    }


    return 0;
}