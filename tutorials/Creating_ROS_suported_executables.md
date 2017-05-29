# Converting a C++ executable into a ROS supported
## General things to be done
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
Variable declaration in ROS for different message types
```c
//pkgname::msg_name var_name; e.g.
std_msgs::Int32 pub_msg;
```
## Specific codes
### Publisher
You need to declare the message variable and store value in it and then use the following command to publish it.
```c
pub_name.publish(pub_msg); //publishing the msg
```
### Subscriber
You need to create a callback function to be called when any message pops on the topicit subscribes to.
```c
void sub_callback(const std_msgs::Int32& sub_msg) //Callback function nd storing the recieved msg in sub_msg...
{
	//do anything you want to do here.
	//The message recieved can be accesse using the variable sub_msg
	//in this case it is sub_msg.data
}
```
### Client
You need to declare the service variable and store value in it and then use the following command to send request to the service
```c
ros_lec::demo_srv srv; //service variable
// this is how value is stored in a servce variable srv.request.in
// srv_var.request.data_name_used_in_while_making_srv_file
// run this command to call service
client.call(srv)
//you will get your response in a varibale in srv_var.response.data_name_used_in_while_making_srv_file
```
### Service
You need to create a callback function to be called when any service request is made.
```c
bool service_callback(ros_lec::demo_srv::Request &req, ros_lec::demo_srv::Response &res)
{
	//req.data_name_used_in_while_making_srv_file will contain your queried varialbe
	//while res.data_name_used_in_while_making_srv_file is used to store the response data inside 
	//this callback function.
	return true;
}
```
## spin() and spinOnce()
You need to add any one of these two in order to check for callbacks.
