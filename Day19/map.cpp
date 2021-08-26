// Listing 19.10 - STL map container class
#include <iostream>
#include <string>
#include <map>
class Student{
	public:
		Student();
		Student(const std::string &name, const int age);
		Student(const Student &rhs);
		~Student();
		void SetName(const std::string &name);
		std::string GetName() const;
		void SetAge(const int age);
		int GetAge() const;
		Student &operator=(const Student &rhs);
	private:
		std::string itsName;
		int itsAge;
};
Student::Student() : itsName("New Student"), itsAge(16) {}
Student::Student(const std::string &name, const int age) : itsName(name), itsAge(age) {}
Student::Student(const Student &rhs) : itsName(rhs.GetName()), itsAge(rhs.GetAge()) {}
Student::~Student() {}
void Student::SetName(const std::string &name){
	itsName = name;
}
std::string Student::GetName() const{
	return itsName;
}
void Student::SetAge(const int age){
	itsAge = age;
}
int Student::GetAge() const{
	return itsAge;
}
Student & Student::operator=(const Student &rhs){
	itsName = rhs.GetName();
	itsAge = rhs.GetAge();
	return *this;
}
std::iostream::ostream & operator<<(std::iostream::ostream &os, const Student &rhs){
	os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
	return os;
}
template<class T, class A>
void ShowMap(const std::map<T, A> &v);
typedef std::map<std::string, Student> SchoolClass;
int main(){
	Student Harry("Harry", 18);
	Student Sally("Sally", 15);
	Student Bill("Bill", 17);
	Student Peter("Peter", 16);
	SchoolClass MathClass;
	MathClass[Harry.GetName()] = Harry;
	MathClass[Sally.GetName()] = Sally;
	MathClass[Bill.GetName()] = Bill;
	MathClass[Peter.GetName()] = Peter;
	std::cout << "MathClass:" << std::endl;
	ShowMap(MathClass);
	std::cout << "We know that " << MathClass["Bill"].GetName() << " is " << MathClass["Gill"].GetAge() << " years old" << std::endl;
	return 0;
}
template<class T, class A>
void ShowMap(const std::map<T, A> &v){
	for(std::map<T, A>::const_iterator ci = v.begin(); ci != v.end(); ++ci)
		std::cout << ci->first << ": " << ci->second << std::endl;
	std::cout << std::endl;
}
