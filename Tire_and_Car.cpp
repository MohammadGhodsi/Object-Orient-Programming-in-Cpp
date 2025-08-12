#include <iostream>
using namespace std;

class Tire {

    private:
        
        int* width;
        int* aspect_ratio;
        int* diameter;

    public:
        Tire();
        Tire(int,int,int);
        ~Tire();
        int getwidth();
        int getaspectratio();
        int getdiamter();


    void PrintTire()
    {

        cout << "Width :" << *width << "Aspect ratio :" << *aspect_ratio << "Diameter" << *diameter;

    }
};

Tire::Tire()
{
    width = 0;
    aspect_ratio = 0;
    diameter = 0;
}

Tire::Tire(int w, int a, int d)
{

   this->width = new int;

}
