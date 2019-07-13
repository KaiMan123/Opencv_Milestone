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
    print('\033[1;32mOriginal image.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    cv2.imshow('image', img)
    k = cv2.waitKey(0)

    rows = None
    cols = None

    def f0():
        global rows, cols, img
        img = cv2.resize(img, None, fx=1.5, fy=1.5, interpolation = cv2.INTER_CUBIC)
        # get the image shape (height, width, rbg/gray) after resize
        rows, cols, color = img.shape
        return img

    def f1():
        cv2.circle(img,(250,250), 10, (250,255,0), -1)
        cv2.circle(img,(400,250), 10, (250,255,0), -1)
        cv2.circle(img,(250,400), 10, (250,255,0), -1)
        return img

    def f2():
        return cv2.warpAffine(img,cv2.getRotationMatrix2D((cols/2, rows/2), 90, 1),(cols,rows))

    def f3():
        return cv2.warpAffine(img, np.float32([[1,0,100],[0,1,50]]), (cols, rows))

    def f4():
        pts1 = np.float32([[250,250],[400,250],[250,400]])
        pts2 = np.float32([[250,300],[400,250],[300,450]])
        M = cv2.getAffineTransform(pts1,pts2)
        return cv2.warpAffine(img, M, (cols, rows))

    transform = {
        # Resize the image as 1.5 times
        0: f0,
        # Assign three point for easier discover the difference
        1: f1,
        # Rotate 90 degree clockwisely
        2: f2,
        # Shift the whole image to right 100 and down 50
        3: f3,
        # Shift, rotate and resize the image so that
        # pts1 position on image becomes pts2 position
        # See the three point highlighted on the image
        4: f4
    }

    def dst(choice):
        return transform[choice]()

    for i in range(0, 5):
        newImg = dst(i)
        cv2.imshow('image', newImg)
        if i == 0:
            print('\033[1;32mResize the image as 1.5 times.\033[0m')
        if i == 1:
            print('\033[1;32mAdd three points for discovering differences.\033[0m')
        if i == 2:
            print('\033[1;32mRotate 90 degree clockwisely.\033[0m')
        if i == 3:
            print('\033[1;32mShift the whole image to right 100 and down 50.\033[0m')
        if i == 4:
            print('\033[1;32mConvert the whole image by changing the three highlighted point position.\033[0m')
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