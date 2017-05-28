//including important header files.
#include "ros.h"
#include "std_msgs/Int32"
#include "Arduino.h"


//CReating node handle with a name of nh..
ros::NodeHandle nh;

//Declaration of msg variables as global variables..
std_msgs::Int32 pub_msg;

//Publisher definations goes here. 
//Use "pub_name.publish(&pub_msg);" to publish the data to the topic..
ros::Publisher pub_name("pub_topic_name", &pub_msg); 

//Callback for Subscriber.
void sub_callback(const std_msgs::Int32& sub_msg)
{
	// will recieved subscribed topics data inside the variable sub_msg.data
	// write the needed codes here. which are to be done, using the subsricbed data.
}

//Defination of subscriber goes here..
ros::Subscriber<std_msgs::Int32> sub_name("sub_topic_name", sub_callback);

//callback function, subscriber and publishers should be declared above setup function to give it a global scope..
void setup()
{
	nh.initNode(); //initialising the node
	nh.advertise(pub_name); //start advertising
	nh.subscribe(sub_name); //start subscribing
}

void loop()
{
	nh.spinOnce();
	delay(some_delay_duration);
}
