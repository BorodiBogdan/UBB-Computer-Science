#
# Functions section
#
def create_flight(code: str, duration: int, departure_city: str, destination_city: str):
    return {"code": code, "duration": duration, "departure-city": departure_city, "destination-city": destination_city}
def get_code_of_the_flight(flight: dict):
    return flight["code"]
def get_duration_of_the_flight(flight: dict):
    return flight["duration"]
def get_departure_city_of_the_flight(flight: dict):
    return flight["departure-city"]
def get_destination_city_of_the_flight(flight: dict):
    return flight["destination-city"]

def to_str(flight: dict):
    return "code: " + flight['code'] + "  duration: "+ str(flight['duration']) + "  departure city: " +  flight["departure-city"] + "  destination-city: " + flight['destination-city']
def increase_duration_of_the_flight(flight:dict, increase_amount: int):
    flight['duration'] += increase_amount

def add_flight(code: str, duration: int, departure_city: str, destination_city: str, Flight_List: list):
    if(len(code) < 3 or len(departure_city) < 3 or len(destination_city) < 3 or duration < 20):
        raise ValueError("ERROR: Inputs to small")

    flight_to_add = create_flight(code, duration, departure_city, destination_city)
    Flight_List.append(flight_to_add)

def sort_flights_by_destination_city(Flight_List: list):
    for i in range(len(Flight_List)):
        for j in range(i + 1, len(Flight_List)):
            if(get_destination_city_of_the_flight(Flight_List[i]) > get_destination_city_of_the_flight(Flight_List[j])):
                Flight_List[i], Flight_List[j] = Flight_List[j], Flight_List[i]

def delete_flight_by_a_given_code(code: str, Flight_List: list):
    """
    :param code: code of the flight that must be removed
    :param Flight_List: list of active flights
    removes the flight that has the given code
    """
    flight_to_be_removed = -1

    for flight in Flight_List:
        if(get_code_of_the_flight(flight) == code):#here we search for the flight
            flight_to_be_removed = flight

    if(flight_to_be_removed == -1):#we did not find it
        return
    else:
        Flight_List.remove(flight_to_be_removed)#we found it
def flights_by_departure_city_sorted_by_destination_city(departure_city: str, Flight_List: list):
    flights_with_given_departure_city = []

    for flight in Flight_List:
        if(get_departure_city_of_the_flight(flight) == departure_city):
            flights_with_given_departure_city.append(flight)

    sort_flights_by_destination_city(flights_with_given_departure_city)

    return flights_with_given_departure_city

def increase_duration_of_flights_flying_from_a_city(departure_city : str, increase_amount: int, Flight_List: list):
    if(increase_amount < 10 or increase_amount > 60):
        raise ValueError("Error: increase amount not in range")
    for flight in Flight_List:
        if(get_departure_city_of_the_flight(flight) == departure_city):
            increase_duration_of_the_flight(flight, increase_amount)
#
# User interface section
#
def print_menu():
    print("1: Add a flight")
    print("2: Delete a given flight")
    print("3: Show all flights with a given departure city")
    print("4: For a given city increase the duration of all flights that have the destination here")

def add_flight_UI(Flight_List: list):
    try:
        code = input("code: ")
        duration = int(input("duration: "))
        departure_city = input("departure city: ")
        destination_city = input("destination city: ")

        add_flight(code, duration, departure_city, destination_city, Flight_List)
    except ValueError as ve:
        print (ve)

def delete_flight_by_a_given_code_ui(Flight_List: list):
    code = input("code: ")

    delete_flight_by_a_given_code(code, Flight_List)

def print_all_flights_by_departure_city_sorted_by_destination_city_UI(Flight_List: list):
    departure_city = input("departure city: ")
    flights_to_be_displayed = flights_by_departure_city_sorted_by_destination_city(departure_city, Flight_List)

    for flight in flights_to_be_displayed:
        print(to_str(flight))

def increase_duration_of_flights_flying_from_a_city_UI(Flight_List: list):
    departure_city = input("departure city:")
    minute_number = int(input("increase amount:"))

    increase_duration_of_flights_flying_from_a_city(departure_city, minute_number, Flight_List)
def main():
    ADD_FLIGHT = "1"
    DELETE_FLIGHT = "2"
    SHOW_FLIGHTS_WITH_GIVEN_DEPARTURE_CITY = "3"
    INCREASE_DURATION_OF_FLIGHTS = "4"
    OPTION_LIST = [ADD_FLIGHT, DELETE_FLIGHT, SHOW_FLIGHTS_WITH_GIVEN_DEPARTURE_CITY, INCREASE_DURATION_OF_FLIGHTS]

    Flight_List = []
    add_flight("123b", 25, "cluj", "bistrita", Flight_List)
    add_flight("AEB45", 65, "mures", "cluj", Flight_List)

    function_list = {ADD_FLIGHT: add_flight_UI, DELETE_FLIGHT: delete_flight_by_a_given_code_ui,
                     SHOW_FLIGHTS_WITH_GIVEN_DEPARTURE_CITY: print_all_flights_by_departure_city_sorted_by_destination_city_UI,
                     INCREASE_DURATION_OF_FLIGHTS: increase_duration_of_flights_flying_from_a_city_UI}

    while(True):
        try:
            print_menu()

            option = input("option: ")

            if(option in OPTION_LIST):
                function_list[option](Flight_List)
        except ValueError as ve:
            print(ve)

if __name__ == "__main__":
    main()