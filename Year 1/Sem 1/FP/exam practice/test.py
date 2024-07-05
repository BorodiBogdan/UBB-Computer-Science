listt = []

def f(count: int, data: list):
    listt.append(1)
    if count != 1:
        if len(data) < 10:
            data.append(count)

        f(count - 1, data)
        f(count - 1, data)
    else:
        print(count, data)

if __name__ == "__main__":
    list = []
    count = 10
    f(count, list)
    print(len(listt))

