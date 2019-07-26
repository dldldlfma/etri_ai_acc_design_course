#include <iostream>

using namespace std;

#include "car.h"


int main(){
	cout<<"Car 생성"<<endl;
	Car a;
	a.set_price(50);
	a.set_volume(100);
	a.show_contents();
	cout<<endl;

	cout<<"TRUCK 생성"<<endl;
	TRUCK b;
	b.set_price(100);
	b.set_volume(1000);
	b.set_max_volume(30);
	b.show_contents();
	cout<<endl;
	
	cout<<"SUV 생성"<<endl;
	SUV c;
	c.set_price(100);
	c.set_volume(1000);
	c.set_spare_tire(30);
	c.show_contents();
	cout<<endl;


	return 0;
}


