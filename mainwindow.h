#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QString>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMap<int,QPushButton*>btnNums;
    int flag=0;
    QString eq;
    QString operand;
    QString result;
    QString opcode;
    QStack<QString>operands;
    QStack<QString>opcodes;
    QString calculation(bool *ok=NULL);
private slots:
    void btnNumClicked();
    void on_btnPeriod_clicked();
    void on_btnDel_clicked();
    void btnUnaryOperatorClicked();
    void btnBinaryOperatorClicked();
    void on_btnClear_clicked();
    void on_btnEqual_clicked();
    virtual void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
