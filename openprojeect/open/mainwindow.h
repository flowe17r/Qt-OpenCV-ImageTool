#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QLabel>
using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage imageCenter(QImage qimage, QLabel *qLabel);

private slots:
    void on_pushButton_clicked();

    void on_btn_Loadimage_clicked();

    void on_btn_Grey_clicked();

    void on_btn_Meanimage_clicked();

    void on_btn_canny_clicked();

private:
    Ui::MainWindow *ui;
    Mat srcimage;
};
#endif // MAINWINDOW_H
