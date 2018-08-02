#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum directionectionEnumeration {NORTH, EAST, SOUTH, WEST};
enum roomEnumeration {SPORTSHOP, CASINO, CARPARK, LOBBY, RESTAURANT, CORRIDOR, STOREROOM, POOL, GARDEN, POND, PUMPROOM};
enum verbEnumeration {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};
enum nounEnumeration {STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD};


const int NONE = -1;
const int DIRECTION = 4;
const int ROOMS = 11;
const int VERBS = 8;
const int NOUNS = 6;


struct word
{
    string word;
    int code;
};

struct room
{
    string description;
    int exitsToRoom[DIRECTION];
};

struct noun
{
    string word;
    string description;
    int code;
    int location;
    bool canBeCarried;
};

void setRooms(room *rooms)
{
    rooms[SPORTSHOP].description.assign("sports shop");
    rooms[SPORTSHOP].exitsToRoom[NORTH] = NONE;
    rooms[SPORTSHOP].exitsToRoom[EAST] = NONE;
    rooms[SPORTSHOP].exitsToRoom[SOUTH] = CARPARK;
    rooms[SPORTSHOP].exitsToRoom[WEST] = NONE;

    rooms[CASINO].description.assign("bustling casino");
    rooms[CASINO].exitsToRoom[NORTH] = NONE;
    rooms[CASINO].exitsToRoom[EAST] = NONE;
    rooms[CASINO].exitsToRoom[SOUTH] = LOBBY;
    rooms[CASINO].exitsToRoom[WEST] = NONE;

    rooms[CARPARK].description.assign("car park");
    rooms[CARPARK].exitsToRoom[NORTH] = SPORTSHOP;
    rooms[CARPARK].exitsToRoom[EAST] = LOBBY;
    rooms[CARPARK].exitsToRoom[SOUTH] = NONE;
    rooms[CARPARK].exitsToRoom[WEST] = NONE;

    rooms[LOBBY].description.assign("hotel lobby");
    rooms[LOBBY].exitsToRoom[NORTH] = CASINO;
    rooms[LOBBY].exitsToRoom[EAST] = RESTAURANT;
    rooms[LOBBY].exitsToRoom[SOUTH] = CORRIDOR;
    rooms[LOBBY].exitsToRoom[WEST] = CARPARK;

    rooms[RESTAURANT].description.assign("restaurant");
    rooms[RESTAURANT].exitsToRoom[NORTH] = NONE;
    rooms[RESTAURANT].exitsToRoom[EAST] = NONE;
    rooms[RESTAURANT].exitsToRoom[SOUTH] = NONE;
    rooms[RESTAURANT].exitsToRoom[WEST] = LOBBY;

    rooms[CORRIDOR].description.assign("corridor");
    rooms[CORRIDOR].exitsToRoom[NORTH] = LOBBY;
    rooms[CORRIDOR].exitsToRoom[EAST] = NONE;
    rooms[CORRIDOR].exitsToRoom[SOUTH] = GARDEN;
    rooms[CORRIDOR].exitsToRoom[WEST] = NONE;

    rooms[STOREROOM].description.assign("store room");
    rooms[STOREROOM].exitsToRoom[NORTH] = NONE;
    rooms[STOREROOM].exitsToRoom[EAST] = NONE;
    rooms[STOREROOM].exitsToRoom[SOUTH] = NONE;
    rooms[STOREROOM].exitsToRoom[WEST] = NONE;

    rooms[POOL].description.assign("swimming pool area");
    rooms[POOL].exitsToRoom[NORTH] = NONE;
    rooms[POOL].exitsToRoom[EAST] = GARDEN;
    rooms[POOL].exitsToRoom[SOUTH] = PUMPROOM;
    rooms[POOL].exitsToRoom[WEST] = NONE;

    rooms[GARDEN].description.assign("tranquil garden");
    rooms[GARDEN].exitsToRoom[NORTH] = CORRIDOR;
    rooms[GARDEN].exitsToRoom[EAST] = POND;
    rooms[GARDEN].exitsToRoom[SOUTH] = NONE;
    rooms[GARDEN].exitsToRoom[WEST] = POOL;

    rooms[POND].description.assign("patio with a fish pond");
    rooms[POND].exitsToRoom[NORTH] = NONE;
    rooms[POND].exitsToRoom[EAST] = NONE;
    rooms[POND].exitsToRoom[SOUTH] = NONE;
    rooms[POND].exitsToRoom[WEST] = GARDEN;

    rooms[PUMPROOM].description.assign("damp pump room");
    rooms[PUMPROOM].exitsToRoom[NORTH] = POOL;
    rooms[PUMPROOM].exitsToRoom[EAST] = NONE;
    rooms[PUMPROOM].exitsToRoom[SOUTH] = NONE;
    rooms[PUMPROOM].exitsToRoom[WEST] = NONE;
}



