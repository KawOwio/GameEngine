#include "Mesh.h"
#include "Core.h"

#include <iostream>
#include <fstream>

namespace engine
{
	void Mesh::load(std::string _path)
	{
		_path += ".obj";

		std::ifstream f(_path);

		if (!f.is_open())
		{
			throw rend::Exception("Failed to open a model!");
		}

		std::string mesh;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			mesh += line + "\n";
		}

		myMesh = core.lock()->getContext()->createMesh();
		myMesh->parse(mesh);
	}
}