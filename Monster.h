#pragma once
class Monster {
public:
	Monster() = default;
	Monster(const char* name, int Attack, int Defenses, int age) {
		memcpy(this->Name, name, strlen(name) + 1);
		this->Attack = Attack;
		this->Defenses = Defenses;
		this->age = age;
	}

private:
	char Name[20];
	int Attack;
	int Defenses;
	int age;
};


