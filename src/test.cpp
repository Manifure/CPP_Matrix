#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(S21MatrixTest, EqTest) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(2, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;
  other(1, 0) = 3;
  other(1, 1) = 4;

  ASSERT_TRUE(matrix.eq_matrix(other));
}

TEST(S21MatrixTest, EqTest2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(2, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;
  other(1, 0) = 8;
  other(1, 1) = 4;

  ASSERT_FALSE(matrix.eq_matrix(other));
}

TEST(S21MatrixTest, SumMatrixTest1) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.sum_matrix(matrix2);
  ASSERT_EQ(matrix1(0, 0), 6);
  ASSERT_EQ(matrix1(0, 1), 8);
  ASSERT_EQ(matrix1(1, 0), 10);
  ASSERT_EQ(matrix1(1, 1), 12);
}

TEST(S21MatrixTest, SumMatrixTest2) {
  S21Matrix matrix1(5, 5);
  matrix1(0, 4) = 3;
  matrix1(1, 1) = 75;
  matrix1(1, 3) = 9;
  matrix1(3, 1) = 12;
  matrix1(4, 2) = 4;
  std::cout << std::endl;

  S21Matrix matrix2(5, 5);
  matrix2(0, 4) = 5;
  matrix2(0, 2) = 9;
  matrix2(1, 1) = 30;
  matrix2(1, 3) = 1;
  matrix2(3, 1) = 100;
  matrix2(4, 2) = 5;

  std::cout << std::endl;

  matrix1.sum_matrix(matrix2);
  ASSERT_EQ(matrix1(0, 4), 8);
  ASSERT_EQ(matrix1(0, 2), 9);
  ASSERT_EQ(matrix1(1, 1), 105);
  ASSERT_EQ(matrix1(1, 3), 10);
  ASSERT_EQ(matrix1(3, 1), 112);
  ASSERT_EQ(matrix1(4, 2), 9);
}

TEST(S21MatrixTest, SumMatrix_InvalidDimensionsTest1) {
  S21Matrix matrix1(2, 7);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;

  ASSERT_THROW(matrix1.sum_matrix(matrix2), std::out_of_range);
}

TEST(S21MatrixTest, SumMatrix_InvalidDimensionsTest2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(1, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;

  ASSERT_THROW(matrix.sum_matrix(other), std::out_of_range);
}

TEST(S21MatrixTest, SubMatrixTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.sub_matrix(matrix2);

  ASSERT_EQ(matrix1(0, 0), -4);
  ASSERT_EQ(matrix1(0, 1), -4);
  ASSERT_EQ(matrix1(1, 0), -4);
  ASSERT_EQ(matrix1(1, 1), -4);
}

TEST(S21MatrixTest, MulNumberTest1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  matrix.MulNumber(2);

  ASSERT_EQ(matrix(0, 0), 2);
  ASSERT_EQ(matrix(0, 1), 4);
  ASSERT_EQ(matrix(1, 0), 6);
}

TEST(S21MatrixTest, MulNumberTest2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 5;
  matrix(1, 1) = 4;

  matrix.MulNumber(0.1);
  ASSERT_EQ(matrix(0, 0), 0.1);
  ASSERT_EQ(matrix(0, 1), 0.2);
  ASSERT_EQ(matrix(1, 0), 0.5);
  ASSERT_EQ(matrix(1, 1), 0.4);
}

TEST(S21MatrixTest, MulMatrixTest2) {
  S21Matrix matrix1(5, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 5);

  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.MulMatrix(matrix2);

  ASSERT_EQ(matrix1(0, 0), 19);
  ASSERT_EQ(matrix1(0, 1), 22);
  ASSERT_EQ(matrix1(1, 0), 43);
  ASSERT_EQ(matrix1(1, 1), 50);
}

TEST(S21MatrixTest, MulMatrixTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.MulMatrix(matrix2);

  ASSERT_EQ(matrix1(0, 0), 19);
  ASSERT_EQ(matrix1(0, 1), 22);
  ASSERT_EQ(matrix1(1, 0), 43);
  ASSERT_EQ(matrix1(1, 1), 50);
}

TEST(S21MatrixTest, TransposeTest) {
  S21Matrix matrix(3, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = 6;

  S21Matrix transposed = matrix.Transpose();

  ASSERT_EQ(transposed(0, 0), 1);
  ASSERT_EQ(transposed(0, 1), 3);
  ASSERT_EQ(transposed(0, 2), 5);
  ASSERT_EQ(transposed(1, 0), 2);
  ASSERT_EQ(transposed(1, 1), 4);
  ASSERT_EQ(transposed(1, 2), 6);
}

TEST(S21MatrixTest, CalcComplementsTest) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  S21Matrix complements = matrix.CalcComplements();

  ASSERT_EQ(complements(0, 0), -3);
  ASSERT_EQ(complements(0, 1), 6);
  ASSERT_EQ(complements(0, 2), -3);
}

TEST(S21MatrixTest, DeterminantTest) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  double determinant = matrix.Determinant();

  ASSERT_EQ(determinant, 0);
}

