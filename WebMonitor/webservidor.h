#ifndef WEBSERVIDOR_H
#define WEBSERVIDOR_H
#include <QList>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QObject>

class WebServidor : public QWebSocketServer
{
    Q_OBJECT
public:
    explicit WebServidor(QObject *parent = nullptr);
signals:
    void msgRecebida(QString);
private slots:
    void NovoConectado();
    void mensagemRecebida(const QString &msg);
    void socketDesconectado();
private:
    QWebSocket *socketWeb;
    QList<QWebSocket *> osClientes;
};

#endif // WEBSERVIDOR_H
