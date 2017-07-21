#include "testscrolltext.h"
#include "ui_testscrolltext.h"
#include "QPropertyAnimation"
#include "QApplication"



TestScrollText::TestScrollText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestScrollText)
{

    m_scrollCaptionStr = QStringLiteral("欢迎来到南昌航空大学E509图形图像处理实验室!");

    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&TestScrollText::scrollCaption);
    m_timer->start(500);
   //界面淡出
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();


    ui->setupUi(this);
}

TestScrollText::~TestScrollText()
{
    delete ui;
}

void TestScrollText::scrollCaption()
{

    static int nPos = 0;
    if(nPos > m_scrollCaptionStr.length())
    {

        nPos = 0;
    }
    ui->m_scrollcaptionLabel->setText(m_scrollCaptionStr.mid(nPos));
    nPos++;

}





void TestScrollText::on_closeBtn_clicked()
{
    //界面动画，改变透明度的方式消失1 - 0渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    this->hide();
}
