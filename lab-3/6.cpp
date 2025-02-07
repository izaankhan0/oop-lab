#include <iostream>
#include <string>
using namespace std;

class Matrix {
	
	int rows, cols;
	int matrix[2][2];
	
	public:
		Matrix(int r, int c) : rows(r), cols(c) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }
		
		int getRows(){
			return rows;
		}
		
		int getCols(){
			return cols;
		}
		
		void setMatrix(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            matrix[i][j] = value;
        } else {
            cout << "Invalid index!" << endl;
        }
    }
		
		void display() {
	        for (int i = 0; i < rows; i++) {
	            for (int j = 0; j < cols; j++) {
	                cout << matrix[i][j] << " ";
	            }
	            cout << endl;
	        }
    }
		
		Matrix add(const Matrix & other){
	        if (rows != other.rows || cols != other.cols) {
	            cout << "Matrices cannot be added" << endl;
	            return Matrix(0, 0);
	        }
	        Matrix result(rows, cols);
	        for (int i = 0; i < rows; i++) {
	            for (int j = 0; j < cols; j++) {
	                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
	            }
	        }
	        return result;
    	}

    Matrix multiply(const Matrix & other) {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
};


int main() {
    Matrix mat1(2, 2), mat2(2, 2);
    
    mat1.setMatrix(0, 0, 1);
    mat1.setMatrix(0, 1, 2);
    mat1.setMatrix(1, 0, 3);
    mat1.setMatrix(1, 1, 4);
    
    mat2.setMatrix(0, 0, 5);
    mat2.setMatrix(0, 1, 6);
    mat2.setMatrix(1, 0, 7);
    mat2.setMatrix(1, 1, 8);
    
    cout << "Matrix 1:" << endl;
    mat1.display();
    
    cout << "Matrix 2:" << endl;
    mat2.display();
    
    Matrix sum = mat1.add(mat2);
    cout << "Sum of matrices:" << endl;
    sum.display();
    
    Matrix product = mat1.multiply(mat2);
    cout << "Product of matrices:" << endl;
    product.display();
    
    return 0;
}

