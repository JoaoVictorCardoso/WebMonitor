#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "webservidor.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    servidor = new WebServidor(this);
    if( servidor->listen(QHostAddress::Any, 9000) ){
        qDebug() <<"Conectado na porta: 9000";
        connect(servidor, SIGNAL( msgRecebida(QString) ), this, SLOT( mensagemRecebida(QString) ));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mensagemRecebida(const QString &msg)
{
    ui->listaMensagens->addItem(msg);
}

