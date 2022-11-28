#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void faceDetection() {
    Mat frame;
    VideoCapture cap(0);
    CascadeClassifier facedetect;
    facedetect.load("haarcascade_frontalface_default.xml");

    //https://github.com/opencv/opencv/tree/master/data/haarcascades

    for(;;) {
        cap.read(frame);

        vector<Rect> faces;

        facedetect.detectMultiScale(frame, faces, 1.3, 5);

        for (int i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 2);
            rectangle(frame, Point(0, 0), Point(240, 50), Scalar(50, 50, 255), FILLED);
            putText(frame, to_string(faces.size()) + " Face Found", Point(5, 35), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 2);
        }

        imshow("Live", frame);
        waitKey(1);
    }
}

int main() {
	faceDetection();

	return 0;
}