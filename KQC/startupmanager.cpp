#include "startupmanager.h"
#include <QDebug>

StartupManager::StartupManager(QObject *parent):QObject(parent)
{
    toolProcess=new QProcess;
    QStringList toolArgument;
    toolArgument<<"client.py";
    toolProcess->setProcessChannelMode(QProcess::MergedChannels);
    toolProcess->setWorkingDirectory("E:/paper/paper/KQC/interact");
    QObject::connect(toolProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStdout()));
    QObject::connect(toolProcess,SIGNAL(readyReadStandardError()),this,SLOT(readyReadStderr()));
    toolProcess->start("python.exe",toolArgument);
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
    qDebug()<<toolProcess->readAll();
}

void StartupManager::readyReadStdout()
{
    qDebug()<<__FUNCTION__<<endl;
    qDebug()<<toolProcess->readAll();
}
