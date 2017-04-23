#include <iostream>
#include <string>
#include <list>
using namespace std;

class Element;

class Visitor
{
public:
	virtual void Visit(Element *element) {}
};

class Element
{
	virtual void Accept(Visitor *visitor) {}
};

class Employee :public Element
{
public:
	string name;
	double income;
	int vacationDays;

public:
	Employee(string n, double i, int v) : name(n), income(i), vacationDays(v){}
	void Accept(Visitor *visitor) override
	{
		visitor->Visit(this);
	}
};

class IncomeVisitor :public Visitor
{
public:
	void Visit(Element *element) override
	{
		Employee* e = dynamic_cast<Employee*>(element);
		e->income *= 1.1;
		cout << e->name << "'s new income :" << e->income << endl;
	}
};

class VacationVisitor :public Visitor
{
public:
	void Visit(Element *element) override
	{
		Employee* e = dynamic_cast<Employee*>(element);
		e->vacationDays += 3;
		cout << e->name << "'s new vacationDays:" << e->vacationDays << endl;
	}
};

class Employees
{
private:
	list<Employee*> employees;
public:
	void Attach(Employee *employee)
	{
		employees.push_back(employee);
	}

	void Detach(Employee* e)
	{
		employees.remove(e);
	}

	void Accept(Visitor *v)
	{
		for (auto iter = employees.begin(); iter != employees.end(); ++iter)
			(*iter)->Accept(v);
	}
};

int main()
{
	Employees * employees = new Employees();
	employees->Attach(new Employee("Tom", 25000.0, 14) );
	employees->Attach(new Employee("Thomas", 35000.0, 16));
	employees->Attach(new Employee("Roy", 45000.0, 21));

	//create visitor
	IncomeVisitor * v1 = new IncomeVisitor();
	VacationVisitor* v2 = new VacationVisitor();
	
	employees->Accept(v1);
	employees->Accept(v2);

	if (employees) { delete employees; employees = nullptr; }
	if (v1) { delete v1; v1 = nullptr; }
	if (v2) { delete v2; v2 = nullptr; }

	return 0;
}