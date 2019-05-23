#pragma once
#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <algorithm>

#include "FormSFML.h"
#include "Tree.h"

using namespace sf;
using namespace form;

class TreeVisualization {
private:
	int width_;
	int height_;
	std::string pathToProject_;
	RenderWindow window_;
	Font font_;
	CircleShape nodeCircle_;
	Text valueText_;
	Button deleteButton_;
	Button insertButton_;
	Input nodeValueInput_;
	Tree* tree_;
public:
	TreeVisualization(int width, int height, std::string pathToProjec);
	TreeVisualization& launchTreeVisualization();
	TreeVisualization& draw();
	TreeVisualization& drawTree();
};

TreeVisualization::TreeVisualization(int width, int height, std::string pathToProject) {
	width_ = width;
	height_ = height;
	pathToProject_ = pathToProject;

	font_.loadFromFile(pathToProject_ + "fonts/arial.ttf");

	tree_ = new Tree(nullptr);

	valueText_.setFont(font_);
	valueText_.setCharacterSize(10);
	valueText_.setFillColor(Color::Black);

	deleteButton_.setProberties(20, 20, 70, 30, "Delete", pathToProject_);
	insertButton_.setProberties(110, 20, 70, 30, "Insert", pathToProject_);
	nodeValueInput_.setProberties(200, 20, 70, 30, "", color::Black)

	nodeCircle_.setRadius(10);
}

TreeVisualization& TreeVisualization::launchTreeVisualization() {
	window_.create(VideoMode(width_, height_), "ABL Tree!");
	window_.setFramerateLimit(60);

	while (window_.isOpen()) {
		Event e;
		while (window_.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window_.close();
				break;
			}
		}

		if (e.type == sf::Event::MouseButtonPressed) {
			if (e.mouseButton.button == sf::Mouse::Left) {
				Vector2i mouse = Mouse::getPosition(window_);

				if (deleteButton_.select(mouse)) {
					tree_->remove(tree_->root, nodeValueInput_.readText());
					drawTree();
				}

				if (insertButton_.select(mouse)) {
					tree->insert(tree_->root, nodeValueInput_.readText());
					drawTree();
				}

				nodeValueInput_.select(mouse);
			}
		}
		if (e.type == sf::Event::TextEntered) {
			sleep(milliseconds(300));
			if (nodeValueInput_.select()) {
				nodeValueInput_.reText(e.text.unicode);
			}
		}

		////// draw  ///////
		window_.clear();
		window_.draw(sprite_);
		window_.display();
		}
	}
	return *this;
}

TreeVisualization& TreeVisualization::drawTree(int xPosition) {
	Node* node = tree_->root;
	nodeCircle_.setPosition(xPosition, (tree-height() - node->height) * 30);
	valueText_.setPosition(xPosition, (tree-height() - node->height) * 30);
	valueText_.setText(node->key);
	window_.draw(nodeCircle_);
	window_.draw(valueText_);
	if (node->right != 0) {
		drawTree(node->right, xPoz + 20);
	}
	if (node->left != 0) {
		drawTree(node->left, xPoz - 20);
	}
	drawTree();
}

TreeVisualization& TreeVisualization::draw() {
	window_.clear();

	window_.draw(deleteButton_.displayButton());
	window_.draw(deleteButton_.displayText());
	window_.draw(insertButton_.displayButton());
	window_.draw(insertButton_.displayText());

	window_.draw(nodeValueInput_.displayButton());
	window_.draw(nodeValueInput_.displayText());

	drawTree(width_ / 2);
	window_.display();
	return *this;
}


#endif /* Game_h */
