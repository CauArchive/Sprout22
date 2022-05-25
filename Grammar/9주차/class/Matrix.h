#include <iostream>
#include <vector>
#define rows 50
#define cols 50

using namespace std;

int N;

// Class for Matrix operator overloading
class Matrix {
  // For input Matrix
  int arr[rows][cols];

 public:
  // Function to take input to arr[][]
  void input(vector<vector<int> >& A);
  void display();

  // Functions for operator overloading
  Matrix operator+(Matrix x);
  Matrix operator-(Matrix x);
  Matrix operator*(Matrix x);
  Matrix operator=(Matrix x);
  friend ostream& operator<<(ostream& stream, const Matrix& x);
};