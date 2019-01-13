#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(){
    // get the camera from the computer 
    VideoCapture capture(0);
    if(!capture.isOpened()){  
        return -1;
    }
    Size videoSize = Size((int)capture.get(CV_CAP_PROP_FRAME_WIDTH),(int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));
    VideoWriter writer;

    /*
    Create a writer to write the image into the output video file "VideoTest.avi"
        CV_FOURCC() create the video format, for example:
            CV_FOURCC(‘P’,’I’,’M’,’1’) refer to the MPEG-1
            CV_FOURCC(‘M’,’J’,’P’,’G’) refer to the motion-jpeg
    */
    writer.open("VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30, videoSize);
    namedWindow("show image",0);

    while(true){
        Mat frame;
        // get the image from the camera
        capture >> frame; 
        if(!frame.empty()){
            // write the image from the camera to the output file
            writer.write(frame);
            imshow("show image", frame);
            // 27 refer to 'Esc', if 'Esc' on the keyboard is pressed, then end this program 
            if(waitKey(33) == 27){ 
                break;
            }
        }
    }
    return 0;
}

