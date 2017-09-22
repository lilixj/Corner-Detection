//包含头文件命名空间
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
//全局变量声明
Mat src, src_gray;
Mat myHarris_dst, myHarris_copy, Mc, myShiTomasi_dst, myShiTomasi_copy;
int myShiTomasi_qualityLevel = 30;
int myHarris_qualityLevel = 30;
int max_qualityLevel = 100;
double myHarris_minVal, myHarris_maxVal;
double myShiTomasi_minVal, myShiTomasi_maxVal;
const char* myHarris_window = "My Harris corner detector";
const char* myShiTomasi_window = "My Shi Tomasi corner detector";
//生成随机数
RNG rng(12345);
//函数声明
void myShiTomasi_function(int, void*);
void myHarris_function(int, void*);
//主函数定义
int main(int, char** argv)
{
	//读取图像
	src = imread("cornerDetector.png");
	//把原图像转换为灰度图像
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	//参数设置
	int blockSize = 3; 
	int ksize = 3;
	myHarris_dst = Mat::zeros(src_gray.size(), CV_32FC(6));
	Mc = Mat::zeros(src_gray.size(), CV_32FC1);
	//计算特征值
	cornerEigenValsAndVecs(src_gray, myHarris_dst, blockSize, ksize, BORDER_DEFAULT);
	//计算响应值
	float k = 0.04;
	for (int j = 0; j < src_gray.rows; j++)
	{
		for (int i = 0; i < src_gray.cols; i++)
		{
			float lambda_1 = myHarris_dst.at<Vec6f>(j, i)[0];
			float lambda_2 = myHarris_dst.at<Vec6f>(j, i)[1];
			Mc.at<float>(j, i) = lambda_1*lambda_2 - k*pow((lambda_1 + lambda_2), 2);
		}
	}
	minMaxLoc(Mc, &myHarris_minVal, &myHarris_maxVal, 0, 0, Mat());
    //创建窗口
	namedWindow(myHarris_window, WINDOW_AUTOSIZE);
	createTrackbar(" Quality Level:", myHarris_window, &myHarris_qualityLevel, max_qualityLevel, myHarris_function);
	myHarris_function(0, 0);
	//计算特征值
	myShiTomasi_dst = Mat::zeros(src_gray.size(), CV_32FC1);
	cornerMinEigenVal(src_gray, myShiTomasi_dst, blockSize, ksize, BORDER_DEFAULT);
	minMaxLoc(myShiTomasi_dst, &myShiTomasi_minVal, &myShiTomasi_maxVal, 0, 0, Mat());
	//创建窗口
	namedWindow(myShiTomasi_window, WINDOW_AUTOSIZE);
	createTrackbar(" Quality Level:", myShiTomasi_window, &myShiTomasi_qualityLevel, max_qualityLevel, myShiTomasi_function);
	myShiTomasi_function(0, 0);
    //等待按键按下
	waitKey(0);
	return(0);
}

//myShiTomasi函数定义
void myShiTomasi_function(int, void*)
{
	myShiTomasi_copy = src.clone();
	if (myShiTomasi_qualityLevel < 1) { myShiTomasi_qualityLevel = 1; }
	for (int j = 0; j < src_gray.rows; j++)
	{
		for (int i = 0; i < src_gray.cols; i++)
		{
			if (myShiTomasi_dst.at<float>(j, i) > myShiTomasi_minVal + (myShiTomasi_maxVal - myShiTomasi_minVal)*myShiTomasi_qualityLevel / max_qualityLevel)
			{
				circle(myShiTomasi_copy, Point(i, j), 4, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 2, 8, 0);
			}
		}
	}
	imshow(myShiTomasi_window, myShiTomasi_copy);
}

//myHarris函数定义
void myHarris_function(int, void*)
{
	myHarris_copy = src.clone();
	if (myHarris_qualityLevel < 1) { myHarris_qualityLevel = 1; }
	for (int j = 0; j < src_gray.rows; j++)
	{
		for (int i = 0; i < src_gray.cols; i++)
		{
			if (Mc.at<float>(j, i) > myHarris_minVal + (myHarris_maxVal - myHarris_minVal)*myHarris_qualityLevel / max_qualityLevel)
			{
				circle(myHarris_copy, Point(i, j), 4, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 2, 8, 0);
			}
		}
	}
	imshow(myHarris_window, myHarris_copy);
}
