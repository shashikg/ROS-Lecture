
#include "ros/ros.h"
#include "ros_lec/demo_srv.h"
#include <iostream>
using namespace std;
using namespace ros;


bool service_callback(ros_lec::demo_srv::Request &req, ros_lec::demo_srv::Response &res)
{

	res.out=(req.in)*(req.in);
	cout<<"The no recieved is: "<<req.in<<" and The no responded is: "<<res.out<<endl<<endl;

	return true;
}

int main(int argc, char **argv)
{
	init(argc, argv, "server");
	NodeHandle nh;
	ServiceServer service = nh.advertiseService("sq", service_callback); //declaring serviceserver variable.
	spin();// spin to check for callbacks.
	return 0;
}

