from extender import *
from programming_language import Language


class Procedural(Language):
    def __init__(self):
        self.name = ""
        self.creation_year = 0
        self.popularity = 0.1
        self.has_abstract_data_types = False

    def read_arguments(self, arguments, position):
        if position >= len(arguments) - 1:
            return 0
        self.name = arguments[position]
        self.creation_year = int(arguments[position + 1])
        self.popularity = float(arguments[position + 2])
        self.has_abstract_data_types = bool(arguments[position + 3])
        position += 4
        return position

    def create_random(self):
        self.name = ''.join(choice(ascii_letters) for i in range(randint(1, 10)))
        self.creation_year = randint(1900, 2020)
        self.popularity = random()
        self.has_abstract_data_types = choice([True, False])
        pass

    def write_in_file(self, ostream):
        ostream.write("Procedural: name: {} year: {} popularity: {} abstract: {} Quotient: {}"
                      .format(self.name, self.creation_year,
                              self.popularity, self.has_abstract_data_types, self.quotient()))
        pass

    def quotient(self):
        return float(self.creation_year) / len(self.name)
        pass
