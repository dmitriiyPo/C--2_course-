#include "Iterator.h"


void Iterator::start() {
	i = queue.getHead() % queue.size();
}

void Iterator::next() {
	i++% queue.size();
}

bool Iterator::finish() {
	return i % queue.size() == queue.getTail() % queue.size();
}

int Iterator::getValue() {
	return queue.getArr()[i];
}
