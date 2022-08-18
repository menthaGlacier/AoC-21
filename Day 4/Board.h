#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board 
{
public:
	Board();

	int calculateSum();
	bool checkColumns();
	bool checkRows();

	void clear();
	void markMatching(int num);

	int board[5][5];
	bool marked[5][5];

	bool boardWin;
};

#endif /* BOARD_H */
