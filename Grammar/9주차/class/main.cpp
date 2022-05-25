#include "Matrix.h"

// Driver Code
int main() {
  // Dimension of Matrix
  N = 3;

  vector<vector<int> > arr1 = {{1, 2, 3}, {4, 5, 6}, {1, 2, 3}};

  vector<vector<int> > arr2 = {{1, 2, 3}, {4, 5, 16}, {1, 2, 3}};

  // Declare Matrices
  Matrix mat1, mat2;

  // Take Input to matrix mat1
  mat1.input(arr1);

  // Take Input to matrix mat2
  mat2.input(arr2);

  // For addition of matrix
  cout << "Addition of two given"
       << " Matrices is : \n";
  cout << (mat1 + mat2);

  // For subtraction of matrix
  cout << "Subtraction of two given"
       << " Matrices is : \n";
  cout << mat1 - mat2;

  // For multiplication of matrix
  cout << "Multiplication of two"
       << " given Matrices is : \n";
  cout << mat1 * mat2;

  // Dynamic memory allocation
  Matrix* mat3 = new Matrix;
  Matrix* mat4 = new Matrix;

  mat3->input(arr1);
  mat4->input(arr2);

  // For addition of matrix
  cout << "Addition of two given"
       << " Matrices is : \n";
  cout << (*mat3 + *mat4);

  // For subtraction of matrix
  cout << "Subtraction of two given"
       << " Matrices is : \n";
  cout << (*mat3 - *mat4);

  // For multiplication of matrix
  cout << "Multiplication of two"
       << " given Matrices is : \n";
  cout << (*mat3 * *mat4);

  return 0;
}