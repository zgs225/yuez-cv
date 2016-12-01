#include <stdio.h>
#include <highgui.h>

int main(int argc, const char *argv[])
{
    cvNamedWindow("Play Video", CV_WINDOW_AUTOSIZE);
    CvCapture *capture = cvCaptureFromFile(argv[1]);
    IplImage *frame;

    while(1)
    {
        frame = cvQueryFrame(capture);
        if (! frame) break;
        cvShowImage("Play Video", frame);

        char c = cvWaitKey(33);
        if (c == 27) break; // Esc pressed
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow("Play Video");

    return 0;
}
