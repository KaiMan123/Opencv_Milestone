#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv){
    try {
        // this choose the image add into the image
        Mat watermark = imread("./Resources/test2.png",CV_LOAD_IMAGE_UNCHANGED);
        resize(watermark, watermark, cv::Size(), 0.5, 0.5);
        // this choos the image as the background (it should be large enough)
        Mat background = imread("./Resources/test3.png",CV_LOAD_IMAGE_UNCHANGED);
        resize(background, background, cv::Size(), 0.5, 0.5);
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
        Mat temp(500, 500, CV_8UC3);
        /*
            get image from watermark which
            start from (0, 0) on the left top coner
            with size (100, 100)
        */
        Mat croppedImage = watermark(Rect(0, 0, 500, 500));
        /*
            get image from background with
            0 is position of x start from the left
            0 is position of y start from the top
            cut the image with width same as the background.cols 
            cut the image with height same as the background.rows 
        */
        Mat imgROI = background(Rect(0, 0, 500, 500));
        /*
            combine the graph background and watermark into temp
            addWeighted(image_1, weight of image_1, image_2, weight of image_2, weight of output, output image)
            where the calculation is 1 * weight_1 + 2 * wight_2 + weight_output = output
        */
        addWeighted(croppedImage, 0.5, imgROI, 0.5, 0.5, temp);

        namedWindow("window");
        imshow("window", croppedImage);
        std::cout << "\033[1;32mOriginal cropped Image1.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        imshow("window", imgROI);
        std::cout << "\033[1;32mOriginal cropped Image2.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        imshow("window", temp);
        std::cout << "\033[1;32mOriginal added weight Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);

        std::cout << "\033[1;36m" << argv[0] << " finshed.\033[0m" << std::endl;
        std::cout << "\033[1;33mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        return 0;
    }
    catch( const std::exception& e ){
        std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[1;31m" << std::endl;
        std::cout << "\033[1;33mPress Enter to continue.\033[0m" << std::endl;
        std::cin.ignore();
    }
}