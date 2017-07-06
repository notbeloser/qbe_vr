#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
    VideoCapture video1(1);
    VideoCapture video2(2);

    namedWindow("video",CV_WINDOW_NORMAL);
    setWindowProperty("video", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN );
    Mat Frame1,Frame2;

    while(true){
        video1 >> Frame1;
        video2 >> Frame2;
        Mat C;
        hconcat(Frame1,Frame2,C);
        imshow("video",C);
       int k = waitKey(33);
       if(k=='a')
    	   break;
    }
    return 0;
}
