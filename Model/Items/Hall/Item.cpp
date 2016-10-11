#include "Item.h"


namespace EP {
    namespace MD {

Item::Item():
    vID(0),
    vName(string()),
    vValue(0)
{

}

Item::Item(unsigned inID, string inName, int inVal):
    vID(inID),
    vName(inName),
    vValue(inVal)
{

}

    }}
