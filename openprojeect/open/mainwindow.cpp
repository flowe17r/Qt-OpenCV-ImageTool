#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QDebug>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 图片居中并自适应label大小
QImage MainWindow::imageCenter(QImage qimage, QLabel *qLabel)
{
    QImage image;
    QSize imageSize = qimage.size();
    QSize labelSize = qLabel->size();

    // 计算宽高缩放比例
    double dWidthRatio = 1.0 * imageSize.width() / labelSize.width();
    double dHeightRatio = 1.0 * imageSize.height() / labelSize.height();

    // 按比例缩放，保证图片完整显示在label里
    if (dWidthRatio > dHeightRatio)
    {
        image = qimage.scaledToWidth(labelSize.width(), Qt::SmoothTransformation);
    }
    else
    {
        image = qimage.scaledToHeight(labelSize.height(), Qt::SmoothTransformation);
    }

    return image;
}
// 打开图片按钮槽函数
void MainWindow::on_btn_Loadimage_clicked()
{

    // 1. 打开文件选择框，获取图片路径
    QString imgPath = QFileDialog::getOpenFileName(this, tr("打开图片"), "/home/mist/图片", "图片(*.png *.jpg *.bmp)");

        // 如果用户没选文件，直接返回
    if (imgPath.isEmpty())
    {
        qDebug() << "用户取消了选择";
        return;
    }

        // 2. 用OpenCV读取图片
    srcimage = imread(imgPath.toStdString());
    if (srcimage.empty()) {
        qDebug() << "图片读取失败！";
        return;
    }
    //把cv bgr 转化为cv rgb 格式 然后在转换为qimag图片
    cvtColor(srcimage,srcimage,COLOR_BGR2RGB);
    QImage displayimage= QImage(srcimage.data,srcimage.cols,srcimage.rows,srcimage.rows *srcimage.channels(),QImage::Format_RGB888);
    QImage centerImage = imageCenter(displayimage, ui->lbi_show1);

        // 显示到label
     ui->lbi_show1->setPixmap(QPixmap::fromImage(centerImage));
     ui->lbi_show1->setAlignment(Qt::AlignCenter);
//        // 3. 创建窗口并显示图片
//    namedWindow("Image Window", WINDOW_AUTOSIZE);
//    imshow("Image Window", srcimage);
//    waitKey(0); // 等待用户按键，窗口才会关闭

}

//
void MainWindow::on_btn_Grey_clicked()
{
    if (srcimage.empty()) {
        qDebug() << "图片读取失败！";
        return;
    }
    Mat resulteimage;
    cvtColor(srcimage,resulteimage,COLOR_BGR2GRAY);
    cvtColor(resulteimage,resulteimage,COLOR_GRAY2RGB);
    QImage displayimage= QImage(resulteimage.data,resulteimage.cols,resulteimage.rows,resulteimage.rows *resulteimage.channels(),QImage::Format_RGB888);
    QImage centerImage = imageCenter(displayimage, ui->lbi_show2);
    ui->lbi_show2->setPixmap(QPixmap::fromImage(centerImage));
    ui->lbi_show2->setAlignment(Qt::AlignCenter);
}
//均值滤波
void MainWindow::on_btn_Meanimage_clicked()
{
    if (srcimage.empty()) {
        qDebug() << "图片读取失败！";
        return;
    }
    Mat blurmage;
    blur(srcimage,blurmage,Size(10,10));
    QImage displayimage= QImage(blurmage.data,blurmage.cols,blurmage.rows,blurmage.rows *blurmage.channels(),QImage::Format_RGB888);
    QImage centerImage = imageCenter(displayimage, ui->lbi_show2);
    ui->lbi_show2->setPixmap(QPixmap::fromImage(centerImage));
    ui->lbi_show2->setAlignment(Qt::AlignCenter);
}
//边缘检测
void MainWindow::on_btn_canny_clicked()
{
    if (srcimage.empty()) {
        qDebug() << "图片读取失败！";
        return;
    }
    Mat grayimage,edgeimage;
    cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
    Canny(grayimage,edgeimage,50,150);
    cvtColor(edgeimage,edgeimage,COLOR_GRAY2RGB);
    QImage displayimage= QImage(edgeimage.data,edgeimage.cols,edgeimage.rows,edgeimage.rows *edgeimage.channels(),QImage::Format_RGB888);
    QImage centerImage = imageCenter(displayimage, ui->lbi_show2);
    ui->lbi_show2->setPixmap(QPixmap::fromImage(centerImage));
    ui->lbi_show2->setAlignment(Qt::AlignCenter);

}
