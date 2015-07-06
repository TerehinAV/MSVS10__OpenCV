// OpenCV_Hello_World.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>


int _tmain(int argc, _TCHAR* argv[])
{
	IplImage* src=cvLoadImage("apple.bmp",1);

    // �������� ������� �����������. ������ ���,
    //����� ��������� ������� OpenCV
	IplImage* smooth = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);
	cvSmooth(src, smooth, CV_MEDIAN, 21, 21 );
    if(src==NULL){ /* ���� ����� ����� �������� ��� */
        printf("������� ���� ���� �� ����������");
        exit(0);
    }
	IplImage* gray = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	//cvCvtColor(src, gray, CV_BGR2GRAY);
	cvCvtColor(smooth, gray, CV_BGR2GRAY);

	IplImage* bin = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	cvThreshold(gray, bin, 50, 250, CV_THRESH_OTSU);

    cvNamedWindow("src", CV_WINDOW_AUTOSIZE );
	cvNamedWindow("smooth", CV_WINDOW_AUTOSIZE );
	cvNamedWindow("gray", CV_WINDOW_AUTOSIZE );
	cvNamedWindow("bin", CV_WINDOW_AUTOSIZE );

    cvShowImage("src",src);
	cvShowImage("smooth",smooth);
    cvShowImage("gray",gray);
	cvShowImage("bin",bin);
    
	//cvSaveImage("image.jpg",frame);     
    cvWaitKey();/* ����, ���� �� ���-������ �� �������, 
                       ����� ������ ������ "��������" � ��
                       ������ ���� ������ �� �������� */
    cvDestroyAllWindows();
	return 0;
}

