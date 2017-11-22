# Create catkin Package
Open your terminal window.
First change your directory to ROS workspace/src, or run the below command
```sh
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
```
After that run the following command to create your package along with dependencies
```sh
$ catkin_create_pkg ros_lec std_msgs rospy roscpp
```
here ros_lec is the package name and other parameters i.e. std_msgs rospy and roscpp are its dependencies. Dependencies are liberaries on which your current package is going to depend. Lib 'roscpp' is included for your package will contain cpp files.
Go back to your catkin_ws directory and run the catkin_make command to build your package.
```sh
$ cd ~/catkin_ws/
$ catkin_make
```
That's all you had succesfully created your first package now its time to add some executables(programmed files of any language which you prefer), msg and srv files.
