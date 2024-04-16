#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <math.h>

#include <iostream>

class S21Matrix {
 private:
  // attributes
  int _rows, _cols;  // rows and columns attributes
  double** _p;       // pointer to the memory where the matrix will be allocated

 public:
  S21Matrix();                    // default constructor
  S21Matrix(int rows, int cols);  // parameterized constructor
  S21Matrix(const S21Matrix& o);  // copy cnstructor
  S21Matrix(S21Matrix&& o);       // move cnstructor
  ~S21Matrix();                   // destructor

  S21Matrix& operator=(const S21Matrix& o);  // assignment operator overload
  double& operator()(int row, int col);      // index operator overload
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& o);
  bool operator==(const S21Matrix& o);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);

  bool eq_matrix(const S21Matrix& o);
  void sum_matrix(const S21Matrix& o);
  void sub_matrix(const S21Matrix& o);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix MinorMatrix(int rows, int cols);
  void NullMatrix();
  void SetRows(int rows);
  void SetCols(int cols);
  int GetRows();
  int GetCols();
};

#endif
