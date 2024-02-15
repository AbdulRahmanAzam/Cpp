#include <iostream>
using namespace std;

class ChessPiece {
    private:
    string name;
    string color;
    char symbol;

    public:
    //default and parametrized constructor
    ChessPiece(string name = "Pawn", string color = "white", char symbol = 'p'){
        this->name = name;
        this->color = color;
        this->symbol = symbol;
    }

    // setter
    void setname(string name){
        this->name = name;
    }
    void setcolor(string color){
        this->color = color;
    }
    void setsymbol(char symbol){
        this->symbol = symbol;
    }
    // getter
    string getname(){
        return this->name;
    }
    string getcolor(){
        return this->color;
    }
    char getsymbol(){
        return this->symbol;
    }
};

class ChessBoard {
    private:
    ChessPiece* board[8][8];

    public:
    //constructor
    ChessBoard(){
        ChessPiece p1,p2,p3,p4,p5,p6,p7,p8, 
               r1("Rook","white",'r'),r2("Rook","white",'r'),n1("Knight","white",'n'),n2("Knight","white",'n'),b1("Bishop","white",'b'),b2("Bishop","white",'b'),q("Queen","white",'q'),k("King","white",'k'),
               P1("Pawn","black",'p'),P2("Pawn","black",'p'),P3("Pawn","black",'p'),P4("Pawn","black",'p'),P5("Pawn","black",'p'),P6("Pawn","black",'p'),P7("Pawn","black",'p'),P8("Pawn","black",'p'), 
               R1("Rook","black",'r'),R2("Rook","black",'r'),N1("Knight","black",'n'),N2("Knight","black",'n'),B1("Bishop","black",'b'),B2("Bishop","black",'b'),Q("Queen","black",'q'),K("King","black",'k');

        board[0][0] = &R1;
        board[0][1] = &N1;
        board[0][2] = &B1;
        board[0][3] = &Q;
        board[0][4] = &K;
        board[0][5] = &B2;
        board[0][6] = &N2;
        board[0][7] = &R2;

        board[1][0] = &p1;
        board[1][1] = &P2;
        board[1][2] = &P3;
        board[1][3] = &P4;
        board[1][4] = &P5;
        board[1][5] = &P6;
        board[1][6] = &P7;
        board[1][7] = &P8;

        for(int i=2; i<6; i++){
            for(int j=0; j<8; j++){
                board[i][j] = nullptr;
            }
        }

        board[6][0] = &p1;
        board[6][1] = &P2;
        board[6][2] = &P3;
        board[6][3] = &P4;
        board[6][4] = &P5;
        board[6][5] = &P6;
        board[6][6] = &P7;
        board[6][7] = &P8;

        board[7][0] = &r1;
        board[7][1] = &n1;
        board[7][2] = &b1;
        board[7][3] = &k;
        board[7][4] = &q;
        board[7][5] = &b2;
        board[7][6] = &n2;
        board[7][7] = &r2;   
    }

    void movePiece(int source, int destination){

    }

    void display(){
        for(int i=0; i< 10; i++){
            for(int j= 0; j< 10; j++){
                
                if((i == 0 || i == 9) && j == 0 && j == 9){
                    cout << 0;
                }else if(i == 0 || i == 9){
                    cout << j + 'a' - 1;
                }else if(i > 1 && i < 9 && (j == 0 || j == 9)){
                    cout << 9 - i;
                }else if(board[i][j] != nullptr){
                    cout << board[i][j]->getsymbol();
                }else {
                    cout << '.';
                }
                    
                cout << "     ";
            }
            cout << endl << endl;
        }
    }

};

int main(){
    ChessBoard box1;
    box1.display();
}


















// for(int i=0; i<10;i++){
        //     for(int j=0; j < 10; j++){
        //         // to print numbers 
        //         if((j == 0 || j == 9 ) && (i > 0 && i < 9)){
        //             board[i][j] = 9 - i + '0';

        //         }else if(i == 0 || i == 9){
        //             if(j > 0 && j < 9)
        //                 board[i][j] = j + 'a' - 1;
        //             else 
        //                 board[i][j] = ' ';

        //         }else if(i == 1){
        //             switch(j){
        //                 case 1:
        //                 case 8:
        //                     board[i][j] = 'R';
        //                     break;
        //                 case 2:
        //                 case 7:
        //                     board[i][j] = 'N';
        //                     break;
        //                 case 3:
        //                 case 6:
        //                     board[i][j] = 'B';
        //                     break;
        //                 case 4:
        //                     board[i][j] = 'Q';
        //                     break;
        //                 case 5:
        //                     board[i][j] = 'K';
        //                     break; 
        //             }
        //         }else if(i == 2){
        //             board[i][j] = 'P';
        //         }else if(i == 7){
        //             board[i][j] = 'p';
        //         }else if(i > 2 && i < 7){
        //             board[i][j] = '.';
        //         }else if(i == 8){
        //             switch(j){
        //                 case 1:
        //                 case 8:
        //                     board[i][j] = 'R' + 32;
        //                     break;
        //                 case 2:
        //                 case 7:
        //                     board[i][j] = 'N' + 32;
        //                     break;
        //                 case 3:
        //                 case 6:
        //                     board[i][j] = 'B' + 32;
        //                     break;
        //                 case 5:
        //                     board[i][j] = 'Q' + 32;
        //                     break;
        //                 case 4:
        //                     board[i][j] = 'K' + 32;
        //                     break; 
        //             }
        //         }
        //     }
        // }