void setDirections(word *direction)
{
    direction[NORTH].code = NORTH;
    direction[NORTH].word = "NORTH";
    direction[EAST].code = EAST;
    direction[EAST].word = "EAST";
    direction[SOUTH].code = SOUTH;
    direction[SOUTH].word = "SOUTH";
    direction[WEST].code = WEST;
    direction[WEST].word = "WEST";
}



void setVerbs(word *verbs)
{

    verbs[GET].code = GET;
    verbs[GET].word = "GET";
    verbs[DROP].code = DROP;
    verbs[DROP].word = "DROP";
    verbs[USE].code = USE;
    verbs[USE].word = "USE";
    verbs[OPEN].code = OPEN;
    verbs[OPEN].word = "OPEN";
    verbs[CLOSE].code = CLOSE;
    verbs[CLOSE].word = "CLOSE";
    verbs[EXAMINE].code = EXAMINE;
    verbs[EXAMINE].word = "EXAMINE";
    verbs[INVENTORY].code = INVENTORY;
    verbs[INVENTORY].word = "INVENTORY";
    verbs[LOOK].code = LOOK;
    verbs[LOOK].word = "LOOK";
}




void setNouns(noun *nouns)
{

    nouns[STORE_DOOR].word = "DOOR";
    nouns[STORE_DOOR].code = STORE_DOOR;
    nouns[STORE_DOOR].description = "a closed store room door";
    nouns[STORE_DOOR].canBeCarried = false;
    nouns[STORE_DOOR].location = CORRIDOR;
    nouns[MAGNET].word = "MAGNET";
    nouns[MAGNET].code = MAGNET;
    nouns[MAGNET].description = "a magnet";
    nouns[MAGNET].canBeCarried = true;
    nouns[MAGNET].location = NONE;
    nouns[METER].word = "METER";
    nouns[METER].code = METER;
    nouns[METER].description = "a parking meter";
    nouns[METER].canBeCarried = false;
    nouns[METER].location = CARPARK;
    nouns[ROULETTE].word = "ROULETTE";
    nouns[ROULETTE].code = ROULETTE;
    nouns[ROULETTE].description = "a roulette wheel";
    nouns[ROULETTE].canBeCarried = false;
    nouns[ROULETTE].location = CASINO;
    nouns[MONEY].word = "MONEY";
    nouns[MONEY].code = MONEY;
    nouns[MONEY].description = "some money";
    nouns[MONEY].canBeCarried = true;
    nouns[MONEY].location = NONE;
    nouns[FISHROD].word = "ROD";
    nouns[FISHROD].code = FISHROD;
    nouns[FISHROD].description = "a fishing rod";
    nouns[FISHROD].canBeCarried = false;
    nouns[FISHROD].location = SPORTSHOP;
}
// ....

// -------------------------------------------------------------------------------------------------

void sectionCommand(string command, string &firstWord, string &secondWord)
{
    string substring;
    vector<string> words;
    char search = ' ';
    size_t i, j;

    for(i = 0; i < command.size(); i++)
    {
        if(command.at(i) != search)
        {
            substring.insert(substring.end(), command.at(i));
        }
        if(i == command.size() - 1)
        {
            words.push_back(substring);
            substring.clear();
        }
        if(command.at(i) == search)
        {
            words.push_back(substring);
            substring.clear();
        }
    }

    for(i = words.size() - 1; i > 0; i--)
    {
        if(words.at(i) == "")
        {
            words.erase(words.begin() + i);
        }
    }

    //lol this is where you start missing the toUpperCase from java
    for(i = 0; i < words.size(); i++)
    {
        for(j = 0; j < words.at(i).size(); j++)
        {
            if(islower(words.at(i).at(j)))
            {
                words.at(i).at(j) = toupper(words.at(i).at(j));
            }
        }
    }

    if(words.size() == 0)
    {
        cout << "No command given" << endl;
    }
    if(words.size() == 1)
    {
        firstWord = words.at(0);
    }
    if(words.size() == 2)
    {
        firstWord = words.at(0);
        secondWord = words.at(1);
    }
    if(words.size() > 2)
    {
        cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
    }
}


