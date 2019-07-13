#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

void simpleblur(){
    Mat src = imread("./Resources/test.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat aveBlur;
    blur(src, aveBlur, Size(3,3));
    imshow("image", src);
    std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
    imshow("image", aveBlur);
    std::cout << "\033[1;32mBlur Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
}

void gaussian_blur(){
    Mat src = imread("./Resources/test.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat gaussianBlur;
    GaussianBlur(src, gaussianBlur, Size(3,3), 0, 0);
    imshow("image", src);
    std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
    imshow("image", gaussianBlur);
    std::cout << "\033[1;32mGaussian Blur Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
}

void median_blur(){
    Mat src = imread("./Resources/test.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat dst;
    medianBlur(src, dst, 5);
    imshow("image", src);
    std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
    imshow("image", dst);
    std::cout << "\033[1;32mMedian Blur Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
}

void bilateral_filter(){
    Mat src = imread("./Resources/test.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat dst;
    bilateralFilter(src, dst, 5, 30, 30);
    imshow("image", src);
    std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
    imshow("image", dst);
    std::cout << "\033[1;32mBilateral Image.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
}

int main(int argc, char** argv){
    try {
        simpleblur();
        gaussian_blur();
        median_blur();
        bilateral_filter();
        std::cout << "\033[1;36m" << argv[0] << " finshed.\033[0m" << std::endl;
        std::cout << "\033[1;33mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
    }
    catch( const std::exception& e ){
        std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[1;31m" << std::endl;
        std::cout << "\033[1;33mPress Enter to continue.\033[0m" << std::endl;
        std::cin.ignore();
    }
}
