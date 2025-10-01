#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damage = 0;
	std::cout << "ClapTrap "<< name << " constructed" <<std::endl;
}
ClapTrap::ClapTrap(ClapTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->damage = other.damage;
	std::cout << "ClapTrap "<< name << " copied" <<std::endl;
}
ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	if(this == &other)
		return(*this);
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->damage = other.damage;
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap "<< name << " destroyed" <<std::endl;
}
std::string	ClapTrap::getName(void)
{
	return(this->name);
}
void		ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		std::cout << "ClapTrap " << name << " doesn't have enough energy or hitpoints to attack!" << std::endl;
	else
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
	}
}
void 		ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << name << " takes " << amount << " points of damage!" << std::endl;	
	if (this->hitPoints <= 0)
		std::cout << "...and dies!" << std::endl;
}
void 		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		std::cout << "ClapTrap " << name << " doesn't have enough energy or hitpoints to heal!" << std::endl;
	else
	{
		this->energyPoints -= 1;
		this->hitPoints += amount;
		std::cout << name << " heals " << amount << " hit points!" << std::endl;
	}
}
