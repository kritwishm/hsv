#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int low_h=0, low_s=100, low_v=100;
int high_h=10, high_s=255, high_v=255;

char* window_name = "threshold";

void threshold(int , void*);
void trackbar();

Mat img1,img2,ThreshImage;

int main(int argc, char** argv){
	img1=imread(argv[1], 1);
	if(!img1.data)
	{
		cout<<"Could not open  image"<<std::endl;
		return -1;
	}
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	imshow(window_name, img1);
	GaussianBlur( img1, img1, Size(3,3), 0, 0);
	cvtColor(img1,img2,CV_BGR2HSV);
	waitKey(0);
	namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	trackbar();
	threshold(0,0);
	waitKey(0);
	return 0;
}
void trackbar(){
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
  createTrackbar("Low H",window_name, &low_h, 180, threshold);
  createTrackbar("High H",window_name, &high_h, 180, threshold);
  createTrackbar("Low S",window_name, &low_s, 255, threshold);
  createTrackbar("High S",window_name, &high_s, 255, threshold);
  createTrackbar("Low V",window_name, &low_v, 255, threshold);
  createTrackbar("High V",window_name, &high_v, 255,threshold);
}
void threshold(int , void *)
{
	inRange(img2,Scalar(low_h,low_s,low_v),Scalar(high_h,high_s,high_v),ThreshImage);
	imshow(window_name, ThreshImage);
}
