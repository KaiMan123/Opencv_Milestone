import cv2

try:
    # Get the camera on your device
    # Change the number in VideoVapture(*) can change the device
    # Once number does not have matched camera, it will failed at cv2.imshow()
    cap = cv2.VideoCapture(0)

    print('\033[1;36mPress q to finish the program.\033[0m')
    while(True):
        # ret is boolean of camera status
        # frame is image read from camera
        ret, frame = cap.read()
        cv2.imshow('frame', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
            
    cap.release()
    cv2.destroyAllWindows()
    print('\033[1;36m'+(__file__)+' finshed.\033[0m')
    input('\033[1;33mPress Enter to continue.\033[0m')

except Exception as e:
    print('\033[1;31m', e,'\033[0m')
    print('\033[1;31m')
    input('\033[1;33mPress Enter to continue.\033[0m')
    raise