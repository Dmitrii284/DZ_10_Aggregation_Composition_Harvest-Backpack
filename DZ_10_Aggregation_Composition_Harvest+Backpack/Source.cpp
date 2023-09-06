/*
Наследование - Композиция, Агрегация
Задание на композицию
Для реализованных семейств классов Растений и Плодов создать классы - контейнеры:
Локация:
при создании создаёт внутри себя от 30 до 100 различных объёктов
наследников растений хранящихся в одной коллекции;
позволяет пользователю узнавать скольно ростений есть на локации
позволяет пользователю перебрать все растения для сбора с них плодов
Рюкзак:
позволяет хранить в себе любых наследников класса Плоды
позволяет пользователю перебрать своё содержимое
при необходимости должен быть механизм изъятия любого плода из рюкзака
В функции мэйн продемонстрируйте возможность сбора пользователем всех плодов со всех
деревьев с локации и последующую работу с рюкзаком в виде сообщения об общем
количестве плодов и их суммарном весе. Показать что если выкинуть из рюкзака все плоды
какого либо типа результат предыдущего алгоритма изменяется.
*/


#include<iostream>
#include<string>
#include<vector>
#include<conio.h>

class Apple;
class AppleTree;
class Harvest;
class Backpack;

class Plant
{
private:
	std::string _nameTree;
	float _heigthTree;
	std::string _type;
	std::string _color;
	int _numFruits;
public:	
	int fruitCount{ 0 };
	int treeCount{ 0 };
	Plant(const std::string& nameTree, float heigthTree,const std::string& type,const std::string& color, int numFruits)
		: _nameTree{ nameTree }, _heigthTree{ heigthTree }, _type{ type }, _color{ color }, _numFruits{ numFruits } {
		std::cout << this << " Plant object created" << std::endl;		
	}
	virtual void ShowPlants() const {
		std::cout << "NameTree: " << _nameTree << std::endl;
		std::cout << "Heigth Tree: " << _heigthTree << std::endl;
		std::cout << "Tree type: " << _type << std::endl; // Большойе Маленькое Среднее
		std::cout << "Color: " << _color << std::endl;
		std::cout << "Numbers of Fruits: " << _numFruits << std::endl;
	}

	virtual ~Plant() {
		std::cout<< this << " Destroit Platts" << std::endl;
	}

	virtual Harvest* harvestFruit() = 0;
	virtual std::shared_ptr <Harvest> harvestFruit1() = 0;
};

class Harvest
{
private:
	std::string _name;
	float _weight;
	std::string _colorHar;
public:
	Harvest(std::string& name, float weight, std::string& colorHar)
		: _name{name}, _weight{weight}, _colorHar{colorHar}{
		std::cout << this << " Harvest object created" << std::endl;		 
	}
	virtual void ShowHarvest() const {
		std::cout << "Fruit name: " << _name << std::endl;
		std::cout << "Heigth Tree: " << _weight << std::endl;
		std::cout << "Color: " << _colorHar << std::endl;
	}

	virtual ~Harvest() {
		std::cout << this << " Destroit Harvest" << std::endl;
	}
};

class Cherry : public Harvest
{
public:
	Cherry(std::string name, float weight, std::string colorHar)
		: Harvest{ name, weight, colorHar } {
		std::cout << this << " Cherry object created" << std::endl;
	}

	~Cherry() override {
		std::cout << this << " Destroit Cherry" << std::endl;
	}
};

class Apple : public Harvest
{
public:
	Apple(std::string name, float weight, std::string colorHar)
		: Harvest{ name, weight, colorHar } {
		std::cout << this << " Apple object cteated" << std::endl;
	}
	/*void ShowHarvest()const override {
		Harvest::ShowHarvest();
		std::cout << " Apple count: " << std::endl;
	}*/

	~Apple() override {
		std::cout << this << " Destroit Apple" << std::endl;
	}
};

class Pear : public Harvest
{
public:
	Pear(std::string name, float weight, std::string colorHar)
		: Harvest{ name, weight, colorHar } {
		std::cout << this << " Pear object created" << std::endl;
	}

	/*void ShowHarvest()const override {
		Harvest::ShowHarvest();
		std::cout << " Pear count: " << std::endl;
	}*/

	~Pear() override {
		std::cout << this << " Destroit Pear" << std::endl;
	}
};

class CherryTree : public Plant
{
public:
	CherryTree(const std::string nameTree, float heigthTree, const std::string type, const std::string color, int numFruits)
		: Plant{ nameTree, heigthTree, type, color, numFruits } {
		std::cout << this << " CherryTree object created" << std::endl;
	}

	void ShowPlants()const override {
		Plant::ShowPlants();
		std::cout << "Fruit count: " << fruitCount << std::endl;
	}

	~CherryTree() override {
		std::cout << this << " Destroit CherryTree" << std::endl;
	}

	Harvest* harvestFruit() override {
		--fruitCount;
		return new Cherry("Cherry", 5.2, "Bard");		
	}

	std::shared_ptr<Harvest>harvestFruit1() {
		--fruitCount;
		return std::make_shared<Cherry>("Cherry", 2.5, "Red-Yellow");
	}

};

class AppleTree : public Plant
{
public:
	AppleTree(const std::string nameTree, float heigthTree, const std::string type, const std::string color, int numFruits)
		: Plant(nameTree, heigthTree, type, color, numFruits) {
		std::cout << this << " AppleTree object created" << std::endl;
	}

