import numpy as np 
import cv2
import os

try:
    # True if mouse is pressed
    drawing = False
    # For mouse position recording
    pt1_x , pt1_y = None , None
    # True for drawing
    # False for erasing
    mode = True

    # Mouse callback function
    def line_drawing(event, x, y, flags, param):
        global pt1_x, pt1_y, drawing
        # Mode: Drawing or Erasing
        # Drawing use background color's opposite
        # Earsing use background color
        # greater thickness for easiser erasing in erasing mode
        if mode:
            color = (255, 255, 255)
            thickness = 3
        else:
            color = (0, 0, 0)
            thickness = 20
            
        # if event is mouse left click, drawing mode
        if event == cv2.EVENT_LBUTTONDOWN:
            drawing = True
            pt1_x, pt1_y= x, y
        # if event is mouse move, draw the line according to position change
        elif event == cv2.EVENT_MOUSEMOVE:
            if drawing == True:
                cv2.line(img, (pt1_x,pt1_y), (x,y), color, thickness)
                pt1_x,pt1_y=x,y
        # if event is mouse left up <not clicked>, Not drawing mode
        elif event == cv2.EVENT_LBUTTONUP:
            drawing = False
            cv2.line(img, (pt1_x,pt1_y), (x,y), color, thickness)        

    # Create empty image
    img = np.zeros((400,400,3), np.uint8)
    # Define a window as 'Blackboard'
    cv2.namedWindow('Blackboard')
    # Set the mouse event on the window 'Blackboard'
    cv2.setMouseCallback('Blackboard', line_drawing)

    print('\033[1;32mYour are in drawing mode. Press ''c'' to change to erasing mode\033[0m')
    print('\033[1;36mPress q to finish the program.\033[0m')
    while True:
        # Show the image on window 'Blackboard'
        cv2.imshow('Blackboard', img)
        # Get the key input
        k = cv2.waitKey(1) & 0xFF
        # If pressed key is 'c', change mode
        if k == ord('c'):
            if mode:
                print('\033[1;32mYour are in earsing mode. Press ''c'' to change to drawing mode\033[0m')
            else:
                print('\033[1;32mYour are in drawing mode. Press ''c'' to change to erasing mode\033[0m')
            print('\033[1;36mPress q to finish the program.\033[0m')
            mode = not mode
        # If pressed key is 'q', quit the program
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