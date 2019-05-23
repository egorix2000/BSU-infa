#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

#include "TreeVisualization.h"
#include "Tree.h"

using namespace sf;

int main() {
	Node* root_ = nullptr;
	root_ = insert(root_, 3);
	root_ = insert(root_, 2);
	root_ = insert(root_, 4);
	TreeVisualization tree(600, 480, "");

	tree.launchTreeVisualization();

    return 0;
}
