#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat src = imread("mini.jpg");
    Mat dst1;
    Mat dst2;
    pyrDown(src, dst1, Size(src.cols/2, src.rows/2));
    pyrUp(dst1, dst2, Size(dst1.cols*2, dst1.rows*2));
    
    imwrite("pyrDown.jpg", dst1);
    imwrite("pyrUp.jpg", dst2);
    waitKey(0);

    return 0;
}
