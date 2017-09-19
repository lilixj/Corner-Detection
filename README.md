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


>3.亚像素级 corner detector;    
function: cornerSubPix()    
**Result**    

    
>开发环境：opencv3.20 + visual studio 2015.
>>**如若，对您有帮助就给个小星星呀。**
