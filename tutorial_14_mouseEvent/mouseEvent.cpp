#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

void onMouse(int Event,int x,int y,int flags,void* param);
Point VertexLeftTop(-1,-1);
Point VertexRightDown(-1,-1);

int main(){
    Mat src = imread("mini.jpg",CV_LOAD_IMAGE_UNCHANGED);
    namedWindow("image",0);
    // the function do when there has a mouse event
    setMouseCallback("image",onMouse,NULL);

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
        if(cvWaitKey(33)==27){
            break;
        }
    }
    return 0;
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
