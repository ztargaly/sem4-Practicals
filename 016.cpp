/*Create Matrix class using templates. Write a menu-driven program 
to perform following Matrix operations (2-D array implementation): 
a) Sum b) Difference c) Product d) Transpose
*/
#include <iostream>
#include <vector>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<T>(cols));
    }

    void input() {
        std::cout << "Enter matrix elements:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions do not match for addition.");
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions do not match for subtraction.");
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication.");
        }

        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T> transpose() {
        Matrix<T> result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter rows and columns of matrices: ";
    std::cin >> rows >> cols;

    Matrix<int> matrix1(rows, cols);
    Matrix<int> matrix2(rows, cols);

    std::cout << "Enter elements for Matrix 1:" << std::endl;
    matrix1.input();

    std::cout << "Enter elements for Matrix 2:" << std::endl;
    matrix2.input();

    int choice;
    do {
        std::cout << "\nMatrix Operations Menu:\n";
        std::cout << "1. Sum\n";
        std::cout << "2. Difference\n";
        std::cout << "3. Product\n";
        std::cout << "4. Transpose\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                try {
                    Matrix<int> sum = matrix1 + matrix2;
                    std::cout << "Sum of matrices:" << std::endl;
                    sum.display();
                } catch (const std::invalid_argument& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 2:
                try {
                    Matrix<int> diff = matrix1 - matrix2;
                    std::cout << "Difference of matrices:" << std::endl;
                    diff.display();
                } catch (const std::invalid_argument& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 3:
                try {
                    Matrix<int> product = matrix1 * matrix2;
                    std::cout << "Product of matrices:" << std::endl;
                    product.display();
                } catch (const std::invalid_argument& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 4:
                std::cout << "Transpose of Matrix 1:" << std::endl;
                matrix1.transpose().display();
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
