#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <vector>
using namespace std;

void BinOtsu(IplImage* src, IplImage* dst)
{
	int hist[256] = { 0 };
	uchar min = *cvPtr2D(src, 0, 0);
	uchar max = min;

	for (int y = 0; y < src->height; ++y)
	{
		for (int x = 0; x < src->width; ++x)
		{
			uchar val = *cvPtr2D(src, y, x);
			++hist[val];

			if (val < min)
				min = val;
			else if (val > max)
				max = val;
		}
	}

	int m = 0;
	int n = src->width * src->height;

	for (int i = 0; i <= max - min; ++i)
		m += i * hist[i + min];

	int alpha = 0;
	int beta = 0;
	double w;
	double a;
	double sigma;
	double sigma_max = 0;
	int threshold = 0;

	for (int i = 0; i < max - min; ++i)
	{
		alpha += i * hist[i + min];
		beta += hist[i + min];

		w = (double)beta / n;
		a = (double)alpha / beta - (double)(m - alpha) / (n - beta);
		sigma = w * (1 - w) * a * a;

		if (sigma > sigma_max)
		{
			sigma_max = sigma;
			threshold = i;
		}
	}

	threshold += min;

	for (int y = 0; y < src->height; ++y)
	{
		for (int x = 0; x < src->width; ++x)
		{
			if (*cvPtr2D(src, y, x) > threshold)
				*cvPtr2D(dst, y, x) = 255;
			else
				*cvPtr2D(dst, y, x) = 0;
		}
	}
}

int main(int argc, char ** argv)
{
	IplImage* orig_im = cvLoadImage("1.jpg");
	IplImage* gray_im = cvCreateImage(cvGetSize(orig_im), 8, 1);
	IplImage* bin_otsu_im = cvCreateImage(cvGetSize(orig_im), 8, 1);
	IplImage* bin_otsu2_im = cvCreateImage(cvGetSize(orig_im), 8, 1);
	cvCvtColor(orig_im, gray_im, CV_BGR2GRAY);
	BinOtsu(gray_im, bin_otsu_im);
	cvThreshold(gray_im, bin_otsu2_im, 0, 255, CV_THRESH_OTSU);
	
	cvShowImage("orig_im", orig_im);
	cvShowImage("gray_im", gray_im);
	cvShowImage("bin_otsu_im", bin_otsu_im);
	cvShowImage("bin_otsu2_im", bin_otsu2_im);

	while (true)
	{
		int c = cvWaitKey();
		
		if ((char)c == 27)
			break;
	}
}
