#include "vmOptions.h"


namespace EP {
namespace VM {

vmOptions::vmOptions(QObject *parent,
                 Proxy &inProxy) :
      QObject(parent),
      vProxy(inProxy)
{

}


void vmOptions::getSlider(QVBoxLayout *vLayout,
                        const Item* inItem,
                        int inMin,
                        int inMax,
                        int inStep)
{
    const int width = 110;
    const int height = 30;
    QSlider* pSlider = new QSlider(Qt::Horizontal);
    pSlider->setTickPosition(QSlider::TicksBothSides);
    pSlider->setFocusPolicy(Qt::StrongFocus);
    pSlider->setSingleStep(inStep);
    pSlider->setMinimum(inMin);
    pSlider->setMaximum(inItem->getVal()- inMax);
    pSlider->setMaximumSize(width,height);
 //   pSlider->setProperty("ID",inItem->ID());
    pSlider->setFixedSize(width,height);
    pSlider->setTracking(true);
    pSlider->setObjectName(QString::fromStdString(to_string(inItem->ID())));
    connect(pSlider,SIGNAL(valueChanged(int)), this, SLOT(EditItem(int)));
    vLayout->addWidget(pSlider);
}



void vmOptions::VideographyGet(QVBoxLayout *vLayout)
{
    SetCheckBox(vLayout, QString("Videography:"),
                vProxy.OptionGet()->getVideography(),
                SLOT(EditVideography(int)));
}

void vmOptions::SetCheckBox(QVBoxLayout *vLayout, QString str,bool inVal, const char* slot)
{
    QCheckBox *cb = new QCheckBox();
    cb->setText(str);
    cb->setChecked(inVal);
    QObject::connect(cb, SIGNAL(stateChanged(int)), this, slot);
    vLayout->addWidget(cb);

    QFrame* hFrame = new QFrame;
    hFrame->setFrameShape(QFrame::HLine);
    vLayout->addWidget(hFrame);
}


void vmOptions::Edit(QVBoxLayout *vLeft,QVBoxLayout *vCenter,QVBoxLayout *vRight,QHBoxLayout *vBottom)
{
    const Option* pOption = vProxy.OptionGet();
    Common::AddLabel(vLeft, QString("Furniture:\n"));
    for(map<unsigned,Item>::const_iterator it = pOption->Furniture()->cbegin();
        it != pOption->Furniture()->cend();
        ++it)
    {
        getSlider(vLeft,&it->second);
    }

    Common::AddLabel(vCenter, QString("Equipment:\n"));
    for(map<unsigned,Item>::const_iterator it = pOption->Equipment()->cbegin();
        it != pOption->Equipment()->cend();
        ++it)
    {
        getSlider(vCenter,&it->second);
    }

    Common::AddLabel(vRight, QString("Menu:\n\n"));
    Common::AddLabel(vRight, QString("Snack:\n"));
    for(map<unsigned,Item>::const_iterator it = pOption->Snack()->cbegin();
        it != pOption->Snack()->cend();
        ++it)
    {
        getSlider(vRight,&it->second);
    }
    Common::AddLabel(vRight, QString("Beverage:\n"));
    for(map<unsigned,Item>::const_iterator it = pOption->Beverage()->cbegin();
        it != pOption->Beverage()->cend();
        ++it)
    {
        getSlider(vRight,&it->second);
    }
}


void vmOptions::List(QVBoxLayout *vLeft,QVBoxLayout *vCenter,QVBoxLayout *vRight,QHBoxLayout *vBottom)
{
        FurnitureList(vLeft);
        EquipmentList(vCenter);
        MenuList(vRight);
}

void vmOptions::FurnitureList(QVBoxLayout *vLayout)
{
    Option* pOption = new Option(vProxy.LogGet());
    Common::AddLabel(vLayout, QString("Furniture:\n"));
    for(map<unsigned,Item>::const_iterator it = pOption->Furniture()->cbegin();
        it != pOption->Furniture()->cend();
        ++it)
    {
        QString str(QString::fromStdString(it->second.getName()));
        str.append("\n");
        Common::AddLabel(vLayout, str);
    }
}

void vmOptions::EquipmentList(QVBoxLayout *vLayout)
{
    QString str("Equipment:\n\nVideography\nProjector\nProjectorScreen\nChalkBoard");
    Common::AddLabel(vLayout, str);
}

void vmOptions::MenuList(QVBoxLayout *vLayout)
{
    QString vSnack("Snack:\n\nShawarma\nCudighi\nRunza");
    QVBoxLayout *vLeft = new QVBoxLayout();
    Common::AddLabel(vLeft, vSnack);
    QString vBeverage("Beverage:\n\nRootBear\nCola\nPepsi");
    QVBoxLayout *vRight = new QVBoxLayout();
    Common::AddLabel(vRight, vBeverage);
    vLayout->addLayout(vLeft);
    vLayout->addLayout(vRight);
    vLayout->update();
}

void vmOptions::EditVideography(int arg)
{
    Option* pOption = const_cast<Option*>(vProxy.OptionGet());
    if (pOption != nullptr)
    {
        pOption->setVideography(arg == 2);
    }
}

void vmOptions::EditItem(int arg)
{

}

}}
