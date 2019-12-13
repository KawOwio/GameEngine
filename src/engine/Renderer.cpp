#include "Renderer.h"
#include "Entity.h"
#include "Core.h"

#include <iostream>

using namespace rend;

const GLchar *vertexAndFragSrc = 
"\n#ifdef VERTEX\n" \
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"uniform mat4 in_Model;" \
"" \
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = in_Model vec4(in_Position, 1.0);" \
"  ex_Color = in_Color;" \
"}" \
""
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"varying vec4 ex_Color;" \
"void main()" \
"{" \
"  gl_FragColor = ex_Color;" \
"}" \
"\n#endif\n" \
"";

namespace engine
{
	void Renderer::onDisplay()
	{
		//getEntity()->getCore()->addEntity();
		bool quit = false;

		while (!quit)
		{
			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			//glClear(GL_COLOR_BUFFER_BIT);

			//SDL_GL_SwapWindow(window);
		}
		shader->render();
	}

	void Renderer::onInit()
	{
		context = Context::initialize();
		shader = context->createShader();
		shader->parse(vertexAndFragSrc);

		buffer = context->createBuffer();
		buffer->add(vec3(0.0f, 0.5f, 0.0f));
		buffer->add(vec3(-0.5f, -0.5f, 0.0f));
		buffer->add(vec3(0.5f, -0.5f, 0.0f));
		shader->setAttribute("in_Position", buffer);

		buffer = context->createBuffer();
		buffer->add(vec4(1.0f, 0.0f, 0.0f, 1.0f));
		buffer->add(vec4(1.0f, 1.0f, 0.0f, 1.0f));
		buffer->add(vec4(1.0f, 0.0f, 1.0f, 1.0f));
		shader->setAttribute("in_Color", buffer);
	}
}