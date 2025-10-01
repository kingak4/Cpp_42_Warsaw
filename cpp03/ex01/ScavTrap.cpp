#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	damage = 20;
	std::cout << "ScavTrap "<< name << " constructed" <<std::endl;
}
ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->damage = other.damage;
	std::cout << "ScavTrap "<< name << " copied" <<std::endl;
}
ScavTrap& ScavTrap::operator=(ScavTrap &other)
{
	ClapTrap::operator=(other);
	return(*this);
}
ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap "<< name << " destroyed" <<std::endl;
}
void	ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		std::cout << "ScavTrap " << name << " doesn't have enough energy or hitpoints to attack!" << std::endl;
	else
	{
		this->energyPoints -= 1;
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
	}
}
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is guarding the gate!" << std::endl;
}
