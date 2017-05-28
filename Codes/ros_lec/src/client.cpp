#include "ros/ros.h"
#include "ros_lec/demo_srv.h"
#include <iostream>

using namespace std;
using namespace ros;

int main(int argc, char **argv)

{
	init(argc, argv,"client");
	NodeHandle nh;
	ServiceClient client = nh.serviceClient<ros_lec::demo_srv>("sq");//declaring serviceclient variable client for service name as "sq"
	Rate loop_rate(10);
	while (ros::ok())
	{
		ros_lec::demo_srv srv; //service variable
		cout<<endl<<"enter a no: ";
		cin>>srv.request.in;
		if (client.call(srv))
		{
			//if service is ready print the response.
			cout<<"The response is: "<<srv.response.out<<endl;
		}else
		{
			ROS_ERROR("Failed to call service");
			return 1;
		}

		spinOnce();
		loop_rate.sleep();
	}
	return 0;
}


