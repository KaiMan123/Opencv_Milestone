#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
/*
    Contrast is the bright color and dark color ratio
    When it is larger, the image will be more clear and color is more bright
*/

/*
    we use x’=a*x+b to change contrast
    x is the grey value of output image
    a is the slope
    y is the grey value of input image
    b is the y-intercept
    --------------------------------------------
    if a > 1, increase the contrast of output image
    if a < 1, decrease the contrast of output image
    if a=1 and b!=0, whole image pixels with same contrast
    if a=-1 and b=255, contrast of output image is reflected
*/

/*
    We can also use another  x’ = (x + esp)^r to get a better contrast
    if r > 1, high grey value increase contrast
    if r < 1, lower grey value increase contrast
    if r = 1, it was doint the x’=a*x+b
*/

/*
    Sometimes, we may use x’ = c*log(1 + x).
    It can make darkness part to be more clear.
*/

void linearTrans(const Mat &input, Mat &output){
    // init the output same as input
    output.create(input.size(), input.type());
    // set widthlimit as (channels of input image * number of pixels of input image width)
    int widthLimit = input.channels() * input.cols;
    // iH maximum is equal to input height
    for(int iH=0; iH<input.rows; iH++){
        // combine 4 pixels as 1 uchar
        const uchar *curPtr = input.ptr<const uchar>(iH);
        // 1 uchar to save the result
        uchar *outputPtr = output.ptr<uchar>(iH);
        // iW maximum is equal to widthlimit
        for(int iW=0; iW<widthLimit; iW++){
            // do the linear calculation x’=a*x+b
            outputPtr[iW] = saturate_cast<uchar>(1.5*curPtr[iW]+30);
        }
    }
}

int main(){
    // read image input.ppm
    Mat input = imread("input.ppm",CV_LOAD_IMAGE_UNCHANGED);
    // declear output1 and output2 image
    Mat output1;
    Mat output2;
    /*
        linearTrans(input, output1); is same as input.convertTo(output2,-1,1.5,30);
        because they do the same x’=a*x+b, but convertTo() is library function
    */
    // do linearTrans of input and save the result in output1
    linearTrans(input, output1);
    // x’=a*x+b in input.convertTo(x, type of output image(-1 means type is same as x), a, b)
    input.convertTo(output2,-1,1.5,30);

    imwrite("output1.ppm", output1);
    imwrite("output2.ppm", output2);
    waitKey(0); 

    return 0;
}

