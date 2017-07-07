#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <time.h>
using namespace cv;

int main(){
    VideoCapture video1(0);
    VideoCapture video2(1);

    namedWindow("video",CV_WINDOW_NORMAL);
    setWindowProperty("video", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN );
    Mat Frame1,Frame2;
    clock_t start,stop;
    while(true){
	start = clock();
        video1 >> Frame1;
        video2 >> Frame2;
	stop = clock();
	printf("Loading Time %fs\n",double(stop - start) / CLOCKS_PER_SEC);
	start = clock();
        Mat C;
        hconcat(Frame1,Frame2,C);
	stop = clock();
	printf("Merge Time %fs\n",double(stop - start) / CLOCKS_PER_SEC);
        imshow("video",C);
       	int k = waitKey(1);
      	if(k=='a')
    		break;
	system("clear");
    }
    return 0;
}
