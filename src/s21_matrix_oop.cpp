#include "s21_matrix_oop.h"
#define DEFAULT 3;

S21Matrix::S21Matrix() {
  _rows = DEFAULT;
  _cols = DEFAULT;
  _p = new double *[_rows];
  for (int i = 0; i < _rows; i++) {
    _p[i] = new double[_cols];
  }
  NullMatrix();
}

S21Matrix::S21Matrix(int rows, int cols) {
  _rows = rows;
  _cols = cols;
  _p = new double *[_rows];
  for (int i = 0; i < _rows; i++) {
    _p[i] = new double[_cols];
  }
  NullMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &o) {
  this->_rows = o._rows;
  this->_cols = o._cols;
  this->_p = new double *[this->_rows];
  for (int a = 0; a < _rows; a++) {
    this->_p[a] = new double[this->_cols];
  }

  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_cols; j++) {
      this->_p[i][j] = o._p[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&o) {
  this->_rows = o._rows;
  this->_cols = o._cols;
  this->_p = new double *[this->_rows];
  for (int a = 0; a < _rows; a++) {
    this->_p[a] = new double[this->_cols];
  }

  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_cols; j++) {
      this->_p[i][j] = o._p[i][j];
    }
  }
  o.~S21Matrix();
}

S21Matrix::~S21Matrix() {
  if (_p != nullptr) {
    for (int i = 0; i < _rows; i++) {
      delete[] _p[i];
    }
    delete[] _p;
    _p = nullptr;
    _rows = 0;
    _cols = 0;
  }
}

S21Matrix &S21Matrix::operator=(const S21Matrix &o) {
  if (this->_p != nullptr) {
    this->~S21Matrix();
  }
  this->_rows = o._rows;
  this->_cols = o._cols;
  this->_p = new double *[_rows]();
  for (int a = 0; a < _rows; a++) {
    _p[a] = new double[_cols];
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      this->_p[i][j] = o._p[i][j];
    }
  }

  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (_rows != row || _cols != col) {
    std::out_of_range("Incorrect input");
  }
  return _p[row][col];
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &o) {
  this->sum_matrix(o);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix &o) {
  sum_matrix(o);

  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &o) {
  sub_matrix(o);

  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &o) {
  S21Matrix result = *this;
  result.sub_matrix(o);

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &o) {
  S21Matrix result = *this;
  result.MulMatrix(o);

  return result;
}

bool S21Matrix::operator==(const S21Matrix &o) { return eq_matrix(o); }

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);

  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);

  return *this;
}

bool S21Matrix::eq_matrix(const S21Matrix &o) {
  bool status = false;
  if ((_rows == o._rows) && (_cols == o._cols)) {
    status = true;
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        if (fabs(_p[i][j] - o._p[i][j]) > 1e-6) {
          status = false;
        }
      }
    }
  }
  return status;
}

void S21Matrix::sum_matrix(const S21Matrix &o) {
  if (_rows == o._rows && _cols == o._cols) {
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        _p[i][j] = _p[i][j] + o._p[i][j];
      }
    }

  } else {
    throw std::out_of_range("ERROR: Different size");
  }
}

void S21Matrix::sub_matrix(const S21Matrix &o) {
  if (_rows == o._rows && _cols == o._cols) {
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        _p[i][j] = _p[i][j] - o._p[i][j];
      }
    }

  } else {
    throw std::out_of_range("ERROR: Different size");
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _p[i][j] = _p[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &o) {
  if (_cols == o._rows) {
    S21Matrix result(_rows, o._cols);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < o._cols; j++) {
        for (int k = 0; k < o._rows; k++) {
          result._p[i][j] += _p[i][k] * o._p[k][j];
        }
      }
    }
    this->~S21Matrix();
    *this = result;

  } else {
    throw std::out_of_range("ERROR: Size is wrong");
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix transpoted(_cols, _rows);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      transpoted._p[j][i] = this->_p[i][j];
    }
  }
  return transpoted;
}

S21Matrix S21Matrix::CalcComplements() {
  if (_rows <= 0 || _cols <= 0 || _cols != _rows)
    throw std::out_of_range("Matrix is not square");

  S21Matrix complem(_rows, _cols);

  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      S21Matrix minor = MinorMatrix(i, j);
      double minorDeterm = minor.Determinant();
      double complement = (i + j) % 2 == 0 ? minorDeterm : -minorDeterm;
      complem._p[i][j] = complement;
    }
  }

  return complem;
}

double S21Matrix::Determinant() {
  if (_rows <= 0 || _cols <= 0 || _rows != _cols)
    throw std::out_of_range("Matrix is not square");

  if (_rows == 1) return _p[0][0];

  if (_rows == 2) return _p[0][0] * _p[1][1] - _p[0][1] * _p[1][0];

  double determinant = 0.0;

  for (int j = 0; j < _cols; j++) {
    S21Matrix minor(MinorMatrix(0, j));
    double minorDeterminant = minor.Determinant();
    determinant += (j % 2 == 0 ? 1 : -1) * _p[0][j] * minorDeterminant;
  }

  return determinant;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (_rows <= 0 || _cols <= 0 || _rows != _cols)
    throw std::out_of_range("Matrix is not square");

  double determinant = Determinant();
  if (determinant == 0.0) throw std::out_of_range("Matrix is not invertible");

  S21Matrix Inverse = CalcComplements().Transpose();

  if (_rows == 1)
    Inverse._p[0][0] = 1.0 / determinant;
  else
    Inverse.MulNumber(1.0 / determinant);

  return Inverse;
}

S21Matrix S21Matrix::MinorMatrix(int rows, int cols) {
  if (_rows == 1 && _cols == 1) return *this;
  S21Matrix minor(_rows - 1, _cols - 1);

  int minorR = 0, minorC = 0;
  for (int i = 0; i < _rows; i++) {
    if (i == rows) continue;
    for (int j = 0; j < _cols; j++) {
      if (j == cols) continue;
      minor._p[minorR][minorC++] = _p[i][j];
    }
    minorR++;
    minorC = 0;
  }
  return minor;
}

void S21Matrix::NullMatrix() {
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_cols; j++) {
      this->_p[i][j] = 0.0;
    }
  }
}

void S21Matrix::SetRows(int rows) {
  if (rows <= 0 || _cols <= 0)
    throw std::length_error("Array size can't be zero");
  S21Matrix new_matrix(rows, _cols);
  for (int i = 0; i < (_rows < rows ? _rows : rows); i++)
    std::copy(_p[i], _p[i] + _cols, new_matrix._p[i]);
  this->~S21Matrix();
  *this = std::move(new_matrix);
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0 || _rows <= 0)
    throw std::length_error("Array size can't be zero");
  S21Matrix new_matrix(_rows, cols);
  for (int i = 0; i < _rows; i++)
    std::copy(_p[i], _p[i] + (_cols < cols ? _cols : cols), new_matrix._p[i]);
  this->~S21Matrix();
  *this = std::move(new_matrix);
}

int S21Matrix::GetRows() { return _rows; }

int S21Matrix::GetCols() { return _cols; }
