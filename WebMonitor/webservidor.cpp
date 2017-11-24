#include "webservidor.h"
#include <QWebSocket>
WebServidor::WebServidor(QObject *parent) : QWebSocketServer ("Servidor", QWebSocketServer::NonSecureMode,parent)
{
    socketWeb = NULL;
    connect(this, SIGNAL(newConnection()), this, SLOT(NovoConectado()) );
}

void WebServidor::NovoConectado()
{
    QWebSocket *novoSocket = WebServidor::nextPendingConnection();
    connect(novoSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(mensagemRecebida(QString) ));
    connect(novoSocket, &QWebSocket::disconnected, this, &WebServidor::socketDesconectado);
    osClientes << novoSocket;
}

void WebServidor::mensagemRecebida(const QString &msg)
{
    QWebSocket *oEnviador = qobject_cast<QWebSocket *>(sender());
    for(QWebSocket *oCliente: qAsConst(osClientes) ){
        if(oCliente != oEnviador){/* não enviar a mensagem de volta para si mesmo*/
            oCliente->sendTextMessage(msg);    }    }
    emit msgRecebida(msg);
}

void WebServidor::socketDesconectado()
{
    QWebSocket *oCliente = qobject_cast<QWebSocket *>(sender());
    if(oCliente){
        osClientes.removeAll(oCliente);
        oCliente->deleteLater();}
}
