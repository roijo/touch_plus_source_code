#pragma once

#include <unordered_map>
#include <opencv2/opencv.hpp>
#include "globals.h"
#include "blob_detector_new.h"
#include "histogram_builder.h"
#include "low_pass_filter.h"
#include "id_point.h"

using namespace std;
using namespace cv;

class ValueStore
{
public:
	unordered_map<string, float> float_map;
	unordered_map<string, int> int_map;
	unordered_map<string, bool> bool_map;
	unordered_map<string, vector<int>*> int_vec_map;
	unordered_map<string, vector<Point>*> point_vec_map;
	unordered_map<string, vector<IDPoint>*> id_point_vec_map;
	unordered_map<string, vector<BlobNew>*> blob_vec_map;
	unordered_map<string, vector<Mat>*> mat_vec_map;
	unordered_map<string, Mat> mat_map;
	unordered_map<string, BlobDetectorNew*> blob_detector_map;
	unordered_map<string, HistogramBuilder*> histogram_builder_map;
	unordered_map<string, LowPassFilter*> low_pass_filter_map;

	vector<int>* int_vec_pool = new vector<int>[10];
	vector<Point>* point_vec_pool = new vector<Point>[10];
	vector<IDPoint>* id_point_vec_pool = new vector<IDPoint>[10];
	vector<BlobNew>* blob_vec_pool = new vector<BlobNew>[10];
	vector<Mat>* mat_vec_pool = new vector<Mat>[10];
	BlobDetectorNew* blob_detector_pool = new BlobDetectorNew[10];
	HistogramBuilder* histogram_builder_pool = new HistogramBuilder[10];
	LowPassFilter* low_pass_filter_pool = new LowPassFilter[10];

	int int_vec_pool_index = 0;
	int point_vec_pool_index = 0;
	int id_point_vec_pool_index = 0;
	int blob_vec_pool_index = 0;
	int mat_vec_pool_index = 0;
	int blob_detector_pool_index = 0;
	int histogram_builder_pool_index = 0;
	int low_pass_filter_pool_index = 0;

	void set_bool(string name, bool value);
	void set_float(string name, float value);
	void set_int(string name, int value);
	void set_point(string name, Point value);
	void set_point2f(string name, Point2f value);
	void set_mat(string name, Mat value);

	vector<int>* push_int(string name, int value);
	vector<Point>* push_point(string name, Point value);
	vector<IDPoint>* push_id_point(string name, IDPoint value);
	vector<BlobNew>* push_blob(string name, BlobNew value);
	vector<Mat>* push_mat(string name, Mat value);

	bool get_bool(string name, bool if_not_exist_result = false);
	float get_float(string name, float if_not_exist_result = 0);
	int get_int(string name, int if_not_exist_result = 0);
	Point get_point(string name, Point if_not_exist_result = Point(0, 0));
	Point2f get_point2f(string name, Point2f if_not_exist_result = Point2f(0, 0));
	Mat get_mat(string name, bool if_not_exist_return_zero_mat = false);

	vector<int>* get_int_vec(string name);
	vector<Point>* get_point_vec(string name);
	vector<IDPoint>* get_id_point_vec(string name);
	vector<BlobNew>* get_blob_vec(string name);
	vector<Mat>* get_mat_vec(string name);
	BlobDetectorNew* get_blob_detector(string name);
	HistogramBuilder* get_histogram_builder(string name);
	LowPassFilter* get_low_pass_filter(string name);

	bool has_point2f(string name);
};