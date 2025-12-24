def curry(func, arity):

    #Проверка арности
    if not isinstance(arity, int):
        raise TypeError("arity must be an integer")
    if arity < 0:
        raise TypeError("arity cannot be negative")


    if arity == 0:
        return func()


    def curried(*args):
        #Если передано достаточно аргументов, вызываем исходную функцию
        if len(args) >= arity:
            return func(*args)
        else:
            """
            Если аргументов недостаточно, возвращаем новую функцию,
            которая будет помнить уже переданные аргументы
            """
            def next_curried(*new_args):
                return curried(*new_args + args)
            return next_curried

    return curried


def uncurry(curried_f, arity):
    
    #Проверка арности
    if not isinstance(arity, int):
        raise TypeError("arity must be an integer")
    if arity < 0:
        raise TypeError("arity cannot be negative")

    def uncurried(*args):
        #Проверяем, что передано правильное количество аргументов
        if len(args) != arity:
            raise TypeError(f"function takes exactly {arity} arguments ({len(args)} given)")
        #Последовательно применяем каждый аргумент к каррированной функции
        res = curried_f
        for el in args:
            res = res(el)
        return res
    return uncurried

def f(x, y, z):
    return x + y + z

f_curry = curry(f, 3)
print(f_curry(1)(2)(3))
f_uncurry = uncurry(f_curry, 3)
print(f_uncurry(1,2,3))
            

    
