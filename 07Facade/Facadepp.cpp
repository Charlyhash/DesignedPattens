#include <iostream>
using namespace std;

class Scanner
{
public:
	void Scan() { cout << "�ʷ�����..." << endl; }
};

class Parser
{
public:
	void Parse() { cout << "�﷨����..." << endl; }
};

class GenMidCode
{
public:
	void GenCode() { cout << "�м��������..." << endl; }
};

class GenachineCode
{
public:
	void GenCode() { cout << "����������..." << endl; }
};

//�߲�ӿ�
class Compliler
{
public:
	void Run()
	{
		Scanner s;
		Parser p;
		GenMidCode g1;
		GenachineCode g2;

		s.Scan();
		p.Parse();
		g1.GenCode();
		g2.GenCode();
	}
};


//�ͻ���
int main()
{
	Compliler c;
	c.Run();

	return 0;
}