	void ShowPlants() const override {
		Plant::ShowPlants();
		std::cout << "Fruit count: " << fruitCount << std::endl;
	}

	~AppleTree() override {
		std::cout << this << " Destroit AppleTee" << std::endl;
	}
	Harvest* harvestFruit() override {
		--fruitCount;
		return new Apple("Apple", 20.32, "Green");
	}

	std::shared_ptr<Harvest> harvestFruit1() override {
		return std::make_shared<Apple>("Apple", 10.2, "Red - Green");
	}	
};

class PearTree : public Plant
{
public:
	PearTree(const std::string nameTree, float heigthTree, const std::string type, const std::string color, int numFruits)
		: Plant(nameTree, heigthTree, type, color, numFruits) {
		std::cout << this << " PearTree object created" << std::endl;
	}

	void ShowPlants() const override {
		Plant::ShowPlants();
		std::cout << "Fruit count: " << fruitCount << std::endl;
	}

	~PearTree() override {
		std::cout << this << " Destroid PearTree" << std::endl;
	}

	Harvest* harvestFruit() override {
		--fruitCount;
		return new Pear("Pear", 18.8, "Yellow");
	}
	std::shared_ptr<Harvest> harvestFruit1()override {
		--fruitCount;
		return std::make_shared<Pear>("Pear", 30, "Yellow - White");
	}
};

class Backpack
{
	/*_backpack представляет собой вектор, содержащий умные указатели на объекты Harvest.*/
private:
	std::vector<std::shared_ptr<Harvest>> _backpack;
public:
	void PushBackpack(const std::shared_ptr<Harvest>& fruit) {
		_backpack.push_back(fruit);
	}
	void Show() {
		std::vector<std::shared_ptr<Harvest>>::iterator fruit = _backpack.begin();
		std::vector<std::shared_ptr<Harvest>>::iterator deleted = _backpack.end();

		char action{ '0' };
		int count{ 0 };

		while (action != '4')
		{
			system("cls");
			(*fruit)->ShowHarvest();
			std::cout << "\nNumber of fruits: " << _backpack.size() << std::endl;
			std::cout << "\nFruit " << count + 1 << '/' << _backpack.size() << ' \n\n' << std::endl;
			std::cout << "'1' - previous fruit in the Backpack" << std::endl;
			std::cout << "'2' - next fruit in the backpack" << std::endl;
			std::cout << "'3' - take the fruit" << std::endl;
			std::cout << "'4' - exit" << std::endl;

			action = _getch();

			switch (action)
			{
			case '1':
				if (fruit != _backpack.begin())
				{
					--fruit;
					count--;				
				}
				break;
			case'2':
				if (fruit != _backpack.end())
				{
					++fruit;
					count++;
				}
				break;
			case'3':
				deleted = fruit;
				break;
			default:
				break;
			}
		}
		if (deleted != _backpack.end())
			_backpack.erase(deleted);
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");

	PearTree tree("PearTree1", 3, "Midle", "Dark Green", 300);
	tree.ShowPlants();
	Harvest* pear = tree.harvestFruit();
	pear->ShowHarvest();

	AppleTree tree1("Apple Tree", 2.5, "Averege", "Green", 500);
	tree1.ShowPlants();
	Harvest* apple = tree1.harvestFruit();
	apple->ShowHarvest();

	CherryTree tree2("Cherry Tree", 1.2, "Low", "Blake - Green", 1900);
	tree2.ShowPlants();
	Harvest* cherry = tree2.harvestFruit();
	cherry->ShowHarvest();


	Backpack backPack;
	std::shared_ptr<Pear> pear0 = std::make_shared<Pear>("Pear", 130.3, "Yellow");
	std::shared_ptr<Pear> pear1 = std::make_shared<Pear>("Pear", 230.5, "Yellow -Red");
	std::shared_ptr<Pear> pear2 = std::make_shared<Pear>("Pear", 100.8, "Yellow - Green");
	backPack.PushBackpack(pear0);
	backPack.PushBackpack(pear1);
	backPack.PushBackpack(pear2);

	std::shared_ptr<Apple>apple0 = std::make_shared<Apple>("Apple", 180.1, "Yellow - Green");
	std::shared_ptr<Apple>apple1 = std::make_shared<Apple>("Apple", 110.6, "Red - Green");
	std::shared_ptr<Apple>apple2 = std::make_shared<Apple>("Apple", 130.5, "Yellow -Red");
	std::shared_ptr<Apple>apple3 = std::make_shared<Apple>("Apple", 189.3, "Green");
	backPack.PushBackpack(apple0);
	backPack.PushBackpack(apple1);
	backPack.PushBackpack(apple2);
	backPack.PushBackpack(apple3);

	std::shared_ptr<Cherry>cherry0 = std::make_shared<Cherry>("Velvet- Cherry", 20.1, "Blake - Green");
	std::shared_ptr<Cherry>cherry1 = std::make_shared<Cherry>("Cherry", 10.6, "Blake - Red");
	std::shared_ptr<Cherry>cherry2 = std::make_shared<Cherry>("Cherry", 30.2, "Yellow -Blake");
	std::shared_ptr<Cherry>cherry3 = std::make_shared<Cherry>("Cherry - Long", 89.3, "Red");
	backPack.PushBackpack(cherry0);
	backPack.PushBackpack(cherry1);
	backPack.PushBackpack(cherry2);
	backPack.PushBackpack(cherry3);

	backPack.Show();

	delete pear;
	delete apple;
	delete cherry;

	return 0;
}

