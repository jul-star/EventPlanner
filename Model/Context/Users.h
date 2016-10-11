#pragma  once
#include <map>
#include <string>

#include <Model/Constants.h>
#include <Model/Context/TemplateMethodMap.hpp>
#include <Model/Items/User/User.h>



using namespace std;

namespace EP {
    namespace MD {

typedef map<unsigned, User*> pUserMap;
typedef map<unsigned, User> UserMap;

class Users : public TemplateMethodMap<User>
{
public:
    Users(Log* inLog);
    virtual ~Users(){}
private:
    void Setup(Log* inLog);
};

    }}
