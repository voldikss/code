from typing import Any


class C:
    def __init__(self) -> None:
        ...

    def __getattribute__(self, name: str) -> Any:
        print("__getattribute__", name)
        # raise AttributeError
        return None

    # fallback
    def __getattr__(self, name):
        print("__getattr__", name)
        return None


c = C()
print(c.value)
