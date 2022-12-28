#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
//工程类的建立
class colour{
public:
    //转换色彩空间的函数
    void tran(Mat &image){
        Mat gray;//输出图像的定义
        cvtColor(image,gray,COLOR_BGR2GRAY);//转换函数的应用
        imshow("gray",gray);// 输出
    }
    //添加高斯滤波的函数
    void GS(Mat &image){
        Mat dst;//输出图像的定义
        GaussianBlur(image,dst,Size(3,3),15);//高斯函数
        imshow("GS",dst);//输出
    }
    // 二值化函数
    void T(Mat &image){
        Mat gray;//输出图像的定义
        cvtColor(image,gray,COLOR_BGR2GRAY);//转换函数的应用
        Mat mask;//二值化图像定义
        inRange( gray, Scalar(15, 15, 15), Scalar(95, 95, 95), mask);
        imshow("two",mask);
    }
};

int main()
{
    Mat img = imread("F:\\packages\\packages\\img\\RM.png");    // 这边修改成自己的图片路径，注意双斜杠
    //判断是否有图片
    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    imshow("image", img);  //原图展示
    colour a;              //对象的定义
    a.tran(img);           //转换色彩空间
    a.GS(img);             //添加高斯滤波
    a.T(img);              //二值化
    waitKey(0);

    return 0;
}
