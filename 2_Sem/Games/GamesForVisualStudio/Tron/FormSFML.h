#pragma once

#include <string>
#include <filesystem>

using namespace std;
using namespace sf;

namespace form {
	Font None;

	class Label {
	public:
		string text;
	protected:
		double x;
		double y;

		Text TXT;

	public:
		Label(double _x = 0, double _y = 0, string _text = "Text", std::string pathToProject = "")
		{
			None.loadFromFile(pathToProject + "fonts/arial.ttf");

			x = _x;
			y = _y;
			text = _text;
			TXT.setFont(None);
			TXT.setCharacterSize(20);
			TXT.setFillColor(Color::White);
            TXT.setPosition(x, y);
		}
		virtual Label& setProperties(double _x = 0, double _y = 0, string _text = "Text", std::string pathToProject = "")
		{
			None.loadFromFile(pathToProject + "fonts/arial.ttf");

			x = _x;
			y = _y;
			text = _text;
			TXT.setFont(None);
			TXT.setCharacterSize(20);
			TXT.setFillColor(Color::White);
			TXT.setPosition(x, y);	
			return *this;
		}
		Text displayText()
		{
			TXT.setString(text);
			return TXT;
		}
	};

	class Button : public Label {
	protected:
		double width;
		double height;
		RectangleShape BOX;
	public:
		Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text = "Button", std::string pathToProject = "")
		{
			None.loadFromFile(pathToProject + "fonts/arial.ttf");

			x = _x;
			y = _y;
			width = _width;
			height = _height;
			text = _text;
			TXT.setFont(None);
			TXT.setCharacterSize(20);
			TXT.setFillColor(Color::White);
			TXT.setPosition(x, y);

			BOX.setSize(Vector2f(width, height));
			BOX.setPosition(x, y);
			BOX.setFillColor(sf::Color(133, 133, 133));
			BOX.setOutlineThickness(1);
			BOX.setOutlineColor(Color(66, 66, 66));
		}

		Button& setProberties(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text = "Button", std::string pathToProject = "")
		{
			None.loadFromFile(pathToProject + "fonts/arial.ttf");

			x = _x;
			y = _y;
			width = _width;
			height = _height;
			text = _text;
			TXT.setFont(None);
			TXT.setCharacterSize(20);
			TXT.setFillColor(Color::White);
			TXT.setPosition(x, y);

			BOX.setSize(Vector2f(width, height));
			BOX.setPosition(x, y);
			BOX.setFillColor(sf::Color(133, 133, 133));
			BOX.setOutlineThickness(1);
			BOX.setOutlineColor(Color(66, 66, 66));
			return *this;
		}
        
		bool select(Vector2i _mouse)
		{
			if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) {
				return  true;
			}
			else {
				return false;
			}
		}
        
		Text displayText()
		{
			TXT.setString(text);
			return TXT;
		}
        
		RectangleShape displayButton()
		{
			return BOX;
		}


	};

	class Input : public Button {
	protected:
		bool focus;
	public:
        Input(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text = "", Color color = Color::White)
		{
			x = _x;
			y = _y;
			width = _width;
			height = _height;
			text = _text;
			focus = false;

			TXT.setFont(None);
			TXT.setCharacterSize(20);
			TXT.setFillColor(Color::Black);
			TXT.setPosition(x, y);

			BOX.setSize(Vector2f(width, height));
			BOX.setPosition(x, y);
			BOX.setFillColor(Color::White);
            BOX.setOutlineColor(color);
            BOX.setOutlineThickness(2);
		}
		
		void reText(char _tmp)
		{
            text.erase(text.size()-1);
            
            if(_tmp != 8){
                text += _tmp;
            } else {
                if(text.size() > 0){
                    text.erase(text.size()-1);
                }
                
            }
            text += "|";
            TXT.setString(text);
		}

		bool select()
		{
			return focus;
		}
        
		bool select(Vector2i _mouse)
		{
            if((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) {
                if (!focus) {
                    focus = true;
                    text += "|";
                }
            } else {
                if(text.size() > 0){
                    if(text[text.size()-1] == 124){
                        text.erase(text.size()-1);
                    }
                }
                focus = false;
            }
            return focus;
		}

        
		Text displayText()
		{
			TXT.setString(text);
			return TXT;
		}

        
		RectangleShape displayBOX()
		{
			return BOX;
		}

        
		string readText()
		{
            if(text[text.size()-1] == 124) {
                text.erase(text.size()-1);
            }
            return text;
		}
	};

} /* namespace form */
