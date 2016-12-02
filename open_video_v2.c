#include <cv.h>
#include <highgui.h>

#define WIN_NAME "Control Video"

int        g_slider_position = 0;
CvCapture *g_capture         = NULL;

void onTrackBarSlide(int pos)
{
    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, const char *argv[])
{
    cvNamedWindow(WIN_NAME, CV_WINDOW_AUTOSIZE);
    g_capture = cvCaptureFromFile(argv[1]);
    int frames = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
    double fps = cvGetCaptureProperty(g_capture, CV_CAP_PROP_FPS);

    if (frames != 0)
    {
        cvCreateTrackbar(
            "Position",
            WIN_NAME,
            &g_slider_position,
            frames,
            onTrackBarSlide
        );
    }

    IplImage *frame;

    while(1)
    {
        frame = cvQueryFrame(g_capture);
        if (! frame) break;
        cvShowImage(WIN_NAME, frame);

        char c = cvWaitKey(33);
        if (c == 27) break;
    }

    cvReleaseCapture(&g_capture);
    cvDestroyWindow(WIN_NAME);

    return 0;
}
