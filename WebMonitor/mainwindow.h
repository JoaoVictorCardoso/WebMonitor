#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class WebServidor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void mensagemRecebida(const QString &msg);
private:
    Ui::MainWindow *ui;
    WebServidor *servidor;

};

#endif // MAINWINDOW_H
