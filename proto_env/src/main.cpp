#include <QApplication>

#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QVBoxLayout>

#include <QThread>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Allow the event loop to process events
    qApp->processEvents();

    return app.exec();
}
