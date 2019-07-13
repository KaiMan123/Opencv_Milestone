#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv){
    try {
        Mat input = imread("./Resources/test.jpg", CV_LOAD_IMAGE_COLOR);
        Mat input_gray = imread("./Resources/test.jpg", CV_LOAD_IMAGE_GRAYSCALE);
        // copy the full matrix input to contoursImg
        Mat contoursImg = input.clone();
        // do simple blur
        blur(input_gray, input_gray, Size(3,3));
        // do Canny (find the edge)
        Mat edge;
        Canny(input_gray, edge, 50, 150, 3);

        // vector use to store the contours
        vector< vector<Point> > contours;
        // vector use to store level of those contours
        vector<Vec4i> hierarchy;
        // set a random seed
        RNG rng(12345);
        /*
        findContours(input image, vector saved contours, vector save the level of contours, way to get contours, way to save contours)
        ********************************************
            way to get contours
                CV_RETR_EXTERNAL    : only get the outest contours
                CV_RETR_LIST        : get all contours without hierarchy
                CV_RETR_CCOMP       : save two level outest contours and contours of hollow part
                CV_RETR_TREE        : get all contours with hierarchy
        ********************************************
            way to save contours
                CV_CHAIN_APPROX_NONE    : save all contour
                CV_CHAIN_APPROX_SIMPLE  : only save vertices that is the interception
        */
        findContours(edge, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
        for(int i = 0; i<contours.size(); i++){
            // set a random deepth red color as the contours color
            Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0, 255), 255);
            // draw the contours
            drawContours(contoursImg, contours, i, color, 2, 8, hierarchy);
        }

        imshow("image", input);
        std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        imshow("image", contoursImg);
        std::cout << "\033[1;32mImage with contours.\033[0m" << std::endl;
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