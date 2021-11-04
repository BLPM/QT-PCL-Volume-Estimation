#include "VolumeEstimation.h"
#include "ui_VolumeEstimation.h"

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer)
{
    viewer.setBackgroundColor(0, 0, 0);
    pcl::PointXYZ o;
    o.x = 1.0;
    o.y = 0;
    o.z = 0;
    viewer.addSphere(o, 0.1, "sphere", 0);
}

void  pp_callback(const pcl::visualization::PointPickingEvent& event, void* args)
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


VolumeEstimation::VolumeEstimation(QWidget* parent):QMainWindow(parent),ui(new Ui::VolumeEstimation)
{
    ui->setupUi(this);
    QString temptitle = QString::fromUtf8("移除離群點");
    this->setWindowTitle("Volume Estimate");
    ui->VolumeEstimate_button->setText(temptitle);


    cloud_filtered.reset(new PointCloudT);
    cloud.reset(new PointCloudT);
    cloud->points.resize(200);

    PointCloudT::Ptr clicked_points_3d(new PointCloudT);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
       
    //Visualizer clicked cb_function init
    cb_args.clicked_points_3d = clicked_points_3d;
    cb_args.viewerPtr = pcl::visualization::PCLVisualizer::Ptr(viewer);
    viewer->registerPointPickingCallback(pp_callback, (void*)&cb_args);

  

    //Connect部分
    connect(ui->LoadPC_button, SIGNAL(clicked()), this, SLOT(InputFile_clicked()));
    connect(ui->filter_button, SIGNAL(clicked()), this, SLOT(PassFilter_clicked()));
    connect(ui->VolumeEstimate_button, SIGNAL(clicked()), this, SLOT(RemoveOutoutlier_clicked()));

    //Render部分
    ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui->qvtkWidget->GetInteractor(), ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->update();

    viewer->addPointCloud(cloud, "cloud");
    viewer->resetCamera();
    ui->qvtkWidget->update();
}

VolumeEstimation::~VolumeEstimation()
{
    delete ui;
}


void VolumeEstimation::InputFile_clicked()
{
    std::string _filename;
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("open image file"),
        "./", tr("pcap files(*.pcd);;All files (*.*)"));

    if (fileName.isEmpty())
    {
        QMessageBox mesg;
        mesg.warning(this, "警告", "開啟檔案失敗!");
        return;
    }
    else
    {
        _filename  = fileName.toStdString();
        std::cout << _filename << std::endl;
        pcl::io::loadPCDFile<pcl::PointXYZ>(_filename, *cloud);//* load the file
        std::sort(cloud->begin(), cloud->end(), [](pcl::PointXYZ pt1, pcl::PointXYZ pt2) {return pt1.z < pt2.z; });
        viewer->updatePointCloud(cloud, "cloud");
        ui->qvtkWidget->update();
    }
}

void VolumeEstimation::PassFilter_clicked()
{
    pass.setInputCloud(cloud);
    //pass.setFilterLimitsNegative (true);
    printf("x");
    pass.setFilterFieldName("x");
    pass.setFilterLimits(0.0 , 2);
    pass.filter(*cloud_filtered);
    printf("y");
    pass.setInputCloud(cloud_filtered);
    pass.setFilterFieldName("y");
    pass.setFilterLimits(0.0, 2);
    pass.filter(*cloud_filtered);
    printf("z");
    pass.setInputCloud(cloud_filtered);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(0.0, 2);
    pass.filter(*cloud);
    
    
    viewer->updatePointCloud(cloud, "cloud");
    ui->qvtkWidget->update();
}

void VolumeEstimation::RemoveOutoutlier_clicked()
{
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud);
    sor.setMeanK(20);
    sor.setStddevMulThresh(1.0);
    sor.filter(*cloud);

    viewer->updatePointCloud(cloud, "cloud");
    ui->qvtkWidget->update();
}


void VolumeEstimation::updatePCinformation()
{
    ui->PointCloudInf_text->setText("");
}