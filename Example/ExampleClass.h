#pragma once
#include <iostream>
#include <string>
#include <sstream>

namespace lessonFirst
{
	class Organism
	{
	public:
		Organism(std::string name): name(name), age(0), mass(0) {};
		Organism(std::string name, int age, double mass) : name(name), age(age), mass(mass) {};
		~Organism() = default;

		
		void spentYear() { ++age; }
		std::string getName() const { return name;  }
		virtual std::string sayInfo() = 0;
	protected:
		int age;
		double mass;
	private:
		std::string name;
	};

	struct Sex
	{
		virtual std::string sexName() = 0;
	};

	struct Male : Sex
	{
		std::string sexName() override { return "male"; }
	};

	struct Female : Sex
	{
		std::string sexName() override { return "female"; }
	};

	class Animal : public Organism
	{
	public:
		Animal(std::string name) : Organism(name) {}
		Animal(std::string name, int age, double mass) : Organism(name, age, mass) {}
		~Animal() = default;

		std::string sayInfo() override
		{
			std::stringstream info;
			info << "Name: " << getName() << ", age:" << age << ", mass: " << mass;
			return info.str();
		}
	};



	template <typename SexInfo>
	class Human : public Organism
	{
	public:
		Human(std::string name, SexInfo sexInfo) : Organism(name), sex(sexInfo) {}
		Human(std::string name, int age, double mass, SexInfo sexInfo) : Organism(name, age, mass), sex(sexInfo) {}
		~Human() = default;

		std::string sayInfo() override
		{
			std::stringstream info;
			info << "Name: " << getName() << ", age:" << age << ", mass: " << mass << ", sex: " << sex.sexName();
			return info.str();
		}
	protected:
		SexInfo sex;
	};

	template <typename SexInfo>
	class SmartHuman : public Human<SexInfo>
	{
	public:
		SmartHuman(std::string name, SexInfo sexInfo) : Human<SexInfo>(name, sexInfo) {}
		SmartHuman(std::string name, int age, double mass, SexInfo sexInfo) : Human<SexInfo>(name, age, mass, sexInfo){}
		~SmartHuman() = default;

		friend std::ostream& operator << (std::ostream& out, SmartHuman& sH)
		{
			return out << sH.sayInfo();
		}
	};
}