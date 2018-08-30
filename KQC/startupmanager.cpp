#include "startupmanager.h"
#include <QDebug>

StartupManager::StartupManager(QObject *parent):QObject(parent)
{
    fetchStatusTimer=new QTimer;
    fetchStatusTimer->setInterval(2000);
    QObject::connect(fetchStatusTimer,SIGNAL(timeout()),this,SLOT(fetchServerRunningStatus()));

    toolProcess=new QProcess;
    QStringList toolArgument;
    toolArgument<<"client.py";
    toolProcess->setProcessChannelMode(QProcess::MergedChannels);
    toolProcess->setWorkingDirectory("E:/paper/paper/KQC/interact");
    QObject::connect(toolProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStdout()));
    QObject::connect(toolProcess,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStderr()));
    toolProcess->start("python.exe",toolArgument);
    fetchStatusTimer->start();
}

StartupManager::~StartupManager()
{

}

void StartupManager::startTool()
{
    qDebug()<<__FUNCTION__<<endl;
    toolProcess->write("s.run_cmd python.exe myProc.py\n");
}

void StartupManager::readyReadStderr()
{
    qDebug()<<__FUNCTION__<<endl;

}

void StartupManager::readyReadStdout()
{
    qDebug()<<__FUNCTION__<<endl;
    QByteArray res=toolProcess->readAll();
    res=res.left(res.length()-2);
    QString status=QString::fromStdString(res.toStdString());
    qDebug()<<status<<endl;
    emit updateCurrentRunningStatus(status);
}

void StartupManager::fetchServerRunningStatus()
{
    qDebug()<<__FUNCTION__<<endl;
    toolProcess->write("s.getState\n");
}
