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

    edge = {
        # Sobel operators is a joint Gausssian smoothing plus differentiation operation
        0: cv2.Sobel(img, cv2.CV_8U, 1, 0, ksize=5),
        # Laplacian of the image improved from Sobel
        1: cv2.Laplacian(img, cv2.CV_8U),
        # Canny is the best edge detection improved from Sobel
        2: cv2.Canny(img, 100, 200)
    }

    def dst(choice):
        return edge[choice]

    for i in range(0, 3):
        newImg = dst(i)
        cv2.imshow('image', img)
        print('\033[1;32mOriginal image.\033[0m')
        print('\033[1;36mPress any key to continue.\033[0m')
        k = cv2.waitKey(0)
        cv2.imshow('image', newImg)
        if i == 0:
            print('\033[1;32mSobel image.\033[0m')
        if i == 1:
            print('\033[1;32mLaplacian image.\033[0m')
        if i == 2:
            print('\033[1;32mCanny image.\033[0m')
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