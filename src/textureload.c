#include "../headers/maze.h"

void loadTextures(char *mapName)
{
	SDL_Surface *texSrc[TEX_COUNT];
	uint8_t *pixel;
	int i, j, k;

	if (strcmp(mapName, "map") == 0)
	{
		texSrc[0] = IMG_Load("textures/stonewall.png");
		texSrc[1] = IMG_Load("textures/night.png");
		texSrc[2] = IMG_Load("textures/grass.png");
	}

	for (i = 0; i < TEX_COUNT; i++)
	{
		for (j = 0; j < TEX_HEIGHT; j++)
		{
			for (k = 0; k < TEX_WIDTH; k++)
			{
				pixel = (uint8_t *)texSrc[i]->pixels
					+ k * texSrc[i]->pitch + j *
					texSrc[i]->format->BytesPerPixel;

				tiles[i][j][k] = pixel[0] | pixel[1] << 8
					| pixel[2] << 16;
			}
		}
	}

	for (i = 0; i < TEX_COUNT; i++)
	{
		SDL_FreeSurface(texSrc[i]);
		texSrc[i] = NULL;
	}
}
