🛩️ This is a greedy game where you have to hit the enemy planes as much as you can to get more points 🛩️

☠️ If 3 planes leave the map, the game ends and you have to try again ☠️


![Game](https://github.com/user-attachments/assets/ce91f498-aebb-4899-bcc9-9ccbe5ff4924)

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


![card4](https://github.com/user-attachments/assets/0e252bcb-7a91-4bb8-91a9-41e2cd7cc212)
![card5](https://github.com/user-attachments/assets/868e720a-0382-42cf-9252-a517d50190a2)


1️⃣Bomb: This bomb destroys enemies in its range, the definition of bomb is in bomb class.

2️⃣Ice Bomb: This bomb slows down enemies in its range. It is defined in the Ice Bomb class.

⭕All of these appear randomly in a box on the side of the page, this is done by a function in the gamepage class, and by selecting them they can be placed on the game map⭕

⚒️Defense systems need iron to be placed on the map, which increases with time in the game. This system is written in the main class of the gamepage.⚒️

![iron](https://github.com/user-attachments/assets/b3e835f2-a20d-4d57-a344-f7532fe222dd)

Enemies of the game : 
Normal enemies have two types
These two enemies differ in speed and health


![enimi](https://github.com/user-attachments/assets/1fe9c68f-2951-4de2-884e-0bbfa5dddcf5) 
![enimi1](https://github.com/user-attachments/assets/7321bbb4-3ada-490b-9edf-606bc8ede869)

Game bosses : 
1️⃣TowerDisabler disables the agents of this boss and keeps it inactive until it dies.

2️⃣towerdestroyer This boss destroys game agents.

3️⃣bombdisabler This boss neutralizes any bomb it sees in its path.

The classes in which the bosses are defined are the special names of the bosses themselves

![enimi3](https://github.com/user-attachments/assets/523057a2-4694-4e06-b017-fe23c5de6281)
![enimi4](https://github.com/user-attachments/assets/7cb7d7fd-5cf2-47c4-a41e-022c79c95058)
![enimi2](https://github.com/user-attachments/assets/51d350cf-20f7-4886-95e0-c5d1e3408582)



