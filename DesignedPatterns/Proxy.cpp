#include <iostream>
#include <string>
using namespace std;

class Image
{
protected:
	string m_imageName;
public:
	Image(string name):m_imageName(name){}
	virtual ~Image(){}
	virtual void Show(){}
};

class BigImage :public Image 
{
public:
	BigImage(string name):Image(name){}
	~BigImage(){}
	void Show()
	{
		cout << "Show big image:" << m_imageName << endl;
	}
};

class BigImageProxy :public Image 
{
private:
	BigImage *m_bigImage;
public:
	BigImageProxy(string name):Image(name), m_bigImage(nullptr){}
	~BigImageProxy() { if (m_bigImage) delete m_bigImage; }
	void Show()
	{
		if (m_bigImage == nullptr)
			m_bigImage = new BigImage(m_imageName);
		m_bigImage->Show();
	}
};

//�ͻ���
int main()
{
	Image *image = new BigImageProxy("proxy.jpg");
	image->Show();//��Ҫʱ�ɴ����
	delete image;

	return 0;
}