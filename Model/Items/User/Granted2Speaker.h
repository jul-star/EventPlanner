#pragma once

#include <map>
#include <Model/Items/user/Granted.h>
using namespace std;

namespace EP {
    namespace MD {

class Granted2Speaker : public Granted
{
public:
    Granted2Speaker();

private:
    void InitializeGranted();
};

    }}
