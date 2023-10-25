from setuptools import setup, Extension

module = Extension('addmodule', sources=['add.c'])

setup(name='AddModule',  # the display name.
      version='1.0',
      description="python c interface to add two num",
      ext_modules=[module]
      )