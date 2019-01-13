#include <iostream>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
	/*
		read image input.ppm
		CV_LOAD_IMAGE_UNCHANGED = read image with no change
		CV_LOAD_IMAGE_GRAYSCALE = read image with grey color
		CV_LOAD_IMAGE_COLOR 	= read image with color RGB
	*/
	Mat img = imread("input.ppm",CV_LOAD_IMAGE_UNCHANGED);
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
	//wait until keyboard input is Esc (Esc ASCII is 27)
	while(true){
        imshow("WindowName", img);     
        if(cvWaitKey(0)==27){                      
            break;
        }
    }
	//write image into output1.ppm
	imwrite ("output.ppm", img);
	/*
		change the quality of image
		CV_IMWRITE_JPEG_QUALITY = init as 95
		{0...100} = we can also directly input 0 to 100 into it
	*/
	vector<int> quality;
	quality.push_back(CV_IMWRITE_JPEG_QUALITY);
	quality.push_back(10);
	//write new changed quality image into output2.jpg 
	imwrite("output2.ppm", img, quality	);
	return 0;
}
