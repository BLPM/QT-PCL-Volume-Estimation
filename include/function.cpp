#include "MyIO.h"
MyIO::MyIO()
{
    
}
MyIO::~MyIO()
{
}
int MyIO::readPLYFile(string filename)
{	

    std::cout << "In read Loaded ";
    if (pcl::io::loadPLYFile<pcl::PointXYZ>(filename, this->cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file \n");
        return (-1);
    }
    std::cout << "Loaded "
        << "width" << cloud.width<<"height" << cloud.height
        << " data points from test_pcd.pcd with the following fields: " << std::endl
        << "pointcloud size "<< cloud.size() << std::endl;

    //for (const auto& point : this->cloud)
    // std::cout << "    " << point.x<< " " << point.y<< " " << point.z << std::endl;
    return (0);
}

pcl::PointCloud<pcl::PointXYZ> MyIO::getPointCloud()
{
    return this->cloud;
}
bool MyIO::SliceToEigenMatrix()
{
    for (const auto& point : this->cloud)
    {
        Eigen::Matrix2f(cloud.width, cloud.height);
    }
    return (0);
}