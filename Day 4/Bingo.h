#ifndef BINGO_H
#define BINGO_H

class Bingo 
{
public:
	Bingo();

	int calculateSum();
	bool checkColumns();
	bool checkRows();

	void clear();
	void markMatching(int num);

	int board[5][5];
	bool marked[5][5];

	bool boardWin;
};

#endif /* BINGO_H */
