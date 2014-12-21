#pragma once
#include <chrono>

class Randomizer {
public:
	virtual double getRandom() = 0;
	virtual ~Randomizer() {}
};

class TrueRandomizer : public Randomizer {
public:
	TrueRandomizer() {
		re.seed(std::chrono::system_clock::now().time_since_epoch().count());
	}
	~TrueRandomizer() {}
	double getRandom() {
		return std::generate_canonical<double, 10>(re);
	}
private:
	std::default_random_engine re;
};

class TestRandomizer : public Randomizer {
public:
	~TestRandomizer() {}
	double getRandom() {
		count += diff;
		return (double)(count % 10) / 10;
	}
private:
	int count = 0;
	const int diff = 3;
};
