from extender import *
from enum import Enum
from programming_language import Language


class Inheritance(Enum):
    SINGLE = 0
    PLURAL = 1
    INTERFACE = 2


class ObjectOriented(Language):
    def __init__(self):
        self.name = ""
        self.creation_year = 0
        self.popularity = 0.1
        self.inheritance = Inheritance.SINGLE

    def read_arguments(self, arguments, position):
        if position >= len(arguments) - 1:
            return 0
        self.name = arguments[position]
        self.creation_year = int(arguments[position + 1])
        self.popularity = float(arguments[position + 2])
        self.inheritance = Inheritance(int(arguments[position + 3]))
        position += 4
        return position

    def create_random(self):
        self.name = ''.join(choice(ascii_letters) for i in range(randint(1, 10)))
        self.creation_year = randint(1900, 2020)
        self.popularity = random()
        self.inheritance = choice([Inheritance.SINGLE, Inheritance.PLURAL, Inheritance.INTERFACE])
        pass

    def write_in_file(self, ostream):
        ostream.write("ObjectOriented: name: {} year: {} popularity: {} inheritance: {} Quotient: {}"
                      .format(self.name, self.creation_year,
                              self.popularity, self.inheritance, self.quotient()))
        pass

    def quotient(self):
        return float(self.creation_year) / len(self.name)
        pass
