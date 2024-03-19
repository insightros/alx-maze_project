#include "../headers/maze.h"

bool initSDL(void)
{
	bool success = true;

	window = NULL;
	renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n",
		       SDL_GetError());
		success = false;
	}

	window = SDL_CreateWindow("Maze", SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n",
		       SDL_GetError());
		success = false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n",
		       SDL_GetError());
		success = false;
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
				    SDL_TEXTUREACCESS_STREAMING,
				    SCREEN_WIDTH, SCREEN_HEIGHT);
	if (texture == NULL)
	{
		printf("Texture could not be initialized! SDL Error: %s\n",
		       SDL_GetError());
		success = false;
	}
	return (success);
}


void updateRenderer(bool textured)
{
	int x, y;

	if (textured)
	{
		SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * 4);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);

		/* clear buffer */
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			for (y = 0; y < SCREEN_HEIGHT; y++)
			{
				buffer[y][x] = 0;
			}
		}
	}

	/* update screen */
	SDL_RenderPresent(renderer);
}


void closeSDL(void)
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
