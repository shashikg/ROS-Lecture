# Create catkin Package
First change your directory to to ROS workspace/src, then run the below command
```sh
$ cd ~/catkin_ws/src
```
After that run the following command to create your package along with dependencies
```sh
$ catkin_create_pkg ros_lec std_msgs rospy roscpp
```
here ros_lec is the package name and other parameters i.e. std_msgs rospy and roscpp are dependencies.
Go back to your catkin_ws directory and run the catkin_make command to build your package.
```sh
$ cd ~/catkin_ws/
$ catkin_make
```
That's all you had succesfully created your first package now its time to add some executables, msg and srv files.
