#include "Text.h"

Text::Text(string content, float x, float y, Game* game)
	:content(content), x(x), y(y), game(game) //inicializar variables
{
}

void Text::draw() {
	//inicializar el color a amarillo (jeje) 
	SDL_Color color;
	color.r = 255;
	color.g = 233;
	color.b = 0;
	color.a = 255; //transparente

	SDL_Surface* surface = TTF_RenderText_Blended(game->font, content.c_str(), color);
	// c_str() transforma el string a cost *char;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(game->renderer, surface);

	SDL_Rect rect; // Base de coordenadas esquina superior izquierda
	rect.x = x - surface->w / 2;
	rect.y = y - surface->h / 2;
	rect.w = surface->w;
	rect.h = surface->h;

	SDL_FreeSurface(surface);
	SDL_RenderCopy(game->renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}


