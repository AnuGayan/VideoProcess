#include <iostream>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

class PlaneDetection{
    CascadeClassifier plane1;


public:PlaneDetection(){
        plane1.load("/home/anusha/IdeaProjects/Old/FaceDetection/cascades/haarcascade_fullbody.xml");
        if(plane1.empty()){
            cout<<"Cascade loading Error--\n";
        }else{
            cout<<"Cascade loaded successfully \n";
        }
    }

public:Mat detect(Mat video_stream){
        Mat mRgb,nGray,oTemp;
        vector<Rect> planes;
        vector<int > rejectLevels;
        vector<double > levelWights;
        int DetectedNumber;
        int temp=0;
        video_stream.copyTo(mRgb);
        cvtColor(mRgb,nGray,COLOR_BGR2GRAY);

//        if (temp = 1) {
//            temp =0;
            plane1.detectMultiScale(nGray, planes, rejectLevels, levelWights, 1.1, 3, 0, cvSize(0, 0), cvSize(0, 0),true);
            int DetectedNo = (int)planes.size();
        printf("Planes detected %d \n",DetectedNo);
        //cout<<DetectedNo+" Planes Detected \n";
//        plane1.detectMultiScale(nGray,planes);



            for (int i = 0; i < DetectedNumber; ++i) {
                Rect r = planes[i];
                rectangle(mRgb, cvPoint(r.x, r.y), cvPoint(r.x + r.width, r.y + r.height), CV_RGB(0, 255, 0));
                putText(mRgb, to_string(rejectLevels[i]), cvPoint(r.x, r.y), 1, 1.0, cvScalar(0, 0, 255));

            }
//        }
//        temp++;

        return mRgb;
    }
};

int main() {
    cv::VideoCapture capture;
    PlaneDetection planeDetection;
    Mat video_image;
    capture.open("/home/anusha/Videos/wso2-cafetria/ch05_20160816094942.mp4");
//    capture.open(0);

    if (!capture.isOpened()) {
        cout << "Could not initialize the capturing \n";
        return -1;
    } else {
        while (true) {
            capture.read(video_image);

            if (video_image.empty()) {
                cout << "Video not Found \n";
            } else {
                video_image = planeDetection.detect(video_image);

            }

            namedWindow("Out", WINDOW_AUTOSIZE);
            imshow("Out", video_image);
            if (waitKey(30) >= 0)break;
        }
    }
    return 0;

}