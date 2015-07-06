#ifndef myfunctions_h 
#define myfunctions_h 
IplImage* rotationimage (IplImage * image)
{
	IplImage* scaled = 0;
	IplImage* gray = 0;
	IplImage* smooth = 0;
	IplImage* bin = 0;
	IplImage* temp = 0;
	IplImage* contour = 0;
	IplImage* tempp = 0;
	scaled = cvCreateImage(cvSize(320, 240), image->depth, image->nChannels);
	cvResize(image, scaled, CV_INTER_LINEAR);
	gray = cvCreateImage(cvGetSize(scaled), IPL_DEPTH_8U, 1);
	cvCvtColor(scaled, gray, CV_BGR2GRAY);
	smooth = cvCreateImage(cvGetSize(gray), IPL_DEPTH_8U, 1);
	cvSmooth(gray, smooth, CV_GAUSSIAN, 5);
	bin = cvCreateImage(cvGetSize(smooth), IPL_DEPTH_8U, 1);
	cvThreshold(smooth, bin, 0, 255, CV_THRESH_OTSU);
	temp = cvCloneImage(bin);
	contour = cvCreateImage(cvGetSize(temp), IPL_DEPTH_8U, 1);

	CvMemStorage* c_storage = cvCreateMemStorage(0);
	CvSeq* c_first= NULL;
	int count = cvFindContours(temp, c_storage, &c_first, sizeof(CvContour), CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
	for( CvSeq* c = c_first; c != NULL && c->h_next !=NULL ; c = c->h_next )
	{
		c_first=c;
	}
	IplImage *mini;
	CvSeq* c = c_first;
	CvBox2D box = cvMinAreaRect2(c);
	float width = box.size.width + 4;
	float height = box.size.height + 4;
	if(box.size.width<box.size.height)
	{
	width = box.size.height + 4;
	height = box.size.width + 4;
	}
	mini = cvCreateImage(cvSize(90, 90), IPL_DEPTH_8U, 1);
	cvFloodFill(mini, cvPoint(0, 0), cvScalarAll(255));
	//јфинные преобразовани€
	IplImage *mask = cvCreateImage(cvGetSize(contour), IPL_DEPTH_8U, 1);
	cvFloodFill(mask, cvPoint(0, 0), cvScalarAll(0));

	int wid = contour->width;
	int hei = contour->height;

	for (int y = 0; y < hei; y++)
	{
		for (int x = 0; x < wid; x++)
		{
			CvPoint2D32f point = cvPoint2D32f((double)x, (double)y);

			if (cvPointPolygonTest(c, point, false) >= 0)
			{
				if (contour->depth == IPL_DEPTH_8U)
				{
				((unsigned char*)(mask->imageData + mask->widthStep*y))[x] = UCHAR_MAX;
				}
				else
				{
				((unsigned short*)(mask->imageData + mask->widthStep*y))[x] = USHRT_MAX;
				}
			}
		}
	}
	IplImage *result = cvCreateImage(cvGetSize(contour), IPL_DEPTH_8U, 1);
	cvFloodFill(result, cvPoint(0, 0), cvScalarAll(255));
	cvCopy(bin, result, mask);
	int rndangle;
	if(width>160 || height>120)
	{
		rndangle=-25+random(50);
	}
	else rndangle=-30+ random(60);
	if (box.size.width < box.size.height) {
		float t = box.size.width;
		box.size.width = box.size.height;
		box.size.height = t;
		if(random(100)>50)
		box.angle += 90 - rndangle;
		else box.angle += 270 - rndangle;
		//275
	}
	else box.angle +=rndangle;
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

	CvMat* rot_mat = cvCreateMat(2, 3, CV_32FC1);
	cv2DRotationMatrix(box.center, (int)(box.angle * 100) / 100.0, 1.0, rot_mat);

	// выполн€ем вращение
	IplImage *rotate = cvCreateImage(cvGetSize(transform), IPL_DEPTH_8U, 1);
	cvWarpAffine(transform, rotate, rot_mat, CV_INTER_LINEAR | CV_WARP_FILL_OUTLIERS, cvScalarAll(255));
	int tmpp=-xc/2;
	int onx=10+random(300-width);
	int ony=50+random(30);
	srcTri[0].x = -onx + box.center.x - box.size.width / 2;
	srcTri[0].y = -ony + box.center.y - box.size.height / 2;
	srcTri[1].x = -onx + box.center.x + box.size.width / 2;
	srcTri[1].y = -ony + box.center.y - box.size.height / 2;
	srcTri[2].x = -onx + box.center.x - box.size.width / 2;
	srcTri[2].y = -ony + box.center.y + box.size.height / 2;
	dstTri[0].x = 0;
	dstTri[0].y = 0;
	dstTri[1].x = box.size.width - 1;
	dstTri[1].y = 0;
	dstTri[2].x = 0;
	dstTri[2].y = box.size.height - 1;

	trans_mat = cvCreateMat(2, 3, CV_32FC1);
	cvGetAffineTransform(srcTri, dstTri, trans_mat);
	cvWarpAffine(rotate, contour, trans_mat, CV_INTER_LINEAR | CV_WARP_FILL_OUTLIERS, cvScalarAll(255));
	cvReleaseImage(&image);
	cvReleaseImage(&scaled);
	cvReleaseImage(&gray);
	cvReleaseImage(&smooth);
	cvReleaseImage(&bin);
	cvReleaseImage(&mask);
	cvReleaseImage(&mini);
	cvReleaseImage(&result);
	cvReleaseImage(&transform);
	cvReleaseImage(&rotate);
	cvReleaseImage(&temp);
	//cvReleaseImage(&temp);
	return contour;
}
#endif