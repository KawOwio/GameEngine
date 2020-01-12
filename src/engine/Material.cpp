#include "Material.h"
#include "Core.h"

#include <fstream>

namespace engine
{
	void Material::load(std::string _path)
	{
		std::ifstream f(_path);

		if (!f.is_open())
		{
			throw rend::Exception("Failed to open a shader!");
		}

		std::string shader;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			shader += line + "\n";
		}

		myShader = core.lock()->getContext()->createShader();
		myShader->parse(shader);
	}
}