#include "s21_matrix_oop.h"
using namespace std;

S21Matrix::S21Matrix() {
    this->rows_ = 3;
    this->cols_ = 3;
    this->matrix_ = new double *[this->rows_];
    for (int i = 0; i < this->rows_; i++) {
        this->matrix_[i] = new double[this->cols_];
    }
    // matrix = new double[rows * cols];
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (this->rows_ < 1 || this->cols_ < 1) {
        throw std::exception();     //  "Incorrect input, matrices should have the size equal 1 and more"
    }
    this->matrix_ = new double *[this->rows_];
    for (int i = 0; i < this->rows_; i++) {
        this->matrix_[i] = new double[cols];
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : rows_(other.rows_), cols_(other.cols_) {
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
    // std::memcpy(this->matrix, other.matrix, other.rows * other.cols * sizeof(double));
}

// S21Matrix::S21Matrix(S21Matrix&& other) {
//     rows_ = other.rows_;
//     cols_ = other.cols_;
//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             matrix_[i][j] = other.matrix_[i][j];
//         }
//     }
//     // *this = std::move(other);
//     // if (other.matrix) {
//     //     for (int i = 0; i < other.rows; i++) {
//     //         delete[] other.matrix[i];
//     //     }
//     //     delete[] other.matrix;
//     //     matrix = NULL;
//     // }
//     other.rows_ = 0;
//     other.cols_ = 0;
// }

S21Matrix::S21Matrix(S21Matrix&& other) {
    S21Matrix(other);
    other.~S21Matrix();
}

S21Matrix::~S21Matrix() {
    if (matrix_) {
        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;
        matrix_ = NULL;
    }
    rows_ = 0;
    cols_ = 0;
}




int main() {
    S21Matrix m1;
    cout << m1.GetRows() << endl;
    S21Matrix m2(4, 5);
    cout << m2.GetRows() << endl;
    // S21Matrix *m2 = new S21Matrix(4, 5); 
    // cout << m2->getRows() << endl;
    // S21Matrix m3(m2);   автоматический конструктор клонирования (по умолчанию)
    S21Matrix m3 = m2;      // копирование при помощи оператора присваивания (определена по умолчанию)
    cout << m3.GetRows() << endl;
    S21Matrix m4 = m1;
    cout << m4.GetRows() << endl;
    cout << m1.GetRows() << endl;

    return 0;
}







// bool S21Matrix::EqMatrix(const S21Matrix& other) {
//     if (!matrix_ || rows_ < 1 || cols_ < 1 || !other.matrix_ || other.rows_ < 1|| other.cols_ < 1) {
//         throw std::exception();     //  "Incorrect input, matrices should have the size equal 1 and more"
//     }
//     if (cols_ != other.cols_ || rows_ != other.rows_) {
//         return false;
//     } else {
//         for (int i = 0; i < rows_; i++) {
//             for (int j = 0; j < cols_; j++) {
//                 if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {           // this is A != B
//                     return false;
//                 }
//             }
//         }
//     }
//     return true;
// }

// void S21Matrix::SumMatrix(const S21Matrix& other) {
//     if (!matrix_ || rows_ < 1 || cols_ < 1 || !other.matrix_ || other.rows_ < 1|| other.cols_ < 1) {
//         throw std::exception();     //  "Incorrect input, matrices should have the size equal 1 and more"
//     }
//     if (rows_ != other.rows_ || cols_ != other.cols_) {
//         throw std::exception();     //  "Incorrect input, matrices should have the same size"
//     }
//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
//         }
//     }
// }

// void S21Matrix::SubMatrix(const S21Matrix& other) {
//     if (!matrix_ || rows_ < 1 || cols_ < 1 || !other.matrix_ || other.rows_ < 1|| other.cols_ < 1) {
//         throw std::exception();     //  "Incorrect input, matrices should have the size equal 1 and more"
//     }
//     if (rows_ != other.rows_ || cols_ != other.cols_) {
//         throw std::exception();     //  "Incorrect input, matrices should have the same size"
//     }
//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
//         }
//     }
// }

// void S21Matrix::MulNumber(const double num) {
//     if (!matrix_ || rows_ < 1 || cols_ < 1 ) {
//         throw std::exception();     //  "Incorrect input, matrices should have the size equal 1 and more"
//     }
//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             matrix_[i][j] = matrix_[i][j] * num;
//         }
//     }
// }

// void S21Matrix::MulMatrix(const S21Matrix& other) {
//     if (!matrix_ || rows_ < 1 || cols_ < 1 || !other.matrix_ || other.rows_ < 1|| other.cols_ < 1) {
//         throw std::exception();     //  "Incorrect input, matrices should have the size equal 1 and more"
//     }
//     if (cols_ != other.rows_) {
//         throw std::exception();     //  "Incorrect input, matrices should have the same size"
//     }
//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             for (int k = 0; k < cols_; k++)
//                 matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
//         }
//     }
// }

















// S21Matrix::sum_matrix(const S21Matrix& o) {
//     // exception throwing example
//     if (_rows != other._rows || _cols != other._cols) {
//         throw std::out_of_range(
//             "Incorrect input, matrices should have the same size");
//     }
//     for (auto i = 0; i < _rows + _cols; i++) {
//         _p[i] = _p[i] + other._p[i];
//     }
// }

// // operator overload example
// S21Matrix S21Matrix::operator+(const S21Matrix& o) {
//     // creating result matrix
//     S21Matrix res(_rows, _cols);
//     res.sum_matrix(o);
//     return res;
// }

// // index operator overload
// int& CMatrix::operator()(int row, int col) {
//     if (row >= _rows || col >= _cols) {
//         throw std::out_of_range("Incorrect input, index is out of range");
//     }
//     return _p[row * _cols + col];
// }
