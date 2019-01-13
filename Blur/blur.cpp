#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;

void simpleblur(){
    Mat src = imread("mini.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat aveBlur1;
    Mat aveBlur2;
    blur(src, aveBlur1, Size(3,3));
    blur(src, aveBlur2, Size(5,5));
    imwrite("blur_3.jpg", aveBlur1);
    imwrite("blur_5.jpg", aveBlur2);
}

void gaussian_blur(){
    Mat src = imread("mini.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat GaussianBlur1;
    Mat GaussianBlur2;
    GaussianBlur(src, GaussianBlur1, Size(3,3) ,0 ,0);
    GaussianBlur(src, GaussianBlur2, Size(5,5) ,0 ,0);
    imwrite("gaussianblur_3.jpg", GaussianBlur1);
    imwrite("gaussianblur_5.jpg", GaussianBlur2);
}

void median_blur(){
    Mat src = imread("mini.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat dst;
    medianBlur(src, dst, 5);
    imwrite("medianBlur.jpg", dst);
}

void bilateral_filter(){
    Mat src = imread("mini.jpg");
    Mat dst;
    bilateralFilter(src, dst, 5 ,30 ,30);
    imwrite("bilateralBlur.jpg", dst);
}

int main(){
    simpleblur();
    gaussian_blur();
    median_blur();
    bilateral_filter();
    return 0;
}
