##pragma once
#include<iostream>
using namespace std;

namespace BoxClass
{

    class Box
    {
    private:

        int length;
        int width;
        int height;
        double weight;
        int value;

    public:

        Box();
        Box(int length1, int width1, int height1, double weight1, int value1);
        int V();

        friend bool cheakBoxInBox(Box arr[], int n);

        bool operator == (const Box& box) const;

        int getLength();
        int getWidth();
        int getHeight();
        double getWeight();
        int getValue();

        void setLength(int length);
        void setWidth(int width);
        void setHeight(int height);
        void setWeight(double weight);
        void setValue(int value);


        friend ostream& operator << (ostream& is, const Box& box);
        friend istream& operator >> (istream& is, Box& box);

    };

}