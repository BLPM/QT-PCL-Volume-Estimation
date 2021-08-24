#include "./src/pcapviewer.h"
#include "./src/ui_pcapViewer.h"

pcapViewer::pcapViewer(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::pcapViewer)
{
    ui->setupUi(this);
    this->setWindowTitle("PCL viewer");

    // Setup the cloud pointer
    cloud.reset(new PointCloudT);
    // The number of points in the cloud
    cloud->points.resize(200);

    // The default color

    // Fill the cloud with some points

    // Set up the QVTK window
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui->qvtkWidget->GetInteractor(), ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->update();

    // Connect point size slider
    viewer->addPointCloud(cloud, "cloud");
    viewer->resetCamera();
    ui->qvtkWidget->update();

    connect(ui->actionInput_File, SIGNAL(triggered()), this, SLOT(InputFileAction_Triggered()));
}

pcapViewer::~pcapViewer()
{
    delete ui;
}


void pcapViewer::InputFileAction_Triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("open image file"),
        "./", tr("pcap files(*.pcap);;All files (*.*)"));

    if (fileName.isEmpty())
    {
        QMessageBox mesg;
        mesg.warning(this, "警告", "開啟檔案失敗!");
        return;
    }
    else
    {
        pcl::VLPGrabber interface(fileName.toStdString());
    }
}
