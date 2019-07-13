#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

void sobel(Mat & src){
    GaussianBlur(src, src, Size(3,3), 0, 0);
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);
    Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs(grad_y, abs_grad_y);
    Mat dst1, dst2;
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst1);
    threshold(dst1, dst2, 80, 255, THRESH_BINARY|THRESH_OTSU);
    imshow("image", dst1);
    std::cout << "\033[1;32mSobel Image1.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
    imshow("image", dst2);
    std::cout << "\033[1;32mSobel Image2.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
}

void laplacian(Mat & src){
    GaussianBlur(src, src, Size(3,3), 0, 0);
    Mat dst1, dst2, dst3;
    Laplacian(src, dst1, CV_16S, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs(dst1, dst2);

    threshold(dst2, dst3, 80, 255, THRESH_BINARY|THRESH_OTSU);
    
    imshow("image", dst2);
    std::cout << "\033[1;32mLaplacian Image1.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
    imshow("image", dst3);
    std::cout << "\033[1;32mLaplacian Image1.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
}

void canny(Mat & src){
    GaussianBlur(src, src, Size(3,3), 0, 0);
    Mat dst1, dst2;
    Canny(src, dst1, 50, 150, 3);
    threshold(dst1, dst2, 128, 255, THRESH_BINARY_INV);    
    imshow("image", dst1);
    std::cout << "\033[1;32mCanny Image1.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
    imshow("image", dst2);
    std::cout << "\033[1;32mCanny Image2.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
    waitKey(0);
}

int main(int argc, char** argv){
    try {
        Mat input = imread("./Resources/test.jpg", CV_LOAD_IMAGE_GRAYSCALE);

        // three ways to find the edge in the map
        imshow("image", input);
        std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        sobel(input);

        imshow("image", input);
        std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);

        laplacian(input);
        imshow("image", input);
        std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        
        canny(input);
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