"""
functions section:
here we have low and mid level functions
"""
def create_flight(code: str, duration: int, departure_city: str, destination_city: str):
    return{"code": code, "duration": duration, "departure_city": departure_city, "destination_city": destination_city}
def get_code(flight: dict):
    return flight["code"]
def get_duration(flight: dict):
    return flight["duration"]
def get_departure_city(flight: dict):
    return flight["departure_city"]
def get_destination_city(flight: dict):
    return flight["destination_city"]
def modify_duration(flight: dict, new_duration: int):
    flight['duration'] = new_duration
def modify_destination(flight: dict, new_destination: str):
    flight['destination_city'] = new_destination
def Add_Flight(code: str, duration: int, departure_city: str, destination_city: str, Flight_List: list):
    if(len(code) < 3 or duration < 20 or len(departure_city) < 3 or len(departure_city) < 3):
        raise ValueError("ERROR")

    flight = create_flight(code, duration, departure_city, destination_city)

    Flight_List.append(flight)
def modify_destination_of_a_given_flight(code: str, new_duration: int, Flight_List: list):
    for flight in Flight_List:
        if(get_code(flight) == code):
            modify_duration(flight, new_duration)

def reroute_all_flights_wiht_the_same_departure_city(departure_city: str, new_destination_city: str, Flight_List: list):
    if(len(new_destination_city) < 3):
        raise ValueError("Invalid input: TRY AGAIN")
    for flight in Flight_List:
        if(get_departure_city(flight) == departure_city):
            modify_destination(flight, new_destination_city)
def all_flights_by_a_given_departure_city(Flight_List: list, departure_city: str):
    flights_that_match_the_criteria = []

    for flight in Flight_List:
        if(get_departure_city(flight) == departure_city):
            flights_that_match_the_criteria.append(flight)

    sorted(flights_that_match_the_criteria, key = lambda x: x.get("duration"))

    return flights_that_match_the_criteria

"""
UI section
Here we have functions that communicate eith the user
"""
def Add_Flight_UI(Flight_List: list):
    try:
        code = input("code:")
        duration = int(input("duration"))
        departure_city = input("departure city:")
        destination_city = input("destination city:")

        Add_Flight(code, duration, departure_city, destination_city, Flight_List)
    except ValueError as ve:
        print(ve)

def modify_destination_of_a_given_flight_UI(Flight_List: list):
    code = input("code")
    new_duration = int(input("new duration: "))

    modify_destination_of_a_given_flight(code, new_duration, Flight_List)

def reroute_all_flights_wiht_the_same_departure_city_UI(Flight_List: list):
    departure_city = input("departure city: ")
    new_destination_city = input("new destination city: ")

    reroute_all_flights_wiht_the_same_departure_city(departure_city, new_destination_city, Flight_List)

def show_all_flights_by_a_given_departure_city_UI(Flight_List: list):
    departure_city = input("departure city:")

    flights_by_departure_city = all_flights_by_a_given_departure_city(Flight_List, departure_city)

    for flight in flights_by_departure_city:
        print(flight)
def print_menu():
    print("1: Add a flight")
    print("2: Modify the duration of a given flight")
    print("3: For a given destiantion city all flights are rerouted to a new given destination")
    print("4: Show all flights by a given departure city")
def main():
    functions_list = {"1": Add_Flight_UI, "2": modify_destination_of_a_given_flight_UI,
                      "3": reroute_all_flights_wiht_the_same_departure_city_UI,
                      "4": show_all_flights_by_a_given_departure_city_UI}
    Flight_List = []

    while(True):
        print_menu()

        option = input("option:")

        try:
            functions_list[option](Flight_List)
        except ValueError as ve:
            print(ve)

if __name__ == "__main__":
    main()