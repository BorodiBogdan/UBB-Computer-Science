"""
functions sections below
"""
#low level
def Create_Coffe(name : str, country_of_origin : str, price : float):
    return {"name" : name, "country_of_origin" : country_of_origin, "price" : price}

def Get_Name(Coffe_Shop : dict):
    return Coffe_Shop['name']
def Get_Country_Of_Origin(Coffe_Shop : dict):
    return Coffe_Shop['country_of_origin']
def Get_Price(Coffe_Shop : dict):
    return Coffe_Shop['price']

def to_str(Coffe_Shop:dict):
    return "Name: " + Get_Name(Coffe_Shop) + "   Country of origin: " + Get_Country_Of_Origin(Coffe_Shop) + "   Price: " + str(Get_Price(Coffe_Shop))


#mid level
def Initialise_Coffes(Coffe_List: list):
    Coffe_List = [
        {"name": "copc", 'country_of_origin': "Romania", "price" : 5.2},
        {"name": "opac", 'country_of_origin': "Romania", "price": 5.2},
        {"name": "coac", 'country_of_origin': "Romania", "price": 5.2},
        {"name": "opc", 'country_of_origin': "Romania", "price": 5.2},
        {"name": "cdac", 'country_of_origin': "Romania", "price": 5.2},
    ]

    return Coffe_List
def Sorted_Coffes_From_A_Country(Coffe_List : list, country : str):
    Coffe_List_From_A_Given_Country = []

    for coffe in Coffe_List:
        if(Get_Country_Of_Origin(coffe) == country):
            Coffe_List_From_A_Given_Country.append(coffe)

    if(len(Coffe_List) > 0):
        sorted(Coffe_List_From_A_Given_Country, key = lambda x: x.get("country_of_origin", "price"))

    return Coffe_List_From_A_Given_Country

def Add_Coffe(name, country_of_origin, price, Coffe_List):
    """
    :param name: name of cofe
    :param country_of_origin: country of origin
    :param price: price of coffe
    :param Coffe_List: listmof existing coffes
    add coffe if price is float and greater then 0 to the coffe list
    """
    if price < 0:
        raise ValueError("Enter a valid price")

    Coffe_List.append(Create_Coffe(name, country_of_origin, price))

"""
Ui section below
Here we print and read data
"""
#high-level

def Add_Coffe_UI(Coffe_List):
    try:
        name = input("name of coffe: ")
        country_of_origin = input("country of origin:")
        price = float(input("price: "))

        Add_Coffe(name, country_of_origin, price, Coffe_List)
    except ValueError as ve:
        print(ve)

def Display_All_Coffes_Sorted_By_Country_of_Origin(Coffe_List : list):
    country = input("country: ")
    Coffe_List_From_A_Given_Country = Sorted_Coffes_From_A_Country(Coffe_List,country)

    for coffe in Coffe_List_From_A_Given_Country:
        print(to_str(coffe))

def Filter_Coffes_Based_On_Country_Of_Origin_UI(Coffe_List : list):
    try:
        country = input("country: ")
        price = input("price: ")
        ok = 0

        if(price == ""):
            price = 1e9
        else:
            price = float(price)

        for coffe in Coffe_List:
            if(country == ""):
                origin_country = Get_Country_Of_Origin(coffe)
            else:
                origin_country = country

            if(Get_Country_Of_Origin(coffe).lower() == origin_country.lower() and price > Get_Price(coffe)):
                print(to_str(coffe))
                ok = 1

            if(ok == 0):
                raise ValueError("No such Coffes")

    except ValueError as ve:
        print(ve)

def Print_Menu():
    print("1 - Add a coffe")
    print("2 - Display all coffes sorted alphabetically by origin country and price")
    print("3 - Filter coffes based on country of origin and price")

def Start():
    function_List = { '1': Add_Coffe_UI, '2' : Display_All_Coffes_Sorted_By_Country_of_Origin, '3' : Filter_Coffes_Based_On_Country_Of_Origin_UI}
    Coffe_List = Initialise_Coffes([])

    while(True):
        Print_Menu()

        option = input("option:  ")

        function_List[option](Coffe_List)

if __name__ == "__main__":
    Start()