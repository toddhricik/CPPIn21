// Listing R2.1 - Apply singly linked list
// ******************************************************************************************************
//
// Title:		Week 2 in Review
// 
// Description: Provide a linked list demonstration program
//
// Classes:		Part:		holds part numbers and potentially other information about parts
// 				PartNode:	acts as a node in a PartsList
// 				PartsList:	provides mechanisms for a linked list of parts
//
// *******************************************************************************************************
#include <iostream>
// ********************************************** Part ***************************************************
// Abstract base class of parts
class Part{
	public:
		Part() : itsPartNumber(1) {}
		Part(int PartNumber) : itsPartNumber(PartNumber) {}
		virtual ~Part() {};
		int GetPartNumber() const { return itsPartNumber; }
		virtual void Display() const = 0;							// pure virtual function must be overridden in derived class(es)
	protected:
		int itsPartNumber;
};
// Implementation of virtual void Display() const = 0;
// Derived classes can chain up to this
void Part::Display() const {
	std::cout << "\nPart Number: " << itsPartNumber << std::endl;
}
// ********************************************** end Part **********************************************
// ********************************************** Car Part **********************************************
class CarPart : public Part{
	public:
		CarPart() : itsModelYear(94) {}
		CarPart(int year, int PartNumber);
		virtual void Display() const {
			Part::Display();
			std::cout << "Model Year: ";
			std::cout << itsModelYear << std::endl;
		}
	private:
		int itsModelYear;
};
CarPart::CarPart(int year, int PartNumber) : itsModelYear(year), Part(PartNumber) {}
// ********************************************** end Car Part *******************************************
// ********************************************** AirPlane Part ******************************************
class AirPlanePart : public Part{
	public:
		AirPlanePart() : itsEngineNumber(1) {}
		AirPlanePart(int EngineNumber, int PartNumber);
		virtual void Display() const {
			Part::Display();
			std::cout << "Engine Number: ";
			std::cout << itsEngineNumber << std::endl;
		}
	private:
		int itsEngineNumber;
};
AirPlanePart::AirPlanePart(int EngineNumber, int PartNumber) :
itsEngineNumber(EngineNumber), Part(PartNumber) {}
// ********************************************** end AirPlane Part ***************************************
// ********************************************* Part Node ************************************************
class PartNode{
	public:
		PartNode(Part *);			// constructor
		~PartNode();
		void SetNext(PartNode * node) { itsNext = node; }
		PartNode * GetNext() const;
		Part * GetPart() const;
	private:
		Part * itsPart;
		PartNode * itsNext;
};
PartNode::PartNode(Part *pPart) : itsPart(pPart), itsNext(0) {}
PartNode::~PartNode(){
	delete itsPart;
	itsPart = 0;
	delete itsNext;
	itsNext = 0;
}
PartNode * PartNode::GetNext() const{
	return itsNext;
}
Part * PartNode::GetPart() const{
	if(itsPart)
		return itsPart;
	else
		return nullptr;
}
// ********************************************* end Part Node **************************************************
// ***************************************** Part List *******************************************************
class PartsList{
	public:
		PartsList();
		~PartsList();
		// needs copy constructor and operator equals!!
		Part * Find(int & position, int PartNubmer) const;
		int GetCount() const { return itsCount; }
		Part * GetFirst() const;
		void Insert(Part *);
		void Iterate() const;
		Part * operator[](int) const;
	private:
		PartNode * pHead;
		int itsCount;
};
PartsList::PartsList() : pHead(0), itsCount(0) {}
PartsList::~PartsList(){
	delete pHead;
}
Part * PartsList::GetFirst() const{
	if(pHead)
		return pHead->GetPart();
	else
		return nullptr;
}
Part * PartsList::operator[](int offSet) const{
	PartNode * pNode = pHead;
	if(!pHead)
		return nullptr;
	if(offSet > itsCount)
		return nullptr;
	for(int i=0; i<offSet; i++)
		pNode = pNode->GetNext();
	return pNode->GetPart();
}
Part * PartsList::Find(int & position, int PartNumber) const{
	PartNode * pNode = 0;
	for(pNode = pHead, position=0; pNode!=nullptr; pNode = pNode->GetNext(), position++){
		if(pNode->GetPart()->GetPartNumber() == PartNumber)
			break;
	}
	if(pNode==nullptr)
		return nullptr;
	else return pNode->GetPart();
}
void PartsList::Iterate() const {
	if(!pHead)
		return;
	PartNode * pNode = pHead;
	do
		pNode->GetPart()->Display();
	while(pNode=pNode->GetNext());
}
void PartsList::Insert(Part * pPart){
	PartNode * pNode = new PartNode(pPart);
	PartNode * pCurrent = pHead;
	PartNode * pNext = 0;
	int New = pPart->GetPartNumber();
	int Next = 0;
	itsCount++;
	if(!pHead){
		pHead = pNode;
		return;
	}
	if(pHead->GetPart()->GetPartNumber() > New){
		pNode->SetNext(pHead);
		pHead = pNode;
		return;
	}
	for(;;){
		if(!pCurrent->GetNext()){
			pCurrent->SetNext(pNode);
			return;
		}
		pNext = pCurrent->GetNext();
		Next = pNext->GetPart()->GetPartNumber();
		if(Next > New){
			pCurrent->SetNext(pNode);
			pNode->SetNext(pNext);
			return;
		}
		pCurrent = pNext;
	}
}
int main(){
	PartsList pl;
	Part * pPart = 0;
	int PartNumber;
	int value;
	int choice = 99;
	while(choice!=0){
		std::cout << "(0)Quit (1)Car (2)Plane: ";
		std::cin >> choice;
		if(choice!=0){
			std::cout << "Enter new Part Number: ";
			std::cin >> PartNumber;
			if(choice ==1){
				std::cout << "Enter the Model Year: ";
				std::cin >> value;
				pPart = new CarPart(value, PartNumber);
			}
			else{
				std::cout << "Enter the Engine Number: ";
				std::cin >> value;
				pPart = new AirPlanePart(value, PartNumber);
			}
			pl.Insert(pPart);
		}
	}
	pl.Iterate();
	return 0;
}


