#include "vmOrders.h"

namespace EP {
namespace VM {


vmOrders::vmOrders(QObject *parent, Proxy &inProxy) :
    QObject(parent),
    vProxy(inProxy)
{

}

void vmOrders::View(QVBoxLayout *inVLayout)
{
    Common::ClearLayout(inVLayout);
    const Orders* pOrders = vProxy.OrdersGet();
    const Order* pOrder = nullptr;
    string str("");

    if(vProxy.UsersGet()->Item()->getRole()->Permission()->isGranted(vProxy.StateGet()->ViewGet(),
                                                                     vProxy.StateGet()->ActionGet()))
    {
        const map<unsigned, Order*>* pOrders = vProxy.UsersGet()->Item()->getOrders();
        QVBoxLayout *tmpLayout = new QVBoxLayout();

        for(map<unsigned, Order*>::const_iterator itOrder = pOrders->cbegin();
            itOrder != pOrders->cend();
            ++itOrder)
        {
            pOrder = itOrder->second;
            str.clear();
            str.append(to_string(pOrder->getDate())).append("\t");
            str.append(pOrder->getDescription()).append("\n");
            str.append(pOrder->getInfo(vProxy.UsersGet()->Item()->getRole()->getID()));
            Common::AddLabel(tmpLayout, QString::fromStdString(str));
        }

        inVLayout->addLayout(tmpLayout);
    }
}






}}
