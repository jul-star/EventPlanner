#pragma once

#include <map>
#include <Model/Items/user/Granted.h>
using namespace std;

namespace EP {
    namespace MD {
class Granted2Manager : public Granted
{
public:
    Granted2Manager();

private:
    void InitializeGranted();

};

    }}
