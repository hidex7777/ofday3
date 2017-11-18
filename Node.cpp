#include "Node.h"



Node::Node() {
	this->location.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(0, -ofGetWidth()));
	this->velocity.set(ofRandom(-3.4, 3.4), ofRandom(-3.4, 3.4), ofRandom(-3.4, 3.4));
	nodecolor.r = 0;
	nodecolor.g = 0;
	nodecolor.b = 0;
}
void Node::update() {
	this->location += this->velocity;

	if (this->location.x < 0) {
		this->location.x = 0;
		this->velocity.x *= -1;
	}
	else if (this->location.x > ofGetWidth()) {
		this->location.x = ofGetWidth();
		this->velocity.x *= -1;
	}

	if (this->location.y < 0) {
		this->location.y = 0;
		this->velocity.y *= -1;
	}
	else if (this->location.y > ofGetHeight()) {
		this->location.y = ofGetHeight();
		this->velocity.y *= -1;
	}

	if (this->location.z > 0) {
		this->location.z = 0;
		this->velocity.z *= -1;
	}
	else if (this->location.z < -ofGetWidth()) {
		this->location.z = -ofGetWidth();
		this->velocity.z *= -1;
	}
}
void Node::draw(vector<shared_ptr<Node>> nodes) {
	ofSetColor(nodecolor);
	ofDrawSphere(this->location, 3);
	float myd;
	float mya;
	for (int i = 0; i < nodes.size(); i++) {
		myd = this->location.distance(nodes[i]->location);
		if (myd < 270) {
			mya = ofMap(myd, 0, 270, 255, 10);
			ofSetColor(nodecolor, mya);
			ofDrawLine(this->location, nodes[i]->location);
		}
	}
}
ofVec3f Node::getLocation() {
	return this->location;
}