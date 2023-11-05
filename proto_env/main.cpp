#include "window.h"

#include <QApplication>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;

    // read an image
    cv::Mat image = cv::imread("D:/Qt_dev/Qt_prototyping_env/proto_env/sett_soul_fighter.jpeg", 1);
    // create image window named "My Image"
    //cv::namedWindow("My Image");
    // show the image on window
    //cv::imshow("My Image", image);


    return a.exec();
}
