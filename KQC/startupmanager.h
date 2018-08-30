#ifndef STARTUPMANAGER_H
#define STARTUPMANAGER_H
#include <QObject>
#include <QProcess>
#include <QTimer>
#include <QByteArray>

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
    void fetchServerRunningStatus();
signals:
    void updateCurrentRunningStatus(QString status);
private:
    QProcess*toolProcess;
    QTimer*fetchStatusTimer;
    QString currentStatus;
};

#endif // STARTUPMANAGER_H
