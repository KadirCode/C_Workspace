#include <iostream>
  #include <string>
  using namespace std;

  class LogicGate {
      public:
              LogicGate(string n){
                      label = n;
              }
              string getLabel(){
                      return label;
              }
              bool getOutput(){
                      output = performGateLogic();
                      return output;
              }
              virtual bool performGateLogic(){
                      cout << "ERROR! performGateLogic BASE" << endl;
                      return false;
              }

              virtual void setNextPin(bool source) {
                      cout << "ERROR! setNextPin BASE" << endl;
              }
      private:
              string label;
              bool output;
  };

  class BinaryGate : public LogicGate {
      public:
              BinaryGate(string n) : LogicGate(n) {
                      pinATaken = false;
                      pinBTaken = false;
              }
              bool getPinA() {
                      if (pinATaken == false) {
                              cout << "Enter Pin A input for gate " << getLabel() << ": ";
                              cin >> pinA;
                              pinATaken = true;
                      }
                      return pinA;
              }
              bool getPinB() {
                      if (pinBTaken == false) {
                              cout << "Enter Pin B input for gate " << getLabel() << ": ";
                              cin >> pinB;
                              pinBTaken = true;
                      }
                      return pinB;
              }
              virtual void setNextPin(bool source) {
                      if (pinATaken == false) {
                              pinA = source;
                              this->pinATaken = true;
                      }
                      else if (pinBTaken == false) {
                              pinB = source;
                              this->pinBTaken = true;
                      }
              }
      private:
              bool pinA, pinATaken, pinB, pinBTaken;
  };

  class UnaryGate : public LogicGate {
      public:
              UnaryGate(string n) : LogicGate(n) {
                      pinTaken = false;
              }
              bool getPin() {
                      if (pinTaken == false) {
                              cout << "Enter Pin input for gate " << getLabel() << ": ";
                              cin >> pin;
                              pinTaken = true;
                      }
                      return pin;
              }
              virtual void setNextPin(bool source) {
                      if (pinTaken == false) {
                              pin = source;
                              pinTaken = true;
                      }
                      else {
                              return;
                      }
              }
      private:
              bool pin, pinTaken;
  };

  class AndGate : public BinaryGate{
      public:
              AndGate(string n) : BinaryGate(n) {};

              virtual bool performGateLogic(){
                      bool a = getPinA();
                      bool b = getPinB();
                      if (a == 1 && b == 1) {
                              return true;
                      }
                      else {
                              return false;
                      }
              }
  };

  class OrGate : public BinaryGate {
      public:
              OrGate(string n) : BinaryGate(n) {};

              virtual bool performGateLogic() {
                      bool a = getPinA();
                      bool b = getPinB();
                      if (a == 1 || b == 1) {
                              return true;
                      }
                      else {
                              return false;
                      }
              }
  };

  class NotGate : public UnaryGate {
      public:
              NotGate(string n) : UnaryGate(n) {};

              virtual bool performGateLogic() {
                      if (getPin()) {
                              return false;
                      }
                      else {
                              return true;
                      }
              }
  };

  class Connector{
      public:
              Connector(LogicGate *fgate, LogicGate *tgate) {
                      fromgate = fgate;
                      togate = tgate;
                      tgate->setNextPin(fromgate->getOutput());
              }
              LogicGate *getFrom() {
                      return fromgate;
              }
              LogicGate *getTo() {
                      return togate;
              }
      private:
              LogicGate *fromgate, *togate;
  };

  int main() {
      char stopme;

      //Setting labels
      AndGate gand1(" AND1 ");
      AndGate gand2(" AND2 ");
      OrGate  gor3(" OR ");
      NotGate gnot4(" NOT ");

      // The inputs can be changed here!
      gand1.setNextPin(0);
      gand1.setNextPin(0);
      gand2.setNextPin(0);
      gand2.setNextPin(0);

      //making comnnections
      Connector c1(&gand1, &gor3);
      Connector c2(&gand2, &gor3);
      Connector c3(&gor3, &gnot4);

      // The output shows order of operators
      cout << gnot4.getLabel() << "(";
      cout << "(" << gand1.getPinA() << gand1.getLabel() << gand1.getPinB() << ")";
      cout << gor3.getLabel();
      cout << "(" << gand2.getPinA() << gand2.getLabel() << gand2.getPinB() << ")";
      cout << ") results in " << gnot4.getOutput() << endl;

      cin >> stopme; //holds open window under some conditions.
      return 0;
  }
