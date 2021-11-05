import sys
from extender import *

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("Incorrect command line!\n"
              "  Waited:\n"
              "     command file InputFile.txt OutputContainerFile.txt\n"
              "   or   command rand OutputContainerFile.txt array_size\n")
        exit()

    is_random_input = False
    if sys.argv[1] == "rand":
        is_random_input = True

    print("Start")
    container = Container()

    output_file_name = ""
    read_objects_number = 0
    if not is_random_input:
        input_file = open(sys.argv[2])
        input_string = input_file.read().replace("\n", " ")
        read_objects_number = read_arguments(container, input_string.split(" "))
        output_file_name = sys.argv[3]
        input_file.close()
    else:
        length = int(sys.argv[3])
        if length > 10000 or length < 0:
            print("Not appropriate size of container\n")
            exit()
        read_objects_number = random_create_arguments(container, length)
        output_file_name = sys.argv[2]

    print("Was able to read ", read_objects_number, " languages")
    output_file = open(output_file_name, 'w')
    container.write_in_file(output_file)

    container.bubble_sort()
    output_file.write("\n\n\n--------------------------After sorting--------------------------\n")
    container.write_in_file(output_file)
    output_file.close()

    print("The process is completed\n")
