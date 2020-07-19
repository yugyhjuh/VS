#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string inventory[10];

void addtoinv(string x)
{
	int i = 1;
	while (true)
	{
		if (inventory[i] == "")
		{
			inventory[i] = x;
			break;
		}
		else
		{
			i = i + 1;
			if (i >= 10)
			{
				cout << "Your inventory is full!" << endl;
				break;
			}
		}
	}
	return;
}

void inv()
{
	int i = 1;
	while (i < 10)
	{
		cout << "Slot " << i << ": " << inventory[i] << endl;
		i = i + 1;
	}
	return;
}

void main()
{
	string name;
	string weapon = "";
	string action = "";
	int playerhealth = 100;
	int enemyhealth = 100;
	cout << "Greetings warrior, what is your name?" << endl;
	cin >> name;
	cout << "Welcome, " << name << "!" << endl;

	while (action != "end")
	{
		while ((weapon != "sword") && (weapon != "crossbow"))
		{
			cout << "Select a weapon: sword or bow" << endl;
			cin >> weapon;
			if (weapon == "sword")
			{
				addtoinv(weapon);
				cout << "You have chosen the sword!" << endl;
				cout << "Would you like to test it out?" << endl;
			}
			else if (weapon == "bow")
			{
				addtoinv(weapon);
				cout << "You have chosen the bow!" << endl;
				cout << "Would you like to test it out?" << endl;
			}
		}
		cin >> action;

		if (action == "CheckInventory")
		{
			inv();
		}
		//troll item
		else if (action == "AddSecretWeapon")
		{
			string name = "A lightstick has been added to your inventory. Yes, a useless glowing lightstick.";
			int x = 0;
			while (name[x] != '\0')
			{
				cout << name[x];
				Sleep(50);
				x++;
				if (name[x] != ' ' && name[x] != '\n')
					//tone,speed(?)
					Beep(600, 50);
			}
			addtoinv("lightstick");
		}
		else if (action == "no")
		{
			enemyhealth = 100;
			cout << "Confident, eh? Let's see how you do against our pupil!" << endl;
			enemyhealth = 100;
			cout << "You have entered the training grounds. You will now test your weapon against the robot dummy." << endl;
			while (playerhealth > 0 && enemyhealth > 0)
			{
				cout << "--------------" << endl;
				cout << "Player Health: " << playerhealth << endl;
				cout << "Enemy Health: " << enemyhealth << endl;
				cout << "--------------" << endl;
				action = "";
				while (action != "attack" && action != "defend")
				{
					cout << "Choose: attack or defend" << endl;
					cin >> action;
				}
				if (action == "attack")
				{
					int playerAttackDamage = 0;
					if (inventory[0] == "sword")
					{
						playerAttackDamage = rand() % 35 + 5;
						cout << "You have dealt " << playerAttackDamage << " damage!" << endl;
						enemyhealth -= playerAttackDamage;
					}
					else
					{
						playerAttackDamage = rand() % 20 + 5;
						cout << "You have dealt " << playerAttackDamage << " damage!" << endl;
						enemyhealth -= playerAttackDamage;
					}
					int enemyAttackDamage = rand() % 40;
					cout << "Eenmy have dealt " << enemyAttackDamage << " damage!" << endl;
					playerhealth -= enemyAttackDamage;
				}
				else if (action == "defend")
				{
					int enemyAttackDamage = rand() % 3;
					cout << "Enemy have dealt " << enemyAttackDamage << " damage!" << endl;
					playerhealth -= enemyAttackDamage;
				}
			}
			if (enemyhealth <= 0)
			{
				cout << "Impressive! Your journey begins here, warrior." << endl;
			}
			else if (playerhealth <= 0)
			{
				cout << "Your training is about to begin here on out so prepare to give it your best, warrior!" << endl;
			}
		}
		else if (action == "yes")
		{
			enemyhealth = 100;
			cout << "You have entered the training grounds. You will now test your weapon against the robot dummy." << endl;
			while (playerhealth > 0 && enemyhealth > 0)
			{
				cout << "--------------" << endl;
				cout << "Player Health: " << playerhealth << endl;
				cout << "Enemy Health: " << enemyhealth << endl;
				cout << "--------------" << endl;
				action = "";
				while (action != "attack" && action != "defend")
				{
					cout << "Choose: attack or defend" << endl;
					cin >> action;
				}
				if (action == "attack")
				{
					int playerAttackDamage = 0;
					if (inventory[0] == "sword")
					{
						playerAttackDamage = rand() % 43 + 1;
						cout << "You have dealt " << playerAttackDamage << " damage!" << endl;
						enemyhealth -= playerAttackDamage;
					}
					else
					{
						playerAttackDamage = rand() % 25 + 5;
						cout << "You have dealt " << playerAttackDamage << " damage!" << endl;
						enemyhealth -= playerAttackDamage;
					}
					int enemyAttackDamage = rand() % 25;
					cout << "Enemy have dealt " << enemyAttackDamage << " damage!" << endl;
					playerhealth -= enemyAttackDamage;
				}
				else if (action == "defend")
				{
					int enemyAttackDamage = rand() % 5;
					cout << "Eenmy have dealt " << enemyAttackDamage << " damage!" << endl;
					playerhealth -= enemyAttackDamage;
				}
			}
			if (enemyhealth <= 0)
			{
				cout << "The weapon's nice eh? Continue to train hard and become you'll become mighty warrior one day!" << endl;
			}
			else if (playerhealth <= 0)
			{
				cout << "How did you lose against a robot dummy? You are unworthy to be a warrior!" << endl;
			}
		}
	}

	return;
}