TEST(test_class, basic_constructor) {
  S21Matrix m;
  EXPECT_EQ(m.GetCols(), 3);
  EXPECT_EQ(m.GetRows(), 3);
}

TEST(test_class, rc_constructor) {
  S21Matrix m(69, 420);
  EXPECT_EQ(m.GetRows(), 69);
  EXPECT_EQ(m.GetCols(), 420);
}

TEST(test_class, copy_constructor) {
  S21Matrix m(12, 12);
  S21Matrix copy(m);

  EXPECT_EQ(copy.GetCols(), 12);
  EXPECT_EQ(copy.GetRows(), 12);
}

TEST(test_class, move_constructor) {
  S21Matrix m(12, 12);
  S21Matrix moved(std::move(m));

  EXPECT_EQ(m.GetCols(), 0);
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(moved.GetCols(), 12);
  EXPECT_EQ(moved.GetRows(), 12);
}

TEST(test_setters, Set_Rows_up) {
  S21Matrix m(2, 2);
  m(1, 1) = 6.9;

  m.SetRows(5);

  EXPECT_EQ(m.GetRows(), 5);
  EXPECT_EQ(m(1, 1), 6.9);
}

TEST(test_setters, Set_Rows_down) {
  S21Matrix m(2, 2);
  m(0, 0) = 6.9;

  m.SetRows(1);
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m(0, 0), 6.9);
}

TEST(test_setters, Set_Rows_zero) {
  S21Matrix m;

  EXPECT_ANY_THROW(m.SetRows(0));
}

TEST(test_setters, Set_Cols_up) {
  S21Matrix m(2, 2);
  m(1, 1) = 6.9;

  m.SetCols(5);
  EXPECT_EQ(m.GetCols(), 5);
  EXPECT_EQ(m(1, 1), 6.9);
}

TEST(test_setters, Set_Cols_down) {
  S21Matrix m(2, 2);
  m(0, 0) = 6.9;

  m.SetCols(1);

  EXPECT_EQ(m.GetCols(), 1);
  EXPECT_EQ(m(0, 0), 6.9);
}

TEST(test_setters, Set_Cols_zero) {
  S21Matrix m;

  EXPECT_ANY_THROW(m.SetCols(0));
}

TEST(test_functional, add_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m = m + n;

  EXPECT_EQ(m(0, 0), 2);
  EXPECT_EQ(m(1, 1), 2);
}

TEST(test_functional, eqadd_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m += n;

  EXPECT_EQ(m(0, 0), 2);
  EXPECT_EQ(m(1, 1), 2);
}

TEST(test_functional, sub_matrix) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m.sub_matrix(n);

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, eqsub_overloaded_operator) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m -= n;

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, sub_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m = m - n;

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, inverese_3x3) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);

  expected(0, 0) = 44300.0 / 367429.0;
  expected(0, 1) = -236300.0 / 367429.0;
  expected(0, 2) = 200360.0 / 367429.0;
  expected(1, 0) = 20600.0 / 367429.0;
  expected(1, 1) = 56000.0 / 367429.0;
  expected(1, 2) = -156483.0 / 367429.0;
  expected(2, 0) = 30900.0 / 367429.0;
  expected(2, 1) = 84000.0 / 367429.0;
  expected(2, 2) = -51010.0 / 367429.0;

  given(0, 0) = 2.8;
  given(0, 1) = 1.3;
  given(0, 2) = 7.01;
  given(1, 0) = -1.03;
  given(1, 1) = -2.3;
  given(1, 2) = 3.01;
  given(2, 0) = 0;
  given(2, 1) = -3;
  given(2, 2) = 2;
  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(S21MatrixTest, operator_mulMatrix) {
  S21Matrix B(2, 2);
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 5;
  B(1, 1) = 6;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 5;
  A(1, 1) = 6;

  expected(0, 0) = 11;
  expected(0, 1) = 14;
  expected(1, 0) = 35;
  expected(1, 1) = 46;

  B = B * A;
  EXPECT_EQ(1, B == expected);
}

TEST(S21MatrixTest, operator_mulNumbereq) {
  S21Matrix B(3, 4);
  S21Matrix A(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;

  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = 6;
  A(0, 3) = 8;
  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 14;
  A(1, 3) = 16;
  A(2, 0) = 18;
  A(2, 1) = 20;
  A(2, 2) = 22;
  A(2, 3) = 24;

  B *= 2;
  EXPECT_EQ(1, B == A);
}

TEST(S21MatrixTest, operator_mulMatrixeq) {
  S21Matrix B(2, 2);
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 5;
  B(1, 1) = 6;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 5;
  A(1, 1) = 6;

  expected(0, 0) = 11;
  expected(0, 1) = 14;
  expected(1, 0) = 35;
  expected(1, 1) = 46;

  B *= A;
  EXPECT_EQ(1, B == expected);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}