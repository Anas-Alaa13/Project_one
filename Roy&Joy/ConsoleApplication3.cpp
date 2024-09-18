#include<iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include <SFML/Audio.hpp>
#include <fstream>
#include<SFML/Graphics.hpp>
using namespace sf;
/*
struct Player {
	std::string name;
	int score;
};
// Define a structure for a simple game level
struct GameLevel {
	std::string name;
	std::vector<sf::RectangleShape> obstacles; // Example: obstacles on the level
	sf::RectangleShape ground; // Ground component
};

// Define a map to store game levels
using GameMap = std::map<std::string, GameLevel>;

void runGame(sf::RenderWindow& window, std::vector<Player>& highScores, const GameMap& gameMap);
void displayHighScores(const std::vector<Player>& highScores);
void exitGame(sf::RenderWindow& window);



*/
void runGame(sf::RenderWindow& window);
void exitGame(sf::RenderWindow& window);
void gamewin(sf::RenderWindow& window);

int main()
{
	RenderWindow window(sf::VideoMode(1150, 684.68f), "Roy&Joy");
	Texture mainback;
	mainback.loadFromFile("back3.png");
	Sprite back3;
	back3.setTexture(mainback);
	back3.setScale(0.5, 0.5);
	sf::Font font;
	if (!font.loadFromFile("font1.ttf")) {
		return EXIT_FAILURE;
	}

	sf::Text menuText[4];
	for (int i = 0; i < 2; ++i) {
		menuText[i].setFont(font);
		menuText[i].setCharacterSize(70);
		menuText[i].setPosition(450, 200 + i * 60);
	}

	menuText[0].setString("1. Start");
	menuText[1].setString("2. Exit");

	int selectedItem = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up) {
					selectedItem = (selectedItem - 1 + 2) % 2;
				}
				else if (event.key.code == sf::Keyboard::Down) {
					selectedItem = (selectedItem + 1) % 2;
				}
				else if (event.key.code == sf::Keyboard::Enter) {
					switch (selectedItem)
					{
					case 0:
						runGame(window);
						break;
					case 1:
						exitGame(window);
						break;
					}
				}
			}
		}

		for (int i = 0; i < 2; ++i) {
			menuText[i].setFillColor((i == selectedItem) ? sf::Color::Red : sf::Color::White);
		}

		window.clear();window.draw(back3);
		for (int i = 0; i < 2; ++i) {
			window.draw(menuText[i]);
		}
		
		window.display();
		
		
	}

	return 0;

}


void gamewin(sf::RenderWindow& window)
{
	Texture mainback1;
	mainback1.loadFromFile("back3.png");
	Sprite back33;
	back33.setTexture(mainback1);
	back33.setScale(0.5, 0.5);
	window.clear(Color::White);
	Font font; font.loadFromFile("font1.ttf");
	Text game2;
	game2.setFont(font);
	game2.setCharacterSize(90);
	game2.setPosition(400, 200);
	game2.setString("Win");
	game2.setFillColor(Color::Yellow);
	window.clear();
	window.draw(back33);
	window.draw(game2);
	window.display();
	sleep(seconds(2));
	exitGame(window);
}
const string SCORE_FILE = "score.txt";

