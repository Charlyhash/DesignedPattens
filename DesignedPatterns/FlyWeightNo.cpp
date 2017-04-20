#include <iostream>
#include <string>
#include <vector>
using namespace std;

//棋子颜色
enum PieceColor {BLACK, WHITE};
//棋子位置
struct PiecePos
{
	int x;
	int y;
	PiecePos(int x_, int y_) : x(x_), y(y_){}
};

//棋子的定义
class Piece
{
protected:
	PieceColor m_color; //棋子颜色
	PiecePos m_pos; //棋子位置

public:
	Piece(PieceColor color, PiecePos pos) : m_color(color), m_pos(pos){}
	~Piece(){}
	virtual void Draw(){}
};

class BlackPiece : public Piece
{
public:
	BlackPiece(PieceColor color, PiecePos pos) : Piece(color, pos) {}
	~BlackPiece() {}
	void Draw() { cout << "绘制一颗黑棋" << endl; }
};
class WhitePiece : public Piece
{
public:
	WhitePiece(PieceColor color, PiecePos pos) : Piece(color, pos) {}
	~WhitePiece() {}
	void Draw() { cout << "绘制一颗白棋" << endl; }
};

class PieceBoard
{
private:
	vector<Piece*> m_vecPiece;	
	string m_blackName;
	string m_whiteName;

public:
	PieceBoard(string black, string white) : m_blackName(black), m_whiteName(white){}
	~PieceBoard(){}
	void SetPiece(PieceColor color, PiecePos pos) //走一步棋
	{
		Piece *piece = NULL;
		if (color == BLACK)
		{
			piece = new BlackPiece(color, pos);
			cout << m_blackName << "在位置" << "(" << pos.x << "," << pos.y << ")";
			piece->Draw();
		}
		else
		{
			piece = new WhitePiece(color, pos);
			cout << m_whiteName << "在位置" << "(" << pos.x << "," << pos.y << ")";
			piece->Draw();
		}
		m_vecPiece.push_back(piece);//加入容器
	}
	void Clear()
	{
		int size = m_vecPiece.size();
		for (int i = 0; i < size; ++i)
			delete m_vecPiece[i];
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