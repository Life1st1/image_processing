#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    if(cap.isOpened() == false) {
        std::cout << "Error opening video stream" << std::endl;
        return -1;
    }

    cv::Mat frame;
    cv::Mat blurred_frame;
    cv::Mat edge_frame;
    std::cout << "Press 'q' to exit the video stream." << std::endl;
    while(true) {
        cap >> frame;

        if(frame.empty()) {
            std::cout << "Error capturing frame" << std::endl;
            break;
        }
        // Apply Gaussian blur to the frame
        cv::GaussianBlur(frame, blurred_frame, cv::Size(7, 7), 0);

        // Apply Canny edge detection
        cv::Canny(blurred_frame, edge_frame, 50, 150);

        //cv::imshow("Video Stream1", frame);
        //cv::imshow("Video Stream2", blurred_frame);
        cv::imshow("Video Stream3", edge_frame);

        char key = (char)cv::waitKey(10);
        if(key == 'q' || key == 27) {
            break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}   