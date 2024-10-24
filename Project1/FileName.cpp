#include<iostream>
#include <string>
#include <Windows.h>
#include <queue>
using namespace std;

class Worker {
	string fullname;
	int age;
	double salary;
	string speciality;

public:
	Worker() {
		fullname = " ";
		age = 0;
		salary = 0.0;
		speciality = " ";
	}

	Worker(string fullname, int age, double salary, string speciality) :Worker() {
		this->fullname = fullname;
		this->age = age;
		this->salary = salary;
		this->speciality = speciality;
	}

	Worker(const Worker& object) {
		this->fullname = object.fullname;
		this->age = object.age;
		this->salary = object.salary;
		this->speciality = object.speciality;
	}

	Worker& operator=(const Worker& object) {
		this->fullname = object.fullname;
		this->age = object.age;
		this->salary = object.salary;
		this->speciality = object.speciality;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Worker& object) {
		out << "Fullname: " << object.fullname << endl;
		out << "Age: " << object.age << endl;
		out << "Salary: " << object.salary << endl;
		out << "Speciality: " << object.speciality << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Worker& object) {
		cout << "Enter fullname: ";
		in.ignore();
		getline(in, object.fullname);

		cout << "Enter age: ";
		in >> object.age;

		cout << "Enter salary: ";
		in >> object.salary;

		cout << "Enter speciality: ";
		in.ignore();
		getline(in, object.speciality);

		return in;;
	}

	string GetFullname() const {
		return this->fullname;
	}

	void SetFullname(const string fullname) {
		if (fullname.length() < 10) {
			cout << "Wrong fullname ";
		}
		else {
			this->fullname = fullname;
		}
	}

	int GetAge() const {
		return this->age;
	}

	void SetAge(const int age) {
		if (age < 10) {
			cout << "Wrong age ";
		}
		else {
			this->age = age;
		}
	}

	double GetSalary() const {
		return this->salary;
	}

	void SetSalary(const double salary) {
		if (salary < 200) {
			cout << "Wrong salary ";
		}
		else {
			this->salary = salary;
		}
	}

	string GetSpeciality() const {
		return this->speciality;
	}

	void SetSpeciality(const string speciality) {
		if (speciality.length() < 1) {
			cout << "Wrong speciality ";
		}
		else {
			this->speciality = speciality;
		}
	}

};

class Printer {
	queue <Worker> workers;

public:

	void AddWorker(const Worker& worker) {
		workers.push(worker);
	}

	void Print() {
		while (!workers.empty()) {
			cout << workers.front();
			workers.pop();
			cout << "-------------------------" << endl;
			Sleep(2000);
		}
	}
};

void main() {

	//Worker worker1;
	//cin >> worker1;
	//cout << worker1;

	Printer printer;
	Worker worker1("Nigar Hesenova", 20, 1000, "IT");
	Worker worker2("Ayla Selimova", 21, 700, "IT");
	Worker worker3("Ayten Ismayilova", 40, 1500, "IT");


	printer.AddWorker(worker1);
	printer.AddWorker(worker2);
	printer.AddWorker(worker3);

	printer.Print();

}