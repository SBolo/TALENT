// classes example
#include <iostream>
using namespace std;

class Rectangle {
    
        public:
            Rectangle (int, int); //constructor
            int area();
    
        private:
            int width, height;
};

int Rectangle::area () {
    return width*height;
}

Rectangle::Rectangle (int a, int b) {
    width = a;
    height = b;
}

int main () {
    Rectangle rect(3,4);
    //in this way I define an array of classes
    cout << "area: " << rect.area() << endl;
    return 0;
}