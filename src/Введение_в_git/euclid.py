# a*x + b*y = gcd - соотношение Безу, где a и b - заданные числа

def gcd_ext(a, b):
    if b == 0:
        return a, 1, 0
    else:
        gcd, x, y = gcd_ext(b, a % b)
        """
        b*x + (a % b) * y = gcd
        b*x + (a - (a // b) * b) * y = gcd
        a*y + b*(x - (a // b) * y) = gcd
        Необходимо преобразовать коэффициент x(x - (a // b) * y) и поменять коэффициенты местами
        """  
        x -= (a // b) * y
        x, y = y, x  
        return gcd, x, y

# Фунцция возвращает НОД и коэффициенты x, y для соотношения Безу

a = int(input('a:'))
b = int(input('b:'))

print(gcd_ext(a, b))