void gameover(sf::RenderWindow& window)
{
	Texture mainback2;
	mainback2.loadFromFile("back3.png");
	Sprite back333;
	back333.setTexture(mainback2);
	back333.setScale(0.5, 0.5);
	window.clear(Color::Red);
	Font font; font.loadFromFile("font1.ttf");
	Text game1;
	game1.setFont(font);
	game1.setCharacterSize(80);
	game1.setPosition(400, 300);
	game1.setString("Game Over");
	game1.setFillColor(Color::Red);
	window.clear();
	window.draw(back333);
	window.draw(game1);
	window.display();
	sleep(seconds(2));
	exitGame(window);
}
//int main()
void runGame(sf::RenderWindow& window)
{

	// RenderWindow window(sf::VideoMode(1150, 684.68f), "SFML Window");
	Texture redblock, blueblock, grayblock, grayblock2, background, breakk, bdoor, rdoor, fireblock, waterblock;
	redblock.loadFromFile("Red_Brickp.png"); blueblock.loadFromFile("Blue_Brick.png");
	grayblock.loadFromFile("Gray_Brick.png"); grayblock2.loadFromFile("Gray_Brick2.png");
	background.loadFromFile("pausebackgrouund.jpg"); breakk.loadFromFile("break.png"); waterblock.loadFromFile("water1.png");
	bdoor.loadFromFile("Bdoor.png"); rdoor.loadFromFile("Rdoor.png"); fireblock.loadFromFile("fire1.png");
	Sprite redb[500], blueb[500], grayb[500], grayb2[500], bg, br[50], rd, bd, fb[10], wb[10];
	rd.setTexture(rdoor); bd.setTexture(bdoor);
	int c1[10]{}, c2[10]{};
	
	Texture firecoin, watercoin;
	firecoin.loadFromFile("./8.png"); watercoin.loadFromFile("./9.png");
	Sprite fc[10], wc[10];
	for (int i = 0; i < 9; i++)
	{
		fc[i].setTexture(firecoin); wc[i].setTexture(watercoin);
		fc[i].setScale(0.035, 0.035); wc[i].setScale(0.025, 0.025);

	}
	fc[0].setPosition(107.6, 543.71);
	wc[0].setPosition(945.18, 98.16);
	fc[1].setPosition(167.4, 159.84);
	wc[1].setPosition(885.8, 336.88);
	fc[2].setPosition(556.2, 338.88);
	wc[2].setPosition(1078.18, 628.39);
	fc[3].setPosition(755.68, 629.39);
	wc[3].setPosition(550, 628.39);
	fc[4].setPosition(400, 629.39);
	wc[4].setPosition(639, 337.88);



	for (int i = 0; i < 10; i++) {
		fb[i].setTexture(fireblock); wb[i].setTexture(waterblock);
		fb[i].setScale(0.7f, 0.7f);
		fb[i].setTextureRect(IntRect(0, 210, 105, 221.2));
		wb[i].setScale(0.7f, 0.7f);
		wb[i].setTextureRect(IntRect(0, 285.6, 170, 285.6));
	}
	bd.setScale(0.3f, 0.3f);
	rd.setScale(0.5f, 0.5f);
	bd.setTextureRect(IntRect(0, 0, 240.6, 248));
	rd.setTextureRect(IntRect(0, 0, 120, 188));
	bd.setPosition(600, 183);
	rd.setPosition(535.2, 172);
	for (int i = 0; i < 100; i++)
	{
		redb[i].setTexture(redblock);
		blueb[i].setTexture(blueblock);
		grayb[i].setTexture(grayblock);
		grayb2[i].setTexture(grayblock2);
		redb[i].setScale(0.27f, 0.37f);
		blueb[i].setScale(0.27f, 0.35f);
		grayb[i].setScale(0.2f, 0.2f);
		grayb2[i].setScale(0.2f, 0.2f);
	}
	bg.setTexture(background);
	bg.setScale(0.6f, 0.65f);
	for (int i = 0; i < 50; i++)
	{
		br[i].setTexture(breakk);
		br[i].setScale(0.06f, 0.08f);
	}
	float speed = .50f;
	Vector2f velocity = { 0,0 };
	Vector2f velocity2 = { 0,0 };
	Clock gameclock;
	float deltatime = 0.0f;
	float gravity = -1.0f;
	float  jump_Height = .80f;


	bool jump1 = false;
	bool jump2 = false;
	bool check1 = false;
	bool check2 = false;
	Font font;
	font.loadFromFile("font1.ttf");
	Text resumeText("Resume", font, 80);
	resumeText.setFillColor(Color::Yellow);
	resumeText.setPosition(400, 200);

	Text quitText("Quit", font, 80);
	quitText.setFillColor(Color::White);
	quitText.setPosition(400, 280);

	Texture pause_background;
	pause_background.loadFromFile("pausebackground1.jpg");
	Sprite pbackground;
	pbackground.setTexture(pause_background);
	pbackground.setPosition(0, 0);
	pbackground.setScale(0.57, 0.57);
	Texture tplayer1;
	tplayer1.loadFromFile("./c1.png");
	Sprite player1;
	player1.setTexture(tplayer1);
	player1.setTextureRect(IntRect(0, 0, 78, 85));
	player1.setPosition(16.8, 625.88);
	player1.setScale(0.57, 0.57);

	Texture tplayer2;
	tplayer2.loadFromFile("./c2.png");
	Sprite player2;
	player2.setTexture(tplayer2);
	player2.setTextureRect(IntRect(0, 0, 81, 85));
	player2.setPosition(1090.86, 34.48);
	player2.setScale(0.5, 0.5);


	Text pause;
	pause.setFont(font);
	pause.setFillColor(Color::White);
	pause.setCharacterSize(80);
	pause.setString("PAUSE");
	pause.setPosition(300, 300);

	//bool isPaused = false;
	int gameState = 0;
	int selectedOption = 0;
	SoundBuffer buffer1;
	if (!buffer1.loadFromFile("jump.wav")) {
		// Handle loading error
		//return EXIT_FAILURE;
	}
	Sound jumpsound;
	jumpsound.setBuffer(buffer1);


	SoundBuffer buffer2;
	if (!buffer2.loadFromFile("Coin.wav")) {
		// Handle loading error
		//return EXIT_FAILURE;
	}
	Sound Coinsound;
	Coinsound.setBuffer(buffer2);


	SoundBuffer buffer3;
	if (!buffer3.loadFromFile("death.wav")) {
		// Handle loading error
		//return EXIT_FAILURE;
	}
	Sound deathsound;
	deathsound.setBuffer(buffer3);


	SoundBuffer buffer4;
	if (!buffer4.loadFromFile("Door.wav")) {
		// Handle loading error
		//return EXIT_FAILURE;
	}
	Sound Doorsound;
	Doorsound.setBuffer(buffer4);


	while (window.isOpen()) {
		gameclock.restart();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::P && gameState == 0) {
					gameState = 1;
					selectedOption = 0;
				}
				else if (event.key.code == Keyboard::Escape && gameState == 1) {
					gameState = 0;
				}
				else if (event.key.code == Keyboard::Up && gameState == 1) {
					selectedOption = (selectedOption - 1 + 2) % 2;
				}
				else if (event.key.code == Keyboard::Down && gameState == 1) {
					selectedOption = (selectedOption + 1) % 2;
				}
				else if (event.key.code == Keyboard::Enter && gameState == 1) {
					if (selectedOption == 0) {
						gameState = 0;
					}
					else if (selectedOption == 1) {
						window.close();
					}
				}

			}
		}



		if (gameState == 0)
		{
			bool r = false, l = false;

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				player1.move(-speed, 0);
				player1.setTextureRect(IntRect(78, 255, 78, 85));
			}

			else  if (Keyboard::isKeyPressed(Keyboard::Right))
			{

				player1.move(speed, 0);
				player1.setTextureRect(IntRect(78, 85, 78, 85));
			}
			else if ((Keyboard::isKeyPressed(Keyboard::Up)) && jump1)
			{
				velocity.y -= jump_Height;
				jump1 = false;
				jumpsound.play();


			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {

				player2.move(speed, 0);
				player2.setTextureRect(IntRect(81, 85, 81, 85));

			}
			else if (Keyboard::isKeyPressed(Keyboard::A)) {

				player2.move(-speed, 0);
				player2.setTextureRect(IntRect(81, 255, 81, 85));


			}
			else if ((Keyboard::isKeyPressed(Keyboard::W)) && jump2) {
				velocity2.y -= jump_Height;
				jump2 = false;
				jumpsound.play();

			}
			for (int i = 0; i < 5; i++) {
				if (player1.getGlobalBounds().intersects(fc[i].getGlobalBounds()))
					c1[i] = 1;
				

			}
			for (int i = 0; i < 5; i++) {
				if (player2.getGlobalBounds().intersects(wc[i].getGlobalBounds()))
					c2[i] = 1;
				
			}

			float x1 = 0, y1 = -48.6;
			for (int i = 0; i < 14; i++)
			{
				y1 += 48.6;
				grayb2[i].setPosition(x1, y1);
			}
			float x2 = 1133, y2 = -48.6;
			for (int i = 14; i < 28; i++)
			{
				y2 += 48.6;
				grayb2[i].setPosition(x2, y2);
			}
			float x3 = -48.6, y3 = 0;
			for (int i = 0; i < 24; i++)
			{
				x3 += 48.6;
				grayb[i].setPosition(x3, y3);
			}
			float x4 = -48.6, y4 = 667.88;
			for (int i = 24; i < 48; i++)
			{
				x4 += 48.6;
				grayb[i].setPosition(x4, y4);
			}
			float q = 14.71;
			for (int i = 5; i < 8; i++) {
				if (player2.getGlobalBounds().intersects(fc[i].getGlobalBounds()))
				
					gameover(window);
			}
			
			if (player1.getGlobalBounds().intersects(wc[6].getGlobalBounds()) || player1.getGlobalBounds().intersects(wc[8].getGlobalBounds()))
			{
				
				gameover(window);
			}
			
			redb[1].setPosition(16.8, 579.71);
			redb[2].setPosition(81.6, 579.71);
			redb[3].setPosition(146.4, 579.71);
			redb[4].setPosition(276, 639.39);
			redb[5].setPosition(276, 491.54);
			redb[6].setPosition(211.2, 491.54);
			wb[0].setPosition(200, 459.74);
			redb[7].setPosition(146.4, 491.54);
			redb[8].setPosition(16.8, 551.22);
			redb[9].setPosition(276, 463.705);
			redb[10].setPosition(146.4, 403.37);
			redb[11].setPosition(81.6, 403.37);
			redb[12].setPosition(16.8, 403.37);
			redb[13].setPosition(16.8, 374.88);
			redb[14].setPosition(146.4, 315.2);
			redb[15].setPosition(16.8, 255.52);
			redb[16].setPosition(146.4, 195.84);
			redb[17].setPosition(211.2, 195.84);
			wb[1].setPosition(161.2, 164.04);
			redb[18].setPosition(16.8, 136.16);
			redb[19].setPosition(146.4, 76.48);
			redb[20].setPosition(211.2, 76.48);
			redb[21].setPosition(276, 76.48);
			wb[2].setPosition(226, 42.68);
			redb[22].setPosition(340.8, 76.48);
			br[0].setPosition(340.8, 104.97);
			br[1].setPosition(340.8, 166.01);
			br[2].setPosition(340.8, 227.05);
			br[3].setPosition(340.8, 288.09);
			br[4].setPosition(340.8, 349.13);
			br[5].setPosition(340.8, 410.17);
			br[6].setPosition(340.8, 471.21);
			br[7].setPosition(340.8, 532.25);
			redb[23].setPosition(405.6, 315.2);
			redb[24].setPosition(535.2, 256.12);
			redb[25].setPosition(535.2, 374.88);
			redb[26].setPosition(405, 434.56);
			redb[27].setPosition(535.2, 494.24);
			wb[3].setPosition(421, 634.88);
			redb[28].setPosition(414, 565.92);
			blueb[1].setPosition(1067.86, 76.48);
			blueb[2].setPosition(937.18, 136.16);
			blueb[3].setPosition(871.84, 136.16);
			fb[0].setPosition(861, 110);
			blueb[4].setPosition(1002.52, 195.84);
			blueb[5].setPosition(937.18, 255.52);
			blueb[6].setPosition(871.84, 255.52);
			blueb[7].setPosition(1067.86, 315.2);
			blueb[8].setPosition(937.18, 374.88);
			blueb[9].setPosition(871.8, 374.88);
			blueb[10].setPosition(1067.86, 424.515);
			fb[1].setPosition(1061.86, 398.515);
			blueb[11].setPosition(1067.86, 451);
			blueb[12].setPosition(1002.52, 451);
			blueb[13].setPosition(871.8, 513.105);
			blueb[14].setPosition(1067.86, 540);
			blueb[15].setPosition(1002.52, 540);
			blueb[16].setPosition(937.18, 639.39);
			fb[2].setPosition(990.18, 638.88);
			fb[3].setPosition(655, 638.88);
			blueb[17].setPosition(871.8, 374.88);
			blueb[18].setPosition(871.8, 374.88);
			blueb[19].setPosition(871.8, 374.88);
			br[8].setPosition(848.76, 104.97);
			br[9].setPosition(848.76, 166.01);
			br[10].setPosition(848.76, 227.05);
			br[11].setPosition(848.76, 288.09);
			br[12].setPosition(848.76, 349.13);
			br[13].setPosition(848.76, 410.17);
			br[14].setPosition(848.76, 471.21);
			br[15].setPosition(848.76, 532.25);
			br[16].setPosition(848.76, 43.93);
			blueb[20].setPosition(600, 256.12);
			blueb[21].setPosition(730.68, 315.2);
			blueb[22].setPosition(615, 374.88);
			blueb[23].setPosition(730.68, 434.56);
			blueb[24].setPosition(615, 494.24);
			blueb[25].setPosition(730.68, 565.92);
			blueb[26].setPosition(600, 639.39);
			wc[5].setPosition(255, 453.74);
			wc[6].setPosition(220.2, 160.04);
			wc[7].setPosition(226, 42.68);
			wc[8].setPosition(445, 629.88);
			fc[5].setPosition(900, 100);
			fc[6].setPosition(1090.86, 388.515);
			fc[7].setPosition(1010.18, 639.88);
			fc[8].setPosition(665, 630.88);



		}
		player1.move(velocity);
		player2.move(velocity2);

		if (check1 == true)
		{
			velocity.y -= gravity * deltatime;

		}
		if (check2 == true)
		{
			velocity2.y -= gravity * deltatime;
		}
		for (int i = 0; i < 50; i++)
		{

			FloatRect player1Bounds = player1.getGlobalBounds();
			FloatRect rectangleBounds = grayb[i].getGlobalBounds();

			if (player1Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector;

				float xOverlap = std::min(player1Bounds.left + player1Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player1Bounds.left);
				float yOverlap = std::min(player1Bounds.top + player1Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player1Bounds.top);


				if (xOverlap < yOverlap) {
					correctionVector.x = (player1Bounds.left < rectangleBounds.left) ? -xOverlap : xOverlap;
				}
				else {
					correctionVector.y = (player1Bounds.top < rectangleBounds.top) ? -yOverlap : yOverlap;

				}

				player1.move(correctionVector);

				velocity.y = 0;
				jump1 = true;

			}
			else {
				check1 = true;
			}





			FloatRect player2Bounds = player2.getGlobalBounds();
			if (player2Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector2;

				float xOverlap2 = std::min(player2Bounds.left + player2Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player2Bounds.left);
				float yOverlap2 = std::min(player2Bounds.top + player2Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player2Bounds.top);


				if (xOverlap2 < yOverlap2) {
					correctionVector2.x = (player2Bounds.left < rectangleBounds.left) ? -xOverlap2 : xOverlap2;
				}
				else {
					correctionVector2.y = (player2Bounds.top < rectangleBounds.top) ? -yOverlap2 : yOverlap2;


				}

				player2.move(correctionVector2);
				velocity2.y = 0;
				jump2 = true;
			}
			else
			{
				check2 = true;
			}

		}
		//grey2

		for (int i = 0; i < 50; i++)
		{

			FloatRect player1Bounds = player1.getGlobalBounds();
			FloatRect rectangleBounds = grayb2[i].getGlobalBounds();

			if (player1Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector;

				float xOverlap = std::min(player1Bounds.left + player1Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player1Bounds.left);
				float yOverlap = std::min(player1Bounds.top + player1Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player1Bounds.top);


				if (xOverlap < yOverlap) {
					correctionVector.x = (player1Bounds.left < rectangleBounds.left) ? -xOverlap : xOverlap;
				}
				else {
					correctionVector.y = (player1Bounds.top < rectangleBounds.top) ? -yOverlap : yOverlap;

				}

				player1.move(correctionVector);

				velocity.y = 0;
				jump1 = true;

			}
			else {
				check1 = true;
			}





			FloatRect player2Bounds = player2.getGlobalBounds();
			if (player2Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector2;

				float xOverlap2 = std::min(player2Bounds.left + player2Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player2Bounds.left);
				float yOverlap2 = std::min(player2Bounds.top + player2Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player2Bounds.top);


				if (xOverlap2 < yOverlap2) {
					correctionVector2.x = (player2Bounds.left < rectangleBounds.left) ? -xOverlap2 : xOverlap2;
				}
				else {
					correctionVector2.y = (player2Bounds.top < rectangleBounds.top) ? -yOverlap2 : yOverlap2;


				}

				player2.move(correctionVector2);
				velocity2.y = 0;
				jump2 = true;
			}
			else
			{
				check2 = true;
			}

		}


		//redbcoll

		for (int i = 0; i < 29; i++)
		{

			FloatRect player1Bounds = player1.getGlobalBounds();
			FloatRect rectangleBounds = redb[i].getGlobalBounds();

			if (player1Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector;

				float xOverlap = std::min(player1Bounds.left + player1Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player1Bounds.left);
				float yOverlap = std::min(player1Bounds.top + player1Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player1Bounds.top);


				if (xOverlap < yOverlap) {
					correctionVector.x = (player1Bounds.left < rectangleBounds.left) ? -xOverlap : xOverlap;
				}
				else {
					correctionVector.y = (player1Bounds.top < rectangleBounds.top) ? -yOverlap : yOverlap;

				}

				player1.move(correctionVector);

				velocity.y = 0;
				jump1 = true;

			}
			else
			{
				check1 = true;


			}

			FloatRect player2Bounds = player2.getGlobalBounds();
			if (player2Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector2;

				float xOverlap2 = std::min(player2Bounds.left + player2Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player2Bounds.left);
				float yOverlap2 = std::min(player2Bounds.top + player2Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player2Bounds.top);


				if (xOverlap2 < yOverlap2) {
					correctionVector2.x = (player2Bounds.left < rectangleBounds.left) ? -xOverlap2 : xOverlap2;
				}
				else {
					correctionVector2.y = (player2Bounds.top < rectangleBounds.top) ? -yOverlap2 : yOverlap2;

				}

				player2.move(correctionVector2);

				velocity2.y = 0;
				jump2 = true;


			}
			else
			{
				check2 = true;
			}


		}

		//blueblock
		for (int i = 0; i < 27; i++)
		{

			FloatRect player1Bounds = player1.getGlobalBounds();
			FloatRect rectangleBounds = blueb[i].getGlobalBounds();

			if (player1Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector;

				float xOverlap = std::min(player1Bounds.left + player1Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player1Bounds.left);
				float yOverlap = std::min(player1Bounds.top + player1Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player1Bounds.top);


				if (xOverlap < yOverlap) {
					correctionVector.x = (player1Bounds.left < rectangleBounds.left) ? -xOverlap : xOverlap;
				}
				else {
					correctionVector.y = (player1Bounds.top < rectangleBounds.top) ? -yOverlap : yOverlap;

				}

				player1.move(correctionVector);

				velocity.y = 0;
				jump1 = true;

			}
			else
			{
				check1 = true;


			}

			FloatRect player2Bounds = player2.getGlobalBounds();
			if (player2Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector2;

				float xOverlap2 = std::min(player2Bounds.left + player2Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player2Bounds.left);
				float yOverlap2 = std::min(player2Bounds.top + player2Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player2Bounds.top);


				if (xOverlap2 < yOverlap2) {
					correctionVector2.x = (player2Bounds.left < rectangleBounds.left) ? -xOverlap2 : xOverlap2;
				}
				else {
					correctionVector2.y = (player2Bounds.top < rectangleBounds.top) ? -yOverlap2 : yOverlap2;

				}

				player2.move(correctionVector2);

				velocity2.y = 0;
				jump2 = true;


			}
			else
			{
				check2 = true;
			}


		}

		//br16
		for (int i = 0; i < 17; i++)
		{

			FloatRect player1Bounds = player1.getGlobalBounds();
			FloatRect rectangleBounds = br[i].getGlobalBounds();

			if (player1Bounds.intersects(rectangleBounds)) {

				Vector2f correctionVector;

				float xOverlap = std::min(player1Bounds.left + player1Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player1Bounds.left);
				float yOverlap = std::min(player1Bounds.top + player1Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player1Bounds.top);


				if (xOverlap < yOverlap) {
					correctionVector.x = (player1Bounds.left < rectangleBounds.left) ? -xOverlap : xOverlap;
				}
				else {
					correctionVector.y = (player1Bounds.top < rectangleBounds.top) ? -yOverlap : yOverlap;

				}

				player1.move(correctionVector);

				velocity.y = 0;
				jump1 = true;

			}
			else
			{
				check1 = true;


			}

			FloatRect player2Bounds = player2.getGlobalBounds();
			if (player2Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector2;

				float xOverlap2 = std::min(player2Bounds.left + player2Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player2Bounds.left);
				float yOverlap2 = std::min(player2Bounds.top + player2Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player2Bounds.top);


				if (xOverlap2 < yOverlap2) {
					correctionVector2.x = (player2Bounds.left < rectangleBounds.left) ? -xOverlap2 : xOverlap2;
				}
				else {
					correctionVector2.y = (player2Bounds.top < rectangleBounds.top) ? -yOverlap2 : yOverlap2;

				}

				player2.move(correctionVector2);

				velocity2.y = 0;
				jump2 = true;


			}
			else
			{
				check2 = true;
			}


		}

		for (int i = 0; i < 17; i++)
		{

			FloatRect player1Bounds = player1.getGlobalBounds();
			FloatRect rectangleBounds = br[i].getGlobalBounds();

			if (player1Bounds.intersects(rectangleBounds)) {

				Vector2f correctionVector;

				float xOverlap = std::min(player1Bounds.left + player1Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player1Bounds.left);
				float yOverlap = std::min(player1Bounds.top + player1Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player1Bounds.top);


				if (xOverlap < yOverlap) {
					correctionVector.x = (player1Bounds.left < rectangleBounds.left) ? -xOverlap : xOverlap;
				}
				else {
					correctionVector.y = (player1Bounds.top < rectangleBounds.top) ? -yOverlap : yOverlap;

				}

				player1.move(correctionVector);

				velocity.y = 0;
				jump1 = true;

			}
			else
			{
				check1 = true;


			}

			FloatRect player2Bounds = player2.getGlobalBounds();
			if (player2Bounds.intersects(rectangleBounds)) {
				Vector2f correctionVector2;

				float xOverlap2 = std::min(player2Bounds.left + player2Bounds.width - rectangleBounds.left,
					rectangleBounds.left + rectangleBounds.width - player2Bounds.left);
				float yOverlap2 = std::min(player2Bounds.top + player2Bounds.height - rectangleBounds.top,
					rectangleBounds.top + rectangleBounds.height - player2Bounds.top);


				if (xOverlap2 < yOverlap2) {
					correctionVector2.x = (player2Bounds.left < rectangleBounds.left) ? -xOverlap2 : xOverlap2;
				}
				else {
					correctionVector2.y = (player2Bounds.top < rectangleBounds.top) ? -yOverlap2 : yOverlap2;

				}

				player2.move(correctionVector2);

				velocity2.y = 0;
				jump2 = true;


			}
			else
			{
				check2 = true;
			}


		}
		FloatRect player1Bounds = player1.getGlobalBounds();
		FloatRect rectangleBounds1 = rd.getGlobalBounds();
		FloatRect player2Bounds = player2.getGlobalBounds();
		FloatRect rectangleBounds2 = bd.getGlobalBounds();
		
		if ((player1Bounds.intersects(rectangleBounds1))&& (player2Bounds.intersects(rectangleBounds2)))
		{
			Doorsound.play();
			sleep(seconds(1));
			gamewin(window);
		}



		
		window.clear(Color::White);


		if (gameState == 0)
		{  // window.draw(bg); 
			window.draw(bg);


			for (int i = 0; i < 100; i++)
			{
				window.draw(grayb2[i]);
				window.draw(grayb[i]);
			}
			for (int i = 1; i < 29; i++)
			{
				window.draw(redb[i]);
				if (i < 27)
					window.draw(blueb[i]);
			}
			for (int i = 0; i < 17; i++)
			{
				window.draw(br[i]);
			}
			window.draw(bd);
			window.draw(rd);
			window.draw(fc[5]);
			window.draw(fc[6]);
			window.draw(fc[7]);
			//window.draw(fc[8]);
			//window.draw(wc[5]);
			window.draw(wc[6]);
			//window.draw(wc[7]);
			window.draw(wc[8]);
			
			for (int i = 0; i < 5; i++)
			{
				if (c1[i] == 0)
					window.draw(fc[i]);
			}
			for (int i = 0; i < 5; i++)
			{
				if (c2[i] == 0)
					window.draw(wc[i]);

			} window.draw(player1);
			window.draw(player2);

		}
		else {
			if (selectedOption == 0) {
				resumeText.setFillColor(Color::Yellow);
				quitText.setFillColor(Color::White);
			}
			else {
				resumeText.setFillColor(Color::White);
				quitText.setFillColor(Color::Yellow);
			}
			window.draw(pbackground);
			window.draw(resumeText);
			window.draw(quitText);


		}

		window.display();
		deltatime = gameclock.getElapsedTime().asSeconds();
	}
	//return 0;

}
void exitGame(sf::RenderWindow& window) {
	std::cout << "Exiting the game...\n";
	window.close();
}
//////////////////////////////////////////////////////////////////////////////////////
/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
struct Player {
	std::string name;
	int score;
};

