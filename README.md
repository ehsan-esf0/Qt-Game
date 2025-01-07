🛩️ This is a greedy game where you have to hit the enemy planes as much as you can to get more points 🛩️

☠️ If 3 planes leave the map, the game ends and you have to try again ☠️

Game defense system 
The game has two types of defense system, shooter and bomb 💣

Shooters: There are four types :D


![card1](https://github.com/user-attachments/assets/032ab31a-071b-414d-a6dd-cfdea21f82b4)
![card2](https://github.com/user-attachments/assets/55e43697-f40b-458d-83c4-cf0a41a63094)
![card3](https://github.com/user-attachments/assets/ad96adc7-c9e8-4069-9554-3dc39b7669b9)
![card6](https://github.com/user-attachments/assets/5c955d03-c705-49dc-be35-23aa5704d36c)


1️⃣A shooter that fires at the enemy that is ahead of all others. This shooter is defined in the turret_q8 class.


2️⃣The shooter that shoots at the last enemy, the one that is behind everyone, this shooter is defined in the turret_q8f class.

3️⃣A shooter that shoots enemies randomly, this shooter is defined in the turret_q8r class.

4️⃣A shooter that fires at the enemy that has the most health. This shooter is defined in the turret_q8m class.

Bomb: There are two types :D

1️⃣Bomb: This bomb destroys enemies in its range, the definition of bomb is in bomb class.

2️⃣Ice Bomb: This bomb slows down enemies in its range. It is defined in the Ice Bomb class.

⭕All of these appear randomly in a box on the side of the page, this is done by a function in the gamepage class, and by selecting them they can be placed on the game map⭕

⚒️Defense systems need iron to be placed on the map, which increases with time in the game. This system is written in the main class of the gamepage.⚒️




