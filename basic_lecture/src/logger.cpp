#include "ros/ros.h"
#include <string.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "logger");
	ros::NodeHandle n;
	ros::Rate loop_rate(1);
	/*if( ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug) ) {
		ros::console::notifyLoggerLevelsChanged();
	}*/

	int count=0;
	while (ros::ok()){
		ROS_DEBUG("log:%i\n", count);
		ROS_INFO( "log:%i\n", count);
		ROS_WARN( "log:%i\n", count);
		ROS_ERROR("log:%i\n", count);
		ROS_FATAL("log:%i\n", count);

		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
