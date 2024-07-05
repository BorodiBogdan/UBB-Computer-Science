def Test():
    try:
        p = input()

        assert float(p) < 0, "ERROR"

    except ValueError as ae:
        print(ae)

while(True):
    Test()