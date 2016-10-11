#pragma  once
#include <string>
#include <Model/Communication/Log.h>

using namespace std;

namespace EP {
    namespace MD {
class Talk
{
public:
    Talk(Log *inLog);
    Talk(const Talk& rhs);

    void Tell(string message);
     Log* GetLog() { return pLog; }

private:
    Log* pLog{nullptr};

};

    }}
