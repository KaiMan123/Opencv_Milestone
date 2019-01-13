#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

/*
    No sound will be detected when you are using opencv
*/

int main(){
    // get the video named input.mp4
    VideoCapture video("input.mp4");
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

    while(true){
        // get the video image
        video >> videoFrame;
        // if nothing get, then break this loop and end the program
        if( videoFrame.empty()){
            break;
        }
        // show the video image, you can do any correction to the matrix as you like before show it out
        imshow("video demo", videoFrame);
        // 27 refer to 'Esc', if 'Esc' on the keyboard is pressed, then end this program 
        if(waitKey(33) == 27){ 
            break;
        }
    }
    return 0;
}
