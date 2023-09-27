class Base:
    def __init__(self) -> None:
        self.num = 12
        self.name = "sd"

    def print_num(self) -> None:
        print(self.num)

    def out(self) -> None:
        print("I am the Base class")


class Derived(Base):
    def __init__(self, num: int) -> None:
        super().__init__()
        self.num = num
    
    def out(self) -> None:
        super().out()
        print("and I am the Derived class")


if __name__ == "__main__":
    der = Derived(33)
    der.print_num()
    print(der.__dict__)

    print("-" * 40)
    der.out()