class Person
{

	private:
		char* name;
		int age;
		bool gender;
	public:
		Person();
		Person(char* name, int age, bool gender);
		~Person();
		void SetPerson(char* name, int age, bool gender);
		void ShowPerson();
	
};

Person::Person()
{
	this->name = "무명";
	this->age = 20;
	this->gender =0;
}

Person::Person(char* name, int age, bool gender)
{
	this->name = name;
	this->age=age;
	this->gender=gender;
}


Person::~Person()
{
	cout<<"소멸자 작동"<<endl;
}

void Person::SetPerson(char* name, int age, bool gender)
{
	this->name = (char*)name;
	this->age=age;
	this->gender=gender;
}

void Person::ShowPerson()
{
	printf("이름 : %s, 나이 : %d ,성별 : ",this->name, this->age );
	if(this->gender == true){
		printf("남성\n");
	}else printf("여성\n");
}
