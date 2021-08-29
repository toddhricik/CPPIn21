// Listing 21.7 - Using bit fields
#include <iostream>
#include <string.h>
enum STATUS { FullTime, PartTime };
enum GRADLEVEL { UnderGrad, Grad };
enum HOUSING { Dorm, OffCampus };
enum FOODPLAN { OneMeal, AllMeals, WeekEnds, NoMeals };
class student{
	public:
		student() : myStatus(FullTime), myGradLevel(UnderGrad), myHousing(Dorm), myFoodPlan(NoMeals) {}
		~student() {}
		STATUS GetStatus();
		void SetStatus(STATUS);
		unsigned GetPlan() { return myFoodPlan; }
	private:
	unsigned myStatus : 1;
	unsigned myGradLevel: 1;
	unsigned myHousing : 1;
	unsigned myFoodPlan : 2;
};
STATUS student::GetStatus(){
	if(myStatus)
		return FullTime;
	else
		return PartTime;
}
void student::SetStatus(STATUS theStatus){
	myStatus = theStatus;
}
int main(){
	student Jim;
	if(Jim.GetStatus()==PartTime)
		std::cout << "Jim is part-time\n";
	else
		std::cout << "Jim is full-time\n";
	std::cout << "Jim is on the ";
	char Plan[80];
	switch(Jim.GetPlan()){
		case OneMeal:		strcpy(Plan, "One meal");
							break;
		case AllMeals:		strcpy(Plan, "All meals");
					  		break;
		case WeekEnds:		strcpy(Plan, "Weekend meals");
							break;
		case NoMeals:		strcpy(Plan, "No Meals");
							break;
	}
	std::cout << Plan << " food plan. \n";
	return 0;
}
