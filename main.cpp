#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
// 方法一
/*int main()
{
    VideoCapture capture("F:\\packages\\packages\\video\\preview.mp4");
    Mat video;
    while(1){
        capture.read(video);
        if(video.empty())break;
        double fps = capture.get(CAP_PROP_FPS);		//获取帧率

        //将帧率显示在图片上
        char str[20];
        string FPSstring("FPS:");
        sprintf_s(str, "%.2f", fps);
        FPSstring += str;
        putText(video, FPSstring, Point(5, 20),
            FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0));
        imshow("video",video);
        int c=waitKey(1);
        if(c==27)break;
    }
    return 0;
}*/
 //方法二
int main()
{
    Mat frame;
    VideoCapture capture("F:\\packages\\packages\\video\\preview.mp4");
    double fps;
    char string[10];  // 用于存放帧率的字符串
    namedWindow("Camera FPS");
    double t = 0;


    while (1)
    {
        t = (double)getTickCount();
        int c=waitKey(1);
        if(c==27)break;
        if (capture.isOpened())
        {
            capture >> frame;
            // getTickcount函数：返回从操作系统启动到当前所经过的毫秒数
            // getTickFrequency函数：返回每秒的计时周期数
            // t为该处代码执行所耗的时间,单位为秒,fps为其倒数
            t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
            fps = 1.0 / t;


            sprintf(string, "%.2f", fps);      // 帧率保留两位小数
            std::string fpsString("FPS:");
            fpsString += string;                    // 在"FPS:"后加入帧率数值字符串
            // 将帧率信息写在输出帧上
            putText(frame, // 图像矩阵
                    fpsString,                  // string型文字内容
                    Point(5, 20),           // 文字坐标，以左下角为原点
                    FONT_HERSHEY_SIMPLEX,   // 字体类型
                    0.5, // 字体大小
                    Scalar(0, 255, 0));       // 字体颜色


            imshow("Camera FPS", frame);
        }
        else
        {
            cout << "No Camera Input!" << endl;
            break;
        }
    }
}

