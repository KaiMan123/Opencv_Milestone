#include <cstdio>
#include <string>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    /*
        get the camera from the computer
        0 is the default camera, change the value can change to different camera
        if that value does not refer to another camera, it will use the default one
        you can try 1 or -1 for the camera other than the default one
    */
    VideoCapture video(0);
    // if camera cannot be opened, the shutdown this program
    if (!video.isOpened()){
        return -1;
    }
    // get the video size depend on the camera default size
    Size videoSize = Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));
    // create a window to show the video
    namedWindow("video demo", CV_WINDOW_NORMAL);
    // create a matrix to store the image come from the camera
    Mat videoFrame;

    while(true){
        // get the video image from the camera
        video >> videoFrame;
        // if nothing get, then break this loop and end the program
        if(videoFrame.empty()){
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
