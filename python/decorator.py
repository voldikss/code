from typing import Any
from time import sleep
from functools import wraps


# class as decorator
class Timer:
    def __init__(self, func) -> None:
        self._func = func

    # 对象实例可以当作函数调用
    def __call__(self, *args: Any, **kwargs: Any) -> Any:
        self._func(*args, **kwargs)


def timer(msg: str):
    def wrap_func(func):
        @wraps(func)
        def inner_func(*args, **kwargs):
            res = func(*args, **kwargs)
            return res

        print("func name", inner_func.__name__)
        return inner_func

    return wrap_func


# @timer('hello')
# or
@Timer
def worker(time_s: int):
    sleep(time_s)


# worker = timer('hello')(worker)

worker(1)
