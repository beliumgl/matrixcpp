#ifndef MATRIXCPP_HPP
#define MATRIXCPP_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    std::vector<std::vector<int>> content;

    Matrix(const std::vector<std::vector<int>>& initialContent);

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

#endif // MATRIXCPP_HPP