// Define a structure for a simple game level
struct GameLevel {
	std::string name;
	std::vector<sf::RectangleShape> obstacles; // Example: obstacles on the level
	sf::RectangleShape ground; // Ground component
};

// Define a map to store game levels
using GameMap = std::map<std::string, GameLevel>;

void runGame(sf::RenderWindow& window, std::vector<Player>& highScores, const GameMap& gameMap);
void displayHighScores(const std::vector<Player>& highScores);
void exitGame(sf::RenderWindow& window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu Example");

	sf::Font font;
	if (!font.loadFromFile("font1.ttf")) {
		return EXIT_FAILURE;
	}

	sf::Text menuText[4];
	for (int i = 0; i < 4; ++i) {
		menuText[i].setFont(font);
		menuText[i].setCharacterSize(60);
		menuText[i].setPosition(100, 150 + i * 60);
	}

	menuText[0].setString("1. Start");
	menuText[1].setString("2. High Scores");
	menuText[2].setString("3. Mute Sound");
	menuText[3].setString("4. Exit");

	int selectedItem = 0;

	std::vector<Player> highScores;

	// Create a simple game map
	GameMap gameMap;
	GameLevel level1;
	level1.name = "Level 1";
	level1.obstacles.push_back(sf::RectangleShape(sf::Vector2f(50, 50)));
	level1.obstacles[0].setFillColor(sf::Color::Red);
	level1.obstacles[0].setPosition(100, 100);
	level1.ground.setSize(sf::Vector2f(800, 50)); // Ground size
	level1.ground.setFillColor(sf::Color::Green);
	level1.ground.setPosition(0, 550); // Adjust position based on your window size
	gameMap["Level 1"] = level1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up) {
					selectedItem = (selectedItem - 1 + 4) % 4;
				}
				else if (event.key.code == sf::Keyboard::Down) {
					selectedItem = (selectedItem + 1) % 4;
				}
				else if (event.key.code == sf::Keyboard::Enter) {
					switch (selectedItem)
					{
					case 0:
						runGame(window, highScores, gameMap);
						break;
					case 1:
						displayHighScores(highScores);
						break;
					case 2:
						// Toggle sound mute
						// Add your sound mute logic here
						std::cout << "Sound Muted/Unmuted\n";
						break;
					case 3:
						exitGame(window);
						break;
					}
				}
			}
		}

		for (int i = 0; i < 4; ++i) {
			menuText[i].setFillColor((i == selectedItem) ? sf::Color::Red : sf::Color::White);
		}

		window.clear();
		for (int i = 0; i < 4; ++i) {
			window.draw(menuText[i]);
		}
		window.display();
	}

	return 0;
}

void runGame(sf::RenderWindow& window, std::vector<Player>& highScores, const GameMap& gameMap) {
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	std::cout << "Starting the game...\n";

	// Display the map of the first level
	const GameLevel& currentLevel = gameMap.begin()->second;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		// Draw the ground
		window.draw(currentLevel.ground);
		// Draw the obstacles on the level
		for (const auto& obstacle : currentLevel.obstacles) {
			window.draw(obstacle);
		}
		window.display();
	}

	// Update the player score
	Player newPlayer;
	newPlayer.name = playerName;
	newPlayer.score = 0; // Set the initial score
	highScores.push_back(newPlayer);
}

void displayHighScores(const std::vector<Player>& highScores) {
	std::vector<Player> sortedHighScores = highScores;
	std::sort(sortedHighScores.begin(), sortedHighScores.end(),
		[](const Player& a, const Player& b) {
			return a.score > b.score;
		});

	std::cout << "High Scores:\n";
	for (const Player& player : sortedHighScores) {
		std::cout << player.name << ": " << player.score << "\n";
	}
	std::cout << std::endl;
}

void exitGame(sf::RenderWindow& window) {
	std::cout << "Exiting the game...\n";
	window.close();
}*/
