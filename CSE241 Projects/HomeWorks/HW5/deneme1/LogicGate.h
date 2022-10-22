#ifndef __LOGICGATE_H__
#define __LOGICGATE_H__

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//----------------- Base Class ----------------------
class LogicGate
{
protected:
    string output;
    int result;
public:
    LogicGate();
    LogicGate(string newout)
    {
        output = newout;
        result = 0;
    };

    string getOutput(){return output;}



    virtual bool eval(){};  //prototipe
    void setResult(int newResult){
        result = newResult;
    };
   
};



//----------------- Binary Gate ----------------------
class BinaryGate : public LogicGate {

protected:
    string inA;
    string inB;
    LogicGate* in1;
    LogicGate* in2;

public:
    BinaryGate(string newout) : LogicGate(newout) {
        in1 = NULL;
        in2 = NULL;
    };



        
};

//  And Gate 
class andGate : public BinaryGate {
public:
    andGate(string newout, string input1, string input2, LogicGate* newin1, LogicGate* newin2) : BinaryGate(newout) {
        //local variables
        inA = input1;
        inB = input2;

        //pointers
        in1 = newin1;
        in2 = newin2;
    };

    bool eval()
    {
        bool a1;
        bool a2;
        bool d1;

        a1 = in1->eval();
        a2 = in2->eval();
        
        d1 = a1 & a2;
        //calculate d1 (output1)
        return d1;
    }
    

};

// Or Gate
class orGate : public BinaryGate {
public:
    orGate(string newout, string input1, string input2, LogicGate* newin1, LogicGate* newin2) : BinaryGate(newout) {
        //local variables
        inA = input1;
        inB = input2;

        //pointers
        in1 = newin1;
        in2 = newin2;
    };

    bool eval()
    {
        bool a1;
        bool a2;
        bool d1;

        a1 = in1->eval();
        a2 = in2->eval();
        
        d1 = a1 | a2;
        //calculate d1 (output1)
        return d1;
    }

};



// DECODER gate
class decoGate : public BinaryGate {
    private:
        bool out1, out2, out3, out4;
        string strResult;
    public:
    decoGate(string newout1, string newout2, string newout3, string newout4, string input1, string input2, LogicGate* newin1, LogicGate* newin2) : BinaryGate("decoder") {
        //local variables
        inA = input1;
        inB = input2;
        strResult = "";
               
        //pointers
        in1 = newin1;
        in2 = newin2; 

    };

    bool eval()
    {
        bool a1;
        bool a2;
        bool d1,d2,d3,d4;


        a1 = in1->eval();
        a2 = in2->eval();
        
        if(a1 == 0 && a2 == 0)
        {
            d1 = 1;
            strResult.push_back('1');
            strResult.push_back(' ');
        }
        else
        {
            d1 = 0;
            strResult.push_back('0');
            strResult.push_back(' ');
        }
            
        if(a1 == 0 && a2 == 1)
        {
            d2 = 1;
            strResult.push_back('1');
            strResult.push_back(' ');
        }
        else
        {
            d2 = 0;
            strResult.push_back('0');
            strResult.push_back(' ');
        }
            
        if(a1 == 1 && a2 == 0)
        {
            d3 = 1;
            strResult.push_back('1');
            strResult.push_back(' ');
        }
        else
        {
            d3 = 0;
            strResult.push_back('0');
            strResult.push_back(' ');
        }
            
        if(a1 == 1 && a2 == 1)
        {
            d4 = 1;
            strResult.push_back('1');
            strResult.push_back(' ');
        }
        else
        {
            d4 = 0;
            strResult.push_back('0');
            strResult.push_back(' ');
        }
        strResult.push_back('\n');

        std::ofstream out("output.txt");
        out << strResult;
        out.close();
 
        return true;
    }



    
};


//----------------- Unary Gate ----------------------
class UnaryGate : public LogicGate {

protected:
    string in;
    LogicGate * inP;

public:
    UnaryGate(string newout) : LogicGate(newout) {
        inP = NULL;
    };
 

};

class notGate : public UnaryGate {
public:
    notGate(string newout, string input, LogicGate* newin) : UnaryGate(newout) {
        in = input;
        inP = newin;
    };

    bool eval()
    {
        bool a1;
        bool d1;

        a1 = inP->eval();
        
        d1 = !a1;
        //calculate d1 (output1)

        return d1;
    }   
};

// FLIPFLOP gate
class ffGate : public UnaryGate {
    private:
        static int currentState;
    public:
    ffGate(string newout, string input, LogicGate* newin) : UnaryGate(newout) {
        in = input;
        inP = newin;
        currentState = 0;
    };
    bool eval()
    {
        bool a1;
        bool d1;

        a1 = inP->eval();
        
        d1 = a1 ^ currentState;
        //calculate d1 (output1)

        currentState = d1;
        return d1;
    }
};

int ffGate::currentState = 0;

// Input Gate
class inputGate : public UnaryGate {
public:
    inputGate(string newout) : UnaryGate(newout) {};

    bool eval() {
        return result;
    }
    
};

// Output Gate
class outputGate : public UnaryGate {
public:
    outputGate(string newout) : UnaryGate(newout) {};
    
    bool eval() {
        return result;
    }

};



#endif
