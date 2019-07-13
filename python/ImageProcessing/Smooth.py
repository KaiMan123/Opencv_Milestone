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

    blur = {
        # Removing noises by removing high frequency content
        0: cv2.blur(img,(5,5)),
        # Compare with simple blur function,
        # Better effective in removing gaussian noise
        1: cv2.GaussianBlur(img,(5,5),0)
    }

    def dst(choice):
        return blur[choice]

    for i in range(0, 2):
        newImg = dst(i)
        cv2.imshow('image', img)
        print('\033[1;32mOriginal image.\033[0m')
        print('\033[1;36mPress any key to continue.\033[0m')
        k = cv2.waitKey(0)
        cv2.imshow('image', newImg)
        if i == 0:
            print('\033[1;32mSimple blur image.\033[0m')
        else:
            print('\033[1;32mGaussian blur image.\033[0m')
        print('\033[1;36mPress any key to continue.\033[0m')
        k = cv2.waitKey(0)

    cv2.destroyAllWindows()
    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')

except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise