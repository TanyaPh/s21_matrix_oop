#ifndef __S21MATRIX_OOP_H__
#define __S21MATRIX_OOP_H__

#include <iostream>
#include <exception>
#include <cstring>

class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();                                                // default constructor
        S21Matrix(int rows, int cols);                              // parameterized constructor
        S21Matrix(const S21Matrix& other);                          // copy cnstructor
        S21Matrix(S21Matrix&& other);                               // move cnstructor
        ~S21Matrix();                                               // destructor

        int GetRows() const {
            return rows_;
        }
        int GetCols() const {
            return cols_; 
        }
        int SetRows(int rows) {
            rows_ = rows;
            return rows_;
        }
        int SetCols(int cols) {
            cols_ = cols;
            return cols_; 
        }

        // some public methods
        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other); 
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();
};





// class S21Matrix {
// private:
//     // attributes
//     int _rows, _cols;                                           // rows and columns attributes
//     double **_p;                                                // pointer to the memory where the matrix will be allocated


// public:
//     S21Matrix();                                                // default constructor
//     S21Matrix(int rows, int cols);                              // parameterized constructor
//     S21Matrix(const S21Matrix& o);                              // copy cnstructor
//     S21Matrix(S21Matrix&& o);                                   // move cnstructor
//     ~S21Matrix();                                               // destructor

//     // some operators overloads
//     S21Matrix& operator=(const S21Matrix& o);                   // assignment operator overload
//     int& operator()(int row, int col);                          // index operator overload
//     int& operator()(int row, int col) const;
//     S21Matrix& operator+=(const S21Matrix& o);                            
//     S21Matrix operator+(const S21Matrix& o);
//     S21Matrix& operator-=(const S21Matrix& o);
//     S21Matrix operator-(const S21Matrix& o);
    
//     // some public methods
//     bool eq_matrix(const S21Matrix& o);
//     void sum_matrix(const S21Matrix& o); 
//     void sub_matrix(const S21Matrix& o);
    
// };

#endif
