from distutils.core import Extension, setup

module_arith = Extension("Arithmetic",sources = ["arithmetic.c"])

setup (name = 'Arithemtic',
        version = '1.0',
        description= "Arithmetic Package to perform some basic arithmetic operations.",
        ext_modules= [module_arith])    