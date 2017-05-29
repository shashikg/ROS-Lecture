#Converting a C++ executable into a ROS supported
## Genral things to be done
Every C++ node should contains the following lines.
```c
//required header files you need to add headers files which you need for your node
#include "ros/ros.h" //this header is compulsory.
#include "std_msgs/Int32.h"

using namespace ros;
```
Just after the int main function add these two lines
```c
init(argc, argv,"demo_node"); // Initiallising node
NodeHandle nh; // declaring node handle.
```
ROS have differen type of data types for its subscribe, publisher, service and client and all are initialised in its own way. Below are given for all of them.
```c
//For Publisher declarartion plus initialisation
Publisher pub_name = nh.advertise<std_msgs::Int32>("/topic",10); 
	//Declaring publisher with name of publisher as pub_name and pub topic name as "/topic".
	//and buffer size as 10. buffer size specifies the no of messages to keep before throwing away
	//some to store new messages.

//For Subscriber declarartion plus initialisation
Subscriber sub_name = nh.subscribe("/topic",10,myfirst_callback); //Declaring subscriber with name as sub_name and sub topic name as "/topic".

//For Client
ServiceClient client = nh.serviceClient<ros_lec::demo_srv>("service_name");//declaring serviceclient variable client for service name as "sq"

//For Server
ServiceServer service = nh.advertiseService("service_name", service_callback); //declaring serviceserver variable.
```
