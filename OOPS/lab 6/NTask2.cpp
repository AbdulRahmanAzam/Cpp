#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class image{
    private:
    int width;
    int height;
    int* data;
    
    public:
    image(int width, int height, int *image_data) : width(width), height(height){
        
        this->data = new int[width * height];
        // memcpy(this->data, image_data, width * height * sizeof(int));
        for(int i =0; i< width * height; i++){
            data[i] = image_data[i];
        }
    }
    
    image(const image& other) : width(other.width), height(other.height), data(other.data) {
        // this->data = new int[width * height];
        // data = other.data;
    }
    
    ~image(){
        if(this->data){
            delete[] this->data;
            cout << "Memory of data is deleted succesfully" << endl;
        }
    }
    
    void display(){
        cout << "Width is = " << this->width << endl
        << "Height is = " << this->height  << endl;
        
        cout << "Image data :";
        for(int i=0; i< width * height; i++){
            cout << this->data[i] << " ";
        }
        cout << endl << endl;
    }
    
    void updateData(){
        for(int i=0; i< width * height; i++){
            if(data[i] <= 0)
                data[i] = (rand() % 255) + 1;
        }
    }
};

int main(){
    srand(time(NULL));
    int image_list[] = {-1,2,3,4,5,6,};
    image  a(2,3, image_list);
    image b(a);
    a.display();
    b.display();
    a.updateData();
    a.display();
    b.display();
}
