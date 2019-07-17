# Opencv && Python

### Installation for ubuntu 16.04
1. Update your system
```
sudo apt-get update
sudo apt-get upgrade
```
2. Install Pyhon version >= 3.6
```
sudo add-apt-repository ppa:jonathonf/python-3.6
sudo apt-get update
sudo apt-get install python3.6
sudo apt-get install python3.6-dev
sudo python3.6 -m pip install numpy
```
3. Install Opencv4 dependencies
```
sudo apt-get install build-essential cmake unzip pkg-config \
	libjpeg-dev libpng-dev libtiff-dev libavcodec-dev \
	libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev \
	libx264-dev libgtk-3-dev libatlas-base-dev gfortran \
	libopencv-dev
```
4. Download Opencv4
```
cd ~
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.0.0.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.0.0.zip
unzip opencv.zip
unzip opencv_contrib.zip
mv opencv-4.0.0 opencv
mv opencv_contrib-4.0.0 opencv_contrib
```
5. CMake and Compile Opencv4
```
cd ~/opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
	-D CMAKE_INSTALL_PREFIX=/usr/local \
	-D INSTALL_PYTHON_EXAMPLES=ON \
	-D INSTALL_C_EXAMPLES=OFF \
	-D OPENCV_ENABLE_NONFREE=ON \
	-D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
	-D PYTHON_EXECUTABLE=/usr/bin/python3.6 \
	-D BUILD_EXAMPLES=ON ..
make -j4
=> *You can use 'make -?*' instead of 'make -j4'. ? dependends on the CPU that you want to allocate for compilation.*
```

**Import Error:**

If you cannot import cv2 with the use of python3.6

`ImportError: /opt/ros/kinetic/lib/python2.7/dist-packages/cv2.so: undefined symbol: PyCObject_Typ`

try solution:

`sudo rm /opt/ros/kinetic/lib/python2.7/dist-packages/cv2.so`

### Basic Opencv

This parts give a brief description about opencv. `opencv.bash` is Simple Bash Script for testing the simple functions in opencv. Please run it in linux system.

`$ bash opencv.bash`

Simple Control:

1. Input choices's number (int) or name (string) to select.
2. Input b (char) or back (string) to go backward.
3. Input exit (string) to exit the program.

Or, you can run the task one by one.

For python: `python3.6 filename --image 'image name' --video 'video name'`

For c++:
```
g++ -ggdb filename -o runnable `pkg-config --cflags --libs opencv`
chmod 777 runnable
./runnable
```

### Conclusion
There are still a lots of functions and interesting project about opencv. Here is only my learning experience about opencv. Thus, it only include simple opencv functions or usage. For more, you may look at following website:

[Full python tutorial](https://docs.opencv.org/master/d9/df8/tutorial_root.html): This web side include c++, java and python opencv tutorial.

[Ramer–Douglas–Peucker algorithm](https://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm): It seems high tech and useful for contours detection, but I had not try it before.

[Object tracking](https://www.pyimagesearch.com/2018/07/30/opencv-object-tracking/): Object tracking is quite simple in computer vision.

[Opencv python + Tensorflow](https://www.itread01.com/content/1546931718.html): Tensorflow is useful packed machine learning library. Include tensorflow can help you handle more difficult computer vision problem with the use of opencv.
