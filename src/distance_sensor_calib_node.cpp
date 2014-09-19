#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "distance_sensor_calib_node");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("/distance_sensor_test_node/distance", 1000);

  ros::Rate loop_rate(10);

  float distanceMeters = 0.0f;
  while (ros::ok())
  {

    std_msgs::Float64 msg;
    msg.data = distanceMeters;

    ROS_INFO("%f", msg.data);

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    distanceMeters += 0.01f;
    if(distanceMeters > 0.80f){
        distanceMeters = 0.0f;
    }
  }


  return 0;
}
