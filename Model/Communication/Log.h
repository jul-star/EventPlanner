#pragma once
#include <string>
#include <vector>

using namespace std;

namespace EP {
    namespace MD {
class Log
{
    friend class Proxy; // ::ClearLog();
public:
    Log();
    void Add(string inMessage);
protected:
    void Clear();
    vector<string>* LogGet(){return &vLog; }

private:
    vector <string> vLog;

};

    }}
