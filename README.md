# My C RPG
![build with C](https://img.shields.io/badge/Build%20with-C-green) ![version](https://img.shields.io/badge/Version-1.0-brightgreen)  		
![for linux's users](https://img.shields.io/badge/made%20for-Linux-orange) ![for OSX's users](https://img.shields.io/badge/made%20for-OSX-blue)

This RPG is made in C with the CSFML.
It's a basic game with a quest, combat and progression system.

The goal of this game is to reach the level 10 and defeat the final boss.
Be aware, if you loose more than 3 matchs that's GameOver.

## How to start
We will see how to manage for get and launch the game.

#### Get the repo
    git clone https://github.com/Rgascoin/my_rpg.git
    
#### Installation
Once you get the repo, the only next step is to use the makefile for building it.

    make re
    
#### Play
Just launch the new binary file that you just created.

    ./my_rpg
    
## Game features
Our main goal in this project was to implement as much possible typical RPG's feature in the game.

### Map
You can move freely in the city, interact with some PNJ and Buildings like the arena or the rest room.

![map preview](https://s6.gifyu.com/images/ezgif.com-video-to-gif-3f027a03c906ba97c.gif)

### Combat system
In the arena you can fight against many enemies, there are randomly generate based on your level. with this, them stats are matching with your owns and the game never feel too easy or too hard.

![Fighting gif](https://s6.gifyu.com/images/ezgif.com-video-to-gif78c13f7357f3c555.md.gif)

You can manage different types of attack, all are listed in your inventory visible by pressing the `i` key while you're in the city.

### Leveling System
By grinding at the arena, you get experience point, that allow you too level-up once you get enough.

![Level up gif](https://s6.gifyu.com/images/ezgif.com-video-to-gif-1ec408be78f2a112e-1.gif)

Their's 3 different statistics type as :

 - Strength
 - Agility
 - Resistance

All those stats have different behavior in the game that's helping you to reach it's end.

### Questing
Their's a PNJ in the North-West of the city who can gives you some quests.
Once you finished a quest go back to her and claim your reward.

![Quest gif](https://s6.gifyu.com/images/ezgif.com-video-to-gif-20a01cd32636a8e12.gif)

## Technical features

### C Graphical Engine
To build this game we past a lot of time to build a cool game engine.
You can find it in game files locate at : `/lib/my_cgraph`

If you want more information on it feel free to check this [link](https://github.com/MrZalTy/my_cgraph)

### Configuration Files
To place assets on scene for building this game, we created some specials files named `configuration.rll`.
You can find them in `/config` and all the code behind them is located in `/lib/my_config`.

This system allow us to load a tones of assets in the game, very quickly with a really small amount of code.

## Authors

 - Roman Gascoin - Me
 - Lorenzo Carneli - [MrZalty](https://github.com/MrZalTy)
 - Luca George-François - [PixelFault](https://github.com/Pixelfault-tech)
