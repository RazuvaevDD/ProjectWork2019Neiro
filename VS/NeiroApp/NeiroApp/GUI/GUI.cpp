#include "GUI/GUI.hpp"
#include "ui_MainWindow.h"//MainWindow.ui -> ui_MainWindow.h
#include "ui_EditWindow.h"

using namespace GUI_module;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QStringList headers;
	headers << "Movement" << "Key";
	ui.tableWidget->setHorizontalHeaderLabels(headers);
	connect(ui.deleteButton, SIGNAL(clicked), this, SLOT(on_deleteButton_clicked()));
	//connect(ui.addButton,SIGNAL(clicked()),this,SLOT(on_addButton_clicked()));
}

EditWindow::EditWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox, SIGNAL(activated(QString)), this, SLOT(on_comboBox_activated()));
	connect(ui.addButton2, SIGNAL(clicked), this, SLOT(on_addButton2_clicked()));
	ui.mouseLabel->hide();
}

void MainWindow::addToTable(QString &arg1, QString &arg2)
{

}

void EditWindow::on_addButton2_clicked()
{
	
}

void MainWindow::on_addButton_clicked()
{
	editWindow = new EditWindow;
	editWindow->show();
}

void MainWindow::on_changeButton_clicked()
{
	
}

void MainWindow::on_deleteButton_clicked()
{	
	
}

void EditWindow::on_comboBox_activated(const QString &arg1)
{
	if (arg1 == "Keyboard")
	{
		ui.keyboardLabel->show();
		ui.mouseLabel->hide();
	}
	if (arg1 == "Mouse")
	{
		ui.mouseLabel->show();
		ui.keyboardLabel->hide();
	}
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
