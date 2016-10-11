#include "Halls.h"
namespace EP {
    namespace MD {
Halls::Halls(Log *inLog):
    TemplateMethodMap<Hall>::TemplateMethodMap()
{
    Setup(inLog);
}

void Halls::Setup(Log* inLog)
{
    this->AddItem(*new Hall(string("Red"), 100, 50, 3, 1, true, true, true, true, 3, 20, 20,inLog));
    this->AddItem(*new Hall(string("Blue"), 200, 120, 10, 1, true, false, true, true, 3, 30, 20,inLog));
    this->AddItem(*new Hall(string("Green"), 20, 50, 3, 0, false, true, false, false, 3, 10, 10,inLog));
}

}}
