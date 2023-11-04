#include "window.h"

#include <QApplication>

#include "opencv2/opencv.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    //w.show();

    // // read an image
    // cv::Mat image = cv::imread("sett_soul_fighter.jpeg", 1);
    // // create image window named "My Image"
    // cv::namedWindow("My Image");
    // // show the image on window
    // cv::imshow("My Image", image);
    return a.exec();
}
