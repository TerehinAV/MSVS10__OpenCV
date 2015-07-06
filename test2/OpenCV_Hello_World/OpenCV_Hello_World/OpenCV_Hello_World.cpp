// OpenCV_Hello_World.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>


int _tmain(int argc, _TCHAR* argv[])
{
	IplImage* src=cvLoadImage("apple.bmp",1);

    // Немножко размоем изображение. Просто так,
    //чтобы потрогать функции OpenCV
	IplImage* smooth = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3); // трехканальное изображение RGB
	cvSmooth(src, smooth, CV_MEDIAN, 21, 21 );
    if(src==NULL){ /* Если вдруг такой картинки нет */
        printf("Кажется этот файл не существует");
        exit(0);
    }
	IplImage* gray = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1); // одноканальное изображение полутоновое
	
	//cvCvtColor(src, gray, CV_BGR2GRAY); // преобразование в полутон исходного изображения
	cvCvtColor(smooth, gray, CV_BGR2GRAY); // преобразование в полутон размытого изображения

	IplImage* bin = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1); // одноканальное изображение двуцветное (бинарное)
	cvThreshold(gray, bin, 50, 250, CV_THRESH_OTSU);

	IplImage * canny = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1); // одноканальное изображение контурное (алгоритм Кенни)
	//алгоритм Кенни
	cvCanny(gray, canny, 10, 100, 3);

    // находим контуры функцией cvFindContours

	IplImage * contour = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1); // одноканальное изображение контурное

	CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contours=0;

    int contoursCont = cvFindContours( bin, storage,&contours,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));

    // нарисуем контуры
	cvFloodFill(contour, cvPoint(0, 0), cvScalarAll(255)); //фон - белый
		
    for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
                cvDrawContours(contour, seq0, CV_RGB(0,0,0), CV_RGB(0,0,0), 0, 1, 8); // рисуем контур
    }

    cvNamedWindow("src", CV_WINDOW_AUTOSIZE );
	cvNamedWindow("canny", CV_WINDOW_AUTOSIZE );
	cvNamedWindow("contour", CV_WINDOW_AUTOSIZE );
	
    cvShowImage("src", src);
	cvShowImage("canny", canny);
    cvShowImage("contour", contour);
    
	//cvSaveImage("image.jpg",frame);     
    cvWaitKey();/* Ждем, пока вы что-нибудь не нажмете, 
                       иначе окошко просто "мелькнет" и вы
                       можете даже ничего не заметить */
            // освобождаем ресурсы
        cvReleaseImage(&src);
		cvReleaseImage(&smooth);
        cvReleaseImage(&gray);
        cvReleaseImage(&bin);

        cvReleaseImage(&canny);        
        cvReleaseImage(&contour);

       	cvDestroyAllWindows();
	return 0;
}

