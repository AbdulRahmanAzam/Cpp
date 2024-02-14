#include <iostream>
using namespace std;

class ChessPiece {
    private:
        
    public:
    //constructor

    // setter

    // getter

    // functions
    

    bool movePiece(string source, string destination){
        return true;
    }
};

class ChessBoard {
    private:
    char board[10][10];

    public:
    //constructor
    ChessBoard(){
        for(int i=0; i<10;i++){
            for(int j=0; j < 10; j++){
                // to print numbers 
                if((j == 0 || j == 9 ) && (i > 0 && i < 9)){
                    board[i][j] = 9 - i + '0';

                }else if(i == 0 || i == 9){
                    if(j > 0 && j < 9)
                        board[i][j] = j + 'a' - 1;
                    else 
                        board[i][j] = ' ';

                }else if(i == 1){
                    switch(j){
                        case 1:
                        case 8:
                            board[i][j] = 'R';
                            break;
                        case 2:
                        case 7:
                            board[i][j] = 'N';
                            break;
                        case 3:
                        case 6:
                            board[i][j] = 'B';
                            break;
                        case 4:
                            board[i][j] = 'Q';
                            break;
                        case 5:
                            board[i][j] = 'K';
                            break; 
                    }
                }else if(i == 2){
                    board[i][j] = 'P';
                }else if(i == 7){
                    board[i][j] = 'p';
                }else if(i > 2 && i < 7){
                    board[i][j] = '.';
                }else if(i == 8){
                    switch(j){
                        case 1:
                        case 8:
                            board[i][j] = 'R' + 32;
                            break;
                        case 2:
                        case 7:
                            board[i][j] = 'N' + 32;
                            break;
                        case 3:
                        case 6:
                            board[i][j] = 'B' + 32;
                            break;
                        case 5:
                            board[i][j] = 'Q' + 32;
                            break;
                        case 4:
                            board[i][j] = 'K' + 32;
                            break; 
                    }
                }
            }
        }
    }

    void movePiece(int source, int destination){

    }

    void display(){
        for(int i=0; i< 10; i++){
            for(int j= 0; j< 10; j++){
                cout << board[i][j] << "     ";
            }
            cout << endl << endl;
        }
    }

};

int main(){
    ChessBoard play1;
    play1.display();
}
