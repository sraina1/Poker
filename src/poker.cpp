#include <iostream>
#include <vector>
#include <string>

class Card{
	public:
		int suit;
		int rank;
};

class Deck{
private:
	std::vector<std::string> suit_str{"Club","Heart","Ace","Diamond"};
public:
std::vector<Card> deck;
Deck(){
	create_deck();
}

void create_deck(){
	for(int suit_iter = 0;suit_iter<4;suit_iter++){
		for(int rank_iter = 0;rank_iter<13;rank_iter++){
			Card* card_iter  = new Card();
			card_iter->suit = suit_iter;
			card_iter->rank = rank_iter;
			deck.push_back(*card_iter);
		}
	}
}

void print_deck(){
	for(int i = 0;i<deck.size();i++){
		std::cout<<deck[i].rank+1<<" of "<<suit_str[deck[i].suit]<<std::endl;			
	}
}
};


int main()
{
	std::cout<< "YOLO";
	Deck d1;
	d1.print_deck();
	return 0;
}