#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename Item>
class SongsBook;

//迭代器
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
		std::cout << "添加歌曲： " << *song << std::endl;
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

	/* 选中歌曲 */
	std::cout << "请选择歌曲" << std::endl;
	songsbook->addSong(new std::string("春天里"));
	songsbook->addSong(new std::string("生如夏花"));
	songsbook->addSong(new std::string("我是一棵秋天的树 "));
	songsbook->addSong(new std::string("冬天里的一把火"));

	/* 遍历曲库 */
	std::cout << std::endl;
	std::cout << "当前列表中包含歌曲: " << songsbook->count() << "首" << std::endl;
	while (!ktvController->isDone()) {
		std::cout << *ktvController->next() << std::endl;
	}
	

	return 0;
}