#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename Item>
class SongsBook;

//������
template<typename Item>
class Iterator
{
public:
	virtual Item* first() = 0;
	virtual Item* next() = 0;
	virtual Item* currentItem() = 0;
	virtual bool isDone() = 0;
	virtual ~Iterator() {}
};

template<typename Item>
class KtvCrlor : public Iterator<Item>
{
public:
public:
	KtvCrlor(SongsBook<Item>* songsbook) : songsbook(songsbook), index(0) { }
	Item* first() override
	{
		index = 0;
		return (*songsbook)[0];
	}
	Item* next() override
	{
		return (*songsbook)[index++];
	}
	Item* currentItem() override
	{
		return (*songsbook)[index];
	}
	bool isDone() override
	{
		return (index >= songsbook->count());
	}
private:
	SongsBook<Item>* songsbook;
	int index;
};

template<typename Item>
class Aggregate
{
public:
	Aggregate<Item>() {};
	virtual Iterator<Item>* createIterator() = 0;
	virtual ~Aggregate() {};
};

template<typename Item>
class SongsBook : public Aggregate<Item>
{
public:
	SongsBook<Item>() : Aggregate<Item>() { };
	void addSong(Item* song)
	{
		if (song != NULL)
			songs.push_back(song);
		std::cout << "��Ӹ����� " << *song << std::endl;
	}

	int count()
	{
		return songs.size();
	}
	virtual Iterator<Item>* createIterator()
	{
		return new KtvCrlor<Item>(this);
	}
	Item* operator[](int index)
	{
		return songs[index];
	}

private:
	std::vector<Item*>  songs;
};

int main()
{
	SongsBook<std::string>* songsbook = new SongsBook<std::string>();
	Iterator<std::string>* ktvController = songsbook->createIterator();

	/* ѡ�и��� */
	std::cout << "��ѡ�����" << std::endl;
	songsbook->addSong(new std::string("������"));
	songsbook->addSong(new std::string("�����Ļ�"));
	songsbook->addSong(new std::string("����һ��������� "));
	songsbook->addSong(new std::string("�������һ�ѻ�"));

	/* �������� */
	std::cout << std::endl;
	std::cout << "��ǰ�б��а�������: " << songsbook->count() << "��" << std::endl;
	while (!ktvController->isDone()) {
		std::cout << *ktvController->next() << std::endl;
	}
	

	return 0;
}