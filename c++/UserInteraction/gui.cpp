#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
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

int main(int argc, char** argv){
    try{
        // get two image
        src1 = imread("./Resources/test2.png", CV_LOAD_IMAGE_UNCHANGED);
        src2 = imread("./Resources/test3.png", CV_LOAD_IMAGE_UNCHANGED);
        
        // set the intial and maximum value for the inserting ratio 
        sliderValue = 0;
        int sliderMaxValue = 100;
        namedWindow("trackbar demo", 0);
        // create a trackbar named "Ratio" with value from sliderValue to sliderMaxValue on the windows "trackbar demo"
        createTrackbar("Ratio", "trackbar demo", &sliderValue, sliderMaxValue, on_trackbar);
        // call the trackbar function
        on_trackbar(sliderValue, 0);

        std::cout << "\033[1;33mPress any key to finish the program.\033[0m" << std::endl;
        waitKey(0);

        std::cout << "\033[1;36m" << argv[0] << " finshed.\033[0m" << std::endl;
        std::cout << "\033[1;33mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        return 0;
    }catch( const std::exception& e ){
        std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[1;33mPress Enter to continue.\033[0m" << std::endl;
        std::cin.ignore();
    }
}
