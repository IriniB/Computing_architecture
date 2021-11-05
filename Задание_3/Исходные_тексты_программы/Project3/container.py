class Container:
    def __init__(self):
        self.store = []

    def bubble_sort(self):
        length = len(self.store)
        for i in range(length - 1):
            for j in range(length - i - 1):
                if self.store[j + 1].quotient() > self.store[j].quotient():
                    self.store[j], self.store[j + 1] = self.store[j + 1], self.store[j]

    def write_in_file(self, ostream):
        ostream.write("Container contains {} elements.\n".format(len(self.store)))
        for language in self.store:
            language.write_in_file(ostream)
            ostream.write("\n")
        pass
