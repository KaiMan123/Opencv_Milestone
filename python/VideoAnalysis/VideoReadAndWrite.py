import cv2
import argparse
import os

try:
    # Using Argument Parser to get the location of video
    ap = argparse.ArgumentParser()
    ap.add_argument('-i', '--image', required=True, help='Path to image')
    ap.add_argument('-v', '--video', required=True, help='Path to video')
    args = ap.parse_args()

    cap = cv2.VideoCapture(args.video)

    # Check if video opened successfully
    if (cap.isOpened() == False): 
        print("\033[1;31mUnable to read camera feed\033[0m")
    else:
        frame_width = int(cap.get(3))
        frame_height = int(cap.get(4))
        # DIVX, XVID, MJPG, X264, WMV1, WMV2. (XVID is more preferable. 
        # MJPG results in high size video. X264 gives very small size video)
        out = cv2.VideoWriter(os.path.dirname(os.path.abspath(__file__))+'/result.avi', cv2.VideoWriter_fourcc('M','J','P','G'), 10, (frame_width,frame_height))

        print('\033[1;36mPress q to finish the program.\033[0m')
        while(cap.isOpened()):
            ret, frame = cap.read()
            if ret == True:
                out.write(frame)
                cv2.imshow('frame', frame)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
            else:
                break
        cap.release()
        out.release()
        cv2.destroyAllWindows()
    
    print('\033[1;32mVideo saved at '+os.path.dirname(os.path.abspath(__file__))+'.\033[0m')
    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')

except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise