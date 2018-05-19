#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"
#include "ros_lecture/cmsg.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "talker_cmsg");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<ros_lecture::cmsg>("array", 100);
	ros::Rate loop_rate(1);

	while (ros::ok()){
		ros_lecture::cmsg data;
		data.word="hello";
		data.number=10;
		pub.publish(data);
		ros::spinOnce();
		loop_rate.sleep();
	}

}
