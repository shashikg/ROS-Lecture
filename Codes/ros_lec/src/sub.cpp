#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
using namespace std;
using namespace ros;

void myfirst_callback(const std_msgs::Int32& sub_msg) //Callback function nd storing the recieved msg in sub_msg...
{
	cout<< "The no. entered is: "<<sub_msg.data<<endl<<endl;	
}

int main(int argc, char **argv)
{
	init(argc, argv,"sub_node"); //Initialising the subscriber node
	NodeHandle nh; //Declaring nodehandle object
	Subscriber sub_name = nh.subscribe("/topic",10,myfirst_callback); //Declaring subscriber with name as sub_name and sub topic name as "/topic".
	spin();//spin is used to check whether the node has recieved any callbacks.
	return 0;
}


