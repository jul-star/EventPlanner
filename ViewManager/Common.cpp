#include "Common.h"
namespace EP {
namespace VM {

void Common::AddLabel(QVBoxLayout *vLayout, QString str)
{    
    QLabel* lbl = new QLabel();
    lbl->setText(str);
    vLayout->addWidget(lbl);
}

void Common::SliderAppearance(QSlider* vSlider)
{
    vSlider->setBaseSize(100,50);
}

void Common::SetCheckBox(QVBoxLayout *vLayout, QString str, QObject* receiver, void(*f)(int))
{
    QCheckBox *cb = new QCheckBox();
    cb->setText(str);
    cb->setChecked(false);
    QObject::connect(cb, SIGNAL(stateChanged(int)), receiver, SLOT(f(int)));
    vLayout->addWidget(cb);

    QFrame* hFrame = new QFrame;
    hFrame->setFrameShape(QFrame::HLine);
    vLayout->addWidget(hFrame);
}

void  Common::ClearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0))!=NULL)
    {
        delete item->widget();
        delete item;
    }
}

void Common::QPushButtonAppeareanceSet(QPushButton *pButton)
{
    pButton->setMinimumHeight(50);
    pButton->setMinimumWidth(90);
    pButton->setMaximumHeight(50);
    pButton->setMaximumWidth(90);
}

}}
