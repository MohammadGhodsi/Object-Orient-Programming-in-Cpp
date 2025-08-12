#include <iostream>
using namespace std;

class Tire 

{

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

        cout << "Width :" << *width << "  Aspect ratio  :" << *aspect_ratio << "  Diameter  " << *diameter;

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
   this->aspect_ratio = new int;
   this->diameter = new int;

   *width = w;
   *aspect_ratio = a;
   *diameter = d;

}

int Tire::getwidth()
{

    return *width;

}

int Tire::getaspectratio()
{
    return *aspect_ratio;

}

int Tire::getdiamter()

{

    return *diameter;

}

Tire::~Tire()
{

    delete width, aspect_ratio , diameter;

}

class Car 
{

    private:

        int* model;
        string* company;
        Tire* t1;

    public:

        Car(int m, string c, Tire& t)
        {
            this->model = new int;
            this-> company = new string;
            *model=m;
            *company = c;
            t1 = new Tire(t.getwidth() ,t.getaspectratio() , t.getdiamter());
        
        }

        ~Car()
        {
            delete model, company , t1;
        }

        void Printcar()
        {
            cout << "Model :" << *model << "Company :" <<*company<< "   ";
            t1->PrintTire();
        }

};

int main()
{
    Tire tNew (12,10,13);
    tNew.PrintTire();
}













