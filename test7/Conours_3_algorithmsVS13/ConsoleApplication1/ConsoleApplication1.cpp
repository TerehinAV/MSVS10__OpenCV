#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <cv.h>
#include <highgui.h>

void Beatle(IplImage* src, IplImage* dst)
{
	enum Direction
	{
		up,
		down,
		left,
		right
	};

	int startR;
	int startC;
	int curR;
	int curC;
	Direction dir = up;
	bool found = false;

	cvSet(dst, cvScalar(255));
	
	for (int r = 0; r < src->height; ++r)
	{
		for (int c = 0; c < src->width; ++c)
		{
			if (*cvPtr2D(src, r, c) == 0)
			{
				*cvPtr2D(dst, r, c) = 0;
				startR = r;
				startC = c;
				curR = r;
				curC = c;
				found = true;
				break;
			}
		}

		if (found)
			break;
	}

	do
	{
		switch (dir)
		{
		case up:
			--curR;

			if (*cvPtr2D(src, curR, curC) == 255)
			{
				*cvPtr2D(dst, curR, curC) = 0;
				dir = right;
			}
			else
				dir = left;

			break;

		case down:
			++curR;

			if (*cvPtr2D(src, curR, curC) == 255)
			{
				*cvPtr2D(dst, curR, curC) = 0;
				dir = left;
			}
			else
				dir = right;

			break;

		case left:
			--curC;

			if (*cvPtr2D(src, curR, curC) == 255)
			{
				*cvPtr2D(dst, curR, curC) = 0;
				dir = up;
			}
			else
				dir = down;

			break;

		case right:
			++curC;

			if (*cvPtr2D(src, curR, curC) == 255)
			{
				*cvPtr2D(dst, curR, curC) = 0;
				dir = down;
			}
			else
				dir = up;
		}
	} while (curR != startR || curC != startC);
}

void Scan(IplImage* src, IplImage* dst)
{
	cvSet(dst, cvScalar(255));

	for (int r = 0; r < src->height; ++r)
	{
		for (int c = 0; c < src->width - 1; ++c)
		{
			if (*cvPtr2D(src, r, c) == 255 && *cvPtr2D(src, r, c + 1) == 0)
				*cvPtr2D(dst, r, c + 1) = 0;
			else if (*cvPtr2D(src, r, c) == 0 && *cvPtr2D(src, r, c + 1) == 255)
				*cvPtr2D(dst, r, c) = 0;
		}
	}

	for (int c = 0; c < src->width; ++c)
	{
		for (int r = 0; r < src->height - 1; ++r)
		{
			if (*cvPtr2D(src, r, c) == 255 && *cvPtr2D(src, r + 1, c) == 0)
				*cvPtr2D(dst, r + 1, c) = 0;
			else if (*cvPtr2D(src, r, c) == 0 && *cvPtr2D(src, r + 1, c) == 255)
				*cvPtr2D(dst, r, c) = 0;
		}
	}
}

void Lane(IplImage* src, IplImage* dst)
{
	int startR;
	int startC;
	int curR;
	int curC;
	bool found = false;
	int posR[] = { -1, -1, -1, 0, 1, 1, 1,  0 };
	int posC[] = { -1, 0,  1,  1, 1, 0, -1, -1 };
	int prevP = 0;

	cvSet(dst, cvScalar(255));

	for (int r = 0; r < src->height; ++r)
	{
		for (int c = 0; c < src->width; ++c)
		{
			if (*cvPtr2D(src, r, c) == 0)
			{
				*cvPtr2D(dst, r, c) = 0;
				startR = r;
				startC = c;
				curR = r;
				curC = c;
				found = true;
				break;
			}
		}

		if (found)
			break;
	}

	do
	{
		for (int p = 0; p < 8; ++p)
		{
			int curP = (p + prevP) % 8;
			if (*cvPtr2D(src, curR + posR[curP], curC + posC[curP]) == 0)
			{
				curR += posR[curP];
				curC += posC[curP];
				*cvPtr2D(dst, curR, curC) = 0;
				prevP = (curP + 5) % 8;
				break;
			}
		}
	} while (curR != startR || curC != startC);
}

int main(int argc, char ** argv)
{
	IplImage* image = cvLoadImage("1.png");
	IplImage* gray = cvCreateImage(cvGetSize(image), 8, 1);
	IplImage* bin = cvCreateImage(cvGetSize(image), 8, 1);
	IplImage* contourBeatle = cvCreateImage(cvGetSize(image), 8, 1);
	IplImage* contourScan = cvCreateImage(cvGetSize(image), 8, 1);
	IplImage* contourLane = cvCreateImage(cvGetSize(image), 8, 1);
	IplImage* rgbBeatle = cvCloneImage(image);
	IplImage* rgbScan = cvCloneImage(image);
	IplImage* rgbLane = cvCloneImage(image);
	
	cvCvtColor(image, gray, CV_BGR2GRAY);
	cvThreshold(gray, bin, 0, 255, CV_THRESH_OTSU);
	
	Beatle(bin, contourBeatle);
	Scan(bin, contourScan);
	Lane(bin, contourLane);

	for (int r = 0; r < image->height; ++r)
	{
		for (int c = 0; c < image->width; ++c)
		{
			if (*cvPtr2D(contourBeatle, r, c) == 0)
			{
				*cvPtr2D(rgbBeatle, r, c) = 0; // B
				*(cvPtr2D(rgbBeatle, r, c) + 1) = 0; // G
				*(cvPtr2D(rgbBeatle, r, c) + 2) = 0; // R
			}

			if (*cvPtr2D(contourScan, r, c) == 0)
			{
				*cvPtr2D(rgbScan, r, c) = 0; // B
				*(cvPtr2D(rgbScan, r, c) + 1) = 0; // G
				*(cvPtr2D(rgbScan, r, c) + 2) = 0; // R
			}

			if (*cvPtr2D(contourLane, r, c) == 0)
			{
				*cvPtr2D(rgbLane, r, c) = 0; // B
				*(cvPtr2D(rgbLane, r, c) + 1) = 0; // G
				*(cvPtr2D(rgbLane, r, c) + 2) = 0; // R
			}
		}
	}

	cvShowImage("image", image);
	cvShowImage("gray", gray);
	cvShowImage("bin", bin);
	cvShowImage("contourBeatle", contourBeatle);
	cvShowImage("contourScan", contourScan);
	cvShowImage("contourLane", contourLane);
	cvShowImage("rgbBeatle", rgbBeatle);
	cvShowImage("rgbScan", rgbScan);
	cvShowImage("rgbLane", rgbLane);
	cvSaveImage("im_contourBeatle.bmp", contourBeatle);
	cvSaveImage("im_contourScan.bmp", contourScan);
	cvSaveImage("im_contourLane.bmp", contourLane);
	cvSaveImage("im_rgbBeatle.bmp", rgbBeatle);
	cvSaveImage("im_rgbScan.bmp", rgbScan);
	cvSaveImage("im_rgbLane.bmp", rgbLane);

	while (true)
	{
		int c = cvWaitKey();
		
		if ((char)c == 27)
			break;
	}
}
