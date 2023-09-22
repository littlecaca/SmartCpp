class Base:
    def __init__(self) -> None:
        self.num = 12
        self.name = "sd"

    def print_num(self):
        print(self.num)


class Derived(Base):
    def __init__(self, num: int) -> None:
        super().__init__()
        self.num = num


if __name__ == "__main__":
    der = Derived(33)
    der.print_num()
    print(der.__dict__)