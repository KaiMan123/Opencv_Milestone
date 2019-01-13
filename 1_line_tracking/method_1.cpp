#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

// cvtColor(input, input, COLOR_BGR2GRAY); change 3 channel into 1 channel

Mat sobel(Mat & input){
    cvtColor(input, input, COLOR_BGR2GRAY);
    GaussianBlur(input, input, Size(3,3), 0, 0);
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Sobel(input, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);
    Sobel(input, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs(grad_y, abs_grad_y);
    Mat output_simple, output_threshold;
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, output_simple);
    threshold(output_simple, output_threshold, 80, 255, THRESH_BINARY|THRESH_OTSU);
    // return output_simple;
    return output_threshold;
}

Mat modify(Mat & input){
    return sobel(input);
}

int main(){
    VideoCapture video(0);
    if (!video.isOpened()){
        return -1;
    }
    Size videoSize = Size((int)video.get(CV_CAP_PROP_FRAME_WIDTH),(int)video.get(CV_CAP_PROP_FRAME_HEIGHT));
    namedWindow("video demo", CV_WINDOW_AUTOSIZE);
    Mat videoFrame;
    while(true){
        video >> videoFrame;
        videoFrame = modify(videoFrame);
        if(videoFrame.empty()){
            break;
        }
        imshow("video demo", videoFrame);
        waitKey(27);
    }
    return 0;
}