#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// EXERCICE 1
size_t folding_string_hash(string const &s, size_t max);
size_t folding_string_ordered_hash(string const &s, size_t max);
size_t polynomial_rolling_hash(const string &s, size_t p, size_t m);

// EXERCICE 2
vector<pair<string, float>> get_robots_fix(size_t size);
unordered_map<string, vector<float>> robots_fixes_map(vector<pair<string, float>> const &robots_fixes);
float float_sum(vector<float> &vec);
void get_robots_fix(unordered_map<string, vector<float>> &map);

// EXERCICE 3

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;

    int value_to_int() const;
    int coeff_card_kind() const;
    int hash() const;
};

string card_name(Card const &card);

bool operator==(Card const &c1, Card const &c2);
vector<Card> get_cards(size_t const size);
unordered_map<Card, int> get_card_map(vector<Card> const &cardsList);

namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}