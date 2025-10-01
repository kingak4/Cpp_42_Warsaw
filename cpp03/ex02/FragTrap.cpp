#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	damage = 30;
	std::cout << "ScavTrap "<< name << " constructed" <<std::endl;
}
FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->damage = other.damage;
	std::cout << "FragTrap "<< name << " copied" <<std::endl;
}
FragTrap& FragTrap::operator=(FragTrap &other)
{
	ClapTrap::operator=(other);
	return(*this);
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< name << " destroyed" <<std::endl;
}
void	FragTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		std::cout << "FragTrap " << name << " doesn't have enough energy or hitpoints to attack!" << std::endl;
	else
	{
		this->energyPoints -= 1;
		std::cout << "FragTrap " << name << " attacks " << target << " causing " << damage << " points of damage!" << std::endl;
	}
}
void	FragTrap::highFivesGuys(void)
{
	std::cout << "High five, guys!" << std::endl;
}
