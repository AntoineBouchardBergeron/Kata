
#include "Die.h"
#include <iostream>

Die::Die(){};

Die::Die(const int * faces):
	m_faces(faces)
{};
Die::~Die(){
	delete m_faces;
};
void Die::printInfo() {
	std::cout << "This die rolled a " << this->m_value << std::endl;
};

int Die::RollDie() {
	this->m_value = this->m_faces[ (rand() % ( *(&this->m_faces + 1) - this->m_faces)) ];
	return this->m_value;
}