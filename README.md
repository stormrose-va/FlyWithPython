# FlyWithPython - New Python Interface for X-Plane


[![Documentation Status](https://readthedocs.org/projects/flywithpython/badge/?version=latest)](https://flywithpython.readthedocs.io/?badge=latest)
[![Join the chat at https://gitter.im/stormrose-va/FlyWithPython](https://badges.gitter.im/stormrose-va/FlyWithPython.svg)](https://gitter.im/stormrose-va/FlyWithPython?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

This project repository contains all code of FlyWithPython, a new Python
Interface for [X-Plane](http://x-plane.com). This project aims at providing a
successor for the well-known but abandoned
[Python Interface](http://www.xpluginsdk.org/python_interface.htm) by Sandy
Barbour.


## Project Objectives

FlyWithPython is being developed for a couple of reasons, although the legacy
Python interface still works. These reasons also form the objectives of this
project:

* **Open Source Develoment:** Sandy's work cannot be continued by the community
  as he decided to keep the sources closed. FlyWithPython on the contrary is
  Open Source, licensed under one of the most permissive licenses available.
* **Python 3 Compatibility:** The latest published legacy Python interface only
  works with a quite dated version of the Python 2.7 branch. FlyWithPython is
  designed to bring the latest Python 3 to X-Plane.
* **Improved Encapsulation:** The legacy interface relied on a system-wide
  installed Python interpreter, sometimes creating conflicts with third-party
  dependencies or simply version mayhem. FlyWithPython bundles a dedicated
  Python interpreter to avoid such problems.


## FAQ

#### Will scripts created for Sandy Barbour's Python Interface run on FlyWithPython?
FlyWithPython is not a drop-in replacement for the previous Python interface.
Thus, most probably existing scripts will not work out of the box with
FlyWithPython, but will need some adaptation to the new structures. Furthermore,
FlyWithPython will work by default with a Python 3 interpreter, so most probably
also the Python code itself will need some love & care before it can run on
FlyWithPython.

#### Will you provide an installer bundle?
We hope there won't be a need for complex installer bundles. We seek at creating
a traditional plugin package which won't need any third party packages to be
installed on your computer. However, our first priority is providing a stable
release before thinking about any bundling (that would require some careful
studying of licenses not only of Python itself, but of all other 3rd party stuff
included to prevent us from being sued for distributing stuff we were not
allowed to).

#### Will you support all three OSes X-Plane runs on?
That is certainly one of our objectives, but this will depend on whether we can
get hold of a sufficient number of testers for the different platforms.
Particularly Linux could prove to be difficult to be supported due to the high
number of flavours, coming all with different versions of the Python
interpreter.

#### Will X-Plane 11 be supported?
Indeed, FlyWithPython is being develped only for X-Plane 11.10 and later
versions. This project uses the most recent API SDK (version 3.0) and thus is
not compatbile with older X-Plane versions.

#### When will it be ready?
For the time being, we cannot tell. FlyWithPython is being developed by
volunteers in their leisure time, so the resources we can dedicate to this
project are limited.
