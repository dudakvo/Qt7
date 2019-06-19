#ifndef CATCHBUTTON_H
#define CATCHBUTTON_H

#include <QWidget>

//class MyButton;
class QPushButton;

class CatchButton : public QWidget
{
    Q_OBJECT
public:
    explicit CatchButton(QWidget *parent = nullptr);

signals:
    void jumpButton();

public slots:
    void buttonJump ();

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    QPushButton* mPressButton;

 //   virtual  bool eventFilter (QObject*, QEvent*);
};

#endif // CATCHBUTTON_H
