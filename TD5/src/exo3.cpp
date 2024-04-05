#include <iostream>
#include <vector>
#include <unordered_map>
#include "global.hpp"

using namespace std;

bool operator==(Card const &c1, Card const &c2)
{
    return (c1.value == c2.value && c1.kind == c2.kind);
}

vector<Card> get_cards(size_t const size)
{
    vector<Card> cards;
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({CardKind(rand() % 4), CardValue(rand() % 13)});
    }
    return cards;
}

string card_name(Card const &card)
{
    string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + card_value;
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'V';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}

int Card::value_to_int() const
{
    return static_cast<int>(value);
}

int Card::coeff_card_kind() const
{
    return 13 * static_cast<int>(kind);
}

int Card::hash() const
{
    return value_to_int() + coeff_card_kind();
}

bool is_in_hash_map(unordered_map<Card, int> map, Card c)
{
    for (pair p : map)
    {
        if (p.first == c)
            return true;
    }
    return false;
}

unordered_map<Card, int> get_card_map(vector<Card> const &cardsList)
{
    unordered_map<Card, int> result{};
    for (Card c : cardsList)
    {
        if (!is_in_hash_map(result, c))
        {
            result.insert({c, 1});
        }
        else
        {
            result.at(c) += 1;
        }
    }
    return result;
}