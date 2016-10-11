#include "Talk.h"

namespace EP {
    namespace MD {
Talk::Talk(Log *inLog):
    pLog(inLog)
{

}

Talk::Talk(const Talk &rhs):
    pLog(rhs.pLog)
{

}

void Talk::Tell(string message)
{
 pLog->Add(message);
}
    }}
