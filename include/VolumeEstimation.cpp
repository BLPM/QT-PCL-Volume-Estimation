#include "VolumeEstimation.h"
#include "ui_VolumeEstimation.h"

int text_id = 0;
void mouseEventOccurred(const pcl::visualization::MouseEvent& event, void* args)
{
    struct callback_args* data = (struct callback_args*)args;
    PointT current_point;
    if (event.getButton() == pcl::visualization::MouseEvent::LeftButton &&
        event.getType() == pcl::visualization::MouseEvent::MouseButtonPress)
    {
       current_point.x = event.getX();
       current_point.y = event.getY();
       current_point.z = data->cloud->height;
       data->clicked_points_3d->points.push_back(current_point);
       printf("push point");
       data->viewerPtr->addPolygon<PointT>(data->clicked_points_3d, "polytest");
       pcl::visualization::PointCloudColorHandlerCustom<PointT> red(data->clicked_points_3d, 255, 0, 0);
       data->viewerPtr->removePointCloud("clicked_points");
       data->viewerPtr->addPointCloud(data->clicked_points_3d, red, "clicked_points");
       data->viewerPtr->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");
    }
}

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

    this->setWindowTitle("Volume Estimate");
    cloud_filtered.reset(new PointCloudT);
    cloud.reset(new PointCloudT);
    cloud->points.resize(200);

    PointCloudT::Ptr clicked_points_3d(new PointCloudT);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
       
    //Visualizer clicked cb_function init
    cb_args.clicked_points_3d = clicked_points_3d;
    cb_args.cloud = cloud;
    cb_args.viewerPtr = pcl::visualization::PCLVisualizer::Ptr(viewer);

    viewer->registerPointPickingCallback(pp_callback, (void*)&cb_args);
    //viewer->registerMouseCallback(mouseEventOccurred, (void*)&cb_args);
  

    //Connect部分
    connect(ui->LoadPC_button, SIGNAL(clicked()), this, SLOT(InputFile_clicked()));
    connect(ui->filter_button_pass, SIGNAL(clicked()), this, SLOT(PassFilter_clicked()));
    connect(ui->filter_button_rmoutlier, SIGNAL(clicked()), this, SLOT(RemoveOutoutlier_clicked()));
    connect(ui->reserve, SIGNAL(clicked()), this, SLOT(ConvexHullFilter_clicked()));
    connect(ui->reserve_2, SIGNAL(clicked()), this, SLOT(SaveFile_clicked()));


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
        this, tr("open pointcloud file"),
        "./", tr("pcd files(*.pcd);;ply files(*.ply);;All files (*.*)"));

    if (fileName.isEmpty())
    {
        QMessageBox mesg;
        mesg.warning(this, "警告", "開啟檔案失敗!");
        return;
    }
    else
    {
        _filename = fileName.toStdString();
        std::cout << _filename << std::endl;
        QStringList splitedFileNAme = fileName.split('.');
        QString subfilename = splitedFileNAme.last();
        std::string _subfilename = subfilename.toStdString();
        std::cout << _subfilename << std::endl;

        if (!_subfilename.compare("pcd"))
        {
            pcl::io::loadPCDFile<pcl::PointXYZ>(_filename, *cloud);//* load pcd the file
        }
        else if (!_subfilename.compare("ply"))
        {
            pcl::io::loadPLYFile<pcl::PointXYZ>(_filename, *cloud);//* load ply the file
        }
        std::sort(cloud->begin(), cloud->end(), [](pcl::PointXYZ pt1, pcl::PointXYZ pt2) {return pt1.z < pt2.z; });
        viewer->updatePointCloud(cloud, "cloud");
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }
}


void  VolumeEstimation::SaveFile_clicked()
{
    std::string _filename;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
        "./untitled",
        tr("ply (*.ply);;pcd (*.pcd);;All files (*.*)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        _filename = fileName.toStdString();
        std::cout << _filename << std::endl;
        QStringList splitedFileNAme = fileName.split('.');
        QString subfilename = splitedFileNAme.last();
        std::string _subfilename = subfilename.toStdString();
        std::cout << _subfilename << std::endl;

        if (!_subfilename.compare("pcd"))
        {
            pcl::io::savePCDFile<pcl::PointXYZ>(_filename, *cloud);//* load pcd the file
        }
        else if (!_subfilename.compare("ply"))
        {
            pcl::io::savePLYFile<pcl::PointXYZ>(_filename, *cloud);//* load ply the file
        }
        QMessageBox mesg; 
        mesg.about(this, "tset", "saveFileSuccess");
    }
}

void VolumeEstimation::ConvexHullFilter_clicked()
{

    pcl::ConvexHull<pcl::PointXYZ> hull;//創建凸包對象
    hull.setInputCloud(cb_args.clicked_points_3d);//設置輸入點雲
    hull.setDimension(3);//設置凸包維度
    std::vector<pcl::Vertices> polygons;//設置pcl:Vertices類型的向量，用於保存凸包頂點
    pcl::PointCloud<pcl::PointXYZ>::Ptr surface_hull(new pcl::PointCloud<pcl::PointXYZ>);//該點雲用於描述凸包形狀
    hull.reconstruct(*surface_hull, polygons);//計算2D凸包結果

    //---------創建CropHull對象，濾波得到2D封閉凸包範圍內的點雲，此處的維度需要與輸入凸包維度一致
    pcl::PointCloud<pcl::PointXYZ>::Ptr objects(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::CropHull<pcl::PointXYZ> bb_filter;//創建CropHull對象
    bb_filter.setDim(3);//設置維度
    bb_filter.setInputCloud(cloud);//設置需要濾波的點雲
    bb_filter.setHullIndices(polygons);//輸入封閉多邊形的頂點
    bb_filter.setHullCloud(surface_hull);//輸入封閉多邊形的形狀
    bb_filter.filter(*cloud);//執行CropHull濾波，儲存結果到objects


    viewer->updatePointCloud(cloud, "cloud");
    viewer->addPolygon<PointT>(surface_hull, 0, .06* -9 * 255, 0.2 * 255, "backview_hull_polyline");
    
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 255, 255, 255, "cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");

    ui->qvtkWidget->update();

}
void VolumeEstimation::PassFilter_clicked()
{
    
    QString x1 = ui->point1_x_lineEdit->text();
    QString y1 = ui->point1_y_lineEdit->text();
    QString z1 = ui->point1_z_lineEdit->text();
    QString x2 = ui->point2_x_lineEdit->text();
    QString y2 = ui->point2_y_lineEdit->text();
    QString z2 = ui->point2_z_lineEdit->text();


    double x1_ = x1.toDouble();
    double y1_ = y1.toDouble();
    double z1_ = z1.toDouble();
    double x2_ = x2.toDouble();
    double y2_ = y2.toDouble();
    double z2_ = z2.toDouble();

    pass.setInputCloud(cloud);
    //pass.setFilterLimitsNegative (true);
    printf("x");
    pass.setFilterFieldName("x");
    pass.setFilterLimits(x1_ , x2_);
    pass.filter(*cloud_filtered);
    printf("y");
    pass.setInputCloud(cloud_filtered);
    pass.setFilterFieldName("y");
    pass.setFilterLimits(y1_, y2_);
    pass.filter(*cloud_filtered);
    printf("z");
    pass.setInputCloud(cloud_filtered);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(z1_, z2_);
    pass.filter(*cloud);
    viewer->updatePointCloud(cloud, "cloud");
    ui->qvtkWidget->update();
}

void VolumeEstimation::RemoveOutoutlier_clicked()
{
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

