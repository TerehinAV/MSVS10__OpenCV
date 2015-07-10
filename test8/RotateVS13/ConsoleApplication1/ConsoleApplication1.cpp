#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
 
IplImage* rotationimage(IplImage* image)
{
	srand(time(NULL));

	IplImage* scaled = cvCreateImage(cvSize(320, 240), image->depth, image->nChannels);
	IplImage* gray = cvCreateImage(cvGetSize(scaled), IPL_DEPTH_8U, 1);
	IplImage* smooth = cvCreateImage(cvGetSize(scaled), IPL_DEPTH_8U, 1);
	IplImage* bin = cvCreateImage(cvGetSize(scaled), IPL_DEPTH_8U, 1);
	IplImage* temp; // ¬ременное изображение дл€ нахождени€ контура
	IplImage* contour = cvCreateImage(cvGetSize(scaled), IPL_DEPTH_8U, 1);
	
	cvResize(image, scaled, CV_INTER_LINEAR);
	cvCvtColor(scaled, gray, CV_BGR2GRAY);
	cvSmooth(gray, smooth, CV_GAUSSIAN, 5);
	cvThreshold(smooth, bin, 0, 255, CV_THRESH_OTSU);
	temp = cvCloneImage(bin);
	
	cvShowImage("image", image);
	cvShowImage("scaled", scaled);
	cvShowImage("gray", gray);
	cvShowImage("smooth", smooth);
	cvShowImage("bin", bin);

	CvMemStorage* c_storage = cvCreateMemStorage(0);
	CvSeq* c_first;
	int count = cvFindContours(temp, c_storage, &c_first);
	
	for (CvSeq* c = c_first; c != NULL && c->h_next != NULL; c = c->h_next)
	{
		c_first = c;
	}

	CvBox2D box = cvMinAreaRect2(c_first);
	float width = box.size.width + 4;
	float height = box.size.height + 4;
	
	if (box.size.width<box.size.height)
	{
		width = box.size.height + 4;
		height = box.size.width + 4;
	}

	IplImage* mask = cvCreateImage(cvGetSize(contour), IPL_DEPTH_8U, 1);
	cvFloodFill(mask, cvPoint(0, 0), cvScalarAll(0));

	for (int y = 0; y < contour->height; y++)
	{
		for (int x = 0; x < contour->width; x++)
		{
			CvPoint2D32f point = cvPoint2D32f((double)x, (double)y);

			if (cvPointPolygonTest(c_first, point, false) >= 0)
			{
				((unsigned char*)(mask->imageData + mask->widthStep*y))[x] = UCHAR_MAX;	
			}
		}
	}

	IplImage *result = cvCreateImage(cvGetSize(contour), IPL_DEPTH_8U, 1);
	cvFloodFill(result, cvPoint(0, 0), cvScalarAll(255));
	cvCopy(bin, result, mask);
	int rndangle;
	
	if (width > 160 || height > 120)
	{
		rndangle = -25 + rand() % 50;
	}
	else 
		rndangle = -30 + rand() % 60;
	
	if (box.size.width < box.size.height)
	{
		float t = box.size.width;
		box.size.width = box.size.height;
		box.size.height = t;

		if (rand() % 100 > 50)
			box.angle += 90 - rndangle;
		else 
			box.angle += 270 - rndangle;
	}
	else 
		box.angle += rndangle;
	
	float xc = contour->width / 2;
	float yc = contour->height / 2;

	CvPoint2D32f srcTri[3], dstTri[3];
	srcTri[0].x = 0;
	srcTri[0].y = 0;
	srcTri[1].x = result->width - 1;
	srcTri[1].y = 0;
	srcTri[2].x = 0;
	srcTri[2].y = result->height - 1;
	dstTri[0].x = (xc - box.center.x);
	dstTri[0].y = (yc - box.center.y);
	dstTri[1].x = result->width - 1 + (xc - box.center.x);
	dstTri[1].y = (yc - box.center.y);
	dstTri[2].x = (xc - box.center.x);
	dstTri[2].y = result->height - 1 + (yc - box.center.y);

	CvMat* trans_mat = cvCreateMat(2, 3, CV_32FC1);
	cvGetAffineTransform(srcTri, dstTri, trans_mat);

	IplImage *transform = cvCreateImage(cvGetSize(result), IPL_DEPTH_8U, 1);
	cvWarpAffine(result, transform, trans_mat, CV_INTER_LINEAR | CV_WARP_FILL_OUTLIERS, cvScalarAll(255));
	
	box.center.x = xc;
	box.center.y = yc;

	cvShowImage("transform", transform);

	CvMat* rot_mat = cvCreateMat(2, 3, CV_32FC1);
	cv2DRotationMatrix(box.center, box.angle, 1.0, rot_mat);

	IplImage *rotate = cvCreateImage(cvGetSize(transform), IPL_DEPTH_8U, 1);
	cvWarpAffine(transform, rotate, rot_mat, CV_INTER_LINEAR | CV_WARP_FILL_OUTLIERS, cvScalarAll(255));
	
	cvReleaseImage(&scaled);
	cvReleaseImage(&gray);
	cvReleaseImage(&smooth);
	cvReleaseImage(&bin);
	cvReleaseImage(&mask);
	cvReleaseImage(&result);
	cvReleaseImage(&transform);
	cvReleaseImage(&temp);
	cvReleaseImage(&contour);

	return rotate;
}

int main(int argc, char ** argv)
{
	IplImage *image = cvLoadImage("1.png");

	IplImage *rotate_im = rotationimage(image);
	cvShowImage("rotate_im", rotate_im);

	while (true)
	{
		int c = cvWaitKey();
		
		if ((char)c == 27)
			break;
	}
}
