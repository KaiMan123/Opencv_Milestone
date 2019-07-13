#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv){
    try {
        /*
            read image input.ppm
            CV_LOAD_IMAGE_UNCHANGED = read image with no change
            CV_LOAD_IMAGE_GRAYSCALE = read image with grey color
            CV_LOAD_IMAGE_COLOR 	= read image with color RGB
        */
        Mat img = imread("./Resources/test.jpg",CV_LOAD_IMAGE_UNCHANGED);
        /*
            get image width and height
            width = img.cols or img.size().width
            hight = img.rows or img.size().height
            resize the windows with fixed size ratio
        */
        int width = img.cols;
        int height = img.rows;
        /*
            create windows
            WINDOW_AUTOSIZE = size of window depends on the Mat and cannot be modify
            WINDOW_NORMAL = size of window can be changed 
        */
        namedWindow("WindowName", WINDOW_NORMAL); 
        /*
            change window size
            resizeWindow(Name, Width, Height);
        */
        resizeWindow("WindowName", 1000, 1000);

        //show image
        imshow("WindowName", img);
        std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);

        //write image into output1.ppm
        imwrite ("./c++/ImageProcessing/output.ppm", img);
        std::cout << "\033[1;32mSaved image1.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);

        /*
            change the quality of image
            CV_IMWRITE_JPEG_QUALITY = init as 95
            {0...100} = we can also directly input 0 to 100 into it
        */
        vector<int> quality;
        quality.push_back(CV_IMWRITE_JPEG_QUALITY);
        quality.push_back(10);
        //write new changed quality image into output2.jpg 
        imwrite("./c++/ImageProcessing/output.jpg", img, quality);
        std::cout << "\033[1;32mSaved image2.\033[0m" << std::endl;
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