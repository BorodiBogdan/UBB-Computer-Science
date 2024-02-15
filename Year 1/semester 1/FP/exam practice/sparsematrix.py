

class SparseMatrix:
    def __init__(self, rows, columns):
        self.__rows = rows
        self.__columns = columns
        self.__stored_values = {}

    def set(self, row, column, value):
        if row >= self.__rows or column >= self.__columns:
            raise ValueError()

        self.__stored_values[(row, column)] = value

    def __str__(self):
        returned_string = ""

        for i in range(0, self.__rows):
            for j in range(0, self.__columns):
                if (i, j) in self.__stored_values.keys():
                    returned_string += str(self.__stored_values[(i, j)]) + " "
                else:
                    returned_string += "0 "

            returned_string += "\n"

        return returned_string

    def get(self, row, column):
        if (row, column) in self.__stored_values.keys():
            return self.__stored_values[(row,column)]

        return 0


if __name__ == "__main__":
    m1 = SparseMatrix(3, 3)
    m1.set(1,1, 2)
    m1.set(2,2,4)
    print(m1)

    try:
        m1.set(3, 3, 99)
    except Exception as ve:
        print(type(ve))

    m1.set(1,1,m1.get(1,1) + 1)

    print(m1)
    