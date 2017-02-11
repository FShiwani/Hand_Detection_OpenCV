# Human Hand Detection utilising OpenCV
The software provided identifies a human hand from a video stream(webcam) by performing some analytical operations on the input video stream. It has been developed using the OpenCV 3.1 library within Visual Studio 2015 on Windows 10.

## Usage:
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
  
  Furthermore, if you are utilising an external webcam, you will need to adjust the following line of code in order to match the device number of the webcam you wish to use:
  
  ```
  capture.open(0);
  ```
  0 is the default webcam. At the moment, the code is not utilising any enhancement features for noise reduction such as erode or dilate.
