#include "RPG.h"
#include <cstdlib>
#include <time.h>
#include <cstring>

Weapon::Weapon(int damage, double criticalStrike)
{
  this->damage = damage;
  this->criticalStrike = criticalStrike;
}

int Weapon::WeaponDamage()
{
  srand(time(NULL));
  if((rand() % 100 + 1) < criticalStrike * 100)
    return 2 * damage;
  else
    return damage;
}

Player::Player(const char* name, int health, Weapon weapon, int level)
{
  strcpy(this->name, name);
  this->health = health;
  this->weapon = weapon;
  this->level = level;
}

int Player::getHealth() const
{
  return health;
}

void Player::setHealth(int health)
{
  this->health = health;
}

void Player::LevelUp()
{
  level++;
  health += 2 * level;
}

void Player::Attack(Player& opponent)
{
  opponent.setHealth(opponent.getHealth() - weapon.WeaponDamage());

  if(opponent.getHealth() <= 0)
  {
    opponent.setHealth(0);
    LevelUp();
  }
}

bool Player::Alive()
{
  return health > 0;
}

Battleground::Battleground()
{
  for(int i = 0; i < MAX_TEAM_SIZE; i++)
  {
    *factionOne[i] = Player();
    *factionTwo[i] = Player();
  }

  playersInFactionOne = MAX_TEAM_SIZE;
  playersInFactionTwo = MAX_TEAM_SIZE;
}

Battleground::Battleground(Player* team1, Player* team2)
{
  for(int i = 0; i < MAX_TEAM_SIZE; i++)
  {
    factionOne[i] = &(team1[i]);
    factionTwo[i] = &(team2[i]);
  }

  playersInFactionOne = MAX_TEAM_SIZE;
  playersInFactionTwo = MAX_TEAM_SIZE;
}

void Battleground::Fight()
{
  int i = 0, j = 0;
  while(playersInFactionOne != 0 && playersInFactionTwo != 0)
  {
    // factionOne's turn:
    factionOne[i]->Attack(*(factionTwo[j]));
    if(!factionTwo[j]->Alive())
      playersInFactionTwo--;

    if(playersInFactionTwo == 0)
      break;

    while(!factionTwo[j]->Alive())
    {
      if(j >= MAX_TEAM_SIZE)
        j = 0;
      else
        j++;
    }


    // factionTwo's turn:
    factionTwo[j]->Attack(*(factionOne[i]));
    if(!factionOne[i]->Alive())
      playersInFactionOne--;

    if(playersInFactionOne == 0)
      break;

    while(!factionOne[i]->Alive())
    {
      if(i >= MAX_TEAM_SIZE)
        i = 0;
      else
        i++;
     }
  }

  Reward();
}

void Battleground::Reward()
{
  if(playersInFactionOne == 0)
  {
    for(int i = 0; i < MAX_TEAM_SIZE; i++)
    {
      if(factionTwo[i]->Alive())
      {
        factionTwo[i]->LevelUp();
        factionTwo[i]->LevelUp();
      }
    }
  }
  else if(playersInFactionTwo == 0)
  {
    for(int i = 0; i < MAX_TEAM_SIZE; i++)
    {
      if(factionOne[i]->Alive())
      {
        factionOne[i]->LevelUp();
        factionOne[i]->LevelUp();
      }
    }
  }
  else
    return;
}

int main()
{
  Weapon w1;
  Player p1("Warrior1", 100, w1, 1), p2("Warrior2", 80, w1, 1), p3("Warrior3", 90, w1, 2);

  Weapon w2(40, 0.35);
  Player p4("Fighter1", 120, w2, 1), p5("Fighter2", 105, w2, 1), p6("Fighter3", 70, w2, 3);

  Player team1[MAX_TEAM_SIZE] = {p1, p2, p3};
  Player team2[MAX_TEAM_SIZE] = {p4, p5, p6};

  Battleground battlefield(team1, team2);
  battlefield.Fight();
}
