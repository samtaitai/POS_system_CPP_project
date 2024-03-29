/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 21 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "VRVideo.h"

using namespace std;

namespace sdds {
	VRVideo::VRVideo() {
		m_equipment = nullptr;
	}
	VRVideo::VRVideo(int length, const char* name) :Video{length} {
		m_equipment = nullptr;
		if (name) {
			m_equipment = new char[strlen(name) + 1];
			strcpy(m_equipment, name);
		}
	}
	VRVideo::~VRVideo()
	{
		delete[] m_equipment;
	}
	void VRVideo::load(std::istream& istr)
	{
		char name[255]{};
		Video::load(istr);
		istr.getline(name, 254, '\n'); //discard \n
		if (name[0] != '0') {
			delete[] m_equipment;
			m_equipment = new char[strlen(name) + 1];
			strcpy(m_equipment, name);
		}
	}
	std::ostream& VRVideo::play(std::ostream& ostr) const
	{
		if (Video::get() != 0 && m_equipment != 0) { //or make bool conversion operator
			ostr << "VRVideo requires " << m_equipment << endl;
			ostr << "Video length = " << Video::get();
		}
		
		return ostr;
	}
}