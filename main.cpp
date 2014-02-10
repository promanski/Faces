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
using namespace cv;

int main(int argc, char** argv) {
  
  // Getting database path
  string orl_database_path;
  
  if(argc > 1) orl_database_path = argv[1];
  else {
    cout << "Usage: Faces <path_to_orl_faces_database>";
    return -1;
  }
  
  for(int class_counter = 1; class_counter <= 40; class_counter++) {
    // Getting class database path
    stringstream sstream;
    string class_path;
    sstream << orl_database_path << "/s" << class_counter;
    sstream >> class_path;
    
    for(int image_counter = 1; image_counter <= 10; image_counter++) {
      // Getting image path
      stringstream sstream2;
      string image_path;
      sstream2 << class_path << "/" << image_counter << ".pgm";
      sstream2 >> image_path;
      
      Mat image;
      image = imread(image_path, CV_LOAD_IMAGE_COLOR);
      namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
      imshow( "Display window", image );                   // Show our image inside it.
      waitKey(0); 
      
    }
  }
  
  
  return 0;
}
