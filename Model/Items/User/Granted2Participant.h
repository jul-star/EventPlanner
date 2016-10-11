#pragma once

#include <map>
#include <Model/Items/user/Granted.h>
using namespace std;

namespace EP {
    namespace MD {

class Granted2Participant : public Granted
{
public:
    Granted2Participant();

private:
    void InitializeGranted();
};

    }}
