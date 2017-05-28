# ROS-Lecture
This repo contains all the codes and files which will be used during the lecture so it is suggested to clone this repo to your local PC. Further instructions are given below please follow them for a smooth conduct. You are also advised to download the lecture slides from  [HERE](#) and the cheatsheat provided in this repo.
## Preparations
Everyone please come prepared. Details are given below what you need to do.
### Prerequisites
* Please make sure you have ubuntu running on your system.
* Know the ubuntu release you had been using.
* ROS installed according to your ubuntu release.
* Arduin IDE.
* A good text editor sublime is suggested.
* And your dedication!!!
### Installations
ROS have different distributions for different release of ubuntu. So, you need to install accordingly. Links for installation instruction for different distributions and supported ubuntu release are given below. Execute the command for Desktop-Full

| ROS Distribution | Ubuntu Release | Installation Instructions |
| ------ | ------ | ------ |
|Lunar|Zesty(17.04), Xenial (16.04 LTS)|http://wiki.ros.org/lunar/Installation/Ubuntu|
|Kinetic|Xenial (16.04 LTS), Wily (15.10)|http://wiki.ros.org/kinetic/Installation/Ubuntu|
|Jade|Ubuntu 15.04|http://wiki.ros.org/jade/Installation/Ubuntu|
|Indigo|Saucy (13.10) and Trusty (14.04)|http://wiki.ros.org/indigo/Installation/Ubuntu|

**Install Arduino IDE using the following command**
```sh
$ sudo apt-get install java-common
$ sudo apt-get install arduino
```
**Install rosserial**
```sh
$ sudo apt-get install ros-kinetic-rosserial ros-kinetic-rosserial-server ros-kinetic-rosserial-arduino ros-kinetic-rosserial-python
```
Please replace kinetic with the ROS distribution you are using.
### Verify your installation for ROS
In two seperate terminal window execute these two commands and verify whether a blue window opens up with a turtle in its center or not.
```sh
$ roscore
$ rosrun turtlesim turtlesim_node
```
## Setting up your ROS Workspace
Run the following commands in series to setup your workspace.
```sh
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
```
Now run this command
```sh
$ gedit ~/.bashrc
```
and add this **source ~/catkin_ws/devel/setup.bash** at the end of the .bashrc file.
## Setting up your Arduino IDE
First of all run the following commands one by one. Replace (sketchbook) with your exact location of Arduino IDE sketchbook.
```sh
$ cd ~/catkin_ws/src
$ git clone https://github.com/ros-drivers/rosserial.git
$ cd ~/catkin_ws/
$ catkin_make
$ rosrun rosserial_arduino make_libraries.py (sketchbook)/libraries
```
### Verify for Arduino IDE setup
Open Arduino IDE and check whether you can see **ros_lib** folder inside Examples.