void look_around(int loc, room *rooms, word *direction, noun *nouns)
{
    int i;
    cout << "I am in a " << rooms[loc].description << "." << endl;

    for(i = 0; i < direction; i++)
    {
        if(rooms[loc].exitsToRoom[i] != NONE)
        {
            cout << "There is an exit " << direction[i].word << " to a " << rooms[rooms[loc].exitsToRoom[i]].description << "." << endl;
        }
    }

    for(i = 0; i < NOUNS; i++)
    {
        if(nouns[i].location == loc)
        {
            cout << "I see " << nouns[i].description << "." << endl;
        }
    }
}



bool parser(int &loc, string firstWord, string secondWord, word *direction, word *verbs, room *rooms, noun *nouns)
{

    static bool doorState = false;


    int i;
    for(i = 0; i < direction; i++)
    {
        if(firstWord == direction[i].word)
        {
            if(rooms[loc].exitsToRoom[direction[i].code] != NONE)
            {
                loc = rooms[loc].exitsToRoom[direction[i].code];
                cout << "I am now in a " << rooms[loc].description << "." << endl;

                if(loc == STOREROOM || loc == CORRIDOR)
                {
                    nouns[STORE_DOOR].location = loc;
                }

                return true;
            }
            else
            {
                cout << "No exit that way." << endl;
                return true;
            }
        }
    }


    int NOUN_MATCH = NONE;

    int VERB_ACTION = NONE;

    for(i = 0; i < VERBS; i++)
    {
        if(firstWord == verbs[i].word)
        {
            VERB_ACTION = verbs[i].code;
            break;
        }
    }


    if(secondWord != "")
    {
        for(i = 0; i < NOUNS; i++)
        {
            if(secondWord == nouns[i].word)
            {
                NOUN_MATCH = nouns[i].code;
                break;
            }
        }
    }

    if(VERB_ACTION == NONE)
    {
        cout << "No valid command entered." << endl;
        return true;
    }

    if(VERB_ACTION == LOOK)
    {
        look_around(loc, rooms, direction, nouns);
        return true;
    }


    if(VERB_ACTION == OPEN)
    {
        if(NOUN_MATCH == STORE_DOOR)
        {
            if(loc == CORRIDOR || loc == STOREROOM)
            {
                if(doorState == false)
                {
                    doorState = true;
                    rooms[CORRIDOR].exitsToRoom[EAST] = STOREROOM;
                    rooms[STOREROOM].exitsToRoom[WEST] = CORRIDOR;
                    nouns[STORE_DOOR].description.clear();
                    nouns[STORE_DOOR].description.assign("an open store room door");
                    cout << "I have opened the door." << endl;
                    return true;
                }
                else if(doorState == true)
                {
                    cout << "The door is already open." << endl;
                    return true;
                }
            }
            else
            {
                cout << "There is no door to open here." << endl;
                return true;
            }
        }
        else
        {
            cout << "Opening that is not possible." << endl;
            return true;
        }
    }


    return false;
}







int main()
{
    string command;
    string word_1;
    string word_2;

    room rooms[ROOMS];
    setRooms(rooms);
    word direction[DIRECTION];
    setDirections(direction);
    word verbs[VERBS];
    setVerbs(verbs);
    noun nouns[NOUNS];
    setNouns(nouns);


    int location = CARPARK;

    while(word_1 != "QUIT")
    {
        command.clear();
        cout << "What shall I do? ";
        getline(cin, command);

        word_1.clear();
        word_2.clear();

        sectionCommand(command, word_1, word_2);

        if(word_1 != "QUIT")
        {
            parser(location, word_1, word_2, direction, verbs, rooms, nouns);
        }
    }
    return 0;
}
