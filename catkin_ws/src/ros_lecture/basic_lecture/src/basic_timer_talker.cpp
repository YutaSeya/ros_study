#include <ros/ros.h>
#include <std_msgs/String.h>

ros::Publisher chatter_pub;

void timer_callcack(const ros::TimerEvent&)
{
    std_msgs::String msg;
    msg.data = "hellow world!";
    ROS_INFO("publish: %s", msg.data.c_str());
    chatter_pub.publish(msg);
}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "basic_timer_talker");
    ros::NodeHandle n;
    chatter_pub = n.advertise<std_msgs::String>("chatter", 10);

    ros::Timer timer = n.createTimer(ros::Duration(0.1), timer_callcack);
    ros::spin();
    return 0;
}