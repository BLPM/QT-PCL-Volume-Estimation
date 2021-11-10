#include <iostream>
#include <typeinfo>
#include <vector>
// Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
// Point Cloud Library
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/passthrough.h> 
#include <pcl/filters/voxel_grid.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/crop_hull.h>
#include <pcl/surface/concave_hull.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>


typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

struct callback_args {
    // structure used to pass arguments to the callback function
	PointCloudT::Ptr cloud;
	PointCloudT::Ptr clicked_points_3d;
    pcl::visualization::PCLVisualizer::Ptr viewerPtr;
};

void pp_callback(const pcl::visualization::PointPickingEvent& event, void* args);

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer);

namespace Ui
{
	class VolumeEstimation;
}

class VolumeEstimation : public QMainWindow
{
	Q_OBJECT
	public:
		explicit VolumeEstimation(QWidget* parent =0);
		~VolumeEstimation();

	public Q_SLOTS:
		void InputFile_clicked();
		void PassFilter_clicked();
		void RemoveOutoutlier_clicked();
		void ConvexHullFilter_clicked();
		void SaveFile_clicked();

	protected:

		boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered;
		pcl::PassThrough<pcl::PointXYZ> pass;
		pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;

	private:
	    Ui::VolumeEstimation *ui;
		struct callback_args cb_args;
		void updatePCinformation();

};


