#include <iostream>
using namespace std;

class Scanner
{
public:
	void Scan() { cout << "词法分析..." << endl; }
};

class Parser
{
public:
	void Parse() { cout << "语法分析..." << endl; }
};

class GenMidCode
{
public:
	void GenCode() { cout << "中间代码生成..." << endl; }
};

class GenachineCode
{
public:
	void GenCode() { cout << "机器码生成..." << endl; }
};

//高层接口
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


//客户端
int main()
{
	Compliler c;
	c.Run();

	return 0;
}