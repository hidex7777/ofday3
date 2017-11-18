#pragma once
#include "ofMain.h"

class Node
{
public:
	Node();
	~Node() {};

	void update();
	void draw(vector<shared_ptr<Node>>);
	ofVec3f getLocation();

private:
	ofVec3f location;
	ofVec3f velocity;
	ofColor nodecolor;
	float branchalp;
	
};