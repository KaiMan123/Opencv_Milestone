#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = imread("mini.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat src2;
    threshold(src,src2,120,255,THRESH_BINARY);
    Mat dst1;
    Mat dst2;
    Mat dst3;
    erode(src2, dst1, Mat());
    dilate(src2, dst2, Mat());
    Mat erodeStruct = getStructuringElement(MORPH_RECT,Size(5,5));
    erode(src2, dst3, erodeStruct);
    
    imwrite("erode.jpg", dst1);
    imwrite("dilate.jpg", dst2);
    imwrite("erode2.jpg", dst3);
    waitKey(0);

    return 0;
}
