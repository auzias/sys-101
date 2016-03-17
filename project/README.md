## Zombie

Zombiland Projet SYS

## Compiling

make

The make command will compile the zombie apocalipse program and the three weapons programs

These executables will be available in the ./bin/ directory


## Zombie apocalipse

To launch the apocalipse, run

./bin/MaitreZombie N

With N being the number of initial zombies to spawn


## Weapons

To use a weapon, run

./bin/WEAPON PID

With WEAPON being eiher knife, handgun or shotgun
With PID being the PID of the process to attack

## Zombie vulnerabilities

Zombies with PID of 0 mod 3 are vulnerable to handguns
Zombies with PID of 1 mod 3 are vulnerable to knives
Zombies with PID of 2 mod 3 are vulnerable to shotuns


## How to kill a zombie

To kill a zombie, a survivor must kill the direct parent process of a zombie process
Killing ancestors is cheating
Killing the un-dead directly is impossible


