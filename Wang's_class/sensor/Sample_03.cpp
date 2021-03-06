#include <opencv\cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> // highguiのヘッダーをインクルード
#include <iostream>

int main(int argc, const char* argv[])
{
	int key;
	CvCapture *capture;
	IplImage *frameImage;

	cvNamedWindow("window", CV_WINDOW_AUTOSIZE);

	if ((capture = cvCaptureFromCAM(0)) == NULL){
		printf("カメラが見つかりません\n");
		return -1;
	}

	while (1){
		frameImage = cvQueryFrame(capture);

		cvShowImage("window", frameImage);

		key = cvWaitKey(1);
		if (key == 'q'){
			break;
		}
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("window");

	return 0;
}