#include "catchbutton.h"
//#include "mybutton.h"
#include "QMouseEvent"
#include "QString"
#include "QDebug"
#include "QRect"
#include "QPushButton"
#include "QRandomGenerator"


CatchButton::CatchButton(QWidget *parent) : QWidget(parent)
{
    setGeometry(x(), y(), 1200,600);
    setWindowTitle("Catch the button");

    setMouseTracking(true);
    mPressButton = new QPushButton(this);
    mPressButton -> move(123, 514);
    mPressButton ->setText("Catch button");

    connect(this, SIGNAL(jumpButton()), this, SLOT(buttonJump()));

}

void CatchButton::buttonJump()
{
    int xRandomPos, yRandomPos;

    xRandomPos=QRandomGenerator::global()->bounded(1100);
    yRandomPos=QRandomGenerator::global()->bounded(530);
    mPressButton->move(xRandomPos, yRandomPos);
}

void CatchButton::mouseMoveEvent(QMouseEvent *event)
{
        int  mouseX=-1, mouseY=-1;
        int xButton=-1, yButton=-1;
        int heightButton=-1, widthButton=-1;

        QString mouseString;
        QRect buttonGeometry;

        xButton=-1;
        yButton=-1;
        heightButton=-1;
        widthButton=-1;

        mouseX=event->x();
        mouseY=event->y();

        buttonGeometry=mPressButton->geometry();
        xButton=buttonGeometry.x();
        yButton=buttonGeometry.y();
        heightButton=buttonGeometry.height();
        widthButton=buttonGeometry.width();

        if( (mouseX>=xButton) && ( mouseX<=(xButton+widthButton)) && ((mouseY>=yButton) && ( mouseY<=(yButton+heightButton)) ) )
        {

            emit jumpButton();

            qDebug() << "mouseX = " + QString::number(mouseX) + " xButton= " + QString::number(xButton);
            qDebug() << "mouseY = " + QString::number(mouseY) + " yButton= " + QString::number(yButton);
        }

}
