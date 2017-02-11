/* Human Hand Detection using OpenCV 3.1
   Author: FShiwani
   Date: 10.02.17
*/

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argv, char** argc) {

	// Image Frames
	Mat src;
	Mat hsv;
	Mat threshold;

	// ADJUST THE FOLLOWING TO MATCH SKIN COLOUR
	// HSV Range Values
	int H_MIN = 0;
	int H_MAX = 20;
	int S_MIN = 10;
	int S_MAX = 150;
	int V_MIN = 60;
	int V_MAX = 255;

	Rect hand_bound;

	VideoCapture capture;
	capture.open(0); // 0 is the default webcam.

	while (true) {
		capture >> src;
		cvtColor(src, hsv, COLOR_BGR2HSV); // converting source frame from RGB colour space to HSV colour space.
		inRange(hsv, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), threshold); // creates a threshold frame after applying HSV min and max conditions to the HSV frame

		
		std::vector<std::vector<Point> > contours; // used to contain hull points for each contour.
		findContours(threshold, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); // finds contours from threshold frame and stores them in contours.

		// Locating the contour with the largest area(i.e the hand in this case.)
		double largest_contour_area = 0.0f;
		int largest_contour_area_index = 1;
		for (int i = 0; i < contours.size(); i++) {

			double contour_area = contourArea(contours[i], false);

			if (contour_area > largest_contour_area) { // if a contour with a larger area is found, update the associated largest_contour variables
				largest_contour_area = contour_area;
				largest_contour_area_index = i;
				hand_bound = boundingRect(contours[i]);
			}

		}

		// Modifying src frame.
		drawContours(src, contours, largest_contour_area_index, (0, 255, 0), 1); // Draws the largest contour on the src frame.
		rectangle(src, hand_bound, (0, 255, 0), 1, 8, 0); // Draws the rectangle hand_bound on the src frame.

		// Displaying src and threshold frames in seperate windows.
		imshow("src", src);
		imshow("Threshold", threshold);
		waitKey(10); // Used to allow time to process imshow events.
			
	}

	return 0;

}