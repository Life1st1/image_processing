#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    if(cap.isOpened() == false) {
        std::cout << "Error opening video stream" << std::endl;
        return -1;
    }

    cv::Mat frame;
    std::cout << "Press 'q' to exit the video stream." << std::endl;
    while(true) {
        cap >> frame;

        if(frame.empty()) {
            std::cout << "Error capturing frame" << std::endl;
            break;
        }

        cv::imshow("Video Stream1", frame);

        char key = (char)cv::waitKey(10);
        if(key == 'q' || key == 27) {
            break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}   