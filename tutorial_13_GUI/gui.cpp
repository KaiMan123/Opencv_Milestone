#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

// set the two input images and ratio value as global so that references to function is saved 
int sliderValue;
Mat src1, src2;

void on_trackbar(int, void*){
    double alpha = (double) sliderValue/100.0 ;
    double beta = ( 1.0 - alpha );
    Mat dst;
    // the weight ratio between image
    addWeighted( src1, alpha, src2, beta, 0.0, dst);
    // show the image on the windows
    imshow("trackbar demo", dst);
}

int main(){
    // get two image
    src1 = imread("input1.jpeg",CV_LOAD_IMAGE_UNCHANGED);
    src2 = imread("input2.jpeg",CV_LOAD_IMAGE_UNCHANGED);
    // set the intial and maximum value for the inserting ratio 
    sliderValue = 0;
    int sliderMaxValue = 100;
    namedWindow("trackbar demo", 0);
    // create a trackbar named "Ratio" with value from sliderValue to sliderMaxValue on the windows "trackbar demo"
    createTrackbar("Ratio", "trackbar demo", &sliderValue, sliderMaxValue, on_trackbar);
    // call the trackbar function
    on_trackbar(sliderValue, 0);

    waitKey(0);
    return 0;
}
