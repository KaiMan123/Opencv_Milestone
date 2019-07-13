import numpy as np
import cv2
import argparse
import os

try:
    # Create a black image
    img = np.zeros((350,450,3), np.uint8)

    # draw a line from point 20,40 to 120,140 with RGB color 255,0,0 and thickness 3
    cv2.line(img,(20,20),(120,140),(255,0,0),3)

    # draw a rectangle from point 150,40 to 250,140 with RGB color 0,0,255 and thickness -1
    # CV_FILLED or negative thickness means fill the whole rectangle
    cv2.rectangle(img,(150,50),(250,140),(0,0,255),-1)

    # draw a circle at 330,90 with radius 50, RGB color 0,255,0 and thickness -1
    cv2.circle(img,(330,90), 50, (0,255,0), -1)

    # draw a ellipse at 80,280 with axes 60,40, RGB color 255,255,0 and thickness 2
    # starting from angle 0 to angle 360 with angle unit 45
    cv2.ellipse(img,(80,280),(60,40),45,0,360,(255,255,0),2)

    # connect the 5 point together to form a closed polygon
    # input image, vertex point Mat, curve vertex point Mat, number of curve vertex, 
    # (1 open polygon) -1 is closed polygon, color(0,255,255), thickess 5
    pts = np.array([[150,270],[190,220],[260,255],[224,296],[178,316]], np.int32)
    pts = pts.reshape((-1,1,2))
    cv2.polylines(img,[pts],True,(0,255,255), 5)

    # Draw string "Drawing" on image at position 280,280 
    # with front sytle 0, front size 1, color 0,0,0 and thickness 3
    cv2.putText(img,'Opencv',(280,280), 0, 1, (250,0,0), 3)

    cv2.imshow('image', img)
    k = cv2.waitKey(0)
    cv2.destroyAllWindows()
    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')

except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise