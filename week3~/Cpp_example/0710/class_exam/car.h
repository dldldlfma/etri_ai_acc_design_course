#include <iostream>
using namespace std;

class Car
{
	protected:
		int engine_volume, price;

	public:
		Car();
		~Car();
		Car(int engine, int price);
		void set_volume(int val);
		void set_price(int val);
		void show_contents();
};

Car::Car(){
	cout<<"No input"<<endl;
}

Car::Car(int engine, int price){
	this->engine_volume = engine;
	this->price = price;
}

Car::~Car(){
	cout<<"Car 소멸자"<<endl;
}

void Car::set_volume(int val){
	this->engine_volume = val;
}

void Car::set_price(int val){
	this->price =val;
}

void Car::show_contents(){
	cout<<"engine_volume : "<<this->engine_volume<<endl;
	cout<<"price : "<<this->price<<endl;
}



class TRUCK : public Car
{
	private:
		int max_volume;
	public:
		TRUCK();
		~TRUCK();
		void set_max_volume(int val);
		void show_contents();
};

TRUCK::TRUCK():Car()
{
	cout<<"TRUCK 생성자"<<endl;
}

TRUCK::~TRUCK()
{
	cout<<"TRUCK 소멸자"<<endl;
}
void TRUCK::set_max_volume(int val){
	this->max_volume =val;
}

void TRUCK::show_contents(){
	Car::show_contents();
	cout<<"max_volume : "<<this->max_volume<<endl;
}


class SUV : public Car
{
	private:
		int spare_tire;
	public:
		SUV();
		~SUV();
		void set_spare_tire(int val);
		void show_contents();
};



SUV::SUV():Car()
{
	cout<<"SUV 생성자"<<endl;
}

SUV::~SUV()
{
	cout<<"SUV 소멸자"<<endl;
}
void SUV::set_spare_tire(int val){
	this->spare_tire =val;
}

void SUV::show_contents(){
	Car::show_contents();
	cout<<"spare_tire : "<<this->spare_tire<<endl;
}


