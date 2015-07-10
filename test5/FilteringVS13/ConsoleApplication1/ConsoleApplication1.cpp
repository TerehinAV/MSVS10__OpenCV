#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <vector>
using namespace std;

int Compare(const void* x1, const void* x2)
{
	return *(uchar*)x1 - *(uchar*)x2;
}

void Median(IplImage* src, IplImage* dst, int mask_size)
{
	cvSetZero(dst);
	size_t val_amount = mask_size * mask_size;
	uchar* values = new uchar[val_amount];

	for (int r = mask_size / 2; r < src->height - mask_size / 2; ++r)
	{
		for (int c = mask_size / 2; c < src->width - mask_size / 2; ++c)
		{
			int idx = 0;

			for (int j = 0; j < mask_size; ++j)
			{
				for (int i = 0; i < mask_size; ++i)
				{
					values[idx++] = *cvPtr2D(src, r + j - mask_size / 2, c + i - mask_size / 2);
				}
			}

			qsort(values, val_amount, sizeof(uchar), Compare);
			*cvPtr2D(dst, r, c) = values[val_amount / 2];
		}
	}
}

void Linear(IplImage* src, IplImage* dst)
{
	cvSetZero(dst);
	int posR[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
	int posC[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
	int coefs[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	double norm = 16;

	for (int r = 1; r < src->height - 1; ++r)
	{
		for (int c = 1; c < src->width - 1; ++c)
		{
			int sum = 0;

			for (int i = 0; i < 9; ++i)
				sum += *cvPtr2D(src, r + posR[i], c + posC[i]) * coefs[i];

			*cvPtr2D(dst, r, c) = (uchar)round(sum / norm);
		}
	}
}

void Sobel(IplImage* src, IplImage* dst)
{
	cvSetZero(dst);

	for (int r = 1; r < src->height - 1; ++r)
	{
		for (int c = 1; c < src->width - 1; ++c)
		{
			int temp = (int)round(sqrt(pow(*cvPtr2D(src, r - 1, c + 1) + 2 * *cvPtr2D(src, r, c + 1) + *cvPtr2D(src, r + 1, c + 1) -
								*cvPtr2D(src, r - 1, c - 1) - 2 * *cvPtr2D(src, r, c - 1) - *cvPtr2D(src, r + 1, c - 1), 2) + 
							pow(*cvPtr2D(src, r + 1, c - 1) + 2 * *cvPtr2D(src, r + 1, c) + *cvPtr2D(src, r + 1, c + 1) -
								*cvPtr2D(src, r - 1, c - 1) - 2 * *cvPtr2D(src, r - 1, c) - *cvPtr2D(src, r - 1, c + 1), 2)));

			if (temp > 255)
				temp = 255;
			
			*cvPtr2D(dst, r, c) = (temp + *cvPtr2D(src, r, c)) / 2;
		}
	}
}

int main(int argc, char ** argv)
{
	IplImage* orig_im = cvLoadImage("1.jpg");
	IplImage* gray_im = cvCreateImage(cvGetSize(orig_im), 8, 1);
	IplImage* median_im = cvCreateImage(cvGetSize(orig_im), 8, 1);
	IplImage* linear_im = cvCreateImage(cvGetSize(orig_im), 8, 1);
	IplImage* sobel_im = cvCreateImage(cvGetSize(orig_im), 8, 1);
	cvCvtColor(orig_im, gray_im, CV_BGR2GRAY);
	Median(gray_im, median_im, 6);
	Linear(gray_im, linear_im);
	Sobel(gray_im, sobel_im);
	cvShowImage("orig_im", orig_im);
	cvShowImage("gray_im", gray_im);
	cvShowImage("median_im", median_im);
	cvShowImage("linear_im", linear_im);
	cvShowImage("sobel_im", sobel_im);

	while (true)
	{
		int c = cvWaitKey();
		
		if ((char)c == 27)
			break;
	}
}
