#include <matrixcpp.hpp>

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& initialContent) {
    if (initialContent.empty()) {
        throw std::invalid_argument("Matrix content cannot be empty.");
    }

    size_t expectedRowLength = initialContent[0].size();
    for (const auto& row : initialContent) {
        if (row.size() != expectedRowLength) {
            throw std::invalid_argument("All rows must have the same length.");
        }
    }

    content = initialContent;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& matrix) {
    if (!CheckAdditionRequirements(*this, matrix)) {
        throw std::invalid_argument("This expression is not valid!");
    }

    Dimensions matrixDimensions = GetDimensions(*this);

    std::vector<std::vector<T>> resultContent(matrixDimensions.rows, std::vector<T>(matrixDimensions.columns));

    for (size_t i = 0; i < matrixDimensions.rows; i++) {
        for (size_t j = 0; j < matrixDimensions.columns; j++) {
            resultContent[i][j] = this->content[i][j] + matrix.content[i][j];
        }
    }

    return Matrix<T>{ resultContent };
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& matrix) {
    Matrix inversedMatrix = InverseMatrix(matrix);
    return *this + inversedMatrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& matrix) {
    if (!CheckMultiplicationRequirements(*this, matrix)) {
        throw std::invalid_argument("This expression is not valid!");
    }

    Dimensions matrixDimensions = GetDimensions(*this);
    Dimensions otherMatrixDimensions = GetDimensions(matrix);

    std::vector<std::vector<T>> resultContent(matrixDimensions.rows, std::vector<T>(otherMatrixDimensions.columns, 0));

    for (size_t i = 0; i < matrixDimensions.rows; i++) {
        for (size_t j = 0; j < otherMatrixDimensions.columns; j++) {
            for (size_t k = 0; k < matrixDimensions.columns; k++) {
                resultContent[i][j] += this->content[i][k] * matrix.content[k][j];
            }
        }
    }

    return Matrix<T>{ resultContent };
}

template <typename T>
typename Matrix<T>::Dimensions Matrix<T>::GetDimensions(const Matrix& matrix) const {
    Dimensions matrixDimensions;

    const size_t rows{ static_cast<size_t>(matrix.content.size()) };
    matrixDimensions.rows = rows;

    const size_t columns{ static_cast<size_t>(matrix.content[0].size()) };
    matrixDimensions.columns = columns;

    return matrixDimensions;
}

template <typename T>
bool Matrix<T>::CheckAdditionRequirements(const Matrix& matrix, const Matrix& otherMatrix) const {
    const Dimensions matrixDimensions{ GetDimensions(matrix) };
    const Dimensions otherMatrixDimensions{ GetDimensions(otherMatrix) };

    return (matrixDimensions.rows == otherMatrixDimensions.rows &&
    matrixDimensions.columns == otherMatrixDimensions.columns);
}

template <typename T>
bool Matrix<T>::CheckMultiplicationRequirements(const Matrix& matrix, const Matrix& otherMatrix) const {
    const Dimensions matrixDimensions{ GetDimensions(matrix) };
    const Dimensions otherMatrixDimensions{ GetDimensions(otherMatrix) };

    return (otherMatrixDimensions.rows == matrixDimensions.columns);
}

template <typename T>
Matrix<T> Matrix<T>::InverseMatrix(const Matrix& matrix) const {
    Dimensions matrixDimensions = GetDimensions(matrix);

    std::vector<std::vector<T>> resultContent(matrixDimensions.rows, std::vector<T>(matrixDimensions.columns));

    for (size_t i = 0; i < matrixDimensions.rows; i++) {
        for (size_t j = 0; j < matrixDimensions.columns; j++) {
            resultContent[i][j] = -matrix.content[i][j];
        }
    }

    return Matrix(resultContent);
}

template class Matrix<int>;
template class Matrix<short>;
template class Matrix<long>;
template class Matrix<long long>;
template class Matrix<float>;
template class Matrix<double>;
