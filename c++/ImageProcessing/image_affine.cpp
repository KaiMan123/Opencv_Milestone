#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv){
    try {
        Mat input = imread("./Resources/test.jpg");
        // Set the output image into empty with same size and type as the input
        Mat output1 = Mat::zeros(input.rows, input.cols, input.type());
        Mat output2 = Mat::zeros(input.rows, input.cols, input.type());

        // get three point from the input image 
        Point2f inputTri[3];
        inputTri[0] = Point2f(0, 0);
        inputTri[1] = Point2f(input.cols-1, 0);
        inputTri[2] = Point2f(0, input.rows-1);

        // get three point from the output image 
        Point2f outputTri[3];
        outputTri[0] = Point2f(0, input.rows*0.3);
        outputTri[1] = Point2f(input.cols*0.8, 0);
        outputTri[2] = Point2f(input.cols*0.1, input.rows*0.9);

        // the three point from input poject to the three point from output 
        Mat warp_mat = getAffineTransform(inputTri, outputTri);
        warpAffine(input, output1, warp_mat, output1.size());

        // set the rotation value
        Point center = Point(output2.cols/2, output2.rows/2);
        double angle = 30.0;
        double scale = 0.8;

        // do the rotation
        Mat rot_mat = getRotationMatrix2D(center, angle, scale);
        warpAffine(input, output2, rot_mat, output2.size());

        imshow("image", input);
        std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        imshow("image", output1);
        std::cout << "\033[1;32mShifted Image1.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        imshow("image", output2);
        std::cout << "\033[1;32mShifted Image2.\033[0m" << std::endl;
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

