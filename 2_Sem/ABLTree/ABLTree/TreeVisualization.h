#pragma once
#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <algorithm>

#include "FormSFML.h"
#include "Tree.h"
#include "TreeManager.h"

using namespace sf;
using namespace form;

class TreeVisualization {
private:
	int circleRadius;
	int width_;
	int height_;
	std::string pathToProject_;
	RenderWindow window_;
	Font font_;
	CircleShape nodeCircle_;
	Text valueText_;
	Text foundNotFoundText_;
	Button deleteButton_;
	Button insertButton_;
	Button findButton_;
	Input nodeValueInput_;
	Tree* tree_;
public:
	TreeVisualization(int width, int height, std::string pathToProjec);
	TreeVisualization& launchTreeVisualization();
	TreeVisualization& draw();
	void drawTree(Node* node, int xPosition, int yPosition, int prevX, int prevY);
};

TreeVisualization::TreeVisualization(int width, int height, std::string pathToProject) {
	width_ = width;
	height_ = height;
	pathToProject_ = pathToProject;
	circleRadius = 20;
	tree_ = new Tree();
	tree_->root = nullptr;

	font_.loadFromFile(pathToProject_ + "fonts/arial.ttf");

	valueText_.setFont(font_);
	valueText_.setCharacterSize(15);
	valueText_.setFillColor(Color::Black);

	foundNotFoundText_.setFont(font_);
	foundNotFoundText_.setCharacterSize(15);
	foundNotFoundText_.setFillColor(Color::Black);
	foundNotFoundText_.setPosition(355, 20);

	deleteButton_.setProberties(20, 20, 75, 30, "Delete", pathToProject_);
	insertButton_.setProberties(115, 20, 70, 30, "Insert", pathToProject_);
	findButton_.setProberties(205, 20, 70, 30, "Find", pathToProject_);
	nodeValueInput_.setProberties(295, 20, 40, 30, "", Color::Black);
	nodeCircle_.setRadius(circleRadius);
	nodeCircle_.setOutlineColor(Color::Black);
	nodeCircle_.setOutlineThickness(1);
}

TreeVisualization& TreeVisualization::launchTreeVisualization() {
	window_.create(VideoMode(width_, height_), "ABL Tree!");
	window_.setFramerateLimit(60);
	window_.clear(sf::Color(255, 255, 255));
	draw();
	window_.display();

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
					tree_->root = remove(tree_->root, atoi(nodeValueInput_.readText().c_str()));
					window_.clear(sf::Color(255, 255, 255));
					draw();
					window_.display();
				}

				if (insertButton_.select(mouse)) {
					tree_->root = insert(tree_->root, atoi(nodeValueInput_.readText().c_str()));
					window_.clear(sf::Color(255, 255, 255));
					draw();
					window_.display();
				}

				if (findButton_.select(mouse)) {
					if (find(tree_->root, atoi(nodeValueInput_.readText().c_str())) != nullptr) {
						foundNotFoundText_.setString("Found");
					}
					else {
						foundNotFoundText_.setString("Not found");
					}
					window_.clear(sf::Color(255, 255, 255));
					draw();
					window_.display();
				}

				nodeValueInput_.select(mouse);
			}
		}
		if (e.type == sf::Event::TextEntered) {
			sleep(milliseconds(300));
			if (nodeValueInput_.select()) {
				nodeValueInput_.reText(e.text.unicode);
				window_.clear(sf::Color(255, 255, 255));
				draw();
				window_.display();
			}
		}
	}
	return *this;
}
void TreeVisualization::drawTree(Node* node, int xPosition, int yPosition, int prevX, int prevY) {
	if (node == 0) {
		return;
	}
	nodeCircle_.setPosition(xPosition, yPosition);
	valueText_.setPosition(xPosition + circleRadius/2, yPosition + circleRadius / 2);
	valueText_.setString(to_string(node->key));
	window_.draw(nodeCircle_);
	window_.draw(valueText_);

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(prevX + circleRadius, prevY + circleRadius), Color::Black),
		sf::Vertex(sf::Vector2f(xPosition + circleRadius, yPosition + circleRadius), Color::Black)
	};
	window_.draw(line, 2, sf::Lines);

	if (node->right != 0) {
		drawTree(node->right, xPosition + (node->height-1) * circleRadius*2, yPosition + circleRadius * 2, xPosition, yPosition);
	}
	if (node->left != 0) {
		drawTree(node->left, xPosition - (node->height-1) * circleRadius*2, yPosition + circleRadius * 2, xPosition, yPosition);
	}
}

TreeVisualization& TreeVisualization::draw() {
	window_.clear(sf::Color(255, 255, 255));

	window_.draw(deleteButton_.displayButton());
	window_.draw(deleteButton_.displayText());
	window_.draw(insertButton_.displayButton());
	window_.draw(insertButton_.displayText());
	window_.draw(findButton_.displayButton());
	window_.draw(findButton_.displayText());

	window_.draw(foundNotFoundText_);

	window_.draw(nodeValueInput_.displayButton());
	window_.draw(nodeValueInput_.displayText());

	drawTree(tree_->root, width_ / 2, 70, width_ / 2, 70);
	window_.display();
	return *this;
}


#endif /* Game_h */
