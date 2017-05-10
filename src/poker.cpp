#include <iostream>
#include <vector>
#include <string>


const std::vector<std::string> suit_str{"Club","Heart","Spade","Diamond"};
const std::vector<std::string> rank_str{"Ace","Two","Three","Four","Five",
    "Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
const int hand_size = 2;

class Card{
public:
    int suit;
    int rank;
};

class Deck{
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
    
    void show_deck(){
        for(int i = 0;i<deck.size();i++){
            std::cout<<rank_str[deck[i].rank]<<" of "<<suit_str[deck[i].suit]<<std::endl;
        }
    }
    void shuffle_deck(){
        srand(time(NULL));
        for(int i =0;i<deck.size();i++)
        {
            int t = rand()%(deck.size());
            Card temp = deck[i];
            deck[i] = deck[t];
            deck[t] = temp;
        }
    }
};


class Person{
public:
    std::string name;
    std::vector<Card> hand;
    void show_hand(){
        for(int i = 0;i<hand.size();i++){
            std::cout<<rank_str[hand[i].rank]<<" of "<<suit_str[hand[i].suit]<<std::endl;
        }
    }
};


class Game{
private:
    const int flop_size = 3;
    const int turn_size = 1;
    const int river_size = 1;
public:
    Person p1;
    Person p2;
    Person p3;
    
    std::vector<Card> table;
    
    
    Deck d;
    Game(){
        d.shuffle_deck();
        for(int i = 0;i<hand_size;i++){
            p1.hand.push_back(d.deck.back());
            d.deck.pop_back();
        }
        p1.show_hand();
        std::cout<<std::endl;
        for(int i = 0;i<hand_size;i++){
            p2.hand.push_back(d.deck.back());
            d.deck.pop_back();
        }
        p2.show_hand();
        std::cout<<std::endl;
        for(int i = 0;i<hand_size;i++){
            p3.hand.push_back(d.deck.back());
            d.deck.pop_back();
        }
        p3.show_hand();
        std::cout<<std::endl;
        
        // FLOP
        for(int i = 0;i<flop_size;i++){
            table.push_back(d.deck.back());
            d.deck.pop_back();
        }
        // TURN
        for(int i = 0;i<turn_size;i++){
            table.push_back(d.deck.back());
            d.deck.pop_back();
        }
        // RIVER
        for(int i = 0;i<river_size;i++){
            table.push_back(d.deck.back());
            d.deck.pop_back();
        }
        
        show_table();
        
        p1.hand.insert( p1.hand.end(), table.begin(), table.end());
        p2.hand.insert( p2.hand.end(), table.begin(), table.end());
        p3.hand.insert( p3.hand.end(), table.begin(), table.end());
        // d.show_deck();
    }
    void show_table(){
        for(int i = 0;i<table.size();i++){
            std::cout<<rank_str[table[i].rank]<<" of "<<suit_str[table[i].suit]<<std::endl;			
        }
    }
    
};




int main()
{
    Game g;
    return 0;
}
