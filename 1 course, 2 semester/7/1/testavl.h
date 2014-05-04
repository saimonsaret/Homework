#pragma once
#include "avl.h"
#include <QTest>
#include <QObject>

class TestAVL : public QObject {
	Q_OBJECT

	public:
		explicit TestAVL(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			tree = new AVLTree;
		}
		void cleanup() {
			delete tree;
		}
		void testAdd() {
			tree->addValue(5);
			QVERIFY(tree->doesExist(5));
		}
		void testDelete() {
			tree->addValue(5);
			tree->deleteValue(5);
			QVERIFY(!tree->doesExist(5));
		}
		void testIdentical() {
			tree->addValue(5);
			tree->addValue(5);
			tree->deleteValue(5);
			QVERIFY(tree->doesExist(5));
		}
		void complexTest() {
			tree->addValue(3);
			tree->addValue(5);
			tree->addValue(7);
			QVERIFY(tree->doesExist(3));
			QVERIFY(tree->doesExist(5));
			QVERIFY(tree->doesExist(7));
			tree->addValue(5);
			tree->deleteValue(5);
			QVERIFY(tree->doesExist(5));
			tree->deleteValue(7);
			QVERIFY(!tree->doesExist(7));
		}

	private:
		AVLTree *tree;
};
