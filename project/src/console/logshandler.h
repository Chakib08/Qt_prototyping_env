#ifndef LOGSHANDLER_H
#define LOGSHANDLER_H

#include <QSet>
#include "Common/Interfaces/Logger/ilogappender.h"

class LogsHandler
{
public:
    LogsHandler();
    void handleMessage(QtMsgType msgType, const QMessageLogContext &context, QString &message);
    void registerAppender(ILogAppender *appender);
    void uneregisterAppender(ILogAppender *appender);

private:
    QSet<ILogAppender*> m_appenders;
};

#endif // LOGSHANDLER_H
