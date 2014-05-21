#pragma once
#include <QString>

template<typename dataType>
class Comparator {
	public:
		virtual bool compare(dataType first, dataType second) = 0;
		virtual ~Comparator() {}
};

class IntIncreaseComparator : public Comparator<int> {
	bool compare(int first, int second) {
		return (first < second);
	}
};

class IntDecreaseComparator : public Comparator<int> {
	bool compare(int first, int second) {
		return (first > second);
	}
};

class QStringIncreaseComparator : public Comparator<QString> {
	bool compare(QString first, QString second) {
		return (first < second);
	}
};

class QStringDecreaseComparator : public Comparator<QString> {
	bool compare(QString first, QString second) {
		return (first > second);
	}
};
