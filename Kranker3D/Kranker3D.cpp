﻿/*####################################################################################################################
#     Copyright(C) 2020 by Tom "Kranker Apfel" RKT																	 #
#     https://portfolio.krankerapfel.fr																				 #
#																													 #
#     The program is distributed under the terms of the GNU General Public License	    							 #
#																													 #
#      ██ ▄█▀ ██▀███   ▄▄▄       ███▄    █  ██ ▄█▀▓█████  ██▀███      ▄▄▄       ██▓███    █████▒▓█████  ██▓          #
#      ██▄█▒ ▓██ ▒ ██▒▒████▄     ██ ▀█   █  ██▄█▒ ▓█   ▀ ▓██ ▒ ██▒   ▒████▄    ▓██░  ██▒▓██   ▒ ▓█   ▀ ▓██▒          #
#     ▓███▄░ ▓██ ░▄█ ▒▒██  ▀█▄  ▓██  ▀█ ██▒▓███▄░ ▒███   ▓██ ░▄█ ▒   ▒██  ▀█▄  ▓██░ ██▓▒▒████ ░ ▒███   ▒██░          #
#     ▓██ █▄ ▒██▀▀█▄  ░██▄▄▄▄██ ▓██▒  ▐▌██▒▓██ █▄ ▒▓█  ▄ ▒██▀▀█▄     ░██▄▄▄▄██ ▒██▄█▓▒ ▒░▓█▒  ░ ▒▓█  ▄ ▒██░          #
#     ▒██▒ █▄░██▓ ▒██▒ ▓█   ▓██▒▒██░   ▓██░▒██▒ █▄░▒████▒░██▓ ▒██▒    ▓█   ▓██▒▒██▒ ░  ░░▒█░    ░▒████▒░██████▒      #
#     ▒ ▒▒ ▓▒░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ▒░   ▒ ▒ ▒ ▒▒ ▓▒░░ ▒░ ░░ ▒▓ ░▒▓░    ▒▒   ▓▒█░▒▓▒░ ░  ░ ▒ ░    ░░ ▒░ ░░ ▒░▓  ░      #
#     ░ ░▒ ▒░  ░▒ ░ ▒░  ▒   ▒▒ ░░ ░░   ░ ▒░░ ░▒ ▒░ ░ ░  ░  ░▒ ░ ▒░     ▒   ▒▒ ░░▒ ░      ░       ░ ░  ░░ ░ ▒  ░      #
#     ░ ░░ ░   ░░   ░   ░   ▒      ░   ░ ░ ░ ░░ ░    ░     ░░   ░      ░   ▒   ░░        ░ ░       ░     ░ ░         #
#     ░  ░      ░           ░  ░         ░ ░  ░      ░  ░   ░              ░  ░                    ░  ░    ░  ░      #
#                                                                                                                    #
#                                                                                                                    #
#                                                                                                                    #
#                                                                                                                    #
#														present 					   							 	 #
#																					   							 	 #
#																					   							 	 #
#												                                                                     #
#                                     __ __              __             ____ ___                                     #
#                                     / //_/______ ____  / /_____ ____  |_  // _ \                                   #
#                                    / ,< / __/ _ `/ _ \/  '_/ -_) __/ _/_ </ // /                                   #
#                                   /_/|_/_/  \_,_/_//_/_/\_\\__/_/   /____/____/                                    #
#                                                                                                                    #
#							a raymarching / signed distance function based graphic engine               		 	 #
#																					   							 	 #
#																					   							 	 #
#																					   							 	 #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....,,,,,,,,,,,,,,,,,,,.,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.  ,.,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,......   .....,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,......,  . .....,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,.,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,,,,,.........   .. .........,.,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,......  ..... .........,,.,,,,,,,,,,,,,,,                    #
#                 .,,,,,,,,,,,,,,,,,,,,,...,,,,,,,,,,,.....  ......  ..........,.,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,...,,,.,,,,,......  .     ...........,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,........................   .....      ........,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,......  ,////////, .....  . .  .////////,  ......,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,....  ///((((((/////* ..... ,//////////////  .....,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,.... '//((((((//////////       '/////////////  .....,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,..... ./////////////////////////////////////////  .....,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,....  /////////////////////////////////.&,//////  .....,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,.....  //////////////////////////////.&@',''///// ......,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,..... .///////////////////////////'.@@,,,'//////   .....,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,....  /////////////////////////,,,,',,',//////  .....,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,.....  ////////////////////////''/','////////  .....,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,.....  .//////////////////////////,'///////  .......,,,,,,,,,,,,,.                    #
#                 ,,,,,,,,,,,,,,......  /////////////////////////////////  ......,,,,,,,,,,,,,,,.                    #
#                 .,,.,,,,,,,,,,........  ///'///((/@/%(/#/&#///(%'//'//  ........,,,,,,,,,,,,,,.                    #
#                 .,,,,,,,,,,,,,,,,....... '//'////&&(%&&&%&&(&%&&////' .......,..,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,......... //'///%&&/%&%&&&(&#&////. .........,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,.......  ////%&&/(//#/(#&/(///  .......,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,........  /////////////////  ........,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,.,.......       .................,,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,.............................,,,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,..................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,,,........,,,,,,,,,,,,,,,,,,,.,,,,,,,,,,,,,,,                    #
#                 ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,                    #
#																					   							 	 #
#																					   							 	 #
####################################################################################################################*/

