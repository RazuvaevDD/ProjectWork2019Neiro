#pragma once
#include <QtWidgets>
#include <QDialog>
#include "ui_MainWindow.h"
#include "ui_EditWindow.h"

namespace GUI_module {
	class EditWindow : public QDialog
	{
		Q_OBJECT

	public:
		EditWindow(QDialog *parent = Q_NULLPTR);
	//private slots:
	private:
		Ui::EditWindow ui;
	};
	
	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = Q_NULLPTR);
		EditWindow* changeWindow;
	private slots:
		void on_changeButton_clicked();
		void on_changeButton_2_clicked();
		void on_changeButton_3_clicked();
		void on_changeButton_4_clicked();
	private:
		Ui::MainWindowClass ui;
	};

	class GUI
	{
	public:
		GUI(int& argc, char** argv);
		int WaitingStopGUI();
		~GUI();
		MainWindow* window;
	private:
		QApplication app;
	};
}
