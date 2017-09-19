//包含头文件和命名空间
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
//全局变量声明
Mat srcImage, grayImage, dstImage, normImage, Scalednorm, resultImage;
int  thresh = 125;
int max_thresh = 255;
//函数声明
void Harris_Conner(int, void*);
//主函数
int main(int argc, char** argv) {
	//读取本地图像
	srcImage = imread("harris.png");
	if (srcImage.empty()) {
		cout << "could not load srcimage...\n" << endl;
		return -1;
	}
	//创建窗口
	namedWindow("srcImage", WINDOW_AUTOSIZE);
	//显示原图像
	imshow("srcImage", srcImage);
	//把原图像转换成灰度图
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	//创建窗口和滚动条
	namedWindow("HarrisConnerDetection", WINDOW_AUTOSIZE);
	createTrackbar("Threshold", "HarrisConnerDetection", &thresh, max_thresh, Harris_Conner);
	//初始化函数
	Harris_Conner(0, 0);

	waitKey(0);
	return 0;
}
//函数定义
void Harris_Conner(int, void*) {
	//置零
	dstImage = Mat::zeros(grayImage.size(), CV_32FC1);
	//参数赋值
	int blocksize = 2;
	int ksize = 3;
	double k = 0.04;
	//进行角点检测
	cornerHarris(grayImage, dstImage, blocksize, ksize, k, BORDER_DEFAULT);
	//归一化
	normalize(dstImage, normImage, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	//将归一化后的图线性变换成8位无符号整型
	convertScaleAbs(normImage, Scalednorm);
	//克隆
	resultImage = srcImage.clone();
	//循环遍历像素，绘制出被检测的角点（也可以用指针实现，速度相对快些）
	for (int i = 0; i < resultImage.rows; i++) {
		 //uchar* pixel_i = Scalednorm.ptr(i);
		for (int j = 0; j < resultImage.cols; j++) { 
			//int Pixel = (int)*pixel_i;
			//if(Pixel > thresh){
				if ((int)normImage.at<float>(i, j)  > thresh) {
					circle(resultImage, Point(j, i), 4, Scalar(0, 0, 255), 2, 8, 0);
					circle(Scalednorm, Point(j, i), 5, Scalar(1, 10, 255), 2, 8, 0);
			}
				//pixel_i++;
		}
	}
	//显示角点检测的结果
	imshow("HarrisConnerDetection", resultImage);
	imshow("Detection", Scalednorm);
}
