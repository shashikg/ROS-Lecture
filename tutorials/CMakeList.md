# How to edit CMakeLists.txt
## Adding buil depends
Build depends are added inside the function find_Package
```py
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)
```
