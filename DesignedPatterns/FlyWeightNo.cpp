#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������ɫ
enum PieceColor {BLACK, WHITE};
//����λ��
struct PiecePos
{
	int x;
	int y;
	PiecePos(int x_, int y_) : x(x_), y(y_){}
};

//���ӵĶ���
class Piece
{
protected:
	PieceColor m_color; //������ɫ
	PiecePos m_pos; //����λ��

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
	void Draw() { cout << "����һ�ź���" << endl; }
};
class WhitePiece : public Piece
{
public:
	WhitePiece(PieceColor color, PiecePos pos) : Piece(color, pos) {}
	~WhitePiece() {}
	void Draw() { cout << "����һ�Ű���" << endl; }
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
	void SetPiece(PieceColor color, PiecePos pos) //��һ����
	{
		Piece *piece = NULL;
		if (color == BLACK)
		{
			piece = new BlackPiece(color, pos);
			cout << m_blackName << "��λ��" << "(" << pos.x << "," << pos.y << ")";
			piece->Draw();
		}
		else
		{
			piece = new WhitePiece(color, pos);
			cout << m_whiteName << "��λ��" << "(" << pos.x << "," << pos.y << ")";
			piece->Draw();
		}
		m_vecPiece.push_back(piece);//��������
	}
	void Clear()
	{
		int size = m_vecPiece.size();
		for (int i = 0; i < size; ++i)
			delete m_vecPiece[i];
	}
};

//�ͻ��˵���
int main()
{
	PieceBoard pieceBoard("A", "B");
	pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
	pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
	pieceBoard.SetPiece(BLACK, PiecePos(16, 4));
	pieceBoard.SetPiece(WHITE, PiecePos(16, 16));

	return 0;
}