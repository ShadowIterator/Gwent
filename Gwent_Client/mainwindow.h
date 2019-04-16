#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"global.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;
public slots:
	void slot_deckbuilder();
	void slot_startgame();
};

#endif // MAINWINDOW_H
