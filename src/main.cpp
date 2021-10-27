#include <iostream>
#include <typeinfo>

#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>


int main(int argc, char** argv)
{   

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    std::cout <<argv[1]<< std::endl;

    if (pcl::io::loadPLYFile<pcl::PointXYZ>(argv[1], *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file \n");
        return (-1);
    }
    
    std::sort(cloud->begin(), cloud->end(), [](pcl::PointXYZ pt1, pcl::PointXYZ pt2) {return pt1.z < pt2.z; });



    return 0;
}
