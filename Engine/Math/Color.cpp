#include "Color.h"
#include <string>

namespace luck
{
	const Color Color::white{ 1,1,1 };
	const Color Color::red{ 1,0,0 };
	const Color Color::green{ 0,1,0 };
	const Color Color::blue{ 0,0,1 };
	const Color Color::purple{ 1,0,1 };
	const Color Color::cyan{ 0,1,1 };
	const Color Color::orange{ 1,0.5f,0 };
	const Color Color::yellow{ 1,1,0 };

	std::istream& operator>>(std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		if (line.find("{") != std::string::npos)
		{
			//red
			std::string r = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
			color.r = std::stof(r);

			line = line.substr(line.find(",") + 1);

			//green
			std::string g = line.substr(0, line.find(","));
			color.g = std::stof(g);

			//blue
			std::string b = line.substr(line.find(",") + 1, line.find("}") - line.find(","));
			color.b = std::stof(b);
		}

		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, Color& v)
	{
		stream << v.r << " " << v.g << " " << v.b;

		return stream;
	}
}