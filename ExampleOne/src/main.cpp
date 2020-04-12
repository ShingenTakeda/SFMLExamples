#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <sstream>
#include <chrono>

//Fix this stuff!
//Its chapter four

using namespace sf;
void UpdateBranches(int seed);

enum class Side
{
    LEFT,
    RIGHT,
    NONE
};

const int NUM_OF_BRANCHES = 6;
Sprite branches[NUM_OF_BRANCHES];

Side branchPos[NUM_OF_BRANCHES];

int main()
{
    VideoMode vm(960, 540);

    RenderWindow window(vm, "Timber");
    View view(sf::FloatRect(0, 0, 1920, 1080));
	window.setView(view);

    Texture textureBackground;

    textureBackground.loadFromFile("graphics/background.png");

    Sprite spriteBackGround;

    spriteBackGround.setTexture(textureBackground);

    spriteBackGround.setPosition(0, 0);

    
    //Tree
    Texture treeTexture;
    treeTexture.loadFromFile("graphics/tree.png");    
    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(810, 0);
    

    //Bee
    Texture beeTexture;
    beeTexture.loadFromFile("graphics/bee.png");
    Sprite beeSprite;
    beeSprite.setTexture(beeTexture);
    beeSprite.setPosition(0, 800);

    //Is the bee moving
    bool isBeeActive = false;

    //Bee speed
    float beeSpeed = 0.0f;

    //Clouds
    Texture cloudTexture;
    cloudTexture.loadFromFile("graphics/cloud.png");

    Sprite cloudSpriteOne;
    Sprite cloudSpriteTwo;
    Sprite cloudSpriteThree;

    cloudSpriteOne.setTexture(cloudTexture);
    cloudSpriteTwo.setTexture(cloudTexture);
    cloudSpriteThree.setTexture(cloudTexture);

    // Position the clouds off screen
	cloudSpriteOne.setPosition(0, 0);
    cloudSpriteTwo.setPosition(0, 150);
    cloudSpriteThree.setPosition(0, 300);

    //Are clouds on screen
    bool cloudOneActive = false;
    bool cloudTwoActive = false;
    bool cloudThreeActive = false;

    //How fast in the cloud
    float cloudOneSpd = 0.0f;
    float cloudTwoSpd = 0.0f;
    float cloudThreeSpd = 0.0f;

    //Setting up the delta time
    Clock clock;

    // Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    //Pause
    bool paused = true;

    //Font
    Font font;
    font.loadFromFile("fonts/Mr.JUNKER_MSX.ttf");

    int score = 0;

    //Making a text object
    Text messageText;
    Text scoreText;

    messageText.setFont(font);
    scoreText.setFont(font);

    //Assigning a string
    messageText.setString("Press enter to start");
    scoreText.setString("Score: 0");

    //Setting text size
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);

    //Setting the text color
    messageText.setColor(Color::White);
    scoreText.setColor(Color::White);

    //Position the text
    FloatRect textRect = messageText.getLocalBounds();

    messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
    scoreText.setPosition(20, 20);

    //Branch setup
    Texture branchTexture;
    branchTexture.loadFromFile("graphics/branch.png");

    //Set the texture for each branch
    for(int i; i < NUM_OF_BRANCHES; i++)
    {
        branches[i].setTexture(branchTexture);
        branches[i].setPosition(-2000, -2000);

        //Setting the origin of the branch for rotation
        branches[i].setOrigin(220, 20);
    }

    UpdateBranches(1);
    UpdateBranches(2);
    UpdateBranches(3);
    UpdateBranches(4);
    UpdateBranches(5);

    //Application loop
    while (window.isOpen())
    {
        //Delta time
        Time deltaTime = clock.restart();

        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        //start the game
        if(Keyboard::isKeyPressed(Keyboard::Enter))
        {
            paused = false;
        }

        if(!paused)
        {
            // Measure time
			Time dt = clock.restart();

			// Subtract from the amount of time remaining
			timeRemaining -= dt.asSeconds();
			// size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond *
				timeRemaining, timeBarHeight));
			
			
			if (timeRemaining <= 0.0f) 
            {
				// Pause the game
				paused = true;

				// Change the message shown to the player
				messageText.setString("Out of time!!");

				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top +
					textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

            }


            //Setup the bee
            if(!isBeeActive)
            {
                //How fast the bee is
                // How fast is the bee
                srand((int)time(0) * 10);
                beeSpeed = (rand() % 200) + 200;
                
                // How high is the bee
                srand((int)time(0) * 10);
                float height = (rand() % 500) + 500;
                beeSprite.setPosition(2000, height);
                isBeeActive = true;
            }
            else
            {
                //Move the bee
                beeSprite.setPosition(
                beeSprite.getPosition().x -
                (beeSpeed * deltaTime.asSeconds()),
                beeSpeed * deltaTime.asSeconds());

                // Has the bee reached the right hand edge of the screen?
                if (beeSprite.getPosition().x < -100)
                {
                    // Set it up ready to be a whole new cloud next frame
                    isBeeActive = false;
                }
            }

            // Manage the clouds
            // Cloud 1
            if (!cloudOneActive)
            {
                // How fast is the cloud
                srand((int)time(0) * 10);
                cloudOneSpd = (rand() % 200);

                // How high is the cloud
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                cloudSpriteOne.setPosition(-200, height);
                cloudOneActive = true;
            }
            else
            {
                cloudSpriteOne.setPosition(
                cloudSpriteOne.getPosition().x +
                (cloudOneSpd * deltaTime.asSeconds()),
                cloudSpriteOne.getPosition().y);

                // Has the cloud reached the right hand edge of the screen?
                if (cloudSpriteOne.getPosition().x > 1920)
                {
                    // Set it up ready to be a whole new cloud next frame
                    cloudOneActive = false;
                }
            }

            // Cloud 2
            if (!cloudTwoActive)
            {
                // How fast is the cloud
                srand((int)time(0) * 20);
                cloudTwoSpd = (rand() % 200);

                // How high is the cloud
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                cloudSpriteTwo.setPosition(-200, height);
                cloudTwoActive = true;
            }
            else
            {
                cloudSpriteTwo.setPosition(
                cloudSpriteTwo.getPosition().x +
                (cloudTwoSpd * deltaTime.asSeconds()),
                cloudSpriteTwo.getPosition().y);

                // Has the cloud reached the right hand edge of the screen?
                if (cloudSpriteTwo.getPosition().x > 1920)
                {
                    // Set it up ready to be a whole new cloud next frame
                    cloudTwoActive = false;
                }
            }

            // Cloud 3
            if (!cloudThreeActive)
            {
                // How fast is the cloud
                srand((int)time(0) * 30);
                cloudThreeSpd = (rand() % 200);

                // How high is the cloud
                srand((int)time(0) * 30);
                float height = (rand() % 400) - 150;
                cloudSpriteThree.setPosition(-200, height);
                cloudThreeActive = true;
            }
            else
            {
                cloudSpriteThree.setPosition(
                cloudSpriteThree.getPosition().x +
                (cloudThreeSpd * deltaTime.asSeconds()),
                cloudSpriteThree.getPosition().y);

                // Has the cloud reached the right hand edge of the screen?
                if (cloudSpriteThree.getPosition().x > 1920)
                {
                    // Set it up ready to be a whole new cloud next frame
                    cloudThreeActive = false;
                }
            }

            // Update the score text
            std::stringstream ss;
            ss << "Score: " << score;
            scoreText.setString(ss.str());

            //Update the branches
            for(int i; i < NUM_OF_BRANCHES; i++)
            {
                float height = i *150;

                if(branchPos[i] == Side::LEFT)
                {
                    //Move branch to the left
                    branches[i].setPosition(610, height);

                    //Rotate the branch to the other side
                    branches[i].setRotation(180);
                }
                else if(branchPos[i] == Side::RIGHT)
                {
                    //Move the branch to the right
                    branches[i].setPosition(1330, height);

                    //Set to the original angles
                    branches[i].setRotation(0);
                }
                else
                {
                    //Hide Branches
                    branches[i].setPosition(3000, height);
                }
            }
        }

        window.clear();
            
        window.draw(spriteBackGround);

        window.draw(cloudSpriteOne);
        window.draw(cloudSpriteTwo);
        window.draw(cloudSpriteThree);

        for(int i = 0; i < NUM_OF_BRANCHES; i++)
        {
            window.draw(branches[i]);
        }

        window.draw(treeSprite);


        window.draw(beeSprite);

        // Draw the score
        window.draw(scoreText);

        // Draw the timebar
        window.draw(timeBar);

        if(paused)
        {
            // Draw our message
            window.draw(messageText);
        }

        window.display();
    }

    return 0;
}

void UpdateBranches(int seed)
{
    //Move all the branches down one notch
    for(int j = NUM_OF_BRANCHES - 1; j > 0; j--)
    {
        branchPos[j] = branchPos[j -1];
    }

    // Spawn a new branch at position 0
	// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);

	switch (r) 
    {
        case 0:
            branchPos[0] = Side::LEFT;
            break;

        case 1:
            branchPos[0] = Side::RIGHT;
            break;

        default:
            branchPos[0] = Side::NONE;
            break;
	}
}