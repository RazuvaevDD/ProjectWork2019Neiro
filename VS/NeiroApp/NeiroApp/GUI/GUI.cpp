#include "GUI/GUI.hpp"
#include "ui_MainWindow.h"//MainWindow.ui -> ui_MainWindow.h
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
	changeWindow = new EditWindow();
	changeWindow->setModal(true);
	changeWindow->show();
}

void MainWindow::on_changeButton_2_clicked()
{
	changeWindow = new EditWindow();
	changeWindow->setModal(true);
	changeWindow->show();
}

void MainWindow::on_changeButton_3_clicked()
{
	changeWindow = new EditWindow();
	changeWindow->setModal(true);
	changeWindow->show();
}

void MainWindow::on_changeButton_4_clicked()
{
	changeWindow = new EditWindow();
	changeWindow->setModal(true);
	changeWindow->show();
}

GUI::GUI(int & argc, char ** argv) :
	app(argc, argv)
{
	//create window and show
	window = new MainWindow();
	window->show();
}

int GUI::WaitingStopGUI() {
	return app.exec();
}

GUI::~GUI()
{
	delete window;
}
