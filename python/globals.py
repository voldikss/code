def load_func():
    print("loading")


globals().setdefault("load", load_func)

load() # type: ignore

print(globals())
print(locals())
print(globals() == locals())
