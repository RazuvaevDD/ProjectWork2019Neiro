#pragma once
#include <qobject.h>
#include "../Settings/Setting.hpp"
#include <vector>

namespace Logic_module
{
	class Logic : public QObject
	{
		Q_OBJECT
	public:
		Logic();
		~Logic();

	public slots:
		void newInputDataSlt(int);
		void updateSettings(std::vector<Settings_module::Setting>);
		
	private:
		std::vector<Settings_module::Setting> settings;
	};
}
