#include "cv.h"
#include "highgui.h"

#define WIN_NAME "Scale Down Image"

IplImage* scale_down(IplImage *in, int filter)
{
    assert(in->width % 2 == 0 && in->height % 2 == 0);

    IplImage *out = cvCreateImage(
        cvSize(in->width / 2, in->height / 2),
        in->depth,
        in->nChannels
    );
    cvPyrDown(in, out, filter);
    return out;
}

IplImage* canny_edge_recognize(IplImage *in, 
                               double lowThresh, 
                               double highThresh, 
                               int aperture)
{
    IplImage *out = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);
    cvCanny(in, out, lowThresh, highThresh, aperture);
    return out;
}

int main(int argc, const char *argv[])
{
    IplImage *in = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
    IplImage *out = scale_down(in, IPL_GAUSSIAN_5x5);
    IplImage *out2 = canny_edge_recognize(out, 10, 100, 3);
    cvNamedWindow(WIN_NAME, CV_WINDOW_AUTOSIZE);
    cvShowImage(WIN_NAME, out2);
    cvReleaseImage(&in);
    cvWaitKey(0);
    cvReleaseImage(&out);
    cvReleaseImage(&out2);
    cvDestroyWindow(WIN_NAME);
    return 0;
}
