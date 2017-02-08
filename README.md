# Human Hand Detection utilising OpenCV
The software provided identifies a human hand from a video stream(webcam) by performing some analytical operations on the input video stream. It has been coded using the OpenCV 3.1 within Visual Studio 2015 on Windows 10.

Usage:
It is necessary to adjust the HSV values to match the skin colour of the hand to be detected. To do this, edit the following lines in the code: 

  ```
	// HSV Range Values
	int H_MIN = 0;
	int H_MAX = 20;
	int S_MIN = 10;
	int S_MAX = 150;
	int V_MIN = 60;
	int V_MAX = 255;
  ```
