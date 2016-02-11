#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <iostream>
using namespace std;

ros::Publisher fake_scan_pub;
sensor_msgs::LaserScan fake_scan;

bool my_update()
{
  
  fake_scan.ranges.resize(4);
  fake_scan.intensities.resize(4);

  unsigned int count = 0;

  //loop through the scan and truncate the beginning and the end of the scan as necessary

  
  fake_scan.ranges[0] = 0;
  fake_scan.ranges[1] = 1;
  fake_scan.ranges[2] = 2;
  fake_scan.ranges[3] = 3;

  //make sure to set all the needed fields on the fake scan
  fake_scan.header.frame_id = "laser_frame";
  fake_scan.angle_min = -3.14;
  fake_scan.angle_max = 3.14;
  fake_scan.angle_increment = double(6.28/4);
  fake_scan.time_increment = 1;
  fake_scan.scan_time = 1;
  fake_scan.range_min = 0;
  fake_scan.range_max = 6;
 

  //ROS_DEBUG("Filtered out %d points from the laser scan.", (int)input_scan.ranges.size() - (int)count);
  return true;
}


int main(int argc, char** argv){
  ros::init(argc, argv, "lidartest");
  ros::NodeHandle n1, n2;
  fake_scan_pub = n2.advertise<sensor_msgs::LaserScan>("/lidartest", 50);
  ros::Rate loop_rate(500);

  while(ros::ok())
  {
    my_update();
    fake_scan_pub.publish(fake_scan);


    ros::spinOnce();
    loop_rate.sleep();
  }
}
