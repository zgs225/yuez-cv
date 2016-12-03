#include <stdio.h>
#include "cv.h"
#include "highgui.h"

#define WIN_NAME_IN  "Example4-in"
#define WIN_NAME_OUT "Example4-out"

void open_img(IplImage *img)
{
    cvNamedWindow(WIN_NAME_IN, CV_WINDOW_AUTOSIZE);
    cvNamedWindow(WIN_NAME_OUT, CV_WINDOW_AUTOSIZE);
    cvShowImage(WIN_NAME_IN, img);
    IplImage *out = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);
    // cvSmooth(img, out, CV_GAUSSIAN, 3, 3, 0.0, 0.0);
    cvSmooth(img, out, CV_BILATERAL, 3, 3, 0.0, 0.0);
    cvShowImage(WIN_NAME_OUT, out);
    cvWaitKey(0);
    cvReleaseImage(&out);
    cvReleaseImage(&img);
    cvDestroyWindow(WIN_NAME_IN);
    cvDestroyWindow(WIN_NAME_OUT);
}

int main(int argc, const char *argv[])
{
    IplImage *img = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
    open_img(img);
    return 0;
}
