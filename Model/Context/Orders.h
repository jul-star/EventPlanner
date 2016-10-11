#pragma  once
#include <map>

#include <Model/Constants.h>
#include <Model/Context/TemplateMethodMap.hpp>
#include <Model/Items/Order/Order.h>



using namespace std;

namespace EP {
    namespace MD {

typedef map<unsigned, Order*> pOrderMap;
typedef map<unsigned, Order> OrderMap;

class Orders : public TemplateMethodMap<Order>
{
public:
    Orders(Log* inLog);
    virtual ~Orders(){}
private:
    void Setup(Log* inLog);
};

    }}
