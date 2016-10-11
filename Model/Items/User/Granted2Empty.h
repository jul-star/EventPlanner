#pragma once

#include <map>
#include <Model/Items/user/Granted.h>
using namespace std;

namespace EP {
    namespace MD {

class Granted2Empty : public Granted
{
public:
    Granted2Empty();

private:
    void InitializeGranted();
};

    }}
