#ifndef STARTUPMANAGER_H
#define STARTUPMANAGER_H
#include <QObject>
#include <QProcess>

class StartupManager:public QObject
{
    Q_OBJECT
public:
    StartupManager(QObject*parent=0);
    ~StartupManager();
public slots:
    void startTool();
    void readyReadStdout();
    void readyReadStderr();
private:
    QProcess*toolProcess;
};

#endif // STARTUPMANAGER_H
