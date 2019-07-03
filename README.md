# Opencv && Python

### Installation for ubuntu 16.04
1. Update your system
```
sudo apt-get update
sudo apt-get upgrade
```
2. Install Pyhon version >= 3.6
```
sudo apt-get update
sudo apt-get install python3.6
sudo apt-get install python3.6-dev
sudo python3.6 -m pip install numpy
```
3. Install Opencv4 dependencies
```
sudo apt-get install build-essential cmake unzip pkg-config
sudo apt-get install libjpeg-dev libpng-dev libtiff-dev libavcodec-dev \
    libavformat-dev libswscale-dev libv4l-dev libxvidcore-dev libx264-dev
sudo apt-get install libgtk-3-dev
sudo apt-get install libatlas-base-dev gfortran
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
5. CMake Opencv4
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
```
6. Compile Opencv

**You can use 'make -?*' instead of 'make -j4'. ? dependends on the CPU that you want to allocate for compilation.**
```
cd ~/opencv/build/
make -j4
```

### Opencv4 Functions

