#pragma once

#include <QObject>


#include <Model/Items/Hall/Option.h>
#include <Model/Proxy.h>

#include <ViewManager/Common.h>

using namespace std;
using namespace EP::MD;

namespace EP {
namespace VM {

class vmOptions : public QObject
{
    Q_OBJECT
public:
    explicit vmOptions(QObject *parent ,
                     Proxy& inProxy);

signals:
  //   void Edit();

public slots:

    void Edit(QVBoxLayout *vLeft, QVBoxLayout *vCenter, QVBoxLayout *vRight, QHBoxLayout *vBottom);
    void List(QVBoxLayout *vLeft, QVBoxLayout *vCenter, QVBoxLayout *vRight, QHBoxLayout *vBottom);
protected slots:
     void EditVideography(int arg);
     void EditItem(int arg);
protected:

    void MenuGet(QVBoxLayout *vLayout);
    void SetCheckBox(QVBoxLayout *vLayout, QString str, bool inVal, const char *slot);
    void FurnitureList(QVBoxLayout *vLayout);
    void EquipmentList(QVBoxLayout *vLayout);
    void MenuList(QVBoxLayout *vLayout);
    void getSlider(QVBoxLayout *vLayout,
                   const Item *inItem,
                   int inMin = 0,
                   int inMax = 50,
                   int inStep = 1);
    void VideographyGet(QVBoxLayout *vLayout);
private:
    Proxy& vProxy;
};

}}
