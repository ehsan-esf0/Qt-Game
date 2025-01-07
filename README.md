![image](https://github.com/user-attachments/assets/08c8f2f3-72dd-4567-8474-ee548ac1f7b4)![image](https://github.com/user-attachments/assets/84fd2217-2684-4964-9a19-e0f402ece220)🛩️ This is a greedy game where you have to hit the enemy planes as much as you can to get more points 🛩️

☠️ If 3 planes leave the map, the game ends and you have to try again ☠️

Game defense system 
The game has two types of defense system, shooter and bomb 💣

Shooters: There are four types :D
![T](https://github.com/user-attachments/assets/26be98a2-5308-4561-932f-eb100618ef12)

1️⃣A shooter that fires at the enemy that is ahead of all others. This shooter is defined in the turret_q8 class.

2️⃣The shooter that shoots at the last enemy, the one that is behind everyone, this shooter is defined in the turret_q8f class.

3️⃣A shooter that shoots enemies randomly, this shooter is defined in the turret_q8r class.

4️⃣A shooter that fires at the enemy that has the most health. This shooter is defined in the turret_q8m class.

Bomb: There are two types :D

1️⃣Bomb: This bomb destroys enemies in its range, the definition of bomb is in bomb class.

2️⃣Ice Bomb: This bomb slows down enemies in its range. It is defined in the Ice Bomb class.

⭕All of these appear randomly in a box on the side of the page, this is done by a function in the gamepage class, and by selecting them they can be placed on the game map⭕

⚒️Defense systems need iron to be placed on the map, which increases with time in the game. This system is written in the main class of the gamepage.⚒️




