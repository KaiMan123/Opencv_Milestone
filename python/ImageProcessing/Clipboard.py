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
    img2 = img

    cv2.imshow('image', img)
    print('\033[1;32mOriginal Image.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    k = cv2.waitKey(0)

    # copy the image from point (40, 290) to (330, 490)
    roiImg = img[40:330,290:490]

    # paste the cropped on image from point (0, 0) to (290, 200)
    # addWeighted define the transparency between two image
    # 1 define soild and 0 define totally transparency
    img[0:290, 0:200] = cv2.addWeighted(img[0:290, 0:200], 0.4, roiImg, 0.6, 0)

    cv2.imshow('image', img)
    print('\033[1;32mAdd trasparent cropped image.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    k = cv2.waitKey(0)

    # paste the cropped on image from point (40, 390) to (330, 590)
    img[40:330, 390:590] = roiImg

    cv2.imshow('image', img)
    print('\033[1;32mAdd cropped image.\033[0m')
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