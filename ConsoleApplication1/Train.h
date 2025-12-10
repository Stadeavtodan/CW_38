#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Train {
private:
	string num;
	string timedep;
	string stat;
public:
	Train() {
		num = " ";
		timedep = " ";
		stat = " ";
	}
	Train(string num, string timedep, string stat) {
		this->num = num;
		this->timedep = timedep;
		this->stat = stat;
	}

	void setTime(string time) {
		this->timedep = time;
	}
	void setStat(string stat) {
		this->stat = stat;
	}
	string getNum()const {
		return num;
	}
	string getTime()const {
		return timedep;
	}
	string getStat()const {
		return stat;
	}

	void showInfo()const {
		cout << "|" << setw(5) << num << "|"
			<< "|" << setw(5) << timedep << "|"
			"|" << setw(15) << stat << "|" << endl;
	}

	bool operator <(const Train& obj)const{
		return this->timedep < obj.timedep;
	}
	bool operator ==(const Train& obj)const {
		return this->num == obj.num;
	}
};