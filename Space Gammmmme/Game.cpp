#include "Game.h"

//Static functions

//intitializer functions

void Game::initWindow()
{
    /*Creates a SFML window using options from a window.ini file.*/

    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);

    
    
}



//constructors/destructors
Game::Game()
{
    this->is();
    this->initWindow();
    
}

Game::~Game()
{
	delete this->window;

    
}
//Functions

void Game::updatedt()
{/*Updates the dt variable with the time it takes to update and render one frame*/
    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->window->close();
    }
}


void Game::update()
{
    this->updateSFMLEvents();

    
    
}

void Game::is()
{

    tmt.loadFromFile("Textures/tilemap/tilemap.jpg");
    pbt.loadFromFile("Textures/Player/Base/1.png");
    pgt.loadFromFile("Textures/Player/Gun/1.png");
    pat.loadFromFile("Textures/Player/Aura/1.png");

    tm.setSize(sf::Vector2f(2560, 1440));
    pb.setSize(sf::Vector2f(100, 75));
    pa.setSize(sf::Vector2f(110, 110));
    pg.setSize(sf::Vector2f(60, 16));

    pb.setOrigin(pb.getSize().x / 2, pb.getSize().y / 2);
    pa.setOrigin(pa.getSize().x / 2, pa.getSize().y / 2);
    pg.setOrigin(pg.getSize().x / 2, pg.getSize().y / 2);


    pb.setTexture(&pbt);
    pa.setTexture(&pat);
    pg.setTexture(&pgt);
    tm.setTexture(&tmt); 

}

void Game::render()
{
    


    this->window->clear();

    //Render items
    this->window->draw(tm);
    this->rp(sf::Vector2f(1280., 720.));
   

    this->window->display();
}

void Game::rp(sf::Vector2f p)
{
    pb.setPosition(p);
    pa.setPosition(p);
    pg.setPosition(p.x - 15, p.y);




    this->window->draw(pa);
    this->window->draw(pb);
    this->window->draw(pg);
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updatedt();
        this->update();
        this->render();
    }

   
}
