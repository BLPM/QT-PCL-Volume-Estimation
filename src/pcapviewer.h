#include <iostream>

// Qt
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/vlp_grabber.h>
#include <pcl/visualization/pcl_visualizer.h>
// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui
{
	class pcapViewer;
}

class pcapViewer : public QMainWindow
{
	Q_OBJECT

public:
	explicit pcapViewer(QWidget* parent = 0);
	~pcapViewer();

public Q_SLOTS:
	void InputFileAction_Triggered();


protected:
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	PointCloudT::Ptr cloud;


private:
	Ui::pcapViewer* ui;

};


