#include <cstdio>
#include <iostream>
#include <string>
#include <exception>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv){
    try {
        // declear a empty image
        Mat img(400, 400, CV_8UC3, Scalar(255,255,255));
        // draw a line from point 20,40 to 120,140 with RGB color 255,0,0 and thickness 3
        line(img, Point(20,40), Point(120,140), Scalar(255,0,0), 3);
        // draw a rectangle from point 150,40 to 250,140 with RGB color 0,0,255 and thickness -1
        // CV_FILLED or negative thickness means fill the whole rectangle
        rectangle(img, Point(150,40), Point(250,140), Scalar(0,0,255), -1);
        // draw a circle at 330,90 with radius 50, RGB color 0,255,0 and thickness -1
        circle(img, Point(330,90), 50, Scalar(0,255,0), -1);
        // draw a ellipse at 80,280 with axes 60,40, RGB color 255,255,0 and thickness 2
        // starting from angle 0 to angle 360 with angle unit 45
        ellipse(img, Point(80,280), Size(60,40), 45, 0, 360, Scalar(255,255,0), 2);
        // draw 5 point on 5 different position
        Point points[1][5];
        points[0][0] = Point(150, 270);
        points[0][1] = Point(190, 220);
        points[0][2] = Point(260, 255);
        points[0][3] = Point(224, 296);
        points[0][4] = Point(178, 316);
        const Point* ppt[1] = {points[0]};
        int npt[] = {5};
        // connect the 5 point together to form a closed polygon
        // input image, vertex point Mat, curve vertex point Mat, number of curve vertex, 
        // (1 open polygon) -1 is closed polygon, color(0,255,255), thickess 5
        polylines(img, ppt, npt, 1, 1, Scalar(0,255,255),5);
        // Draw string "OpenCV" on image at position 280,280 
        // with front sytle 0, front size 1, color 0,0,0 and thickness 3
        putText(img, string("Good"), Point(280,280), 0, 1, Scalar(0,0,0),3);
        // output the img
        imshow("image", img);
        std::cout << "\033[1;32mDrawn Image.\033[0m" << std::endl;
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