#functions sections
#low level
import operator

"""
below we have getters for month, name and artists of festival
"""
def get_month(Festival):
    return Festival['month']

def get_name(Festival):
    return Festival['name']

def get_artists(Festival):
    return Festival['artists']
def to_str(Festival):
    MONTH = ['', 'january', 'february', 'march', 'april', 'may', 'june', 'july', 'august', 'september', 'october', 'november', 'december']
    return "month " + MONTH[get_month(Festival)] + " name: " + get_name(Festival)
def Create_Festival(name : str, month : int, ticket_cost : int, artists : list) -> dict:
    """
    :param name: name of the festival
    :param month: when it will occur
    :param ticket_cost: price of a ticket
    :param artists: artists that will perform
    :return: Festival informations
    """
    return {"name": name, "month" : month, "ticket-cost" : ticket_cost, "artists": artists}
#mid-level
def Is_Festival(name : str, Festivals_List : list):
    """
    :param name: name of festival
    :param Festivals_List: list of festivals
    :return: True if the festival is not in the list
    """
    for festival in Festivals_List:
        if(get_name(festival) == name):
            return False

    return True
def Initialise_Festivals(Festivals_List : list):
    """
    :param Festivals_List:
    :return: Filled Festivals_list
    """
    Festivals_List = [
        Create_Festival("Hstle", 12, 100, ["nane", "lil cagula"]),
        Create_Festival("Huste", 11, 100, ["nane", "lil cagula"]),
        Create_Festival("Hstle", 10, 100, ["nane", "lil cagula"]),
        Create_Festival("Husle", 9, 100, ["nane", "lil cagula"]),
        Create_Festival("ustle", 8, 100, ["nane", "lil cagula"]),
        Create_Festival("Huste", 7, 100, ["nane", "lil cagula"])
    ]
    return Festivals_List

def Add_Festival(Festivals_list : list, Festival):
    """
    :param name: name of the festival
    :param month: when it will occur
    :param ticket_cost: price of a ticket
    :param artists: artists that will perform
    :We will add this festival to the list
    """

    try:
        if(get_month(Festival) < 0 or get_month(Festival) > 12 or Is_Festival(get_name(Festival), Festivals_list) == False):
            raise ValueError("Error")

        Festivals_list.append(Festival)
    except ValueError as ve:
        print(ve)

def All_Festivals_During_A_Given_Season(Festivals_List : list, season : str):
    """
    :param Festivals_List: list of festivals
    :param season: a season
    :return: list of festivals occuring in a given season
    """
    season = season.lower()
    SEASONS = {"winter": (12, 1, 2), "spring": (3, 4, 5), "summer": (6, 7, 8), "autumn": (9, 10, 11)}
    Festivals_In_A_Season = []

    for festival in Festivals_List:
        if(get_month(festival) in SEASONS[season.lower()]):
            Festivals_In_A_Season.append(festival)

    sorted(Festivals_In_A_Season,key = lambda x: x.get('month', 'name'))

    return Festivals_In_A_Season
def All_Festivals_Where_An_Artist_Will_Perform(Festival_List : list, artist_name):
    """
    :param Festivals_List: list of festivals
    :param artist_name: name of an artist
    :return: list of festivals where an artist will perform sorted by month
    :return:
    """
    New_Festival_List = []

    for festival in Festival_List:
        for artist in get_artists(festival):
            if(artist == artist_name):
                New_Festival_List.append(festival)

    return sorted(New_Festival_List, key = lambda x : x.get("month"))

#high-level
#user interfacec
#all functions that read and print data should be here
def Print_Menu():#here we print the menu
    print("1: Add a music festival")
    print("2: Show all festivals taking place during a given season")
    print("3: Show all festivals where a given artist will perform")

def Read_Festival():
    """
        Read the specs of an festival
    :return: festival represenatition
    """
    name = input("name: ")
    month = int(input("month: "))
    ticket_cost = int(input("ticket cost: "))
    artists = input("artists:").split()

    return Create_Festival(name, month, ticket_cost, artists)

def Show_All_Festivals_During_A_Given_Season(Festivals_list, season : str):
    """
    :param Festivals_list: list of festivals
    :param season: seosen
    will display all festivals during a given season

    """
    Festivals_In_A_Season = All_Festivals_During_A_Given_Season(Festivals_list,season)

    for festival in Festivals_In_A_Season:
        print(to_str(festival))

def Show_All_Festivals_Where_An_Artist_Will_Sing(Festivals_List, artist_name: str):
    """
    :param Festivals_List:
    :param artist_name:
    we will display all fesivals where an artist will perform sorted by month
    """
    Festivals_where_an_given_artist_will_perfom = All_Festivals_Where_An_Artist_Will_Perform(Festivals_List,artist_name)

    for festival in Festivals_where_an_given_artist_will_perfom:
        print(to_str(festival))

def main():
    """
        main of our program
    """
    ADD_FESTIVAL = '1'
    SHOW_ALL_FESTIVALS_DURING_A_GIVEN_SEASON = '2'
    SHOW_ALL_FESTIVALS_WHERE_A_GIVEN_ARTIST_WILL_PERFORM = '3'
    #MAGIC NUMBERS  ABOVE

    Festivals_List = Initialise_Festivals([])

    while (True):
        Print_Menu()

        option = input("Choose your option: ")

        if(option == ADD_FESTIVAL):
            Festival = Read_Festival()
            Add_Festival(Festivals_List, Festival)
        elif(option == SHOW_ALL_FESTIVALS_DURING_A_GIVEN_SEASON):
            season = input("enter season: ")
            Show_All_Festivals_During_A_Given_Season(Festivals_List, season)
        elif(option == SHOW_ALL_FESTIVALS_WHERE_A_GIVEN_ARTIST_WILL_PERFORM):
            artist_name = input("artist: ")
            Show_All_Festivals_Where_An_Artist_Will_Sing(Festivals_List, artist_name)
        else:
            print("Invalid Option")

if __name__ == "__main__":
    #here we run the program
    main()