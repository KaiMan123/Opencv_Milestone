#include <cstdio>
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
    imwrite("layer1_Sobel.jpg", dst1);
    imwrite("layer2_Sobel.jpg", dst2);
}

void laplacian(Mat & src){
    GaussianBlur(src, src, Size(3,3), 0, 0);
    Mat dst1, dst2, dst3;
    Laplacian(src, dst1, CV_16S, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs(dst1, dst2);

    threshold(dst2, dst3, 80, 255, THRESH_BINARY|THRESH_OTSU);
    
    imwrite("layer1_Laplacian.jpg", dst2);
    imwrite("layer2_Laplacian.jpg", dst3);
}

void canny(Mat & src){
    GaussianBlur(src, src, Size(3,3), 0, 0);
    Mat dst1, dst2;
    Canny(src, dst1, 50, 150, 3);
    threshold(dst1, dst2, 128, 255, THRESH_BINARY_INV);    
    imwrite("layer1_Canny.jpg", dst1);
    imwrite("layer2_Canny.jpg", dst2);
}

int main(){
    Mat input = imread("input.pgm", CV_LOAD_IMAGE_GRAYSCALE);
    // three ways to find the edge in the map
    sobel(input);
    laplacian(input);
    canny(input);
    return 0;
}