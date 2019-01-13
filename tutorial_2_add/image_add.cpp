#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    // this choose the image add into the image
    Mat watermark = imread("julia_gpu.ppm",CV_LOAD_IMAGE_UNCHANGED);
    // this choos the image as the background (it should be large enough)
    Mat background = imread("input.ppm",CV_LOAD_IMAGE_UNCHANGED);
    /*
        create an img with size same as background img for output
        One channel - one pixel one value
            CV_8U  = 8 bit unsigned int
            CV_8S  = 8 bit signed int
            CV_16U = 16 bit unsigned int
            CV_32F = 32 bit floating point
        Three channel - one pixels three value RGB
            CV_8UC3, CV_8SC3, CV_16UC3, CV_32FC3

    */
    Mat temp(background.rows, background.cols, CV_8UC3);
    /*
        get image from background with
        30 is position of x start from the left
        50 is position of y start from the top
        cut the image with width same as the watermark.cols 
        cut the image with height same as the watermark.rows 
    */
    Mat imgROI = background(Rect(30,40,watermark.cols,watermark.rows));
    /*
        get image from watermark which
        start from (100, 100) on the left top coner
        with size (150, 200)
    */
    Mat croppedImage = watermark(Rect(100, 100, 150, 200));
    /*
        combine the graph background and watermark into temp
        addWeighted(image_1, weight of image_1, image_2, weight of image_2, weight of output, output image)
        where the calculation is 1 * weight_1 + 2 * wight_2 + weight_output = output
    */
    addWeighted(imgROI,0.5,watermark,0.5,0,imgROI);

    namedWindow("window");
    imshow("window", background);
    imwrite ("output.ppm", background);
    waitKey(0); 

    return 0;
}