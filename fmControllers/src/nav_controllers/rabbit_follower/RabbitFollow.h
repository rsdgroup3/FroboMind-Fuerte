/*
 * RabbitFollow.h
 *
 *  Created on: Apr 27, 2012
 *      Author: morl
 */

#ifndef RABBITFOLLOW_H_
#define RABBITFOLLOW_H_

#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <fmControllers/rabbit_follow_paramsConfig.h>
#include <dynamic_reconfigure/server.h>

class RabbitFollow
{
public:
	RabbitFollow(std::string,std::string);
	virtual ~RabbitFollow();

	void setParams(double P,double I,double I_max,double max_ang,double max_lin);

	void spin(const ros::TimerEvent& e);

	ros::Publisher cmd_vel_pub;
	double fov;
	double max_ang_vel;
	double max_lin_vel;
	double oscilation_bound;
	double target_acquired_tolerance;

	ros::NodeHandle* nh;

private:
	void findTheRabbit();
	void driveToTheRabbit();


	double current_rabbit_heading;
	double previous_rabbit_heading;
	double distance;

	double P,I,D;
	double Pg,Ig,Dg;
	double error;
	double I_max;

	std::string rabbit_frame;
	std::string odom_frame;
	std::string vehicle_frame;

	tf::TransformListener tf_listen;

	geometry_msgs::Twist cmd_vel;


};

#endif /* RABBITFOLLOW_H_ */
