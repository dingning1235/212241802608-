#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void HoughTranslate(Mat& image)
{
    //做边缘检测首先要进行高斯边缘模糊，如果利用Canny高斯边缘模糊Canny会帮我们做
    Mat image_gray, dst;
    Canny(image, image_gray, 150, 200);//100,200分别是低阈值和高阈值输出二值图
    imshow("edge_image", image_gray);
    cvtColor(image_gray, dst, COLOR_GRAY2BGR);

    vector<Vec4f> plines;//吧每个像素点的平面坐标转化为极坐标产生的曲线放入集合中
    HoughLinesP(image_gray, plines, 1, CV_PI / 180.0, 10, 0, 10);//从平面坐标转换到霍夫空间,最终输出的是直线的两个点（x0,y0,x1,y1）
    Scalar color = Scalar(0, 0, 255);
    for (size_t i = 0; i < plines.size(); i++)
    {
        Vec4f hline = plines[i];
        line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 3, LINE_AA);
    }
    imshow("hough_line_detection", dst);

}
int main()
{
    Mat img = imread("F:\\packages\\packages\\img\\board.jpg");    // 这边修改成自己的图片路径，注意双斜杠

    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }
    imshow("image", img);
    HoughTranslate(img);
    waitKey(0);

    return 0;
}
