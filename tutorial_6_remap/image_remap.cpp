#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    Mat input = imread("input.ppm");
    // create 3 set (x,y)
    Mat map_x_1,map_y_1,map_x_2,map_y_2,map_x_3,map_y_3;
    map_x_1.create(input.size(), CV_32FC1);
    map_y_1.create(input.size(), CV_32FC1);
    map_x_2.create(input.size(), CV_32FC1);
    map_y_2.create(input.size(), CV_32FC1);
    map_x_3.create(input.size(), CV_32FC1);
    map_y_3.create(input.size(), CV_32FC1);
    // IH is the height and IW is the width
    for(int iH=0; iH<input.rows; iH++){ 
        for(int iW=0; iW<input.cols; iW++){
            // map 1 will reflex left and right hand side
            map_x_1.at<float>(iH,iW) = iW ;
            map_y_1.at<float>(iH,iW) = input.rows - iH ;
            // map 2 will reflex top and down side
            map_x_2.at<float>(iH,iW) = input.cols - iW ;
            map_y_2.at<float>(iH,iW) = iH ;
            // map 3 will rotate 180 degree
            map_x_3.at<float>(iH,iW) = input.cols - iW ;
            map_y_3.at<float>(iH,iW) = input.rows - iH ;
        } 
    }
    // Do the remap that change the pixels value
    Mat output1,output2,output3;
    remap(input, output1, map_x_1, map_y_1, CV_INTER_LINEAR);
    remap(input, output2, map_x_2, map_y_2, CV_INTER_LINEAR);
    remap(input, output3, map_x_3, map_y_3, CV_INTER_LINEAR);

    imwrite("remap_1.ppm", output1);
    imwrite("remap_2.ppm", output2);
    imwrite("remap_3.ppm", output3);
    waitKey(0);

    return 0;
}
