#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDEbug>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     btnNums = {
        {Qt::Key_0, ui->btnNum0},
        {Qt::Key_1, ui->btnNum1},
        {Qt::Key_2, ui->btnNum2},
        {Qt::Key_3, ui->btnNum3},
        {Qt::Key_4, ui->btnNum4},
        {Qt::Key_5, ui->btnNum5},
        {Qt::Key_6, ui->btnNum6},
        {Qt::Key_7, ui->btnNum7},
        {Qt::Key_8, ui->btnNum8},
        {Qt::Key_9, ui->btnNum9},
        {Qt::Key_Plus, ui->btnPlus},
        {Qt::Key_Minus, ui->btnMinus},
        {Qt::Key_Asterisk, ui->btnMultiple},
        {Qt::Key_Slash, ui->btnDivide},
        {Qt::Key_Backspace, ui->btnDel},
        {Qt::Key_Period, ui->btnPeriod}
    };

    connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));


    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnNumClicked()
{
    //if(flag==0){
        operand = ui->display->text();
        operand = operand + qobject_cast<QPushButton*>(sender())->text();
        ui->display->setText(operand);
    //}
   // else if(flag==1){
        // operands.push_back(operand);
        // operand="";
        // operand = ui->display->text();
        // operand = operand + qobject_cast<QPushButton*>(sender())->text();
        // ui->display->setText(operand);
        // flag--;
   // }
    // operand = ui->display->text();
    // operand = operand + qobject_cast<QPushButton*>(sender())->text();
    // ui->display->setText(operand);
    // operands.push_back(opera"nd);
        qDebug()<<"数字按键执行成功";
}


void MainWindow::on_btnPeriod_clicked()
{
    operand = ui->display->text();
    if(!operand.contains("."))
        operand = operand + qobject_cast<QPushButton*>(sender())->text();
    ui->display->setText(operand);
    qDebug()<<"小数点按键执行成功";
}


void MainWindow::on_btnDel_clicked()
{
    operand=ui->display->text();
    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
    qDebug()<<"删除按键执行成功";
}

void MainWindow::btnUnaryOperatorClicked()
{
    if (operand != "") {
        double result = operand.toDouble();
        operand = "";
        QString op = qobject_cast<QPushButton *>(sender())->text();
        if (op == "%") {
            result /= 100.0;
        } else if (op == "1/x") {
            result = 1 / result;
        } else if (op == "x^2") {
            result *= result;
        } else if (op == "") {
            result = sqrt(result);
        }
        ui->display->setText(QString::number(result));
    }
    qDebug()<<"单符运算执行成功";
}

void MainWindow::btnBinaryOperatorClicked(){
    flag++;
    opcode = qobject_cast<QPushButton *>(sender())->text();
    //qDebug() << opcode;
    //ui->display->setText(opcode);
    if (operand != "") {
        operands.push_back(operand);
        operand = "";
    }
    opcodes.push_back(opcode);
    // opcodes.push_back(opcode);
    // result = calculation();
    // ui->display->setText(result);
    ui->display->setText("");
    qDebug()<<"双操作符执行成功";
}
QString MainWindow::calculation(bool *ok)
{
    double result1;
    // qDebug()<<operands.size();
    // qDebug()<<opcodes.size();
    if(operands.size() == 2 && opcodes.size() > 0){

        double operand1 = operands.front().toDouble();
        operands.pop_front();

        double operand2 = operands.front().toDouble();
        operands.pop_front();
        QString op = opcodes.front();
        opcodes.pop_front();

        if(op == "+"){
            result1 = operand1 + operand2;
        }else if(op == "-"){
            result1 = operand1 - operand2;
        }else if(op == "*"){
            result1 = operand1 * operand2;
        }else if(op == "/"){
            result1 = operand1 / operand2;
        }
        //qDebug() << result1;
        operands.push_back(QString::number(result1));
 }
    return QString::number(result1);
 qDebug()<<"逻辑计算执行成功";

}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    ui->display->setText(operand);
    result="";
    operands.pop_front();
}


void MainWindow::on_btnEqual_clicked()
{
    if (operand != "") {
        operands.push_back(operand);
        operand = "";
    }
    result = calculation();
     ui->display->setText(result);
    //operands.push_back(operand);
    // if(operand !=""){
    //     operands.push_back(operand);
    //     operand ="";
    // }
    // ui->display->setText(result);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey, btnNums.keys()) {
        if(event->key() == btnKey) {
            btnNums[btnKey]->animateClick();
        }
    }
    qDebug()<<"键盘事件执行成功";
}


