#include<vector>
#include<exception>
#include"Container.h"
#include"WeightException.h"
#include "Box.h"
using namespace std;
using namespace BoxClass;

namespace ContainerClass
{
	
	Container::Container()
	{
		this->length = 0;
		this->height = 0;
		this->width = 0;
		this->maxWeight = 0;
	}

	Container::Container(int plength, int pwidth, int pheight, double pmaxWeight)
	{
		this->length = plength;
		this->height = pheight;
		this->width = pwidth;
		this->maxWeight = pmaxWeight;
	}

	int Container::addBox(BoxClass::Box box)
	{
		double containerWeight = getSumOfWeights();
		if (containerWeight + box.getWeight() <= Container::maxWeight)
		{
			Container::boxes.push_back(box);
			return this->getSize() - 1;
		}
		else
		{
			throw WeightException();
		}
	}

	void Container::deleteBox(int stand)
	{
		Container::boxes.erase(Container::boxes.begin() + stand); //если задать stand то можно удалить диапозон начиная с первого
	}

	int Container::getSize()
	{
		return Container::boxes.size(); //кол-во коробок (в массиве) (в векторе)
	}

	double Container::getSumOfWeights()
	{
		double sum = 0;
		for (int i = 0; i < getSize(); i++)
		{
			//sum += Container::boxes.at(i).getWeight();
			sum += Container::boxes[i].getWeight();
		}
		return sum;
	}

	int Container::getSumOfValues()
	{
		int sum = 0;

		for (int i = 0; i < getSize(); i++)
		{
			sum += Container::boxes[i].getValue();
		}
		return sum;
	}

	BoxClass::Box Container::getBox(int i)
	{
		return Container::boxes.at(i);
	}

	const vector<BoxClass::Box>& Container::getBoxes() const { return boxes; }

	void Container::setBoxes(const vector<BoxClass::Box>& boxes)
	{
		this->boxes = boxes;
	}

	BoxClass::Box& Container::operator[](int i)
	{
		return this->boxes.at(i);
	}

	ostream& operator<<(ostream& os, const Container& container)
	{
		return os << "Main characteristics: length: " << container.getLength() << ", width: " <<
			container.getWidth() << ", height: " << container.getHeight() << ", maxWeight: " << container.getMaxWeight() << ".";
	}

	istream& operator>>(istream& in, Container& container)
	{
		int l, w, h; double mW;
		return in >> l >> w >> h >> mW;
		container.setLength(l);
		container.setWidth(w);
		container.setHeight(h);
		container.setMaxWeight(mW);
	}

	int Container::getLength() const { return length; }
	int Container::getWidth() const { return width; }
	int Container::getHeight() const { return height; }
	double Container::getMaxWeight() const { return maxWeight; }

	void Container::setLength(int length) { this->length = length; }
	void Container::setWidth(int width) { this->width = width; }
	void Container::setHeight(int height) { this->height = height; }
	void Container::setMaxWeight(double maxWeight) { this->maxWeight = maxWeight; }

}