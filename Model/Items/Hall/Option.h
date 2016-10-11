#pragma once
#include  <string>
#include <vector>
#include <map>
#include <Model/Constants.h>
#include <Model/Items/Hall/Item.h>
#include <Model/Communication/Talk.h>

typedef nsOption::nsMenu::nsBeverage::ID eBeverage;
typedef nsOption::nsMenu::nsSnack::ID eSnack;
typedef nsOption::nsFurniture::ID eFurniture;
typedef nsOption::nsEquipment::ID eEquipment;

using namespace std;

namespace EP {
	namespace MD {
		/**
		 * Опция
		 */
        class Option:public Talk
		{

		public:
            Option(Log* inLog);
			Option(const Option& rhs);
			Option& operator=(const Option& rhs);
			virtual ~Option();

            map<unsigned,Item>* Furniture() { return &vFurniture; }
            const map<unsigned,Item>* Furniture() const { return &vFurniture; }

            map<unsigned,Item>* Equipment() { return &vEquipment; }
            const map<unsigned,Item>* Equipment() const { return &vEquipment; }

            map<unsigned,Item>* Beverage() { return &vBeverage; }
            const map<unsigned,Item>* Beverage() const { return &vBeverage; }

            map<unsigned,Item>* Snack() { return &vSnack; }
            const map<unsigned,Item>* Snack() const { return &vSnack; }

            Item* FurnitureByID(unsigned inID){ return &vFurniture.at(inID); }
            Item* EquipmentByID(unsigned inID){ return &vEquipment.at(inID); }
            Item* BeverageByID(unsigned inID){ return &vBeverage.at(inID); }
            Item* SnackByID(unsigned inID){ return &vSnack.at(inID); }

            bool getVideography() const { return vVideography; }
            void setVideography(bool inVideography)  {  vVideography=inVideography; }

            string View(nRole::ID inRole);

        protected:
            void BeverageSetup();
            void SnackSetup();
            void FurnitureSetup();
            void EquipmentSetup();
            string getItems(map<unsigned, Item> *inOptions);
        private:
            static unsigned vID;

            map<unsigned,Item> vBeverage, vSnack;
            map<unsigned,Item> vFurniture;
            map<unsigned, Item> vEquipment;

			bool vVideography;

		};
	}
}
