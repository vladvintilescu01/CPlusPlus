#include <iostream>

using namespace std;

class Rectangle {

    int width, height;

public:
    void display() {
        cout << this->width << " " << height << "\n";
    }
    friend class RectangleArea;
};

class RectangleArea : public Rectangle {

    int w, h;

public:
    void read_input() {
        cin >> w >> h;
        this->width = w;
        this->height = h;
    }
    void display() {
        cout << (this->width) * (this->height);
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}