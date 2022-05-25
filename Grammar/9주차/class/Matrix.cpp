#include "Matrix.h"

// Functions to get input to Matrix
// array arr[][]
void Matrix::input(vector<vector<int> >& A) {
  // Traverse the vector A[][]
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      arr[i][j] = A[i][j];
    }
  }
}

// Function to display the element
// of Matrix
void Matrix::display() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Print the element
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}

// Function for addition of two Matrix
// using operator overloading
Matrix Matrix::operator+(Matrix x) {
  // To store the sum of Matrices
  Matrix mat;

  // Traverse the Matrix x
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Add the corresponding
      // blocks of Matrices
      mat.arr[i][j] = arr[i][j] + x.arr[i][j];
    }
  }

  // Return the sum of Matrices
  return mat;
}

// Function for subtraction of two Matrix
// using operator overloading
Matrix Matrix::operator-(Matrix x) {
  // To store the difference of Matrices
  Matrix mat;

  // Traverse the Matrix x
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Subtract the corresponding
      // blocks of Matrices
      mat.arr[i][j] = arr[i][j] - x.arr[i][j];
    }
  }

  return mat;
}

// Function for multiplication of
// two Matrix using operator
// overloading
Matrix Matrix::operator*(Matrix x) {
  // To store the multiplication
  // of Matrices
  Matrix mat;

  // Traverse the Matrix x
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Initialise current block
      // with value zero
      mat.arr[i][j] = 0;

      for (int k = 0; k < N; k++) {
        mat.arr[i][j] += arr[i][k] * (x.arr[k][j]);
      }
    }
  }

  return mat;
}

Matrix Matrix::operator=(Matrix x) {
  // To store the multiplication
  // of Matrices
  Matrix mat;

  // Traverse the Matrix x
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Initialise current block
      // with value zero
      mat.arr[i][j] = 0;

      for (int k = 0; k < N; k++) {
        mat.arr[i][j] += arr[i][k] * (x.arr[k][j]);
      }
    }
  }

  return mat;
}

ostream& operator<<(ostream& stream, const Matrix& x) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // Print the element
      stream << x.arr[i][j] << ' ';
    }
    stream << endl;
  }
  return stream;
}
