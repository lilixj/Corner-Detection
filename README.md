
# Corner-Detection
## OpenCV corner detection
角点检测主要应用于运动检测，图像匹配，目标跟踪，三维建模和目标识别等领域. 

**Types of Image Features**    
* Edges    
* Corners(also known as interest points)    
* Blobs(also known as regions of interest)    
in this tutorial we will study the corner features, specifically.    
>关于角点的具体描述大体如下：    
+ 一阶导数的局部最大所对应的像素点；    
+ 两条或两条以上边缘的交点；    
+ 图像中梯度值和梯度方向的变化率都很高的点；    
+ 角点处的一阶导数最大，二阶导数为零，它指示了物体边缘变化不连续的方向。    

>1.Harris corner detector;    
function：cornerHarris（）    
**Result:**     

![harris](http://ow9372wwb.bkt.clouddn.com/harris2.PNG)    

![harris](http://ow9372wwb.bkt.clouddn.com/harris1.PNG)    

you can get the source code in Harris file.

>2.Shi-Tomasi conrer detector;    
function：goodFeaturesToTrack（）    
**Result:** 

![Shi-Tomasi](http://ow9372wwb.bkt.clouddn.com/Shi-Tomasi.PNG)    

you can get the source code in Shi-Tomasi file.    

>3.Generic Corner Detector;    
- Use the OpenCV function cv::cornerEigenValsAndVecs to find the eigenvalues and eigenvectors    
**Result:**   

![Harris corner detector](http://ow9372wwb.bkt.clouddn.com/Harris%20corner%20detector.PNG)

- Use the OpenCV function cv::cornerMinEigenVal to find the minimum eigenvalues for corner detection.     
**Result:**    

![Shi Tomasi corner detector](http://ow9372wwb.bkt.clouddn.com/Shi%20Tomasi%20detector.PNG)    

you can get the source code in Corner Detector file.

>4.亚像素级 corner detector;    
function: cornerSubPix()    
**Result:**    

![yaxiangsu](http://ow9372wwb.bkt.clouddn.com/yaxiangsu.PNG)

![yaxiangsu_c](http://ow9372wwb.bkt.clouddn.com/yaxiangsu_c.PNG)    

you can get the source code in Sub pixel file.
 
>开发环境：opencv3.20 + visual studio 2015.
>>**如若，对您有帮助就给个小星星呀。**
