#pragma once

#include <direct.h>
#include <windows.h>

// #include <atlstr.h>
// #include <ShlObj.h>

#include <iostream>
#include <fstream>
#include <string.h>
#include <opencv2/opencv.hpp>
#include "globals.h"
#include "math_plus.h"
#include "curve_fitting.h"
#include "ipc.h"
#include "processes.h"
#include "filesystem.h"

using namespace std;
using namespace cv;

class Reprojector
{
public:
	double a_out;
	double b_out;
	double c_out;
	double d_out;

	Point** rect_mat0 = NULL;
	Point** rect_mat1 = NULL;

	void load(IPC& ipc);
	void proceed();
	float compute_depth(float disparity_in);
	Point2f compute_plane_size(float depth);
	Point3f reproject_to_3d(float pt0_x, float pt0_y, float pt1_x, float pt1_y);
	Mat remap(Mat* const image_in, const uchar side, const bool interpolate);
	Mat remap(Mat* const image_in, const int x_offset, const int y_offset, const uchar side, Point& pt_offset);
	Point remap_point(Point& pt_in, const uchar side, const uchar scale);
	Mat compute_gray_image(Mat* const image);

private:
	struct compare_point_x
	{
		inline bool operator() (const Point pt0_in, const Point pt1_in)
		{
			return pt0_in.x < pt1_in.x;
		}
	};
};