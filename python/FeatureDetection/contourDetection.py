import numpy as np
import cv2
import argparse
import os

try:
    # Using Argument Parser to get the location of video
    ap = argparse.ArgumentParser()
    ap.add_argument('-i', '--image', required=True, help='Path to image')
    ap.add_argument('-v', '--video', required=True, help='Path to video')
    args = ap.parse_args()
    
    img = cv2.imread(args.image)

    cv2.imshow('image', img)
    print('\033[1;32mOriginal image.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    cv2.waitKey(0) 

    # Grayscale 
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 

    cv2.imshow('image', gray)
    print('\033[1;32mConvert RGB image into gray image.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    cv2.waitKey(0) 

    # Find Canny edges
    dst = cv2.Canny(gray, 30, 200) 
    cv2.waitKey(0)

    # Finding Contours
    contours, hierarchy = cv2.findContours(dst, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE) 

    cv2.imshow('image', dst)
    print('\033[1;32mGet the contours on the gray image.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    cv2.waitKey(0)

    # Draw all contours
    cv2.drawContours(img, contours, -1, (0, 255, 0), 3)

    cv2.imshow('image', img)
    print('\033[1;32mShow contours on original image.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    cv2.waitKey(0)

    cv2.destroyAllWindows() 

    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')

except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise

