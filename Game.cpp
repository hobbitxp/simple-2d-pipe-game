/* File for game class
* Author: CRoope 20/11/2009
* Version: 0.8 5/12/2009
* All methods written by Chris Roope
* Game class is where everything happens, the grids are created and drawn here, the players are created.
* The game loop is here to deal with player input and redrawing of the grids.
* The class contains a vector of pipes that is randomly populated then used for each player when placing pipes
*/
#include <stdlib.h>
#include <vector>
#include "SDL.h"
#include "Game.h"
#include "Pipe.h"
#include "Player.h"
#include "Image.h"
#include "Tile.h"
#include "Grid.h"

//using namespace std;


	Game::Game() {

	//2/12:Initialise the SDL_Surfaces to draw for the game
	initImages();

	//2/12:Create a new Image object, which draws a window
	Image window;
	//2/12:Create a grid for Player 1
	Grid grid1("player1");
	//2/12:Create a grid for Player 2
	Grid grid2("player2");

	//3/12:Get a pointer to the vector of tiles within a vector for each grid ready to draw tiles, pipes within them, and change their states
	vector<vector<Tile>>* tiles1 = grid1.getTiles();
	vector<vector<Tile>>* tiles2 = grid2.getTiles();

	//Set the start and end pipes in both the grids and add them to the pipes vector
	Pipe pipe1("up");
	Pipe pipe2("up");
	Pipe pipe3("up");
	Pipe pipe4("up");
	pipes.push_back(pipe1);
	pipes.push_back(pipe2);
	pipes.push_back(pipe3);
	pipes.push_back(pipe4);

	//Create the vector of pipes for the players to place
	createPipes();

	//4/12:Add Pipes, set the tiles above the pipes to open, set tiles to open at the start and end and the side
	// add players to the grid
	tiles1->at(6).at(14).addPipe(pipe1);
	tiles1->at(6).at(13).setState("open");
	tiles2->at(6).at(14).addPipe(pipe2);
	tiles2->at(6).at(13).setState("open");
	tiles1->at(6).at(0).addPipe(pipe3);
	tiles2->at(6).at(0).addPipe(pipe4);
	tiles1->at(6).at(14).setOpen("down");
	tiles2->at(6).at(14).setOpen("down");
	tiles1->at(6).at(0).setOpen("up");
	tiles2->at(6).at(0).setOpen("up");
	tiles1->at(12).at(7).setOpen("right");
	tiles2->at(0).at(7).setOpen("left");
	tiles1->at(0).at(14).setPlayer(true);
	tiles2->at(0).at(14).setPlayer(true);

	//4/12:draw each grid
	drawGrid(grid1, tiles1);
	drawGrid(grid2, tiles2);
	
	//Create a player1 object
	Player p1("Bob");

	//Create a player2 object
	Player p2("Dale");

	SDL_Event event;
	bool gameRunning = true;

	int timer1=0;
	int timer2=0;
	bool gameEnd = false;

	while (gameRunning)
	{
		timer1 = SDL_GetTicks();
		timer2 = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			if( event.type == SDL_KEYDOWN && gameEnd == false)
			{
				//5/12: Get current positions of the players and store them in local variables
				int oldP1x = p1.getX();
				int oldP1y = p1.getY();
				int oldP2x = p2.getX();
				int oldP2y = p2.getY();
				switch( event.key.keysym.sym )
				{
					//5/12: increase player posistion by one when moving (one cell);
					case SDLK_w: p1.setPosition(p1.getX(), p1.getY()- 1); break;
					case SDLK_s: p1.setPosition(p1.getX(), p1.getY()+ 1); break;
					case SDLK_a: p1.setPosition(p1.getX()- 1, p1.getY()); break;
					case SDLK_d: p1.setPosition(p1.getX()+ 1, p1.getY()); break;
					case SDLK_UP: p2.setPosition(p2.getX(), p2.getY()- 1); break;
					case SDLK_DOWN: p2.setPosition(p2.getX(), p2.getY()+ 1); break;
					case SDLK_LEFT: p2.setPosition(p2.getX()- 1, p2.getY()); break;
					case SDLK_RIGHT: p2.setPosition(p2.getX()+ 1, p2.getY()); break;
					//5/12:Draw a pipe from the end of the pipes vector at the players current position
					//5/12: Modified to use the setPipe method
					case SDLK_SPACE: setPipe(tiles1, p1.getX(), p1.getY()); break;
					case SDLK_KP0: setPipe(tiles2, p2.getX(), p2.getY()); break;
				}
				//5/12: Remove player from tile at old player position and set it to the new position
				//redraw the grids with the new position of players and any pipes that have been added
				tiles1->at(oldP1x).at(oldP1y).setPlayer(false);
				tiles1->at(p1.getX()).at(p1.getY()).setPlayer(true);
				tiles2->at(oldP2x).at(oldP2y).setPlayer(false);
				tiles2->at(p2.getX()).at(p2.getY()).setPlayer(true);
				//redraw the grids with the updated tile attributes
				drawGrid(grid1, tiles1);
				drawGrid(grid2, tiles2);
				//update the screen
				SDL_Flip( window.getScreen() );
			}
			//6/12: Check both of the timers have reached 500, if they have show the Time Over screen
			if (timer1/1000 > 50 && timer2/1000 > 50) {
				window.draw(timeOver, 0,0);
				gameEnd = true;
			//6/12: test to check if player1 has ran out of time or they have reached the end
			} else if (timer2/1000 > 50 || (tiles1->at(6).at(1).isPipe() == true &&  tiles1->at(6).at(1).getState() == "up")
				|| (tiles1->at(5).at(0).isPipe() == true && tiles1->at(5).at(0).getState() == "side")
					||(tiles1->at(7).at(0).isPipe() == true && tiles1->at(7).at(0).getState() == "side")) {
 						window.draw(player1Wins, 0, 0);
						gameEnd = true;
			//6/12: test to check if player2 has ran out of time or they have reached the end
			} else if (timer1/1000 > 50 || (tiles2->at(6).at(1).isPipe() == true &&  tiles2->at(6).at(1).getState() == "up")
				|| (tiles2->at(5).at(0).isPipe() == true && tiles2->at(5).at(0).getState() == "side")
					||(tiles2->at(7).at(0).isPipe() == true && tiles2->at(7).at(0).getState() == "side")) {
						window.draw(player2Wins , 0, 0);
						gameEnd = true;
			}

			//update the screen
			SDL_Flip( window.getScreen() );
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		}
	}
	//run cleanUp to free the SDL_Surfaces
	cleanUp();
	//quit SDL
	SDL_Quit();
	}

	Game::~Game() {}

	//2/12: Initialise all the images used for the game
	void Game::initImages() {
		sidePipeImg = SDL_LoadBMP( "pipeside.bmp" );
		upPipeImg = SDL_LoadBMP( "pipeup.bmp" );
		playerImg = SDL_LoadBMP( "player.bmp" );
		tileImg = SDL_LoadBMP( "tile.bmp" );
		openRightTileImg = SDL_LoadBMP( "tileopenright.bmp" );
		openLeftTileImg = SDL_LoadBMP( "tileopenleft.bmp" );
		openUpTileImg = SDL_LoadBMP( "tileopenup.bmp" );
		openDownTileImg = SDL_LoadBMP( "tileopendown.bmp" );
		player1Wins = SDL_LoadBMP( "player1wins.bmp" );
		player2Wins = SDL_LoadBMP( "player2wins.bmp" );
		gameOverImg = SDL_LoadBMP( "gameover.bmp" );
		timeOver = SDL_LoadBMP( "timeover.bmp" );
	}

	//4/12: DrawGrid method, takes grid reference and tiles pointer as parameters
	//Method iterates over the tiles array and checks if a tile is open in any direction, has a pipe or a player
	void Game::drawGrid(Grid &grid, vector<vector<Tile>>* tiles){
		//Nested for loops that goes through the grids and draws the tiles, for the playing grid
		for ( int i=0; i<grid.getWidth(); i++) {
			for ( int j=0; j<grid.getHeight(); j++) {
				//Check if a tile has a pipe and draw the correct pipe at that tile position
				if (tiles->at(i).at(j).getOpen() == "right") {
					window.draw(openRightTileImg, tiles->at(i).at(j).getX(), tiles->at(i).at(j).getY());
				} else if (tiles->at(i).at(j).getOpen() == "left") {
					window.draw(openLeftTileImg, tiles->at(i).at(j).getX(), tiles->at(i).at(j).getY());
				} else if (tiles->at(i).at(j).getOpen() == "up") {
					window.draw(openUpTileImg, tiles->at(i).at(j).getX(), tiles->at(i).at(j).getY());
				} else if (tiles->at(i).at(j).getOpen() == "down") {
					window.draw(openDownTileImg, tiles->at(i).at(j).getX(), tiles->at(i).at(j).getY());
				//4/12:if the tiles are none of the above just draw a standard tile image
				} else {
					window.draw(tileImg, tiles->at(i).at(j).getX(), tiles->at(i).at(j).getY());
				}
				//4/12: if the tiles has a Pipe then get the type and draw it at the current tile posisiton
				if (tiles->at(i).at(j).getState() == "up") {
					window.draw(upPipeImg, tiles->at(i).at(j).getX()+1, tiles->at(i).at(j).getY()+1);
				} else if (tiles->at(i).at(j).getState() == "side") {
					window.draw(sidePipeImg, tiles->at(i).at(j).getX()+1, tiles->at(i).at(j).getY()+1);
				}
				//4/12: Test to see if a player is at the current tile position and draw
				if (tiles->at(i).at(j).isPlayer() == true) {
					window.draw(playerImg, tiles->at(i).at(j).getX(), tiles->at(i).at(j).getY());
				}
			}
		}
	}

	//5/12: create a vector of pipes using a random number generator to decide which type
	// Vector 200 as one grid is 195 tiles big but a tile can only be places next to another tile, so not all of that will be used
	void Game::createPipes() {
		for (int i = 0; i<200; i++) {
			int j = rand() %11;
			if (j <= 5) {
				Pipe pipei("up");
				pipes.push_back(pipei);
			} else {
				Pipe pipei("side");
				pipes.push_back(pipei);
			}
		}
	}

	//5/12: Method to add a pipe to the tiles vector at the given x y position
	//Method adds a pipe to the grid and removes the pipe from the pipes vector
	//5/12: Added a check to see if a pipe is in the current positon
	//5/12: Added a lot of boolean conditions to test whether the pipe you are setting a pipe at is next to an existing pipe
	void Game::setPipe(vector<vector<Tile>>* tiles, int x, int y) {
		//if there is no pipe at the current position and the current tile is open (has a pipe next to it)
		if (tiles->at(x).at(y).isPipe() == false && tiles->at(x).at(y).getState() == "open") {
			//add a pipe at the tile
			tiles->at(x).at(y).addPipe(pipes.back());
			//If the pipe type is up, set the above tile to open so you can set a pipe above it. While y>0
			if (pipes.back().getType() == "up" && y>0 && tiles->at(x).at(y-1).isPipe() == false) {
				tiles->at(x).at(y-1).setState("open");
			//Else if the pipe is side set the pipes either side of it open if there isn't a pipe there already
				//make sure x is within the grid before open the tile otherwise the tile wont exist in the vector
			} else if (pipes.back().getType() == "side" && x<12 && x>0) {
				//if tile to the right hasn't got a pipe in, set it open
				if (tiles->at(x+1).at(y).isPipe() == false){
					tiles->at(x+1).at(y).setState("open");
				}
				//if tile to the left hasn't got a pipe in, set it open
				if (tiles->at(x-1).at(y).isPipe() == false){
					tiles->at(x-1).at(y).setState("open");
				}
			}
			//delete the last pipe in the vector
			pipes.pop_back();
		}
	}
 
	//5/12: Method to free all the SDL_Surfaces before quitting
	void Game::cleanUp() {
		SDL_FreeSurface( sidePipeImg );
		SDL_FreeSurface( upPipeImg );
		SDL_FreeSurface( playerImg );
		SDL_FreeSurface( tileImg );
		SDL_FreeSurface( openRightTileImg );
		SDL_FreeSurface( openLeftTileImg );
		SDL_FreeSurface( openUpTileImg );
		SDL_FreeSurface( openDownTileImg );
		SDL_FreeSurface( player1Wins );
		SDL_FreeSurface( player2Wins );
		SDL_FreeSurface( gameOverImg );
		SDL_FreeSurface( timeOver );
	}