#pragma once
#include <string>
// #include <map>
#include <Model/Constants.h>

using namespace std;

namespace EP {
    namespace MD {
class Item
{
public:
    Item();
    Item(unsigned inID, string inName, int inVal);
    int getVal() { return vValue; }
    int getVal()const { return vValue; }
    void setVal(int inVal){vValue = inVal;}
    string getName(){return vName;}
    string getName()const{return vName;}
    void setName(string inName){ vName = inName; }
    unsigned ID() {return vID;}
    unsigned ID() const {return vID;}
private:
    unsigned vID{0};
    string vName{string()};
    int vValue{0};
};

 }}
