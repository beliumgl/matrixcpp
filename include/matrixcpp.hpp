#ifndef MATRIXCPP_HPP
#define MATRIXCPP_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Matrix {
public:
    std::vector<std::vector<T>> content;

    Matrix(const std::vector<std::vector<T>>& initialContent);

    Matrix operator+(const Matrix& matrix);
    Matrix operator-(const Matrix& matrix);
    Matrix operator*(const Matrix& matrix);

private:
    struct Dimensions {
        size_t rows;
        size_t columns;
    };

    Dimensions GetDimensions(const Matrix& matrix) const;
    bool CheckAdditionRequirements(const Matrix& matrix, const Matrix& otherMatrix) const;
    bool CheckMultiplicationRequirements(const Matrix& matrix, const Matrix& otherMatrix) const;
    Matrix InverseMatrix(const Matrix& matrix) const;
};

extern template class Matrix<int>;
extern template class Matrix<short>;
extern template class Matrix<long>;
extern template class Matrix<long long>;
extern template class Matrix<float>;
extern template class Matrix<double>;

#endif // MATRIXCPP_HPP
