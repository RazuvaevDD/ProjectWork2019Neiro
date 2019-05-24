#include <iostream>
#include <cstring>
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
	ui.checker->setVisible(false);
	allPButtons = findChildren<QPushButton *>();
	for (int i = 0; i < allPButtons.size(); i++)
	{
		if (allPButtons.at(i) != ui.cancel && allPButtons.at(i) != ui.setCords && allPButtons.at(i) != ui.reset && allPButtons.at(i) != ui.ok)
		{
			QObject::connect(allPButtons.at(i), SIGNAL(clicked()), this, SLOT(pushButtonKeys()));
		}
	}
}

TCP_IPWindow::TCP_IPWindow(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

AboutWindow::AboutWindow(QDialog* parent)
{
	ui.setupUi(this);
}

void EditWindow::pushButtonKeys()
{
	QString ss = ui.checker->text();
	QString t;
	QString s = sender()->objectName();
	t = ui.keyLabel->text();
	if (s != ss && s != t)
	{
		if (t == "None" || t == "")
		{
			ui.keyLabel->setText(s);
		}
		else
		{
			t += " + ";
			t += s;
			ui.keyLabel->setText(t);
		}
		ui.checker->setText(s);
	}
	else
	{
		if (t == s)
		{
			t = "";
			ui.keyLabel->setText(t);
			ui.checker->setText("");
		}
		else
		{
			int pos = t.lastIndexOf(QChar('+'));
			t = t.left(pos - 1);
			ui.keyLabel->setText(t);
			pos = t.lastIndexOf(QChar('+'));
			ui.checker->setText(t.right(t.size() - pos - 2));
		}
	}
	if (ui.keyLabel->text() == "")
	{
		ui.keyLabel->setText("None");
	}
}

void EditWindow::on_reset_clicked()
{
	ui.keyLabel->setText("None");
	ui.xEdit->setText("0");
	ui.yEdit->setText("0");
	ui.xEdit_2->setText("0");
	ui.yEdit_2->setText("0");
	ui.mouseDelayEdit->setText("0");
}

void EditWindow::on_ok_clicked()
{
	Settings_module::Setting setting;
	setting.id = ID;
	setting.movement = ui.movementEdit->text().toStdString();
	setting.keys = ui.keyLabel->text().toStdString();
	setting.x = ui.xEdit->text().toDouble();
	setting.dx = ui.xEdit_2->text().toDouble();
	setting.y = ui.yEdit->text().toDouble();
	setting.dy = ui.yEdit_2->text().toDouble();
	setting.mouseDelay = ui.mouseDelayEdit->text().toDouble();

	emit editSettingSig(setting);
	close();
}

void EditWindow::on_setCords_clicked()
{
	ui.xEdit->setText("0");
	ui.yEdit->setText("0");
	ui.xEdit_2->setText("0");
	ui.yEdit_2->setText("0");
}

void MainWindow::on_changeButton_clicked()
{
	Settings_module::Setting nullSetting;
	nullSetting.isNULL = true;
	emit openEditWindow(1, nullSetting);
}

void MainWindow::on_changeButton_2_clicked()
{
	Settings_module::Setting nullSetting;
	nullSetting.isNULL = true;
	emit openEditWindow(2, nullSetting);
}

void MainWindow::on_changeButton_3_clicked()
{
	Settings_module::Setting nullSetting;
	nullSetting.isNULL = true;
	emit openEditWindow(3, nullSetting);
}

void MainWindow::on_changeButton_4_clicked()
{
	Settings_module::Setting nullSetting;
	nullSetting.isNULL = true;
	emit openEditWindow(4, nullSetting);
}

void MainWindow::on_startButton_clicked()
{
	ui.label->setText(QString::fromLocal8Bit("Ðàáîòàåò"));
	emit start_stopProgram(true);
}

void MainWindow::on_stopButton_clicked()
{
	ui.label->setText(QString::fromLocal8Bit("Îñòàíîâëåí"));
	emit start_stopProgram(false);
}

void GUI::on_changeIP_Port_triggered(QAction* action)
{
	tcp_ipWindow->show();
}

void GUI::on_aboutProgram_triggered(QAction* action)
{
	aWindow->show();
}

void GUI::start_stopProgramSlt(bool started)
{
	emit start_stopProgramSig(started);
}

void TCP_IPWindow::on_okButton_clicked()
{
	char* ip = ui.ipLine->text().toUtf8().data();
	int port = ui.portLine->text().toInt();
	emit updateIP_PortSig(ip, port);
}

void GUI::updateIP_PortSlt(char* ip, int port)
{
	emit updateIP_PortSig(ip, port);
}

void EditWindow::openWindow(int ID, Settings_module::Setting setting)
{
	this->ID = ID;
	if (setting.isNULL)
	{
		emit getUpdatedSettingsSig();
		return; // At next stages we should change it. If setting does not exist it should be created
	}

	ui.movementEdit->setText(QString::fromStdString(setting.movement));
	ui.keyLabel->setText(QString::fromStdString(setting.keys));
	ui.xEdit->setText(QString::number(setting.x));
	ui.xEdit_2->setText(QString::number(setting.dx));
	ui.yEdit->setText(QString::number(setting.y));
	ui.yEdit_2->setText(QString::number(setting.dy));
	ui.mouseDelayEdit->setText(QString::number(setting.mouseDelay));

	setModal(true);
	show();
}

void EditWindow::updatedSettingsSlt(std::vector<Settings_module::Setting> settings)
{
	for (unsigned int i = 0; i < settings.size(); i++)
	{
		if (ID == settings[i].id)
		{
			openWindow(ID, settings[i]);
		}
	}
}

GUI::GUI(int & argc, char ** argv) :
	app(argc, argv)
{
	//create windows and show main window
	window = new MainWindow();
	window->show();
	eWindow = new EditWindow();
	tcp_ipWindow = new TCP_IPWindow();
	aWindow = new AboutWindow();

	connect(window, SIGNAL(openEditWindow(int, Settings_module::Setting)), eWindow, SLOT(openWindow(int, Settings_module::Setting)));
	connect(tcp_ipWindow, SIGNAL(updateIP_PortSig(char*, int)), this, SLOT(updateIP_PortSlt(char*, int)));
	connect(window->ui.server, SIGNAL(triggered(QAction*)), this, SLOT(on_changeIP_Port_triggered(QAction*)));
	connect(window->ui.about, SIGNAL(triggered(QAction*)), this, SLOT(on_aboutProgram_triggered(QAction*)));
	connect(eWindow, SIGNAL(getUpdatedSettingsSig()), this, SLOT(getUpdatedSettingsSlt()));
	connect(this, SIGNAL(updatedSettingsSig(std::vector<Settings_module::Setting>)), eWindow, SLOT(updatedSettingsSlt(std::vector<Settings_module::Setting>)));
	connect(eWindow, SIGNAL(editSettingSig(Settings_module::Setting)), this, SLOT(editSettingSlt(Settings_module::Setting)));
	connect(window, SIGNAL(start_stopProgram(bool)), this, SLOT(start_stopProgramSlt(bool)));

}

void GUI::getUpdatedSettingsSlt()
{
	emit getUpdatedSettingsSig();
}

void GUI::updatedSettingsSlt(std::vector<Settings_module::Setting> settings)
{
	emit updatedSettingsSig(settings);
	Settings_module::Setting setting1;
	Settings_module::Setting setting2;
	Settings_module::Setting setting3;
	Settings_module::Setting setting4;
	for (unsigned int i = 0; i < settings.size(); i++)
	{
		if (settings[i].id == 1)
		{
			setting1 = settings[i];
		}
		if (settings[i].id == 2)
		{
			setting2 = settings[i];
		}
		if (settings[i].id == 3)
		{
			setting3 = settings[i];
		}
		if (settings[i].id == 4)
		{
			setting4 = settings[i];
		}
	}
	window->ui.keysLine->setText(QString::fromStdString(setting1.keys));
	window->ui.keysLine_2->setText(QString::fromStdString(setting2.keys));
	window->ui.keysLine_3->setText(QString::fromStdString(setting3.keys));
	window->ui.keysLine_4->setText(QString::fromStdString(setting4.keys));
	window->ui.movementLine->setText(QString::fromStdString(setting1.movement));
	window->ui.movementLine_2->setText(QString::fromStdString(setting2.movement));
	window->ui.movementLine_3->setText(QString::fromStdString(setting3.movement));
	window->ui.movementLine_4->setText(QString::fromStdString(setting4.movement));
}

void GUI::editSettingSlt(Settings_module::Setting setting)
{
	emit editSettingSig(setting);
}

int GUI::WaitingStopGUI()
{
	return app.exec();
}

GUI::~GUI()
{
	delete window;
	delete eWindow;
	delete tcp_ipWindow;
}
