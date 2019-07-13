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

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    gray = np.float32(gray)
    dst = cv2.cornerHarris(gray, 2, 3, 0.04)

    # Result is dilated for marking the corners, not important
    dst = cv2.dilate(dst, None)

    # Threshold for an optimal value, it may vary depending on the image.
    img[dst > 0.01*dst.max()] = [0, 0, 255]

    cv2.imshow('image', img)
    print('\033[1;32mAdd highlighted coner on the image.\033[0m')
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