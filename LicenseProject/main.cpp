#include <iostream>
#include <stdexcept>

#include "SeriesBuilder.hpp"
#include "EdgeExtractor.hpp"
//#include <opencv2/opencv.hpp>
/*
	PREPROCESSING to do: checkpoint
	PROCESSING 1: canny edge detection
	PROCESSING 2: generate points
	PROCESSING 3: generate mesh
*/
static void preprocessing();
static void processing1();
static void processing2() {};
static void processing3() {};

const bool withCheckpoints{ false };

int main() {
	// if this pipeline is going to be moved in a class (maybe a template pattern), 
	preprocessing();
	processing1();
	processing2();
	processing3();

	//std::cout << "---END-OF-EXECUTION---\n";
	//std::cin.get();

	return EXIT_SUCCESS;
}

void preprocessing()
{
	try {
		SeriesBuilder seriesBuilder{ "C:\\Users\\L7aur\\Desktop\\StatusCodeLic\\dicom_data\\Series 500 [CT - CRANE APC]", withCheckpoints };
		seriesBuilder.waitForFinish();
	}
	catch (...) {
		std::cout << "Unable to create the multithreaded series builder!\n Exception: " << /*e.what() <<*/ std::endl;
		std::exit(EXIT_THREAD_ALLOCATION_ERROR);
	}
}

void processing1()
{
	//cv::Mat m = cv::imread("C:\\Users\\L7aur\\Desktop\\StatusCodeLic\\dicom_data\\Series 500 [CT - CRANE APC]\\1.3.6.1.4.1.5962.99.1.2786334768.1849416866.1385765836848.668.0.dcm");
	//cv::imshow("...", m);
	//try {
	//	EdgeExtractor edgeExtractor{ withCheckpoints };
	//	edgeExtractor.waitForFinish();
	//}
	//catch (const std::exception& e) {
	//	std::cout << "Unable to create the multithreaded edge extractor!\n Exception: " << e.what() << std::endl;
	//	std::exit(EXIT_THREAD_ALLOCATION_ERROR);
	//}
}