#include "stdafx.h"
#include "src/ui/window.h"
#include "src/core/rendering/shader.h"
#include "src/core/rendering/mesh.h"
#include "resources/meshes/DragonData.h"

#include "src/core/objects/camera.h"
#include "src/core/objects/object.h"

using namespace std;
using namespace Kranker3D;

Mesh setDragoon(vector<Kranker3D::Vertex>& vertices, vector<unsigned int>& indices)
{

	for (int i = 0; i < sizeof(DragonVertices) / sizeof(float) - 7; i += 8)
	{
		glm::vec3 pos(DragonVertices[i], DragonVertices[i + 1], DragonVertices[i + 2]);
		glm::vec3 norm(DragonVertices[i + 3], DragonVertices[i + 4], DragonVertices[i + 5]);
		glm::vec2 text(DragonVertices[i + 6], DragonVertices[i + 7]);
		vertices.push_back(Kranker3D::Vertex{ pos, norm, text });
	}

	for (int i = 0; i < sizeof(DragonIndices) / sizeof(uint16_t); i++) {
		indices.push_back(DragonIndices[i]);
	}

	return Mesh(vertices, indices);
}

int main()
{
	// 1. initialization
	Window w(800, 800, "Gegege no Kitaro");
	Camera cam(800, 800);
	Shader s("resources\\shaders\\test_vertex.glsl", "resources\\shaders\\test_fragment.glsl");

	vector<Kranker3D::Vertex> vertices;
	vector<unsigned int> indices;

	Mesh dragon_mesh = setDragoon(vertices, indices);
	Object dragon_obj;
	dragon_obj.getTransform()->translate(glm::vec3(0.0f, -1, 0.0f));

	dragon_obj.getTransform()->rotate(45, glm::vec3(0.0f, 1, 0.0f));
	dragon_obj.getTransform()->scale(glm::vec3(0.25f, 0.25f, 0.25f));

	while (w.isOpen())
	{
		w.run();

		dragon_obj.getTransform()->rotate(10 * glfwGetTime(), glm::vec3(0, 1, 0));
 		s.setMat4("transform", dragon_obj.getTransform()->getMatrix());
		s.setMat4("view", cam.getView());
		s.setMat4("projection", cam.getProj());
		s.setFloat("iTime", glfwGetTime());
		s.use();
		dragon_mesh.draw();
	}
	// 3. terminate
	s.terminate();
	dragon_mesh.terminate();
}

