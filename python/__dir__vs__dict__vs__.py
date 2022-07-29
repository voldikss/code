from typing import Iterable

class CMetaclass(type):
    def __new__(cls, name, bases, attrs):
        print(cls, name, bases, attrs)
        return super().__new__(cls, name, bases, attrs)

    def __dir__(self):
        return ['__new__', '__dir__']

class C(metaclass=CMetaclass):
    def __init__(self) -> None:
        self.value = 0

    def name():
        ...

    def __dir__(self) -> Iterable[str]:
        return ['value']

# print(C.__dict__)
# print(C().__dict__)
# print(vars(C))
# print(vars(C()))
print(dir(C))
print(dir(C()))
