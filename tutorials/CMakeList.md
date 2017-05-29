# How to edit CMakeLists.txt
### Adding buil depends
Build depends are added inside the function find_Package
```python
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)
```
### Adding message files
```py
add_message_files(
   FILES
   demo_msg.msg
)
```
### Adding service files
```py
add_service_files(
  FILES
  demo_srv.srv
)
```
### Adding message dependencies for generating the msg and srv files.
```py
 generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
 )
```
### Adding run depends
```py
catkin_package(
   CATKIN_DEPENDS message_runtime roscpp rospy std_msgs
)
```
### Adding needed directories
At present stage just add the below command.
```py
include_directories(
  ${catkin_INCLUDE_DIRS}
)
```
### Adding C++ executables
```py
add_executable(demo src/demo.cpp)
target_link_libraries(demo ${catkin_LIBRARIES}) 
add_dependencies(demo ros_lec_generate_messages_cpp)
```
The add dependencies here makes sure message headers of this package are generated before being used. If you use message headers from other packages as well you need to add those also.
