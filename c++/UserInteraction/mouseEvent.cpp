#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

void onMouse(int Event,int x,int y,int flags,void* param);
Point VertexLeftTop(-1,-1);
Point VertexRightDown(-1,-1);

int main(int argc, char** argv){
    try {
        Mat src = imread("./Resources/test.jpg",CV_LOAD_IMAGE_UNCHANGED);
        namedWindow("image",0);
        // the function do when there has a mouse event
        setMouseCallback("image",onMouse,NULL);

        std::cout << "\033[1;36mPress q to finish the program.\033[0m" << std::endl;
        while(true){
            if(VertexLeftTop.x==-1 && VertexRightDown.x==-1){
                // this condition is no mouse event or the mouse only pressed and still not release
                // it just shows the image we have
                imshow("image", src);
            }
            if(VertexLeftTop.x!=-1 && VertexRightDown.x!=-1){
                // draw the rectangle with the use of x and y position when mouse pressed and released
                rectangle(src, Rect(VertexLeftTop,VertexRightDown),Scalar(255,0,0),2);
                // after retangle was drawed, set the mouse event value back to initial
                VertexLeftTop.x = -1;
                VertexLeftTop.y = -1;
                VertexRightDown.x = -1;
                VertexRightDown.y = -1;
                imshow("image", src);
            }
            // if 'q' on the keyboard is pressed, then end this program 
            if(waitKey(33) == (int)('q')){ 
                std::cout << "\033[1;36m" << argv[0] << " finshed.\033[0m" << std::endl;
                std::cout << "\033[1;33mPress any key to continue.\033[0m" << std::endl;
                waitKey(0);
                break;
            }
        }
        return 0;
    }catch( const std::exception& e ){
        std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
        std::cout << "\033[1;33mPress Enter to continue.\033[0m" << std::endl;
        std::cin.ignore();
    }
}
// return the x and y position of mouse on the image
void onMouse(int Event,int x,int y,int flags,void* param){
    // return the x and y position when mouse left button was pressed
    if(Event==CV_EVENT_LBUTTONDOWN){
        VertexLeftTop.x = x;
        VertexLeftTop.y = y;
    }
    // return the x and y position when mouse left button was released
    if(Event==CV_EVENT_LBUTTONUP){
        VertexRightDown.x = x;
        VertexRightDown.y = y;
    }
}
