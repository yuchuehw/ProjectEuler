#!/usr/bin/python3
import operator
import random

SQUARES = [
    "go", "a1", "cc1", "a2", "t1", "r1", "b1", "ch2", "b2", "b3", "jail",
    "c1", "u1", "c2", "c3", "r2", "d1", "cc2", "d2", "d3", "fp", "e1",
    "ch2", "e2", "e3", "r3", "f1", "f2", "u2", "f3", "2j", "g1", "g2",
    "cc3", "g3", "r4", "ch3", "h1", "t2", "h2"
]

DICE = 4
CCHEST = [""]*14+["go", "jail"]
CHANCES = [""]*6+["go", "c1", "e3", "h2", "r1", "r", "r", "u", "-3"]



def simulate(rounds: int = 10000) -> list:
    def handle_event():
        nonlocal current_square
        nonlocal cchest_deck
        nonlocal chances_deck
        match SQUARES[current_square][:2]:
            case "cc":
                top_card = cchest_deck.pop(0)
                if top_card:
                    current_square = SQUARES.index(top_card)
                cchest_deck.append(top_card)
            case "ch":
                top_card = chances_deck.pop(0)
                if top_card == "-3":
                    current_square -= 3
                    handle_event()
                elif len(top_card) == 1:
                    while not SQUARES[current_square].startswith(top_card):
                        current_square += 1
                        current_square %= len(SQUARES)
                elif top_card:
                    current_square = SQUARES.index(top_card)
                chances_deck.append(top_card)
            case "2j":
                current_square = SQUARES.index("jail")
    current_square = 0
    counter = [0]*len(SQUARES)
    cchest_deck = random.sample(CCHEST, len(CCHEST))
    chances_deck = random.sample(CHANCES, len(CHANCES))
    for i in range(rounds):
        if i:
            counter[current_square] += 1
        doubles = 0
        dice1 = 0
        dice2 = 0
        while dice1 == dice2:
            if doubles == 3:
                break
            if dice1:
                handle_event()
            dice1 = random.randint(1, DICE)
            dice2 = random.randint(1, DICE)
            current_square += dice1 + dice2
            current_square %= len(SQUARES)
            doubles += 1
        else:
            handle_event()
            continue
        current_square = SQUARES.index("jail")

    return sorted(zip(range(len(counter)), counter),
                  key=operator.itemgetter(1), reverse=True)


if __name__ == "__main__":
    print("SQUARES LANDED BASED ON 10,000 simulations")
    print("SQUARE NAME".ljust(12), "SQUARE INDEX".ljust(12), "FREQUENCY".ljust(12))
    result = simulate()
    for square_index, frequency in result:
        square_name = SQUARES[square_index]
        print(f"{square_name.ljust(12)} {square_index:<12} {frequency:<12}")
