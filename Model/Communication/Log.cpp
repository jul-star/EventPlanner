#include "Log.h"


namespace EP {
    namespace MD {
Log::Log()
{

}

void Log::Add(string inMessage)
{
    vLog.push_back(inMessage);
}

void Log::Clear()
{
    vLog.clear();
}

    }}
