#include<iostream>
#include<time.h>
#include<vector>
#include"Human.cpp"
#include"Counting.h"
using namespace std;

class Player : public Human{
    public:
        Player(int initial_wager, int initial_sidebet_wager);
        void create_hand(DeckOfCard doc, Card initial_card);
        void add_money(double amount);
        void add_sidebet_money(double amount);
        int get_wager();
        double get_money();
        int get_sidebet_wager();
        double get_sidebet_money();
        void set_wager(int new_wager);
        void modify_bet_by_count(int current_count);
    private:
        double money;
        int wager;
        int sidebet_wager;
        double sidebet_money;
        int betting_unit;
};
Player::Player(int unit_of_bet, int initial_sidebet_wager) : Human(){
    money = 0;
    betting_unit = unit_of_bet;
    wager = betting_unit;
    sidebet_wager = initial_sidebet_wager;
}
void Player::create_hand(DeckOfCard doc, Card initial_card){
    Hand newHand(doc, get_wager(), initial_card);
    hands.push_back(newHand);
}
void Player::add_money(double amount){
    money += amount;
    return;
}
void Player::add_sidebet_money(double amount){
    sidebet_money += amount;
    return;
}
double Player::get_money(){
    return money;
}
double Player::get_sidebet_money(){
    return sidebet_money;
}
int Player::get_sidebet_wager(){
    return sidebet_wager;
}
void Player::set_wager(int new_wager){
    wager = new_wager;
}
int Player::get_wager(){
    return wager;
}
void Player::modify_bet_by_count(int current_count){
    if(current_count >=0){
        set_wager(betting_unit*positive_count[current_count]);
    }else{
        set_wager(betting_unit*negative_count[-1*current_count]);
    }
}
