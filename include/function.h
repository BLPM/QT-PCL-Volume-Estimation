#pragma once
#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <Eigen/Dense>
#include "./Slice.h" 

using namespace std;

class MyIO {
	private:
		pcl::PointCloud<pcl::PointXYZ> cloud;
		
	public:
		MyIO();
		~MyIO();
		pcl::PointCloud<pcl::PointXYZ> getPointCloud();
		int readPLYFile(string filename);
		bool SliceToEigenMatrix();
};

