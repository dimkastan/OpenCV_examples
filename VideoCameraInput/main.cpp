/*
 Simple camera/video preview demo.
 Tested with laptopt and usb camera indexed as 0 and 1 respectivelly --camera 0 and --camera 1
 as well as with video filepath

 Author: Dimitris Kastaniotis
*/
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

#include <iostream>
#include <cstring>  

int main(int argc,    char ** argv) {

	if (argc == 1)
	{
		std::cout << "Select a source:" << std::endl;
		std::cout<<" --camera { 0 | 1 } or --video video_filepath" << std::endl;
		std::cout << "Application will exit" << std::endl;
		return 0;
	}
	cv::VideoCapture cap;

	if (std::strcmp(argv[1] , "--camera")==0)
	{
		const int CamNum = atoi(argv[2]);
		if ((CamNum <0) || (CamNum > 1))
		{
			std::cout << "Select Camera {0 or 1}" << std::endl;
			std::cout << "Application will exit" << std::endl;
		}
		cap.open(CamNum);
	}
	else if(std::strcmp(argv[1] , "--video")==0) {
		if(argc!=3)
		{
			std::cout << "video filepath is missing" << std::endl;
			return 0;
		}else
		{
		    cap.open(argv[2]);
	    }

	}
	else {

		std::cout << "Select a source:" << std::endl;
		std::cout << " --camera { 0 | 1 } or --video video_filepath" << std::endl;
		std::cout << "Application will exit" << std::endl;
		return 0;
	}


	// Check stream status
	if (!cap.isOpened()) {
		std::cout << "Failed to open stream";
		return 0;
	}
	// loop over all available frames
	cv::Mat image;
	while (cap.read(image)) {
	 	cv::namedWindow("Input Frame",0);
		imshow("Input Frame", image);
		int key=cv::waitKey(20);
		if (key >0 ) // press any key to exit
		{
			std::cout << "Application will exit" << std::endl;
			break;
		}
	}
	return 0;
}