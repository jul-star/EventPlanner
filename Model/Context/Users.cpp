#include "Users.h"

namespace EP {
namespace MD {
Users::Users(Log *inLog):
    TemplateMethodMap<User>::TemplateMethodMap()
{
    Setup(inLog);
}

void Users::Setup(Log *inLog)
{
    this->AddItem(*new User(string("Ivan"), string("Ivanov"), *new Role(nRole::ID::Manager), string("123-456"), string("email"),inLog));
    this->AddItem(*new User(string("Petr"), string("Petrov"), *new Role(nRole::ID::Customer), string("phone"), string("email"),inLog));
    this->AddItem(*new User(string("Semen"), string("Semenov"),*new Role(nRole::ID::Speaker), string("phone"), string("email"),inLog));
    this->AddItem(*new User(string("Sidor"), string("Sidorov"), *new Role(nRole::ID::Participant), string("phone"), string("email"),inLog));
}

}}
