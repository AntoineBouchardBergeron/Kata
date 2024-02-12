#pragma once

constexpr int default_number_faces {6};
constexpr int default_four_faces[4] = {1,2,3,4};
constexpr int default_six_faces[6] = {1,2,3,4,5,6};
constexpr int default_eight_faces[8] = {1,2,3,4,5,6,7,8};
constexpr int default_ten_faces[10] = {1,2,3,4,5,6,7,8,9,10};
constexpr int default_twenty_faces[20]  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
class Die
{
private:
	const int * m_faces;
	int m_value = 0;

public:
	Die();
	Die(const int * faces);
	~Die();
	void printInfo();
	int RollDie();
};