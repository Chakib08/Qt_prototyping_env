#include "window.h"

#include <QApplication>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/videoio/videoio.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Window w;

    // Create a CV Mat to store the frames
    cv::Mat cv_img;

    // Create window to display the image
    cv::namedWindow("Video Player");

    // Create a video capture for web camera (Channel 0 is web camera by default)
    cv::VideoCapture cap(0);

    if(!cap.isOpened())
    {
        qErrnoWarning("No video stream detected");
        return EXIT_FAILURE;
    }

    // Launch the stream
    while(cap.isOpened())
    {
        cap >> cv_img;
        if(cv_img.empty())
        {
            qErrnoWarning("No frame");
            break;
        }

        // Display the image
        cv::imshow("Video Player", cv_img);

        char c = (char) cv::waitKey(25);//Allowing 25 milliseconds frame processing time and initiating break condition//
        if (c == 27){ //If 'Esc' is entered break the loop//
            break;
        }

    }

    cap.release();
    return a.exec();
}
