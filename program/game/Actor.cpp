#include "Actor.h"
#include"JankenCard.h"

Actor::Actor()
{
	JankenCard* hand1 = new JankenCard(0);
	JankenCard* hand2 = new JankenCard(1);
	JankenCard* hand3 = new JankenCard(2);

	hand[JANKEN::GUU] = hand1;
	hand[JANKEN::CHOKI] = hand2;
	hand[JANKEN::PAH] = hand3;

}

void Actor::Draw()
{
	for (int i = 0; i < 3; ++i) {
		hand[i]->Draw(20 + (50 + 20) * i, 30);
	}
}
