#
# Functions section
#

def get_manufacturer(phone: tuple) -> str:
    return phone[0]


def get_model(phone: tuple) -> str:
    return phone[1]


def get_price(phone: tuple) -> int:
    return phone[2]


def add_phone(phones, brand, model, price):
    if len(brand) < 3 or len(model) < 3 or price < 100:
        raise ValueError("Incorrect data")
    phones.append((brand, model, price))


def display(phones, S):

    res = []
    S = S.lower()
    for ph in phones:
        brand = get_manufacturer(ph).lower()
        if S in brand:
            res.append(ph)
    return res


def increase_amount(phones: list, brand: str, model: str, amount: int):
    ok: int = 0
    n: int = len(phones)
    for i in range(n):
        if get_manufacturer(phones[i]) == brand and get_model(phones[i]) == model:
            ok = 1
            phones[i] = (brand, model, get_price(phones[i]) + amount)
    if ok == 0:
        raise ValueError("Cannot find this phone!")


def increase_percent(phones, percent):

    if percent < -50 or percent > 100:
        raise ValueError("Percent value is wrong!")
    n = len(phones)
    for i in range(n):
        brand = get_manufacturer(phones[i])
        model = get_model(phones[i])
        price = get_price(phones[i])
        phones[i] = (brand, model, price * (100 + percent) // 100)
#
# User interface section
#


def ad_phone_ui(phones):

    try:
        brand = input("Manufacturer: ")
        model = input("Model: ")
        price = int(input("Price: "))
        add_phone(phones, brand, model, price)
    except ValueError as ve:
        print("ERROR!")
        print(str(ve))


def display_ui(phones):
    S = input("String: ")
    res = display(phones, S)
    for r in res:
        print(r)


def increase_amount_ui(phones):
    try:
        brand = input("Manufacturer: ")
        model = input("Model: ")
        amount = int(input("Amount: "))
        increase_amount(phones, brand, model, amount)
    except ValueError as ve:
        print("ERROR!")
        print(str(ve))


def increase_percent_ui(phones):
    try:
        percent = int(input("Percent: "))
        increase_percent(phones, percent)
    except ValueError as ve:
        print("ERROR!")
        print(str(ve))


def print_menu():
    print("1. Add a phone.")
    print("2. Display all phones from a given manufacturer.")
    print("3. Increase the price of a phone whit a given amount.")
    print("4. Increase the price of a phone whit a given percent.")
    print("0. Exit")


def start():

    #phones = [("Samsung", "Galaxy S23", 3800), ("Allview", "X2 Soul", 1300)]
    phones = []
    functions = {"1": ad_phone_ui, "2": display_ui, "3": increase_amount_ui, "4": increase_percent_ui}

    while True:
        print_menu()
        option = input(">")
        if option == "0":
            print("BYE!")
            break
        elif option in functions:
            functions[option](phones)
        else:
            print("Wrong option!")


if __name__ == "__main__":
    start()