#pragma once

#include <map>
#include <Model/Items/user/Granted.h>
using namespace std;

namespace EP {
    namespace MD {
class Granted2Customer : public Granted
{
public:    
    Granted2Customer();

private:
    void InitializeGranted();

};

    }}
