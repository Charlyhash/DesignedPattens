#include <iostream>
#include <string>
#include <vector> 
#include <set>
using namespace std;

//文件类
class File
{
protected:
	string name_;
public:
	File(string name) :name_(name){}
	virtual void Show() {}
	virtual void Add(File* f) {}
	virtual void Remove(File* f) {}
	virtual string GetName() { return ""; }
};

//文件夹类，继承自文件
class Folder :public File
{
private:
	set<File*> fileSet_;
public:
	Folder(string name) :File(name)
	{
		fileSet_.clear();
	}
	void Show() override
	{
		for (auto iter = fileSet_.begin(); iter != fileSet_.end(); ++iter)
			(*iter)->Show();
	}
	//添加文件
	void Add(File* f) override
	{
		fileSet_.insert(f);
	}
	void Remove(File* f) override
	{
		fileSet_.erase(f);
	}
	string GetName()
	{
		return name_;
	}
	~Folder()
	{
		cout << "Delete file " << name_ << endl;
	}

};

class TextFile : public File
{
public:
	TextFile(string name): File(name){}
	void Show() override
	{
		cout << "This is a text file: " << name_ << endl;
	}
	~TextFile()
	{
		cout << "delete text file :" << name_ << endl;
	}
	string GetName() override
	{
		return name_;
	}
};

class ImageFile : public File
{
public:
	ImageFile(string name) : File(name) {}
	void Show() override
	{
		cout << "This is a image file: " << name_ << endl;
	}
	~ImageFile()
	{
		cout << "Delete image file: " << name_ << endl;
	}
};

class VideoFile : public File
{
public:
	VideoFile(string name) : File(name) {}
	void Show() override
	{
		cout << "This is a video file: " << name_ << endl;
	}
	~VideoFile()
	{
		cout << "Delete video file :" << name_ << endl;
	}
};

int main()
{
	Folder mainfold("mainFold");
	TextFile text1("1.txt");
	VideoFile video1("1.avi");
	Folder chilefold("chileFoled");
	TextFile text2("2.txt");
	ImageFile image1("1.jpg");
	VideoFile video2("2.avi");
	chilefold.Add(&video2);
	chilefold.Add(&text2);
	chilefold.Add(&image1);
	mainfold.Add(&text1);
	mainfold.Add(&video1);
	mainfold.Add(&chilefold);
	mainfold.Show();
	cout << "-----------" << endl;
	chilefold.Show();
	video1.Show();
	cout << "-----------" << endl;
	chilefold.Show();
	cout << "-----------" << endl;
	chilefold.Remove(&video2);
	mainfold.Show();
	cout << "-----------" << endl;
	mainfold.Remove(&chilefold);
	mainfold.Show();
	cout << "-----------" << endl;
	mainfold.Remove(&text1);
	mainfold.Show();
	cout << "-----------" << endl;
	return 0;
}
