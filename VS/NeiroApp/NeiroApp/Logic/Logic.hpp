#pragma once
#include <qobject.h>

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
	};
}
