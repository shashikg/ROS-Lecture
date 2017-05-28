#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

using namespace std;
using namespace ros;

int main(int argc, char **argv)
{
	init(argc, argv,"pub_node"); // Initiallising publisher node
	NodeHandle nh; // declaring node handle.
	Publisher pub_name = nh.advertise<std_msgs::Int32>("/topic",10); 
	//Declaring publisher with name of publisher as pub_name and pub topic name as "/topic".
	//and buffer size as 10. buffer size specifies the no of messages to keep before throwing away
	//some to store new messages.
	Rate loop_rate(10); //defining loop rate
	
	while (ros::ok()) //ros::ok() gives true value when node is active and vice-versa
	{
		std_msgs::Int32 pub_msg;//declaring a msg variable
		cout<<"enter a no: ";
		cin>>pub_msg.data;
		//you can know the structure type of a message by typing the terminal command as
		//rosmsg show package_name/message_name
		pub_name.publish(pub_msg); //publishing the msg
		spinOnce(); //spinOnce is used to check whether the node has recieved any callbacks, we don't exactly need it here.
		loop_rate.sleep(); //starting the sleep to get the desired loop time.
	}
	return 0;
}


