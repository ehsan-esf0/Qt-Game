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

Agent upgrade system :
In the bar on the right side of the game screen, the level of the agent is shown, which increases the power of the agents by upgrading them. Each agent has 5 levels


![card1-lvl5](https://github.com/user-attachments/assets/cf0f6fdd-74fa-46dd-9cd8-0f82dde176d6)
![card1-lvl4](https://github.com/user-attachments/assets/54f02f10-275a-46a7-a976-8e81626c913c)
![card1-lvl3](https://github.com/user-attachments/assets/cd071ad6-1066-48bf-bf97-1951ba14fe66)
![card1-lvl2](https://github.com/user-attachments/assets/71b558fc-1ce0-4f98-bf09-639eddddfa85)
![card1-lvl1](https://github.com/user-attachments/assets/9456d07c-28ff-43d5-85a8-867166ff4fa9)

By improving the power, the shape of the bullets will change

![bullet5](https://github.com/user-attachments/assets/00d3c6de-529f-41b8-bedd-b9d9df74c5a8)
![bullet4](https://github.com/user-attachments/assets/ba6e65ef-4be9-4562-929a-f03b470a873c)
![bullet3](https://github.com/user-attachments/assets/ecdc7ea1-0d96-4426-be32-1013793d3cdc)
![bullet2](https://github.com/user-attachments/assets/b96397fa-b5f4-425d-901d-aa372f804853)

Agent mutation system :
If you drag two agents of the same level on top of each other, the level will increase and the shooting speed will increase 
(there is a button below the agents, you need to select the agent and click on that button)


![T](https://github.com/user-attachments/assets/0dfe6766-37db-4f1f-b234-7f0462056b3a)
![T-2](https://github.com/user-attachments/assets/97dbe90f-2c50-4b51-b842-41630e9d4704)
![T-3](https://github.com/user-attachments/assets/00e22a62-5b20-4d29-bc0e-b276817688da)
![T-5](https://github.com/user-attachments/assets/2b9dd789-f33e-4e3d-8217-0ba5015c6d8d)
![T-4](https://github.com/user-attachments/assets/761fa16e-ff02-4c99-8949-ca0a01239425)



