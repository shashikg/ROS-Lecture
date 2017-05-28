cmake_minimum_required(VERSION 2.8.3)
project(ros_lec)

## Every commands in this files should be used in the given sequence of order only.

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)

## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   demo_msg.msg
 )

## Generate services in the 'srv' folder
 add_service_files(
   FILES
	demo_srv.srv
 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
 )

catkin_package(
   CATKIN_DEPENDS message_runtime roscpp rospy std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

## adding c++ executables..

add_executable(ros_lec_pub src/pub.cpp)
add_executable(ros_lec_sub src/sub.cpp)
add_executable(ros_lec_service src/server.cpp)
add_executable(ros_lec_client src/client.cpp)

## Add cmake target dependencies of the executable
## same as for the library above

add_dependencies(ros_lec_pub ros_lec_generate_messages_cpp)
add_dependencies(ros_lec_sub ros_lec_generate_messages_cpp)
add_dependencies(ros_lec_service ros_lec_generate_messages_cpp)
add_dependencies(ros_lec_client ros_lec_generate_messages_cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(ros_lec_pub
   ${catkin_LIBRARIES}
 )
 target_link_libraries(ros_lec_sub
   ${catkin_LIBRARIES}
 )
 target_link_libraries(ros_lec_service
   ${catkin_LIBRARIES}
 )
 target_link_libraries(ros_lec_client
   ${catkin_LIBRARIES}
 )