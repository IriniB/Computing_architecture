from extender import *
from enum import Enum
from programming_language import Language


class Typing(Enum):
    STRICT = 0
    DYNAMIC = 1


class Functional(Language):
    def __init__(self):
        self.name = ""
        self.creation_year = 0
        self.popularity = 0.1
        self.typing = Typing.STRICT
        self.lazy_evaluation_support = False

    def read_arguments(self, arguments, position):
        if position >= len(arguments) - 1:
            return 0
        self.name = arguments[position]
        self.creation_year = int(arguments[position + 1])
        self.popularity = float(arguments[position + 2])
        self.lazy_evaluation_support = bool(arguments[position + 3])
        self.typing = Typing(int(arguments[position + 4]))
        position += 5
        return position

    def create_random(self):
        self.name = ''.join(choice(ascii_letters) for i in range(randint(1, 10)))
        self.creation_year = randint(1900, 2020)
        self.popularity = random()
        self.lazy_evaluation_support = choice([True, False])
        self.typing = choice([Typing.STRICT, Typing.DYNAMIC])
        pass

    def write_in_file(self, ostream):
        ostream.write("Functional: name: {} year: {} popularity: {} support: "
                      "{} type: {} Quotient: {}"
                      .format(self.name, self.creation_year,
                              self.popularity, self.lazy_evaluation_support,
                              self.typing, self.quotient()))
        pass

    def quotient(self):
        return float(self.creation_year) / len(self.name)
        pass
