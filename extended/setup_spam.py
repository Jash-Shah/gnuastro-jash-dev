from distutils.core import setup, Extension

module_spam = Extension("spam",sources=["spammodule.c"])

setup (name = 'Spam',
        version = '1.0',
        description= "Spam Package.",
        ext_modules= [module_spam])     

# module_custom = Extension(name="custom",sources=["custom.c"])

# setup(name="custom",version="1.0",ext_modules=[module_custom])