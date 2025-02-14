#include<iostream>
using namespace std;

class Matrix{
    int rows;
    int cols;
    double *matrix;
    public:
        Matrix(){ // default
            matrix = nullptr;
        }
        Matrix(int rows, int cols){ // parameterized
            matrix = new double[rows * cols];
        }
        Matrix(Matrix &p){ // deep copy
            matrix = new double[rows * cols];
            for (int i = 0; i < rows; i++)
            {
                p.matrix[i] = matrix[i];
            }
        }
        Matrix(Matrix &&p){
            p.rows = 0;
            p.cols = 0;
            p.matrix = nullptr;
        }
        ~Matrix(){ // destructor
            cout << "Matrix Object Destroyed" << endl;
            delete[] matrix;
        }


        int getRows(){
            return rows;
        }
        int getCols(){
            return cols;
        }
        int at(int r, int c){
            return matrix[r * cols + c];
        }
        void fill(double value){
            for (int i = 0; i < (rows * cols); i++)
            {
                matrix[i] = value;
            }
        }
        Matrix transpose(){
            Matrix transposed(rows, cols); 
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    transposed.at(j, i) = at(i, j);
                }
            }
            return transposed;

        }



};

int main(){

    


    return 0;
}