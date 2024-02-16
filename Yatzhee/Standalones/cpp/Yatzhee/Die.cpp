
#include "Die.h"
#include <iostream>
#include <array>

Die::Die(){
	this->m_faces = default_six_faces;
	this->m_faces_number = default_number_faces;
};

Die::Die(const int * faceValues, int faces)
{
	this->m_faces = faceValues;
	this->m_faces_number = faces;
};
Die::~Die(){
	// delete m_faces; // apparently, this delete was not required.
};
void Die::PrintInfo() {
	std::cout << "This " << this->m_faces_number << " die rolled a " << this->m_value << std::endl;
};

int Die::RollDie() {
	this->m_value = this->m_faces[ (rand() % this->m_faces_number) ];
	return this->m_value;
}