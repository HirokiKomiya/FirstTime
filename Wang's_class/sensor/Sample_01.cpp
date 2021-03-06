#include <opencv\cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> // highguiのヘッダーをインクルード
#include <iostream>

int main(int argc, const char* argv[])
{
	IplImage* img;
	cvNamedWindow("Window");

	img = cvLoadImage("lena.jpg");

	if (img == NULL){
		printf("no file\n");
		cvWaitKey(0);
		return -1;

	}

	cvShowImage("Window", img);

	cvWaitKey(0);

	cvDestroyWindow("Window");
	cvReleaseImage(&img);

	return 0;
}