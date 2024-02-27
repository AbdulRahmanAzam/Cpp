#include <iostream>
using namespace std;

class Table{
    private:
    int totalCapacity;
    int seatsOccupied;
    int freeSeats;
    bool clean;
    bool emptytable = true;
    public:

    //default constructor
    Table(){
        totalCapacity = 4;
        seatsOccupied = 0;
        freeSeats = totalCapacity;
        clean = true;
    }

    // parametrized constructor
    Table(int totalCapacity){
        if(totalCapacity < 6){
            this->totalCapacity = 4;
        }else
            this->totalCapacity = 8;

        seatsOccupied = 0;
        freeSeats = this->totalCapacity;
        clean = true;
    }

    //setters
    void setseatsOccupied(int seatsOccupied){
        this->seatsOccupied = seatsOccupied;
        this->freeSeats = totalCapacity - seatsOccupied;
        emptytable = false;
    }

    void Cleaningthetable(){
        cout << "cleaning the table" << endl;
        this->clean = true;
    }
    void Leavingthetable(){
        cout << "leaving the table" << endl;
        this->seatsOccupied = 0;
        this->freeSeats = 0;
        emptytable = true;
    }
    void usingthetable(){
        cout << "using the table" << endl;
        emptytable = false;
    }
    void havinglunch(){
        cout << "having lunch on the table" << endl;
        this->clean = false;
    }
    // getters
    int gettotalCapacity(){
        return this->totalCapacity;
    }
    bool getClean(){
        return clean;
    }

    void display(){
        cout << "Seats Occupied = " << this->seatsOccupied
        << "\ntotal capacity = " << this->totalCapacity
        << "\nis table empty = " << (emptytable ? "true" : "false") 
        << "\nis table is clean = " <<  (clean ? "true" : "false") 
        << "free seats = " << this->freeSeats << endl;
    }
};

void OccupyTable(Table *tables, int SeatsOccupied, int size){
    for(int i=0; i< size; i++){
        if(tables[i].getClean()){
            if(SeatsOccupied <= 4 && tables[i].gettotalCapacity() == 4){
                tables[i].setseatsOccupied(SeatsOccupied);
                cout << "Table no is = " << i+1 << " seatingCapacity of the table is = " << 4 << endl;
                return;
            }
            
            if(SeatsOccupied > 4 && tables[i].gettotalCapacity() == 8){
                tables[i].setseatsOccupied(SeatsOccupied);
                cout << "Table no is = " << i+1 << " seatingCapacity of the table is = " << 8 << endl;
                return;
            }
        }
    }
    cout << "All the tables are full " << endl;
};

void EmptyTable(Table tables[5], int tableNum){
    tables[tableNum].Leavingthetable();
}

int main(){
    Table tables[5] = {
        Table(8), Table(8), Table(4), Table(4), Table(4)
    };
    int size = sizeof(tables)/ sizeof(tables[0]);
    
    OccupyTable(tables, 4, size);
    OccupyTable(tables, 6, size);

    tables[0].usingthetable();
    tables[0].havinglunch();
    tables[0].Leavingthetable();
    tables[0].Cleaningthetable();

    EmptyTable(tables, 0);
}
