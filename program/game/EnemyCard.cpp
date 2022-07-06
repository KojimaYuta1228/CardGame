#include"EnemyCard.h"
#include"../dxlib_ext/dxlib_ext.h"

EnemyCard::EnemyCard() {
	
	
	el = LoadGraph("graphics/elpa.png");
	hu = LoadGraph("graphics/huma.png");
	an = LoadGraph("graphics/ant.png");
}

void EnemyCard::Draw()
{
	if (!start) {
		enemy = rand() % 3 + 1;
	}
	if (enemy == 1) {

		
		DrawRotaGraph(600, 550, 1.0, 0, el, true);
	}
	else if (enemy == 2) {
		
		DrawRotaGraph(700, 550, 1.0, 0, hu, true);
	}
	else if (enemy == 3) {
		
		DrawRotaGraph(600, 550, 1.0, 0, an, true);
	}
}



