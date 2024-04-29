#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class Matrix{
    protected:
    int col;
    int row;

    vector<vector<T>> arr;

    public: 
    Matrix(int row, int col) : row(row), col(col) {
        arr.resize(row);

        for(int i =0; i < this->row; ++i){
            arr[i].resize(col);
        }
    }

    void setMatrix(int row, int col, T n){
        this->arr[row][col] = n;
    }
    T getMatrix(int row, int col){
        return this->arr[row][col];
    }

    Matrix<T> operator+(Matrix<T>& other){
        Matrix<T> result(this->row, this->col);

        for(int i=0;i < this->row; ++i){
            for(int j=0;j < this->col; ++j){
                result.arr[i][j] = this->arr[i][j] + other.arr[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(Matrix<T>& other){
        Matrix<T> result(this->row, this->col);

        for(int i=0;i < this->row; ++i){
            for(int j=0;j < this->col; ++j){
                result.arr[i][j] = this->arr[i][j] - other.arr[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(Matrix<T>& other){
        Matrix<T> result(this->row, this->col);

        for(int i=0;i < this->row; ++i){
            for(int j=0;j < this->col; ++j){
                result.arr[i][j] = this->arr[i][j] * other.arr[i][j];
            }
        }
        return result;
    }

    virtual void display(){
        cout << "Matrix class " << endl << endl;
        for(int i=0; i< this->row ; ++i){
            for(int j=0; j < this->col ; ++j){
                cout << this->arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
};

template <typename T>
class intMatrix : public Matrix<T> {
    public:
    intMatrix(int row, int col) : Matrix<T>(row, col) {}

    void display() override {
        cout << "Int Matrix " << endl << endl;
        for(int i=0; i< this->row ; ++i){
            for(int j=0; j < this->col ; ++j){
                cout << this->arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

template <typename T>
class DoubleMatrix : public Matrix<T> {
    public:
    DoubleMatrix(int row, int col) : Matrix<T>(row, col) {}
    void display() override {
        cout << "Double Matrix" << endl << endl;
        for(int i=0; i< this->row; ++i){
            for(int j=0; j < this->col; ++j){
                cout << this->arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(){
    intMatrix<int> intm(2,2);
    DoubleMatrix<double> doublem(2,2);

    intm.setMatrix(0, 0, 1);
    intm.setMatrix(0, 1, 2);
    intm.setMatrix(1, 0, 3);
    intm.setMatrix(1, 1, 4);

    doublem.setMatrix(0, 0, 5);
    doublem.setMatrix(0, 1, 6);
    doublem.setMatrix(1, 0, 7);
    doublem.setMatrix(1, 1, 8);

    intm.display();
    doublem.display();

    Matrix<int> ans1 = intm + intm;
    Matrix<double> ans2 = doublem + doublem;

    ans1.display();
    ans2.display();
}
