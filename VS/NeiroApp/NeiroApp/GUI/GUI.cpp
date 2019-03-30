#include "GUI/GUI.hpp"
#include "ui_MainWindow.h"
#include "ui_EditWindow.h"

using namespace GUI_module;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

EditWindow::EditWindow(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

void MainWindow::on_changeButton_clicked()
{
	emit openEditWindow(1);
}

void MainWindow::on_changeButton_2_clicked()
{
	emit openEditWindow(2);
}

void MainWindow::on_changeButton_3_clicked()
{
	emit openEditWindow(3);
}

void MainWindow::on_changeButton_4_clicked()
{
	emit openEditWindow(4);
}

void EditWindow::openWindow(int ID) {
	//подгрузить по id потом
	setModal(true);
	show();
}

GUI::GUI(int & argc, char ** argv) :
	app(argc, argv)
{
	//create window and show
	window = new MainWindow();
	window->show();
	eWindow = new EditWindow();

	QObject::connect(window, SIGNAL(openEditWindow(int)), eWindow, SLOT(openWindow(int)));
}

int GUI::WaitingStopGUI() {
	return app.exec();
}

GUI::~GUI()
{
	delete window;
	delete eWindow;
}