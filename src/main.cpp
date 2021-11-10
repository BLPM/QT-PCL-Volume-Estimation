#include <iostream>
#include <typeinfo>
#include "VolumeEstimation.h"
#include <QApplication>
#include <QMainWindow>
/*/
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

struct callback_args {
    // structure used to pass arguments to the callback function
    PointCloudT::Ptr clicked_points_3d;
    pcl::visualization::PCLVisualizer::Ptr viewerPtr;
};

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer)
{
    viewer.setBackgroundColor(0, 0, 0);
    pcl::PointXYZ o;
    o.x = 1.0;
    o.y = 0;
    o.z = 0;
    viewer.addSphere(o, 0.1, "sphere", 0);
}

void pp_callback(const pcl::visualization::PointPickingEvent& event, void* args)
{
    struct callback_args* data = (struct callback_args*)args;
    if (event.getPointIndex() == -1)
        return;
    PointT current_point;
    event.getPoint(current_point.x, current_point.y, current_point.z);
    data->clicked_points_3d->points.push_back(current_point);
    // Draw clicked points in red:
    pcl::visualization::PointCloudColorHandlerCustom<PointT> red(data->clicked_points_3d, 255, 0, 0);
    data->viewerPtr->removePointCloud("clicked_points");
    data->viewerPtr->addPointCloud(data->clicked_points_3d, red, "clicked_points");
    data->viewerPtr->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
    std::cout << current_point.x << " " << current_point.y << " " << current_point.z << std::endl;
}
*/

int main(int argc, char** argv)
{   

    QApplication a(argc, argv);
    VolumeEstimation w;
    w.show();
    /*
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);


    if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
    
    std::sort(cloud->begin(), cloud->end(), [](pcl::PointXYZ pt1, pcl::PointXYZ pt2) {return pt1.z < pt2.z; });
    */
    /**


    */

    /* ¥­­±segment
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
    // Create the segmentation object
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    // Optional
    seg.setOptimizeCoefficients(true);
    // Mandatory
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setDistanceThreshold(0.1);

    seg.setInputCloud(cloud);
    seg.segment(*inliers, *coefficients);


    std::cerr << "Model coefficients: " << coefficients->values[0] << " "
        << coefficients->values[1] << " "
        << coefficients->values[2] << " "
        << coefficients->values[3] << std::endl;


    if (inliers->indices.size() == 0)
    {
        PCL_ERROR("Could not estimate a planar model for the given dataset.");
        return (-1);
    }
    

    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud(cloud);
    extract.setIndices(inliers);
    extract.filter(*cloud_filtered);

    */
    return a.exec();
}
