#include "vmParticipants.h"


namespace EP {
namespace VM {

vmParticipants::vmParticipants(QObject *parent, Proxy &inProxy) :
    QObject(parent),
    vProxy(inProxy)
{

}

}}
