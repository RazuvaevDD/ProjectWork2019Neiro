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
	allPButtons = findChildren<QPushButton *>();
	for (int i = 0; i < allPButtons.size(); i++)
	{
		if (allPButtons.at(i) != ui.cancel && allPButtons.at(i) != ui.setCords && allPButtons.at(i) != ui.reset &&
			allPButtons.at(i) != ui.ok)
		{
			QObject::connect(allPButtons.at(i), SIGNAL(clicked()), this, SLOT(pushButtonKeys()));
		}
	}
}

void EditWindow::pushButtonKeys()
{
	QString t;
	QString s = sender()->objectName();
	if (ui.keyLabel->text() == "None")
	{
		ui.keyLabel->setText(s);
	}
	else
	{
		t = ui.keyLabel->text();
		t += " + ";
		t += s;
		ui.keyLabel->setText(t);
	}
}

void EditWindow::on_reset_clicked()
{
	ui.keyLabel->setText("None");
	ui.xEdit->setText("");
	ui.yEdit->setText("");
	ui.xEdit_2->setText("");
	ui.yEdit_2->setText("");
}

void EditWindow::on_ok_clicked()
{
	
}

void EditWindow::on_setCords_clicked()
{
	ui.xEdit->setText("None");
	ui.yEdit->setText("None");
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