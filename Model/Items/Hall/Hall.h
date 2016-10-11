#pragma  once
#include  <string>
#include <sstream>

#include <Model/Constants.h>
#include <Model/Communication/Talk.h>


using namespace std;

namespace EP {
    namespace MD {

		/**
		 * conference hall
		 * Конференц-Зал
		 */
        class Hall: public Talk
		{

		public:
			Hall(string inName,
				unsigned int inCapacity,
				unsigned int inSeats,
				unsigned int inTables,
				unsigned int inTribune,
				bool inHasAirConditioning,
				bool inHasChalkBoard,
				bool inHasProjector,
				bool inHasProjectorScreen,
				unsigned int inHeight,
				unsigned int inLength,
                unsigned int inWidth,
                Log* inLog);
			virtual ~Hall();

            friend bool operator==(const Hall& lhs, const Hall& rhs);

			unsigned int getCapacity() const;
			unsigned int getSeats() const;
			void setSeats(unsigned int inSeats);
			bool HasChalkBoard() const;
			void setHasChalkBoard(bool valB);
            string View(nRole::ID inRoleId) const;
			void setTables(unsigned int inTables);
            unsigned getIndex() const;

		private:
			static unsigned vHallCounter;
            unsigned vIndex{0};
			string vName;
			/**
			 * Вместимость
			 */
            unsigned int vCapacity{0};
            unsigned int vSeats{0};
            unsigned int vTables{0};
            unsigned int vTribune{0};
            bool vHasAirConditioning{false};
            bool vHasChalkBoard{false};
            bool vHasProjector{false};
            bool vHasProjectorScreen{false};
            unsigned int vHeight{0};
            unsigned int vLength{0};
            unsigned int vWidth{0};
			
		};

    inline bool operator==(const Hall& lhs, const Hall& rhs)
    {
        return lhs.vIndex == rhs.vIndex;
    }

	}
}
