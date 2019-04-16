#ifndef FLOWCONTROL_H
#define FLOWCONTROL_H


#include"global.h"
#include"field.h"
#include"userinteraction.h"

const int PASSED=1;
const int NOTPASSED=0;

class Game:public QObject
{
	Q_OBJECT
public:
	Field* field;
	UserInteraction* user[MAX_TEAM_NUM];
	QString deckpath[2];
	QString cardDir;
	int curTeam;
	int round;
	int score[MAX_TEAM_NUM][MAX_ROUND_NUM];
	int winRound[MAX_TEAM_NUM];
	int passed[MAX_TEAM_NUM];
	list<Card*> cardInput;
	list<CardSet*> cardSetInput;
	list<int> orderInput;
public:
	Game(QObject* parent=0);
	~Game();
	void __init();
	void __test();
	Card* __popFront_cardInput();
	CardSet* __popFront_cardSetInput();
	int __popFront_orderInput();
public slots:

	void _inputCard_(Card*);
	void _inputCardSet_(CardSet*);
	void _inputOrder_(int);

	void endTurn(int,int);
	void endRound(int);
	void endGame();

	void startGame();
	void startRound(int,int);
	void startTurn(int,int);

signals:
	void _startGame();
	void _startRound(int,int);
	void _startTurn(int,int);
	void _endRound(int);
	void _endTurn(int,int);
	void _endGame();

	void startGame_();
	void startRound_(int,int);
	void startTurn_(int,int);
	void endRound_();
	void endTurn_(int,int);
	void endGame_();

	void _inputCard(CardSet*);
	void _inputCardSet(list<CardSet*>*);
	void _inputOrder(CardSet*);
	void _queryPass();

	void _gameover();

};

#endif // FLOWCONTROL_H
