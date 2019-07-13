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

    def noCallback(value):
        pass

    cv2.namedWindow('colorboard')
    # Using trackbar for easier observation
    cv2.createTrackbar('h', 'colorboard', 0, 179, noCallback)
    cv2.createTrackbar('H', 'colorboard', 179, 179, noCallback)
    cv2.createTrackbar('s', 'colorboard', 0, 255, noCallback)
    cv2.createTrackbar('S', 'colorboard', 255, 255, noCallback)
    cv2.createTrackbar('v', 'colorboard', 0, 255, noCallback)
    cv2.createTrackbar('V', 'colorboard', 255, 255, noCallback)

    print('\033[1;36mPress q to finish the program.\033[0m')
    while True:
        # small case representing lower bound
        # large case representing upper bound
        h = cv2.getTrackbarPos('h', 'colorboard')
        H = cv2.getTrackbarPos('H', 'colorboard')
        s = cv2.getTrackbarPos('s', 'colorboard')
        S = cv2.getTrackbarPos('S', 'colorboard')
        v = cv2.getTrackbarPos('v', 'colorboard')
        V = cv2.getTrackbarPos('V', 'colorboard')
        # set the lower and upper bound of the required color
        lower = np.array([h, s, v],np.uint8)
        upper = np.array([H, S, V],np.uint8)

        # get the hsv diagram of the image
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        # get the region of point have hsv between lower and upper bound in hsv diagram
        region = cv2.inRange(hsv, lower, upper)
        # get the region in the image
        res = cv2.bitwise_and(img, img, mask = region)

        cv2.imshow('colorboard', res)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cv2.destroyAllWindows()
    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')

except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise