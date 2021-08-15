// Listing 16.2 - Employee class and driver program that uses MyString.hpp
#include "MyString.hpp"
class Employee{
	public:
		Employee();																// default constructor
		Employee(char *, char *, char *, long);									// another constructor
		~Employee();															// destructor
		Employee(const Employee &);												// copy constructor
		Employee & operator=(const Employee &);									// overloads operator (=)
		const String & GetFirstName() const { return itsFirstName; }	
		const String & GetLastName() const { return itsLastName; }
		const String & GetAddress() const { return itsAddress; }
		long GetSalary() const { return itsSalary; }
		void SetFirstName(const String & fName) { itsFirstName = fName; }
		void SetLastName(const String & lName) { itsLastName = lName; }
		void SetAddress(const String & address) { itsAddress = address; }
		void SetSalary(long salary) { itsSalary = salary; }
	private:
		String itsFirstName;
		String itsLastName;
		String itsAddress;
		long itsSalary;
};
// Default constructor
Employee::Employee() : itsFirstName(""), itsLastName(""), itsAddress(""), itsSalary(0) {}
// Another constructor
Employee::Employee(char * firstName, char * lastName, char * address, long salary) :
itsFirstName(firstName), itsLastName(lastName), itsAddress(address), itsSalary(salary) {}
// copy constructor
Employee::Employee(const Employee & rhs) :
itsFirstName(rhs.GetFirstName()), itsLastName(rhs.GetLastName()), itsAddress(rhs.GetAddress()), itsSalary(rhs.GetSalary()) {}
// destructor
Employee::~Employee() {}
// overload operator (=)
Employee & Employee::operator=(const Employee & rhs){
	if(this==&rhs)
		return *this;
	itsFirstName = rhs.GetFirstName();
	itsLastName = rhs.GetLastName();
	itsAddress = rhs.GetAddress();
	itsSalary = rhs.GetSalary();
	return *this;
}
int main(){
	Employee Edie("Jane", "Doe", "1461 Shore Parkway", 20000);
	Edie.SetSalary(50000);
	String LastName("Levine");
	Edie.SetLastName(LastName);
	Edie.SetFirstName("Edythe");
	std::cout << "Name: ";
	std::cout << Edie.GetFirstName().GetString();
	std::cout << " " << Edie.GetLastName().GetString();
	std::cout << ".\nAddress: ";
	std::cout << Edie.GetAddress().GetString();
	std::cout << ".\nSalary: ";
	std::cout << Edie.GetSalary();
	return 0;
}
