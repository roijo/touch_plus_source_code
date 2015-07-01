#pragma once

#include "kalman.h"
#include "hungarian.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

class CTrack
{
public:
	vector<Point2f> trace;
	static size_t NextTrackID;
	size_t track_id;
	size_t skipped_frames; 
	Point2f prediction;
	Point2f raw;
	TKalmanFilter* KF;
	CTrack(Point2f p, float dt, float Accel_noise_mag);
	~CTrack();
};


class CTracker
{
public:
	float dt;
	float Accel_noise_mag;
	float dist_thres;
	int maximum_allowed_skipped_frames;
	int max_trace_length;

	vector<CTrack*> tracks;
	void Update(vector<Point2f>& detections);

	CTracker();
	CTracker(float _dt, float _Accel_noise_mag, float _dist_thres, int _maximum_allowed_skipped_frames, int _max_trace_length);
	~CTracker(void);
};

