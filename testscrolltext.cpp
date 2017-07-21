#include "testscrolltext.h"
#include "ui_testscrolltext.h"



TestScrollText::TestScrollText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestScrollText)
{

    m_scrollCaptionStr = QStringLiteral("欢迎来到南昌航空大学E509图形图像处理实验室!");
    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&TestScrollText::scrollCaption);
    m_timer->start(500);
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
