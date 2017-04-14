#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//建造者
class Builder
{
public:
	Builder() {}
	virtual ~Builder() {}
	virtual void BuildStep1() = 0;
	virtual void BuildStep2() = 0;
	virtual void BuildStep3() = 0;
	virtual void BuildStep4() = 0;
};

//KFC具体建造者
class KFCBuilder : public Builder
{
public:
	KFCBuilder() { cout << "KFC builder:" << endl; }

	void BuildStep1() {
		cout << "KFC step1..." << endl;
	}

	void BuildStep2() {
		cout << "KFC step2..." << endl;
	}

	void BuildStep3() {
		cout << "KFC step3..." << endl;
	}

	void BuildStep4() {
		cout << "KFC step4..." << endl;
	}

	~KFCBuilder() {}
};

//Mcdonalds具体建造者
class MCDBuilder : public Builder
{
public:
	MCDBuilder() { cout << "MCD builder:" << endl; }

	void BuildStep1() {
		cout << "MCD step1..." << endl;
	}

	void BuildStep2() {
		cout << "MCD step2..." << endl;
	}

	void BuildStep3() {
		cout << "MCD step3..." << endl;
	}

	void BuildStep4() {
		cout << "MCD step4..." << endl;
	}
	~MCDBuilder() {}
};

class Director
{
private:
	Builder *m_pBuilder;
public:
	Director(Builder* bulder) :m_pBuilder(bulder) {}

	//建造
	void Create()
	{
		m_pBuilder->BuildStep1();
		m_pBuilder->BuildStep2();
		m_pBuilder->BuildStep3();
		m_pBuilder->BuildStep4();
	}
};