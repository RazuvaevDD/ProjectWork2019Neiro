#include "Logic.hpp"
#include <QDebug>

using namespace Logic_module;

Logic::Logic()
{
}

Logic::~Logic()
{
}

void Logic::newInputDataSlt(int IDSignal) {
	qDebug() << "Input data: "<< IDSignal;
}
