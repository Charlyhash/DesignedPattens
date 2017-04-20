#include <iostream>
#include <string>
#include <vector>
using namespace std;

//棋子颜色
enum PieceColor { BLACK, WHITE };
//棋子位置
struct PiecePos
{
	int x;
	int y;
	PiecePos(int x_, int y_) : x(x_), y(y_) {}
};

//棋子的定义
class Piece
{
protected:
	PieceColor m_color; //棋子颜色

public:
	Piece(PieceColor color) : m_color(color){}
	~Piece() {}
	virtual void Draw() {}
};

class BlackPiece : public Piece
{
public:
	BlackPiece(PieceColor color) : Piece(color) {}
	~BlackPiece() {}
	void Draw() { cout << "绘制一颗黑棋" << endl; }
};
class WhitePiece : public Piece
{
public:
	WhitePiece(PieceColor color) : Piece(color) {}
	~WhitePiece() {}
	void Draw() { cout << "绘制一颗白棋" << endl; }
};

class PieceBoard
{
private:
	vector<PiecePos> m_vecPos; //存放棋子位置
	Piece *m_blackPiece;
	Piece *m_whitePiece;
	string m_blackName;
	string m_whiteName;

public:
	PieceBoard(string black, string white) : m_blackName(black), m_whiteName(white) 
	{
		m_blackPiece = nullptr;
		m_whitePiece = nullptr;
	}
	~PieceBoard() 
	{
		if (m_blackPiece)
		{
			delete m_blackPiece; m_blackPiece = nullptr;
		}
		if (m_whitePiece)
		{
			delete m_whitePiece; m_whitePiece = nullptr;
		}
	}
	void SetPiece(PieceColor color, PiecePos pos) //走一步棋
	{
		if (color == BLACK)
		{
			if (m_blackPiece == nullptr)
				m_blackPiece = new BlackPiece(color);
			cout << m_blackName << "在位置" << "(" << pos.x << "," << pos.y << ")";
			m_blackPiece->Draw();
		}
		else
		{
			if (m_whitePiece == nullptr)
				m_whitePiece = new WhitePiece(color);
			cout << m_whiteName << "在位置" << "(" << pos.x << "," << pos.y << ")";
			m_whitePiece->Draw();
		}
		m_vecPos.push_back(pos);//加入容器
	}
};

//客户端调用
int main()
{
	PieceBoard pieceBoard("A", "B");
	pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
	pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
	pieceBoard.SetPiece(BLACK, PiecePos(16, 4));
	pieceBoard.SetPiece(WHITE, PiecePos(16, 16));

	return 0;
}