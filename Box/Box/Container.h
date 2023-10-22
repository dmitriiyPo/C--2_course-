#pragma once
#include<iostream>
#include<vector>
#include"Box.h"
using namespace std;


namespace ContainerClass
{
	
	class Container
	{
	private:

		vector<BoxClass::Box> boxes;
		int length;
		int width;
		int height;
		double maxWeight;

	public:

		Container();
		Container(int plength, int pwidth, int pheight, double pmaxWeight);

		int addBox(BoxClass::Box box);
		void deleteBox(int stand);
		BoxClass::Box getBox(int i);


		int getSize();
		double getSumOfWeights();
		int getSumOfValues();

		const vector<BoxClass::Box>& getBoxes() const;
		void setBoxes(const vector <BoxClass::Box > & boxes);


		BoxClass::Box& operator[](int i);

		friend ostream& operator<<(ostream& os, const Container& container);
		friend istream& operator>>(istream& in, Container& container);

		int getLength() const;
		int getWidth() const;
		int getHeight() const;
		double getMaxWeight() const;

		void setLength(int length);
		void setWidth(int width);
		void setHeight(int height);
		void setMaxWeight(double maxWeight);
	};

}