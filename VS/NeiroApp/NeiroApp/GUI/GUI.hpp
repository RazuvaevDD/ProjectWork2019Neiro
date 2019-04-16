#pragma once
#include <QtWidgets>
#include <QDialog>
#include <qobject.h>
#include <vector>

#include "ui_MainWindow.h"
#include "ui_EditWindow.h"
#include "Settings/Setting.hpp"

namespace GUI_module {
	class EditWindow : public QDialog
	{
		Q_OBJECT

	public:
		EditWindow(QDialog *parent = Q_NULLPTR);
		QList<QPushButton *> allPButtons;
	signals:
		void getUpdatedSettingsSig();
	private slots:
		void openWindow(int, Settings_module::Setting);
		void on_ok_clicked();
		void pushButtonKeys();
		void on_reset_clicked();
		void on_setCords_clicked();
		void updatedSettingsSlt(std::vector<Settings_module::Setting>);
	private:
		Ui::EditWindow ui;
		int ID = 0;
	};
	
	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = Q_NULLPTR);
		EditWindow* changeWindow;
	signals:
		void openEditWindow(int, Settings_module::Setting);
	private slots:
		void on_changeButton_clicked();   
		void on_changeButton_2_clicked();   
		void on_changeButton_3_clicked(); 
		void on_changeButton_4_clicked(); 
	private:
		Ui::MainWindowClass ui;
	};

	class GUI : public QObject
	{
		Q_OBJECT
	public:
		GUI(int& argc, char** argv);
		int WaitingStopGUI();
		~GUI();
		MainWindow* window;
		EditWindow* eWindow;
	signals:
		void getUpdatedSettingsSig();
		void updatedSettingsSig(std::vector<Settings_module::Setting>);
	private:
		QApplication app;
	private slots:
		void getUpdatedSettingsSlt();
		void updatedSettingsSlt(std::vector<Settings_module::Setting>);
	};
}
