#ifndef ILOGAPPENDER_H
#define ILOGAPPENDER_H

#include <QString>
#include <QMap>
#include <QDateTime>
#include <QMetaType>

class LogsHandler;

enum class LogLevel
{
    Info = 0,
    Warning,
    Debug,
    Error,
    Critical,
    Fatal
};

static const QMap<LogLevel, QString> loglevelToString {
    {LogLevel::Info, "Info"},
    {LogLevel::Warning, "Warning"},
    {LogLevel::Debug, "Debug"},
    {LogLevel::Critical, "Critical"},
    {LogLevel::Fatal, "Fatal"}
};

static const QMap<QString, LogLevel> stringToLoglevel {
    {"Info", LogLevel::Info},
    {"Warning", LogLevel::Warning},
    {"Debug", LogLevel::Debug},
    {"Critical", LogLevel::Critical},
    {"Fatal", LogLevel::Fatal}
};

static const QMap<QtMsgType, LogLevel> qtMsgTypeToLoglevel {
    {QtMsgType::QtInfoMsg, LogLevel::Info},
    {QtMsgType::QtWarningMsg, LogLevel::Warning},
    {QtMsgType::QtDebugMsg, LogLevel::Debug},
    {QtMsgType::QtCriticalMsg, LogLevel::Critical},
    {QtMsgType::QtFatalMsg, LogLevel::Fatal}
};

struct LogMessage
{
    LogLevel level;
    QString message;
    QDateTime timestamp;
    QString function;
    uint32_t line;
    QString fileName;
};

class ILogAppender
{
public:
    explicit ILogAppender();
    ~ILogAppender();
    virtual void append(const LogMessage &logMessage) = 0;

private:
    LogsHandler *m_logsHandler;
};

#endif // ILOGAPPENDER_H
