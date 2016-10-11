#pragma  once
#include <map>
#include <string>

#include <Model/Constants.h>
#include <Model/Context/TemplateMethodMap.hpp>
#include <Model/Items/Hall/Hall.h>



using namespace std;

namespace EP {
    namespace MD {



class Halls:public TemplateMethodMap<Hall>
{
public:
    typedef map<unsigned, Hall*> pHallMap;
    typedef map<unsigned, Hall> HallMap;
    Halls(Log* inLog);
    virtual ~Halls(){}
private:
    void Setup(Log* inLog);
};

    }}
