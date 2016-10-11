#pragma once

#include <map>

#include <QObject>
#include <QVBoxLayout>

#include <Model/Items/Order/Order.h>
#include <Model/Proxy.h>
#include <ViewManager/Common.h>

using namespace std;
using namespace EP::MD;

namespace EP {
namespace VM {


class vmOrders : public QObject
{
    Q_OBJECT
public:
    explicit vmOrders(QObject *parent , Proxy &inProxy);

signals:

public slots:
    void View(QVBoxLayout *inVLayout);

private:
     Proxy& vProxy;

};

}}
