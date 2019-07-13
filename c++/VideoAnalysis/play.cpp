#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

/*
    No sound will be detected when you are using opencv
*/
int main(int argc, char** argv){
    try {

        // get the video named input.mp4
        VideoCapture video("./Resources/test.avi");
        // if this video cannot be opened, the end this program
        if (!video.isOpened()){
            return -1;
        }
        // get the size of this video
        Size videoSize = Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));
        // open a window to show the video
        namedWindow("video demo", CV_WINDOW_AUTOSIZE);
        // matrix to store the image from the video
        Mat videoFrame;

        std::cout << "\033[1;36mPress q to finish the program.\033[0m" << std::endl;
        while(true){
            // get the video image
            video >> videoFrame;
            // if nothing get, then break this loop and end the program
            if(videoFrame.empty()){
                break;
            }
            // show the video image, you can do any correction to the matrix as you like before show it out
            imshow("video demo", videoFrame);
            // if 'q' on the keyboard is pressed, then end this program 
            if(waitKey(33) == (int)('q')){ 
                std::cout << "\033[1;36m" << argv[0] << " finshed.\033[0m" << std::endl;
                std::cout << "\033[1;33mPress any key to continue.\033[0m" << std::endl;
                waitKey();
                break;
            }
        }
        return 0;
    }
    catch( const std::exception& e ){
        std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[1;31m" << std::endl;
        std::cout << "\033[1;33mPress Enter to continue.\033[0m" << std::endl;
        std::cin.ignore();
    }
}

