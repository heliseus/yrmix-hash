from distutils.core import setup, Extension

yrmix_hash_module = Extension('yrmix_hash',
                                 sources = ['yrmixmodule.c',
                                            'yrmix.c',
                                            'sha3/blake.c',
                                            'sha3/bmw.c',
                                            'sha3/groestl.c',
                                            'sha3/jh.c',
                                            'sha3/keccak.c',
                                            'sha3/skein.c',
                                            'sha3/cubehash.c',
                                            'sha3/echo.c',
                                            'sha3/luffa.c',
                                            'sha3/simd.c',
                                            'sha3/shavite.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'yrmix_hash',
       version = '1.3.1',
       description = 'Binding for Dash X11 proof of work hashing.',
       ext_modules = [yrmix_hash_module])
