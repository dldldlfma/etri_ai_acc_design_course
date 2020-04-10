#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector <int> v;


	v.push_back(1);
	v.push_back(9);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);

	cout<< "[v.at(i)] size_type : ";
	for(vector<int>::size_type i=0; i<v.size(); i++){
		cout<<v.at(i)<<" ";
	}
	cout<<endl;

	cout<< "[v[i] ] size_type : ";
	for(vector<int>::size_type i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl<<endl;

	cout<<"[v.at(i)] int : ";
	for(int i =0; i<v.size(); i++){
		cout <<v.at(i) <<" ";
	}

	cout<<" [ v[i] ] int : ";
	for(int i=0; i<v.size(); i++){
		cout<< v[i]<<" ";
	}

	cout <<endl<<endl;

	cout<<" [*iter] iterator : ";
	vector<int>::iterator iter;
	for(iter = v.begin(); iter != v.end(); iter++){
		cout<<*iter <<" ";
	}
	cout <<endl<<endl;

	return 0;
}

