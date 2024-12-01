# MatrixCPP

MatrixCPP is a simple C++11 project for performing basic matrix operations such as addition, subtraction, and multiplication.

# Requirements

- C++11 or later

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/matrixcpp.git
   cd matrixcpp
2. **Create a build directory**:
   ```bash
   mkdir build
   cd build
3. **Run CMake to configure the project and build it to static library**:
   ```bash
   cmake ..
   cmake --build .

# Usage
```cpp
#include "matrixcpp.hpp"
#include <iostream>

int main() {
    try {
        Matrix m1({{1, 2}, {3, 4}});
        Matrix m2({{5, 6}, {7, 8}});
        
        Matrix result = m1 + m2;

        for (const auto& row : result.content) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

