class Player:
    def __init__(self, player_id: int, name: str, strength: int):
        self.__player_id = player_id
        self.__name = name
        self.__strength = strength

    def __str__(self):
        return f"{self.__player_id},{self.name},{self.__strength}"

    def __eq__(self, other):
        return self.__name == other.name and self.__strength == other.strength and self.__player_id == other.player_id

    @property
    def player_id(self):
        return self.__player_id

    @property
    def name(self):
        return self.__name

    @property
    def strength(self):
        return self.__strength

    def increase_strenght(self):
        self.__strength += 1
