#include <iostream>
#pragma once
using namespace std;

const int DEFAULT_DAMAGE = 50;
const double DEFAULT_CRITICAL = 0.3;
const int NAME_LENGTH = 25;
const int DEFAULT_HEALTH = 100;
const int DEFAULT_LEVEL = 1;
const int MAX_TEAM_SIZE = 3;

class Weapon
{
  int damage;
  double criticalStrike;
public:
  Weapon(int damage = DEFAULT_DAMAGE, double criticalStrike = DEFAULT_CRITICAL);
  int WeaponDamage();
};

class Player
{
  char name[NAME_LENGTH];
  int health;
  Weapon weapon;
  int level;
public:
  Player(const char* name = "UnknownName", int health = DEFAULT_HEALTH, Weapon weapon = Weapon(), int level = DEFAULT_LEVEL);

  int getHealth() const;
  void setHealth(int health);

  void LevelUp();
  void Attack(Player& opponent);
  bool Alive();
};

class Battleground
{
  Player* factionOne[MAX_TEAM_SIZE];
  Player* factionTwo[MAX_TEAM_SIZE];
  int playersInFactionOne;
  int playersInFactionTwo;
public:
  Battleground();
  Battleground(Player* team1, Player* team2);
  void Fight();
  void Reward();
};
