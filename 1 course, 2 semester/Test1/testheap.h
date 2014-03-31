#pragma once
#include <QObject>
#include <QTest>

class TestHeap : public QObject {
	Q_OBJECT
	public:
		explicit TestHeap(QObject *parent = 0) : QObject(parent) {}
};
