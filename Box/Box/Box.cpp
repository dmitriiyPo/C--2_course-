#include <iostream>
#include"Box.h"
using namespace std;


namespace BoxClass
{

    Box::Box()
    {
        length = 0;
        width = 0;
        height = 0;
        weight = 0;
        value = 0;
    }

    Box::Box(int lenght1, int width1, int height1, double weight1, int value1)
    {
        length = lenght1;
        width = width1;
        height = height1;
        weight = weight1;
        value = value1;
    }

    int Box::V()
    {
        return length * height * width;
    }


    int AllValue(Box arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i].getValue();
        }
        return sum;
    }

    bool cheak(Box arr[], int n, int max)
    {
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            val += arr[i].getLength() + arr[i].getHeight() + arr[i].getWidth();
        }
        return val <= max;
    }


    double MaxWeight(Box arr[], int n, double maxV)
    {
        double Vbox = 0;
        double VweightMax = 0;
        for (int i = 0; i < n; i++)
        {
            Vbox = arr[i].getLength() * arr[i].getHeight() * arr[i].getWidth();
            if (Vbox <= maxV)
            {
                VweightMax += arr[i].getWeight();
            }
        }
        return VweightMax;
    }

    bool cheakBoxInBox(Box arr[], int n)
    {
       
        int a, b, c, d, e, f;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i].weight == 0)
            {
                for (int j = i + 1; j < n; j++)
                {

                    a = arr[i].length;
                    b = arr[i].height;
                    c = arr[i].width;

                    d = arr[j].length;
                    e = arr[j].height;
                    f = arr[j].width;

                    if ((a > d) && (b > e) && (c > f) || (d > a) && (e > b) && (f > c))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            
        }
        
    }

    bool Box::operator == (const Box& box) const //перегружаем оператор ==
    {
        return  width == box.weight &&
            height == box.height &&
            length == box.length &&
            weight == box.weight &&
            value == box.value;
    };

    istream& operator >> (istream& is, Box& box) //ввод
    {
        return is >> box.length >> box.width >> box.height >> box.weight >> box.value;
    }

    ostream& operator << (ostream& is, const Box& box) //вывода
    {
        return is << "length: " << box.length << " width: " << box.width << " height: " << box.height << " weight: " << box.weight << " value: " << box.value;
    }

    int Box::getLength()
    {
        return length;
    }

    int Box::getWidth()
    {
        return width;
    }

    int Box::getHeight()
    {
        return height;
    }

    int Box::getValue()
    {
        return value;
    }

    double Box::getWeight()
    {
        return weight;
    }

    void Box::setLength(int length2)
    {
        this->length = length2;
    }

    void Box::setHeight(int height2)
    {
        this->height = height2;
    }

    void Box::setWidth(int width2)
    {
        this->width = width2;
    }

    void Box::setValue(int value2)
    {
        this->value = value2;
    }

    void Box::setWeight(double weight2)
    {
        this->weight = weight2;
    }

}