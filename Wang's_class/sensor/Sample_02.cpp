#include <opencv\cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp> // highguiのヘッダーをインクルード
#include <iostream>

int main(int argc, const char* argv[])
{
	IplImage *src_img, *dst_img1, *dst_img2, *dst_img3;
	IplImage *tmp_img;

	if ((src_img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE)) == 0)
		return -1;

	tmp_img = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_16S, 1);
	dst_img1 = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
	dst_img2 = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);
	dst_img3 = cvCreateImage(cvGetSize(src_img), IPL_DEPTH_8U, 1);

	cvSobel(src_img, tmp_img, 1, 0);
	cvConvertScaleAbs(tmp_img, dst_img1);

	cvLaplace(src_img, tmp_img);
	cvConvertScaleAbs(tmp_img, dst_img2);

	cvCanny(src_img, dst_img3, 50.0, 200.0);

	cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
	cvShowImage("Original", src_img);
	cvNamedWindow("Sobel", CV_WINDOW_AUTOSIZE);
	cvShowImage("Sobel", dst_img1);
	cvNamedWindow("Laplace", CV_WINDOW_AUTOSIZE);
	cvShowImage("Laplace", dst_img2);
	cvNamedWindow("Canny", CV_WINDOW_AUTOSIZE);
	cvShowImage("Canny", dst_img3);
	cvWaitKey(0);
	cvDestroyWindow("Original");
	cvDestroyWindow("Sobel");
	cvDestroyWindow("Laplace");
	cvDestroyWindow("Canny");
	cvReleaseImage(&src_img);
	cvReleaseImage(&dst_img1);
	cvReleaseImage(&dst_img2);
	cvReleaseImage(&dst_img3);
	cvReleaseImage(&tmp_img);

	return 0;
}