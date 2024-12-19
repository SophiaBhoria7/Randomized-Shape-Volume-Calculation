// Programmer: Sophia Bhoria
// Date: Oct 01, 2024
// Purpose: A program that takes in the user's input for a shape and then outputs the volume of the shape with random dimensions

#include <iostream>
#include <cstdlib>   // For the rand() and srand() functions 
#include <ctime>     // For the time() function 
#include <string>
using namespace std;

// Template function to compute volume
template <typename T>
T computeVolume(T dimension1, T dimension2, T dimension3, const string shape) {
  // Convert string shape to an integer for switch-case
  int shapeCode = 0;
  if (shape == "cube") {
    shapeCode = 1; // showing when the user puts in 1
  } else if (shape == "cuboid") {
    shapeCode = 2; //showing when the user puts in 2
  } else if (shape == "cylinder") {
    shapeCode = 3; //showing when the user puts in 3
  }
  
  // Use switch-case to compute volume
  switch (shapeCode) {
    case 1: // returning the volume of a CUBE
      return dimension1 * dimension1 * dimension1;
    case 2: // returning the volume of a CUBOID
      return dimension1 * dimension2 * dimension3;
    case 3: // returning the volume of a CYLINDER
      return 3.14 * dimension1 * dimension1 * dimension2;
    default:
      cout << "Invalid shape!" << endl;
      return 0;
  }
}

// Function to generate random dimensions
double generateRandomDimension() {
  bool generateInt = rand() % 2;
  if (generateInt == 1) {
    return static_cast<double>(rand()) / RAND_MAX * 9.0 + 1.0; // Random float between 1.0 and 10.0
  } else {
    return rand() % 10 + 1; // Random int between 1 and 10
  }
}

int main() {
  srand(time(0)); // This is the seed for the random number generator

  int shapeChoice;
  string shape;
  cout << "Select a shape (1: cube, 2: cuboid, 3: cylinder): ";
  cin >> shapeChoice;

  double dimension1 = generateRandomDimension();
  double dimension2 = generateRandomDimension();
  double dimension3 = generateRandomDimension();

  switch (shapeChoice) {
    case 1: // if the user puts in shapeChoice =1 
      shape = "cube"; 
      cout << "Shape: Cube" << endl; // print shape name
      cout << "Dimension: " << dimension1 << endl; // print dimension
      cout << "Volume: " << computeVolume<double>(dimension1, 0, 0, shape) << endl; // calc and print the volume 
      break;
    case 2: // if the user puts in shapeChoice =2
      shape = "cuboid";
      cout << "Shape: Cuboid" << endl; // print shape name 
      cout << "Dimensions: " << dimension1 << " x " << dimension2 << " x " << dimension3 << endl; //print dimensions
      cout << "Volume: " << computeVolume<double>(dimension1, dimension2, dimension3, shape) << endl; //calc and print the volume
      break;
    case 3: // if the user puts in shapeChoice =3
      shape = "cylinder";
      cout << "Shape: Cylinder" << endl; //print shape name
      cout << "Radius: " << dimension1 << ", Height: " << dimension2 << endl; //print radius and height (dimensions for cylinder) 
      cout << "Volume: " << computeVolume<double>(dimension1, dimension2, 0, shape) << endl; //calc and print the volume
      break;
    default:
      cout << "Invalid choice!" << endl;
  }
  
  return 0;
}

