//
// Created by katle on 9/4/2022.
//

#ifndef MINMAX_XNO_GV_H
#define MINMAX_XNO_GV_H

//Constant Variables
static const char blank = '_';
static const char xMove = 'X';
static const char oMove = 'O';

static const char moves[] = {xMove, oMove};

enum gameResults {winX, winO, draw, playing};
enum directions{right, left};

#endif //MINMAX_XNO_GV_H
