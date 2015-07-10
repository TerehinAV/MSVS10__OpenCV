// OpenCV_Hello_World.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	IplImage* image = cvLoadImage("image.png");
	IplImage* gray = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
	IplImage* bin = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
	IplImage* temp_bin_for_contours = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
	

	cvCvtColor(image, gray, CV_BGR2GRAY);
	cvThreshold(gray, bin, 254, 255, CV_THRESH_BINARY);
	temp_bin_for_contours = cvCloneImage(bin);
	cvNot(temp_bin_for_contours, temp_bin_for_contours);

	IplImage* contour = cvCreateImage(cvGetSize(bin), IPL_DEPTH_8U, 1);
	cvFloodFill(contour, cvPoint(0, 0), cvScalarAll(255));

	CvMemStorage* c_storage = cvCreateMemStorage(0);
	CvSeq* c_first;
	cvFindContours(temp_bin_for_contours, c_storage, &c_first, sizeof(CvContour), 0, CV_CHAIN_APPROX_NONE);
	
	unsigned long long images_amount = 1;

	for (CvSeq* c = c_first; c != NULL; c = c->h_next)
	{
		cvDrawContours(contour, c, cvScalarAll(0), cvScalarAll(0), 0, 1);
		cvSetImageROI(image, cvBoundingRect(c));
		string name = to_string(images_amount);
		cvShowImage(name.c_str(), image);
		cvSaveImage((name + ".bmp").c_str(), image);
		++images_amount;
	}
	
	cvResetImageROI(image);
	cvShowImage("image", image);
	cvShowImage("gray", gray);
	cvShowImage("contour", contour);

	while (true)
	{
		int c = cvWaitKey();
		
		if ((char)c == 27)
			break;
	}
}

