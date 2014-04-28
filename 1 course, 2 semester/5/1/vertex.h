#pragma once

class Vertex {
	public:
		virtual ~Vertex() {}
		///Calculates answer in current vertex's subtree
		virtual double calculateSubtree() = 0;
		virtual void printSubtree() = 0;
		bool isNumber = false;
};
