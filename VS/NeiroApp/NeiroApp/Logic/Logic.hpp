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
		void newInputDataSlt(unsigned int);
		void updateSettings(std::vector<Settings_module::Setting>);

	signals:
		void pressKeySig(std::string key);
		void releaseKeySig(std::string Key);
		
	private:
		std::vector<Settings_module::Setting> settings;
	};
}
