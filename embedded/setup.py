from distutils.core import setup, Extension

moduel_emb = Extension('emb',sources=['embedding.c'])

setup(name = 'Embedded', 
      version = '1.0',
      description = 'Embedded Python Script',
      ext_modules=[moduel_emb])