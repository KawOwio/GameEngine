#include "Texture.h"
#include "Core.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <fstream>

#include <SDL2/SDL.h>
#include <sr1/memory>

namespace engine
{
	void Texture::load(std::string _path)
	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char *data = stbi_load(_path.c_str(), &w, &h, &bpp, 3);

		if (!data)
		{
			throw rend::Exception("Failed to open an image!");
		}

		myTexture = core.lock()->getContext()->createTexture();
		myTexture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				myTexture->setPixel(x, y, rend::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}
		stbi_image_free(data);
	}
}