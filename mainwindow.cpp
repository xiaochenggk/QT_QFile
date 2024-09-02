#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,file()//初始化file对象到构造函数初始化列表里面，让该对象全局可用。
           //这是文件操作的第一步
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_find_clicked()//查找按钮的槽
{   QString str = ui->lineEdit_open->text();//将lineEdit控件中输入的地址抠出来传给字符串对象str
    file.setFileName(str);//将上面str的值传给file对象，这样就做到了在ui里面输入地址查找文件
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){//以指定方式打开文件，这是文件的第二步
        ui->textEdit_read->setText("成功找到文件");//这里判断文件打开成功后向textEdit_read发送一个提示代表查找到文件
    }


}


void MainWindow::on_pushButton_read_clicked()//显示按钮的槽
{
    QString str_02 =  file.readAll();//读取文本内容
    ui->textEdit_read->setPlainText(str_02);//再将接受到的内容传到textEdit_read中
    file.close();//关闭
}

