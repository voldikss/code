# 读取属性时，如T.d,返回的是d.__get__(None, T)的结果，t.d返回的是d.__get__(t, T)的结果。
# 设置属性时，t.d = value，实际上调用d.__set__(t, value)，T.d = value，这是真正的赋值，T.d的值从此变成value。删除属性和设置属性类似。


class Descriptor:
    def __init__(self, value: float = 3.14) -> None:
        self.value = value

    def __get__(self, instance, cls):
        print("__get__")
        print(instance)
        print(cls)
        return self.value

    def __set__(self, instance, value):
        print("__set__")
        self.value = float(value)


class Clazz:
    prop = Descriptor()


c = Clazz()
c.prop = 0.618
print(c.prop)


##############################################################################

# https://stackoverflow.com/questions/3798835/understanding-get-and-set-and-python-descriptors
# 描述符 数据描述符


def has_descriptor_attrs(c: type):
    return bool(set(["__get__", "__set__", "__delete__"]).intersection(dir(c)))


def is_descriptor(c: type):
    return has_descriptor_attrs(c)


def has_data_descriptor_attrs(c: type):
    return bool(set(["__set__", "__delete__"]).intersection(set(dir(c))))


def is_data_descriptor(c: type):
    return has_data_descriptor_attrs(c)


print(is_descriptor(classmethod), is_data_descriptor(classmethod))
print(is_descriptor(staticmethod), is_data_descriptor(staticmethod))
print(is_data_descriptor(property))

##############################################################################

# - 属性查找策略，对于 obj.attr = value
#
#     1.如果attr是一个Python自动产生的属性，找到！(优先级非常高！)
#
#     2.查找obj.__class__.__dict__，如果attr存在并且是**data descriptor**，返回data descriptor的__get__方法的结果，如果没有继续在obj.__class__的父类以及祖先类中寻找data descriptor
#
#     3.在obj.__dict__中查找，这一步分两种情况，第一种情况是obj是一个普通实例，找到就直接返回，找不到进行下一步。第二种情况是obj是一个类，依次在obj和它的父类、祖先类的__dict__中查找，如果找到一个descriptor就返回descriptor的__get__方法的结果，否则直接返回attr。如果没有找到，进行下一步。
#
#     4.在obj.__class__.__dict__中查找，如果找到了一个descriptor(插一句：这里的descriptor一定是non-data descriptor，如果它是data descriptor，第二步就找到它了)descriptor的__get__方法的结果。如果找到一个普通属性，直接返回属性值。如果没找到，进行下一步。
#
#     5.很不幸，Python终于受不了。在这一步，它raise AttributeError
#
# - 对属性赋值时的查找策略，对于 obj.attr = value
#
#     1.查找obj.__class__.__dict__，如果attr存在并且是一个data descriptor，调用attr的__set__方法，结束。如果不存在，会继续到obj.__class__的父类和祖先类中查找，找到 data descriptor则调用其__set__方法。没找到则进入下一步。
#
#     2.直接在obj.__dict__中加入obj.__dict__['attr'] = value


class Name:
    def __get__(self, instance, clazz):
        return "alan"

    def __set__(self, instance, value):
        ...


class CC:
    name = Name()


c = CC()
c.__dict__["name"] = Name()
print(c.__dict__)
print(c.name)


##############################################################################
# 如果属性不是类得实例，你可以自己搞个元类，把__get__方法加上，type没有


class MetaClassForD(type):
    def __new__(cls, name, bases, attrs):
        print(
            "cls",
            cls,
        )
        print("name", name)
        print("bases", bases)
        print("attrs", attrs)
        print("__new__")
        return type.__new__(cls, name, bases, attrs)

    def __get__(self, instance, clazz):
        print("__get__ in MetaClassForD")
        return None


class D(metaclass=MetaClassForD):
    name = "D"

    def __get__(self, instance, clazz):
        print("__get__")
        return 5


class C:
    attr = D

    def func(self):
        print("func")
        print(self)


c = C()
print(c.attr)
##############################################################################

# python版本使用非数据描述符的实现方法:


class StaticMethod(object):
    "Emulate PyStaticMethod_Type() in Objects/funcobject.c"

    def __init__(self, f):
        self.f = f

    def __get__(self, obj, objtype=None):
        return self.f


# classmethod()使用无数据描述符协议实现:


class ClassMethod(object):
    "Emulate PyClassMethod_Type() in Objects/funcobject.c"

    def __init__(self, f):
        self.f = f

    def __get__(self, obj, klass=None):
        if klass is None:
            klass = type(obj)

        def newfunc(*args):
            return self.f(klass, *args)

        return newfunc
