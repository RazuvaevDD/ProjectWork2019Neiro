#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include "ui_MainWindow.h"

namespace GUI_module {
	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = Q_NULLPTR);

	private:
		Ui::MainWindowClass ui;
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
