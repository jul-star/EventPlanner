#pragma once

namespace nsOption
{
namespace nsFurniture
{
enum ID { Chair = 0, Table };
}
namespace nsEquipment
{
enum ID { Tribune=0,Projector,ProjectorScreen, ChalkBoard };
}

namespace nsMenu
{
namespace nsBeverage
{
enum ID { RootBear = 0, Cola, Pepsi };
}
namespace nsSnack
{
enum ID { Shawarma = 0, Cudighi, Runza };
}
}
}

namespace nView {
enum ID {Empty = 0, Order, Hall, Option,Schedule, ParticipantList, User};
}
namespace nAction {
enum ID{Empty = 0, View,Edit,Delete,Place,Close,Accept,Decline };
}
namespace nRole {
enum ID {Empty = 0,  Manager , Customer, Speaker, Participant};
}



namespace nsDebug
{	
extern const int iDummy;
extern const unsigned uiDummy;
extern const void* ptrDummy;
}

namespace nsNames
{
extern const char* cBeverage ;
extern const char*  cSnack ;
extern const char*  cFurniture;
extern const char*  cVideography;
}
