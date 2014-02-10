#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <cstdio>
#include <cmath>


#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O


using namespace std;

int main(int argc, char** argv) {
  
  string orl_database_path;
  
  if(argc > 1) orl_database_path = argv[1];
  else {
    cout << "Usage: Faces <path_to_orl_faces_database>";
    return -1;
  }
  
  cout << endl << orl_database_path << endl;
  
  
  return 0;
}