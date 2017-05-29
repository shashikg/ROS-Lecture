#Converting a C++ executable into a ROS supported
## Genral things to be done
Every C++ node should contains the following lines.
```c
//required header files you need to add headers files which you need for your node
#include "ros/ros.h" //this header is compulsory.
#include "std_msgs/Int32.h"
```
