#pragma once
#include <QtWidgets>
#include "ui_MainWindow.h"
#include "ui_EditWindow.h"

namespace GUI_module {
	class EditWindow : public QWidget
	{
		Q_OBJECT

	public:
		EditWindow(QWidget *parent = Q_NULLPTR);
	private slots:
		void on_comboBox_activated(const QString &arg1);
		void on_addButton2_clicked();
	private:
		Ui::EditWindow ui;
	};
	
	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = Q_NULLPTR);
		void addToTable(QString &arg1,QString &arg2);
	private slots:
		void on_addButton_clicked();
		void on_changeButton_clicked();
		void on_deleteButton_clicked();
	private:
		Ui::MainWindowClass ui;
		EditWindow* editWindow;
	};

	class GUI
	{
	public:
		GUI(int& argc, char** argv);
		int WaitingStopGUI();
		~GUI();
	private:
		QApplication app;
		MainWindow* window;
	};
}
