#include <Eigen/Dense>
#include <pcl/point_types.h>
#pragma once

class Slice
{
	private:
		double minX, minY;
		double maxX, maxY;
		Eigen::Matrix2Xf A;
		Eigen::Vector2d X;
		Eigen::Vector2d Y;
		

	public:
		double Calculate_Area();

};

