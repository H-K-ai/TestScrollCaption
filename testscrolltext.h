#ifndef TESTSCROLLTEXT_H
#define TESTSCROLLTEXT_H

#include <QWidget>
#include <QTimer>
#include <QLabel>



namespace Ui {
class TestScrollText;
}

class TestScrollText : public QWidget
{
    Q_OBJECT

public:
    explicit TestScrollText(QWidget *parent = 0);
    ~TestScrollText();
private slots:
    void scrollCaption();
    void on_closeBtn_clicked();

private:
    Ui::TestScrollText *ui;
private:
    QString m_scrollCaptionStr;
    QTimer *m_timer;


};

#endif // TESTSCROLLTEXT_H
