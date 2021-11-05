from extender import *


def read_arguments(container, arguments_array):
    length = len(arguments_array)
    position = 0
    read_objects_number = 0
    while position < length - 1:
        key = int(arguments_array[position])
        if key == 1:
            position += 1
            language = Functional()
            position = language.read_arguments(arguments_array, position)
        elif key == 2:
            position += 1
            language = ObjectOriented()
            position = language.read_arguments(arguments_array, position)
        elif key == 3:
            position += 1
            language = Procedural()
            position = language.read_arguments(arguments_array, position)
        else:
            return read_objects_number

        if position == 0:
            return read_objects_number

        read_objects_number += 1
        container.store.append(language)
    return read_objects_number


def random_create_arguments(container, length):
    position = 0
    create_objects_number = 0
    while position < int(length):
        key = randint(1, 3)
        if key == 1:
            position += 1
            language = Functional()
            language.create_random()
        elif key == 2:
            position += 1
            language = ObjectOriented()
            language.create_random()
        elif key == 3:
            position += 1
            language = Procedural()
            language.create_random()
        else:
            return create_objects_number

        if position == 0:
            return create_objects_number

        create_objects_number += 1
        container.store.append(language)
    return create_objects_number
