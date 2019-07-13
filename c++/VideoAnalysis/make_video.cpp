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
        // get the camera from the computer 
        VideoCapture video("./Resources/test.avi");
        if(!video.isOpened()){  
            return -1;
        }
        Size videoSize = Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));
        VideoWriter writer;

        /*
        Create a writer to write the image into the output video file "VideoTest.avi"
            CV_FOURCC() create the video format, for example:
                CV_FOURCC(‘P’,’I’,’M’,’1’) refer to the MPEG-1
                CV_FOURCC(‘M’,’J’,’P’,’G’) refer to the motion-jpeg
        */
        writer.open("./c++/VideoAnalysis/VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, videoSize);
        namedWindow("show image", 0);

        std::cout << "\033[1;36mPress q to finish the program.\033[0m" << std::endl;
        Mat frame;
        while(true){
            // get the image from the camera
            video >> frame;
            // if nothing get, then break this loop and end the program
            if(frame.empty()){
                break;
            }
            writer.write(frame);
            imshow("show image", frame);
            // if 'q' on the keyboard is pressed, then end this program 
            if(waitKey(33) == (int)('q')){ 
                std::cout << "\033[1;36m" << argv[0] << " finshed.\033[0m" << std::endl;
                std::cout << "\033[1;33mPress any key to continue.\033[0m" << std::endl;
                waitKey(0);
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

