//It was a good question for practice as it could be a semester project if asked to built full game

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
    ChessPiece board[8][8];

    public:
    //constructor
    ChessBoard(){

        board[7][0] = ChessPiece("Rook", "black",'R');
        board[7][1] = ChessPiece("Knight","black",'N');
        board[7][2] = ChessPiece("Bishop","black",'B');
        board[7][3] = ChessPiece("Queen","black", 'Q');
        board[7][4] = ChessPiece("King","black",'K');
        board[7][5] = ChessPiece("Bishop","black",'B');
        board[7][6] = ChessPiece("Knight","black",'N');
        board[7][7] = ChessPiece("Rook","black",'R');

        for(int i=0; i<8; i++){
            // for black pawns
            board[6][i] = ChessPiece("Pawn","black",'P');
            //for white pawns
            board[1][i] = ChessPiece();
        }
        for(int i=2; i<6; i++){
            for(int j=0; j<8; j++){
                board[i][j] = ChessPiece("none","none",'.');
            }
        }

        board[0][0] = ChessPiece("Rook", "white",'r');
        board[0][1] = ChessPiece("Knight","white",'n');
        board[0][2] = ChessPiece("Bishop","white",'b');
        board[0][3] = ChessPiece("Queen","white", 'q');
        board[0][4] = ChessPiece("King","white",'k');
        board[0][5] = ChessPiece("Bishop","white",'b');
        board[0][6] = ChessPiece("Knight","white",'n');
        board[0][7] = ChessPiece("Rook","white",'r');
    }

    bool movePiece(string source, string destination){
        int src_c = source[0] - 'a'  , src_r = source[1] - '0'-1, 
        dest_c = destination[0] - 'a' , dest_r = destination[1] - '0'-1;

        // checking for placing position
        if(board[dest_r][dest_c].getsymbol() == '.' || // if already null
                board[dest_r][dest_c].getcolor() != board[src_r][src_c].getcolor()){ // if not my peice
                
                // working for knight
            if(board[src_r][src_c].getsymbol() == 'n' || board[src_r][src_c].getsymbol() == 'N'){
                
                // if move is valid
                if((abs(src_r - dest_r) == 2) && (abs(src_c - dest_c) == 1)){
                    return true;
                }else {
                    cout << "invalid, your move was " << board[src_r][src_c].getsymbol() << endl;
                    return false;
                }

            // working for pawn
            }else if(board[src_r][src_c].getsymbol() == 'p' || board[dest_r][dest_c].getsymbol() == 'P'){
                
                // for all the moves and for the first move
                if(((dest_r - src_r == 1) && (dest_c - src_c == 0)) || ((dest_r - src_r == 2) && (dest_c - src_c == 0) && src_r == 1)) {
                    return true;
                // for killing move
                }else if((abs(dest_r - src_r) == 1) && (abs(src_c - dest_c) == 1)){
                    return true;

                }else {
                    cout << "invalid. your move was " << board[dest_r][dest_c].getsymbol()  << " dest_r " << dest_r - src_r << " dest_c " << dest_c - src_c << endl;
                    return false;
                }
            }
        }
        return false;
    }

    void display(){    
        cout << " " << "   ";
        for(char ch = 'a'; ch <= 'h'; ch++) cout << ch << "   ";
        cout << endl << endl;
        
        int no = 8;
        for(int i=7; i>=0; i--){
            cout << no << "   ";

            for(int j=0; j<8; j++){
                    cout << board[i][j].getsymbol() << "   ";
            }
            cout << no-- << endl << endl;
        }

        cout << " " << "   ";
        for(char ch = 'a'; ch <= 'h'; ch++) cout << ch << "   ";
        cout << endl;
    }
};
int main(){
    ChessBoard box1;
    box1.display();

    cout << (box1.movePiece("g1","f3") ? "valid" : "invalid") << endl;
    box1.display();
    
    cout << (box1.movePiece("b1","c3") ? "valid" : "invalid") << endl;
    box1.display();

    cout << (box1.movePiece("a2","a4") ? "valid" : "invalid") << endl;
    box1.display();
}
