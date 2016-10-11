#include "Orders.h"

namespace EP {
    namespace MD {
Orders::Orders(Log* inLog):
    TemplateMethodMap<Order>::TemplateMethodMap()
{
    Setup(inLog);
}

void Orders::Setup(Log *inLog)
{
//    this->AddItem(*new User(string("Ivan"), string("Ivanov"), *new Role(nRole::ID::Manager), string("123-456"), string("email"),inLog));
}
    }}
