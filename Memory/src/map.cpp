#include "map.h"



////////////////////////////////////////////////////////////////////////////////
// METHODS

//DECLA


// Constructors
Map::Map() {
//getRandom en retirant les numéro pioché à chaque boucle 3 fois même temps (L'ENFER)////
	int hiddenNameArray[8]={0,1,2,3,4,5,6,7};
	int tileArray[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	int hiddenName=Utils::getRandom(0,7);
	int tile1=Utils::getRandom(0,15);
	int tile2=Utils::getRandom(0,15);

	for (int i=0; i<8; i++){
		//Répétion de getRandom jusqu'à trouver un indice qui n'a pas déjà été pris (pour hiddenName)
		while (hiddenNameArray[hiddenName]==99){
			hiddenName=Utils::getRandom(0,7);
		}
		//Répétion de getRandom jusqu'à trouver un indice qui n'a pas déjà été pris (pour tile 1 et tile 2 différents)
		while (tileArray[tile1]==99){
			tile1=Utils::getRandom(0,15);
			while (tileArray[tile2]==99||tileArray[tile2]==tile1){
				tile2=Utils::getRandom(0,15);
			}
		}
		//Attribution d'un nom caché aléatoire à 2 cases aléatoire jusqu'à remplir le tableau
		if (tile1==0)this->pTiles[0]=new Tile(hiddenName," 1-1  ",1,1);
		else if (tile1==1)this->pTiles[1]=new Tile(hiddenName," 1-2  ",1,2);
		else if (tile1==2)this->pTiles[2]=new Tile(hiddenName," 1-3  ",1,3);
		else if (tile1==3)this->pTiles[3]=new Tile(hiddenName," 1-4  ",1,4);
		else if (tile1==4)this->pTiles[4]=new Tile(hiddenName," 2-1  ",2,1);
		else if (tile1==5)this->pTiles[5]=new Tile(hiddenName," 2-2  ",2,2);
		else if (tile1==6)this->pTiles[6]=new Tile(hiddenName," 2-3  ",2,3);
		else if (tile1==7)this->pTiles[7]=new Tile(hiddenName," 2-4  ",2,4);
		else if (tile1==8)this->pTiles[8]=new Tile(hiddenName," 3-1  ",3,1);
		else if (tile1==9)this->pTiles[9]=new Tile(hiddenName," 3-2  ",3,2);
		else if (tile1==10)this->pTiles[10]=new Tile(hiddenName," 3-3  ",3,3);
		else if (tile1==11)this->pTiles[11]=new Tile(hiddenName," 3-4  ",3,4);
		else if (tile1==12)this->pTiles[12]=new Tile(hiddenName," 4-1  ",4,1);
		else if (tile1==13)this->pTiles[13]=new Tile(hiddenName," 4-2  ",4,2);
		else if (tile1==14)this->pTiles[14]=new Tile(hiddenName," 4-3  ",4,3);
		else if (tile1==15)this->pTiles[15]=new Tile(hiddenName," 4-4  ",4,4);
		if (tile2==0)this->pTiles[0]=new Tile(hiddenName," 1-1  ",1,1);
		else if (tile2==1)this->pTiles[1]=new Tile(hiddenName," 1-2  ",1,2);
		else if (tile2==2)this->pTiles[2]=new Tile(hiddenName," 1-3  ",1,3);
		else if (tile2==3)this->pTiles[3]=new Tile(hiddenName," 1-4  ",1,4);
		else if (tile2==4)this->pTiles[4]=new Tile(hiddenName," 2-1  ",2,1);
		else if (tile2==5)this->pTiles[5]=new Tile(hiddenName," 2-2  ",2,2);
		else if (tile2==6)this->pTiles[6]=new Tile(hiddenName," 2-3  ",2,3);
		else if (tile2==7)this->pTiles[7]=new Tile(hiddenName," 2-4  ",2,4);
		else if (tile2==8)this->pTiles[8]=new Tile(hiddenName," 3-1  ",3,1);
		else if (tile2==9)this->pTiles[9]=new Tile(hiddenName," 3-2  ",3,2);
		else if (tile2==10)this->pTiles[10]=new Tile(hiddenName," 3-3  ",3,3);
		else if (tile2==11)this->pTiles[11]=new Tile(hiddenName," 3-4  ",3,4);
		else if (tile2==12)this->pTiles[12]=new Tile(hiddenName," 4-1  ",4,1);
		else if (tile2==13)this->pTiles[13]=new Tile(hiddenName," 4-2  ",4,2);
		else if (tile2==14)this->pTiles[14]=new Tile(hiddenName," 4-3  ",4,3);
		else if (tile2==15)this->pTiles[15]=new Tile(hiddenName," 4-4  ",4,4);
		//Exclusion des cases déjà pioché
		hiddenNameArray[hiddenName]=99;
		tileArray[tile1]=99;
		tileArray[tile2]=99;
	}
}//Fin du constructeur :D


//DANS LA BOUCLE
	int Map::case1(){
	int posX=0;
	int posY=0;
	int value1=101;
		cout << "Case 1, Coordonnée X :";
		cin >> posX;
		cout << "Case 1, Coordonnée Y :";
		cin >> posY;
		//Si user fait nimp
		if (posX>4) posX=4;
		else if (posX<1) posX=1;
		if (posY>4) posY=4;
		else if (posY<1) posY=1;
		//
		for (int i=0; i<16; i++){
			if (this->pTiles[i]->getPosX()==posX && this->pTiles[i]->getPosY()==posY){
				if (this->pTiles[i]->isPaired==false){
					this->pTiles[i]->reveal();
					this->revealedName1=this->pTiles[i]->getHiddenName();
					value1 = i;
					//Definit comme étant choisi
					this->pTiles[i]->beChosen();
				//Si user choisit une case déjà apairé
				}else value1 = 98;
			}
		}
		return value1;
	}

	int Map::case2(){
	int posX=0;
	int posY=0;
	int value2=102;
		cout << "Case 2, Coordonnée X :";
		cin >> posX;
		cout << "Case 2, Coordonnée Y :";
		cin >> posY;
		//Si user fait nimp
		if (posX>4) posX=4;
		else if (posX<1) posX=1;
		if (posY>4) posY=4;
		else if (posY<1) posY=1;
		//
		for (int i=0; i<16; i++){
			if (this->pTiles[i]->getPosX()==posX && this->pTiles[i]->getPosY()==posY && this->pTiles[i]->isChosen == false){
				if (this->pTiles[i]->isPaired==false){
					this->pTiles[i]->reveal();
					this->revealedName2=this->pTiles[i]->getHiddenName();
					value2 = i;
					//Les cases ne sont plus choisis
					for(int i=0; i<16; i++){
						this->pTiles[i]->notChosenAnymore();
					}
					//Si user choisit une case déjà apairé
				}else value2 = 98;
				//Si user rechoisit la même case
			}else if(this->pTiles[i]->getPosX()==posX && this->pTiles[i]->getPosY()==posY && this->pTiles[i]->isChosen){
				value2 = 99;
			}
		}
		return value2;
	}

	//Verif
	void Map::verif(int caseValue1, int caseValue2){
		//Si les cases choisient sont les mêmes
		if (this->revealedName1==this->revealedName2){
			this->pTiles[caseValue1]->setIsPaired(true);
			this->pTiles[caseValue1]->setColor(3);
			this->pTiles[caseValue2]->setIsPaired(true);
			this->pTiles[caseValue2]->setColor(3);
		}
		//Recacher les cases qui ne sont pas apairés
		for (int i=0; i<16; i++){
			if (this->pTiles[i]->isPaired==false) this->pTiles[i]->hide();
		}
	}

	//timer
	void Map::timer(){
		for (int i=0; i<10;i++){
			Utils::delay(50);
			cout<<"."<<std::flush;
		}
		cout <<"\n";
	}

	//END
	bool Map::end(){
		for (int i=0; i<15;i++){
			if (this->pTiles[i]->isPaired==false) return false;
		}return true;
	}


// Displayer
string Map::toString() const {
	string A1 = Utils::setTextColor(this->pTiles[0]->color)+this->pTiles[0]->getDisplayedName()+Utils::resetTextColor();
	string A2 = Utils::setTextColor(this->pTiles[1]->color)+this->pTiles[1]->getDisplayedName()+Utils::resetTextColor();
	string A3 = Utils::setTextColor(this->pTiles[2]->color)+this->pTiles[2]->getDisplayedName()+Utils::resetTextColor();
	string A4 = Utils::setTextColor(this->pTiles[3]->color)+this->pTiles[3]->getDisplayedName()+Utils::resetTextColor();
	string B1 = Utils::setTextColor(this->pTiles[4]->color)+this->pTiles[4]->getDisplayedName()+Utils::resetTextColor();
	string B2 = Utils::setTextColor(this->pTiles[5]->color)+this->pTiles[5]->getDisplayedName()+Utils::resetTextColor();
	string B3 = Utils::setTextColor(this->pTiles[6]->color)+this->pTiles[6]->getDisplayedName()+Utils::resetTextColor();
	string B4 = Utils::setTextColor(this->pTiles[7]->color)+this->pTiles[7]->getDisplayedName()+Utils::resetTextColor();
	string C1 = Utils::setTextColor(this->pTiles[8]->color)+this->pTiles[8]->getDisplayedName()+Utils::resetTextColor();
	string C2 = Utils::setTextColor(this->pTiles[9]->color)+this->pTiles[9]->getDisplayedName()+Utils::resetTextColor();
	string C3 = Utils::setTextColor(this->pTiles[10]->color)+this->pTiles[10]->getDisplayedName()+Utils::resetTextColor();
	string C4 = Utils::setTextColor(this->pTiles[11]->color)+this->pTiles[11]->getDisplayedName()+Utils::resetTextColor();
	string D1 = Utils::setTextColor(this->pTiles[12]->color)+this->pTiles[12]->getDisplayedName()+Utils::resetTextColor();
	string D2 = Utils::setTextColor(this->pTiles[13]->color)+this->pTiles[13]->getDisplayedName()+Utils::resetTextColor();
	string D3 = Utils::setTextColor(this->pTiles[14]->color)+this->pTiles[14]->getDisplayedName()+Utils::resetTextColor();
	string D4 = Utils::setTextColor(this->pTiles[15]->color)+this->pTiles[15]->getDisplayedName()+Utils::resetTextColor();

	string str = "";
	str += "            /------\\        /------\\          \n";
	str += "           /        \\      /        \\         \n";
	str += "    /------\\ "+B1+" /------\\ "+D1+" /      		\n";
	str += "   /        \\______/        \\______/          \n";
	str += "   \\ "+A1+" /      \\ "+C1+" /      \\     		\n";
	str += "    \\______/        \\______/        \\   			\n";
	str += "    /      \\ "+B2+" /      \\ "+D2+" /    		\n";
	str += "   /        \\______/        \\______/   			\n";
	str += "   \\ "+A2+" /      \\ "+C2+" /      \\        \n";
	str += "    \\______/        \\______/        \\       \n";
	str += "    /      \\ "+B3+" /      \\ "+D3+" /        \n";
	str += "   /        \\______/        \\______/         \n";
	str += "   \\ "+A3+" /      \\ "+C3+" /      \\        \n";
	str += "    \\______/        \\______/        \\       \n";
	str += "    /      \\ "+B4+" /      \\ "+D4+" /        \n";
	str += "   /        \\______/        \\______/         \n";
	str += "   \\ "+A4+" /      \\ "+C4+" /               	\n";
	str += "    \\______/        \\______/            			\n";
	return str;
}
ostream& operator <<(ostream& sout, const Map& map) {
	sout << "";
	sout << map.toString();
	return sout;
}
