#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

void sharpen(const Mat &src, Mat &dst);

int main(int argc, char** argv){
    try {
        // read image input.ppm
        Mat input = imread("./Resources/test.jpg",CV_LOAD_IMAGE_UNCHANGED);
        // init output image
        Mat output;
        // call sharpen funcrion
        sharpen(input, output);
        // output image into output.ppm
        imshow("image", input);
        std::cout << "\033[1;32mOriginal Image.\033[0m" << std::endl;
        std::cout << "\033[1;36mPress any key to continue.\033[0m" << std::endl;
        waitKey(0);
        imshow("image", output);
        std::cout << "\033[1;32mSharpen image1.\033[0m" << std::endl;
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

void sharpen(const Mat &input, Mat &output){
    // copy input image into output image
    input.copyTo(output);
    // Save the input channels used in for loop
    const int nChannels = input.channels();
    // max height = input height - 1 because we use iH+1 (line 38) in for loop
    int heightLimit = input.rows - 1;
    // output width = (input - 1) * channels because we use iW+nChannels (line 48) in for loop
    int widthLimit = nChannels * (input.cols-1);
    // As we need to have iH-1 (line 35), width should not be less than 1
    for(int iH=1; iH < heightLimit; iH++){
        /*
            We are combining 4 input pixels into 1 uchar because uchar is a 4-value container
            As we have 3 uchar with IH (height) to form 3 line
            prePtr and curPtr and nextPtr can be combined together to form a 3(rows) * 4(cols) filters
        */
        const uchar *prePtr = input.ptr<const uchar>(iH-1);
        const uchar *curPtr = input.ptr<const uchar>(iH);
        const uchar *nextPtr = input.ptr<const uchar>(iH+1);
        // also we have one uchar to store the result
        uchar *outputPtr = output.ptr<uchar>(iH);
        /*
            We use nChannels as the starting point of for loop because
            one pixels have 3 or 1 values if channel number is 3 or 1 
            As we need to have curPtr[iW-nChannels], width should not be less than nChannels
        */
        for(int iW=nChannels; iW<widthLimit; iW++){
            /*
                If we use saturate_cast, final result is 0~255. 
                If we get smaller than 0, result would be 0. If we get greater than 255, result would be 255.
                sharpen calculation
                output pixels = 5 * middle pixels - 1 previous previous pixels - 1 next next pixels - 1 previous pixels - 1 next pixels
            */
            outputPtr[iW] = saturate_cast<uchar>(5*curPtr[iW]-curPtr[iW-nChannels]-curPtr[iW+nChannels]-prePtr[iW]-nextPtr[iW]);
        }
    }
}