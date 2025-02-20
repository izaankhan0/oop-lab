#include <iostream>
using namespace std;

class Table {
    private:
        int Height;
        int Width;
        int **Grid;
    
    public:
        Table() {
            Height = 0; 
            Width = 0;
            Grid = new int*[Height];
            for (int i = 0; i < Height; i++) {
                Grid[i] = new int[Width];
            }
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    Grid[i][j] = 0;
                }
            }
        }
        
        Table(int h, int w) {
            Height = h; 
            Width = w;
            Grid = new int*[Height];
            for (int i = 0; i < Height; i++) {
                Grid[i] = new int[Width];
            }
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    Grid[i][j] = 0;
                }
            }
        }
        
        Table(const Table& ref) {
            Height = ref.Height;
            Width = ref.Width;
            Grid = new int*[Height];
            for (int i = 0; i < Height; i++) {
                Grid[i] = new int[Width];
            }
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    Grid[i][j] = ref.Grid[i][j];
                }
            }
        }
        
        Table(Table&& ref) noexcept : Grid(ref.Grid), Height(ref.Height), Width(ref.Width) {
            ref.Grid = nullptr;
            ref.Height = 0;
            ref.Width = 0;
        }
        
        ~Table() {
            for (int i = 0; i < Height; i++) {
                delete[] Grid[i];
            }
            delete[] Grid;
        }
        
        int GetHeight() {
            return Height;
        }
        
        int GetWidth() {
            return Width;
        }
        
        int Fetch(int x, int y) {
            return Grid[x][y];
        }
        
        void Populate(double data) {
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    Grid[i][j] = data;
                }
            }
        }
        
        void Flip() {
            int** Swapped = new int*[Width];
            for (int i = 0; i < Width; i++) {
                Swapped[i] = new int[Height];
            }
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    Swapped[j][i] = Grid[i][j];
                }
            }
            for (int i = 0; i < Width; i++) {
                for (int j = 0; j < Height; j++) {
                    cout << Swapped[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < Width; i++) {
                delete[] Swapped[i];
            }
            delete[] Swapped;
        }
        
        void Show() const {
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    cout << Grid[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    cout << "Creating Table A" << endl;
    Table A(2,3);
    A.Show();
    cout << endl;
    
    cout << "Filling Table A" << endl;
    A.Populate(12);
    A.Show();
    cout << endl;
    
    cout << "Copying Table A to Table B" << endl;
    Table B = A;
    B.Show();
    cout << endl;
    
    cout << "Flipping Table B" << endl;
    B.Flip();
    cout << endl;
    
    cout << "Transferring Table A to Table C" << endl;
    Table C = move(A);
    C.Show();
    cout << endl;
    
    cout << "Height of Table A: " << A.GetHeight() << endl;
    cout << "Width of Table A: " << A.GetWidth() << endl;
    cout << "Value at (1,2) in Table B: " << B.Fetch(1,2);
    
    return 0;
}
