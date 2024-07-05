#low level
#functions that deal with representation
def Create_Phone(manufacturer : str, model : str, price : int):
    return { "manufacturer" : manufacturer, "model" : model, "price" : price}

def to_str(phone:dict):
    return "manufacturer: " + phone['manufacturer'] + "\n model: " + phone['model'] + "\n price: " + str(phone['price'])
#mid-level
#functions that implement program functionalities
def Add_Phone(Phone_List : list, Phone_Specifications):
    Phone_List.append(Phone_Specifications)
def Increase_The_Price_Of_A_Phone_By_A_Given_Amount(Phone_List : list ,manufacturer : str, model : str, price : int):
    ok = 0

    for phone in Phone_List:
        if(manufacturer == phone['manufacturer'] and model == phone['model']):
            phone['price'] += price
            ok = 1

    if ok == 0:
        raise ValueError("There is no phone with the given specs")

def Increase_The_Price_Of_All_Phones_By_A_Given_Amount(Phone_List : list , percent : int):
    assert percent >= -50 and percent <= 100, "Invalid percent(must be between -50 and 100)"

    for phone in Phone_List:
        phone['price'] += int(phone['price'] * (1 / percent))
#high-level
#functions that deal with input/output
def Print_Menu():
    print("1: Add phone")
    print("2: Display all phones from a given manufacturer")
    print("3: Increase the price of a phone by a gicen amount")
    print("4: Increase the price of all phones by  a given amount")
def Read_Phone_Specifications():
    print("Reading phone specifications: ")

    manufacturer = input("manufacturer: ")
    model = input("model:")
    price = input("price:")

    if (len(manufacturer) < 3 or len(model) < 3 or len(price) < 3):
        raise ValueError("Length must be smaller or equal to 3")

    price = int(price)

    return Create_Phone(manufacturer, model, price)

def Display_All_Phones_From_A_Manufacturer(Phone_List : list , manufacturer: str):
    for phone in Phone_List:
        if(manufacturer.lower() in phone['manufacturer'].lower()):
            print(to_str(phone))


ADD_PHONE = '1'
DISPLAY_PHONES_BY_MANUFACTURER = '2'
INCREASE_PRICE_OF_PHONE = '3'
INCREASE_PRICE_OF_ALL_PHONES = '4'

def main():
    option = input("enter option: ")

    if (option == ADD_PHONE):
        Phone_Specification = Read_Phone_Specifications()
        Add_Phone(Phone_List, Phone_Specification)
    elif (option == DISPLAY_PHONES_BY_MANUFACTURER):
        manufacturer = input("manufacturer: ")
        Display_All_Phones_From_A_Manufacturer(Phone_List, manufacturer)
    elif (option == INCREASE_PRICE_OF_PHONE):
        manufacturer = input("manufacturer: ")
        model = input("model:")
        increase_price = int(input("price:"))
        Increase_The_Price_Of_A_Phone_By_A_Given_Amount(Phone_List, manufacturer, model, increase_price)
    elif (option == INCREASE_PRICE_OF_ALL_PHONES):
        increase_percentage = int(input("percentage:"))
        Increase_The_Price_Of_All_Phones_By_A_Given_Amount(Phone_List, increase_percentage)

if __name__ == "__main__":
    Phone_List = []

    while(True):
        Print_Menu()

        try:
            main()
        except ValueError as ve:
            print(ve)
