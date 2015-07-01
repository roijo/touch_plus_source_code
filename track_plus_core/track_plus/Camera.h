#pragma once
#include <winsock2.h>
#include <stdio.h>
#include <functional>
#include "opencv2/opencv.hpp"
#include "EtronDI_O.h"
#include "eSPAEAWBCtrl.h"
#include "CameraDS.h"
#include <time.h>
#include "RactivJPEGDecompressor.h"
#include "globals.h"

using namespace cv;
using namespace std;

class Camera
{
public:
	Camera();
	Camera(bool _useMJPEG, int _width, int _height, function<void (Mat& image_in)> callback_in);
	~Camera();
	unsigned char * frame;

	bool device_not_detected = false;

	unsigned static const left = 0;
	unsigned static const right = 1;
	unsigned static const both = 2;

	static function<void (Mat& image_in)> callback;
	
	unsigned char* getDataPointer();
	//accelerometer acquisition
	int getAccelerometerValues(int *x, int *y, int *z);
	
	// Camera Parameters
	int		setExposureTime(int whichSide, float expTime);
	float	getExposureTime(int whichSide);

	int		setGlobalGain(int whichSide, float gain);
	float	getGlobalGain(int whichSide);

	int		setColorGains(int whichSide, float red, float green, float blue);
	int		getColorGains(int whichSide, float *red, float *green, float * blue);

	int		turnLEDsOn();
	int		turnLEDsOff();

	int		enableAutoExposure(int whichSide);
	int		disableAutoExposure(int whichSide);

	int		enableAutoWhiteBalance(int whichSide);
	int		disableAutoWhiteBalance(int whichSide);

	int     do_software_unlock();
	int     isCameraPresent();
	string  getSerialNumber();

private:

	void YUY2_to_RGB24_Microsoft(BYTE *pSrc, BYTE *pDst, int cx, int cy);
	
	int width;
	int height;
	BYTE * buffer;
	BYTE * bufferRGB;
	BYTE * depth;
	Mat  result;
	Mat decoded;
	void *pHandle;
	Rect left_roi;
	Rect right_roi;
	int doSetup(const int & format);

	CvCapture                          *capture_camera_;
	CCameraDS                          *ds_camera_;
	
	bool useMJPEG;
	volatile long last_given_frame = 0;
	bool record;
	VideoWriter outputVideo;
};

