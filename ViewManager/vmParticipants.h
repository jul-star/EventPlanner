#pragma once

#include <QObject>
#include <Model/Items/Order/ParticipantsList.h>
#include <Model/Proxy.h>

using namespace std;
using namespace EP::MD;

namespace EP {
namespace VM {

class vmParticipants : public QObject
{
    Q_OBJECT
public:
    explicit vmParticipants(QObject *parent, Proxy &inProxy);

signals:

public slots:
private:
     Proxy& vProxy;
};

}}
