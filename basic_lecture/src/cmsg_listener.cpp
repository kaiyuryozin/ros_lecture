#include "ros/ros.h"
#include "std_msgs/String.h"

#include "simple_udp.h"

simple_udp udp0("0.0.0.0",4001);

#include <string.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Rate loop_rate(10);

  udp0.udp_bind();

  while (ros::ok()){
	std::string rdata=udp0.udp_recv_nb();
	ROS_INFO("recv:%s\n", rdata.c_str());
	ros::spinOnce();
	loop_rate.sleep();
  }
  return 0;
}
