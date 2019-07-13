import numpy as np 
import cv2
import os

try:
    drawing = False
    pt1_x , pt1_y = None , None
    mode = True
    thickness = 5

    def mouseCallback(event, x, y, flags, param):
        global pt1_x, pt1_y, drawing, mode, thickness
        if mode:
            color = (255, 255, 255)
        else:
            color = (0, 0, 0)

        if event == cv2.EVENT_LBUTTONDOWN:
            drawing = True
            pt1_x, pt1_y= x, y
        elif event == cv2.EVENT_MOUSEMOVE:
            if drawing == True:
                cv2.line(img, (pt1_x,pt1_y), (x,y), color, thickness)
                pt1_x,pt1_y=x,y
        elif event == cv2.EVENT_LBUTTONUP:
            drawing = False
            cv2.line(img, (pt1_x,pt1_y), (x,y), color, thickness)        

    # Trackbar callback getting the value on the trackbar
    def barCallback(value):
        global thickness
        # Thickness cannot be 0 for drawing line
        if(value <= 0):
            value = 1
        # Set the thickness for drawing
        thickness = value

    img = np.zeros((400,400,3), np.uint8)
    cv2.namedWindow('Blackboard')
    cv2.setMouseCallback('Blackboard', mouseCallback)
    # Set the trackbar on the window 'Blackboard' named 'thickness'
    # with init value 3 and max value 50
    cv2.createTrackbar('thickness', 'Blackboard', 3, 50, barCallback)

    print('\033[1;32mYour are in drawing mode. Press ''c'' to change to erasing mode\033[0m')
    print('\033[1;36mPress q to finish the program.\033[0m')
    while True:
        cv2.imshow('Blackboard', img)
        k = cv2.waitKey(1) & 0xFF
        if k == ord('c'):
            if mode:
                print('\033[1;32mYour are in earsing mode. Press ''c'' to change to drawing mode\033[0m')
            else:
                print('\033[1;32mYour are in drawing mode. Press ''c'' to change to erasing mode\033[0m')
            print('\033[1;36mPress q to finish the program.\033[0m')
            mode = not mode
        elif k == ord('q'):
            break
    cv2.destroyAllWindows()
    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')

except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise