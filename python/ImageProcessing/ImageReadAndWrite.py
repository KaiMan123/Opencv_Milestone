import cv2
import argparse
import os

try:
    # Using Argument Parser to get the location of image
    ap = argparse.ArgumentParser()
    ap.add_argument('-i', '--image', required=True, help='Path to image')
    ap.add_argument('-v', '--video', required=True, help='Path to video')
    args = ap.parse_args()

    # read the image 'test.jpg' in RGB format
    img = cv2.imread(args.image)
    # read the image 'test.jpg' in Gray format
    img2 = cv2.imread(args.image, 0)
    # Convert RGB image into Gray format
    img3 = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

    # define a window with name 'image'
    # you can ignore the window, but then you cannot resize windows
    cv2.namedWindow('image', cv2.WINDOW_NORMAL)

    # show the RGB image on the window named 'image'
    cv2.imshow('image', img)
    print('\033[1;32mImage read in RGB format.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    k = cv2.waitKey(0)

    # show the Gray image on the window named 'image'
    cv2.imshow('image', img2)
    print('\033[1;32mImage read in Gray format.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    k = cv2.waitKey(0)

    # show the Gray image converted from RGB format on the window named 'image'
    cv2.imshow('image', img3)
    print('\033[1;32mImage converted from RGB format.\033[0m')
    print('\033[1;36mPress any key to continue.\033[0m')
    print('\033[1;36mOr press ''q'' to save the image.\033[0m')
    k = cv2.waitKey(0)

    # if key read is 'q', save the image before left
    if k == ord('q'):
        # write the image as 'result.png'
        cv2.imwrite(os.path.dirname(os.path.abspath(__file__))+'/result.png', img)
        print('\033[1;32mImage saved at '+os.path.dirname(os.path.abspath(__file__))+'.\033[0m')
        cv2.destroyAllWindows()
    # if key read is not 'q', left directly
    else:
        cv2.destroyAllWindows()
    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    
except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise