// Listing 19.8 - STL vector class
#include <iostream>
#include <string>
#include <vector>
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
void Student::SetAge(const int age){
	itsAge = age;
}
int Student::GetAge() const{
	return itsAge;
}
Student &Student::operator=(const Student &rhs){
	itsName = rhs.GetName();
	itsAge = rhs.GetAge();
	return *this;
}
std::ostream &operator<<(std::ostream &os, const Student &rhs){
	os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
	return os;
}
template<class T>
// Display vecotr porperties
void ShowVector(const std::vector<T> &v);
typedef std::vector<Student> SchoolClass;
int main(){
	Student Harry;
	Student Sally("Sally", 15);
	Student Bill("BIll", 17);
	Student Peter("Peter", 16);
	SchoolClass EmptyClass;
	std::cout << "EmptyClass:" << std::endl;
	ShowVector(EmptyClass);
	SchoolClass GrowingClass(3);
	std::cout << "GrowingClass(3):" << std::endl;
	ShowVector(GrowingClass);
	GrowingClass[0] = Harry;
	GrowingClass[1] = Sally;
	GrowingClass[2] = Bill;
	std::cout << "FrowingClass(3) after assigning students:" << std::endl;
	ShowVector(GrowingClass);
	GrowingClass.push_back(Peter);
	std::cout << "GrowingClass() after added 4th student:" << std::endl;
	ShowVector(GrowingClass);
	GrowingClass[0].SetName("Harry");
	GrowingClass[0].SetAge(18);
	std::cout << "GrowingClass() after Set\n:";
	ShowVector(GrowingClass);
	return 0;
}
template<class T>
void ShowVector(const std::vector<T> &v){
	std::cout << "max_size() = " << v.max_size();
	std::cout << "\tsize() = " << v.size();
	std::cout << "\tcapacity() = " << v.capacity();
	std::cout << "\t" << (v.empty() ? "empty" : "not empty");
	std::cout << std::endl;
	for(int i=0; i<v.size(); ++i)
		std::cout << v[i] << std::endl;
	std::cout << std::endl;
}

	
