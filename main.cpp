#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <cstdio>
#include <cmath>
#include <vector>   // civilized way for storing multiple values...


#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O


using namespace std;
using namespace cv;

int main(int argc, char** argv) {
  
  if(argc < 3) {
    cout << "Usage: Faces <path_to_orl_faces_database>";
    return -1;
  }
  
  // Getting database path
  string orl_database_path = argv[1];
  string output_path = argv[2];
  
  // Images
  vector< vector< double > > images;
  
  Mat mean_face;
  int faces_counter = 0;
  
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
      
      // Get image
      Mat image;
      image = imread(image_path, CV_LOAD_IMAGE_COLOR);
      
      vector<double> img_normalized;
      
      // Normalize faces to 0-1
      for(int px = 0; px < 92*112*3; px += 3) {
        img_normalized.push_back(1.0 * image.data[px] / 255);
      }
      
      images.push_back(img_normalized);
      
      // Add to mean face
      if(faces_counter == 0) {
        mean_face = image;
      } else {
        mean_face = image / (faces_counter + 1) + mean_face * (1.0 * faces_counter/(faces_counter+1));
      }
      faces_counter++;
    }
  }
      
  //Display mean face so far
  namedWindow("Mean face", WINDOW_AUTOSIZE);
  imshow("Mean face", mean_face);
  waitKey(0); 
  
  // Normalize mean face to 0-1
  vector<double> mean_face_normalized;
  for(int px = 0; px < 92*112*3; px += 3) {
    mean_face_normalized.push_back(1.0 * mean_face.data[px] / 255);
  }
  
  // Remove mean face
  for(int i = 0; i < faces_counter; i++) {
    for(int px = 0; px < 92*112; px++) {
      images[i][px] = images[i][px] - mean_face_normalized[px];
    }
  }
  
  
  return 0;
}
