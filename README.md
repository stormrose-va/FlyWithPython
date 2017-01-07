# PIX - Python Interface for X-Plane

This project repository contains all code of PIX, a new Python Interface for
[X-Plane](http://x-plane.com). This project aims at providing a successor for
the well-known but abandoned
[Python Interface](http://www.xpluginsdk.org/python_interface.htm) by Sandy
Barbour.


## Project Objectives

PIX is being developed for a couple of reasons, although the legacy Python
interface still works. These reasons also form the objectives of this project:

* **Open Source Develoment:** Sandy's work cannot be continued by the community
  as he decided to keep the sources closed. PIX on the contrary is Open Source,
  licensed under one of the most permissive licenses available.
* **Python 3 Compatibility:** The latest published legacy Python interface only
  works with a quite dated version of the Python 2.7 branch. PIX is designed to
  bring the latest Python 3 to X-Plane.
* **Improved Encapsulation:** With the legacy interface, all scripts used the
  same runtime environment, sometimes creating conflicts for third-party
  dependencies. PIX offers the ability to use dedicated virtual environments for
  each script, resolving this problem.


## FAQ

#### Will scripts created for Sandy Barbour's Python Interface run on PIX?
PIX is not a drop-in replacement for the previous Python interface. Thus, most
probably existing scripts will not work out of the box with PIX, but will need
some adaptation to the new structures. Furthermore, PIX will work by default
with a Python 3 interpreter, so most probably also the Python code itself will
need some love & care before it can run on PIX.

#### Will you provide an installer bundle?
That is not yet decided. We seek at providing a stable release first before
thinking about any bundling (that would require some careful studying of
licenses not only of Python itself, but of all other 3rd party stuff included to
prevent us from being sued for distributing stuff we were not allowed to do so).

#### Will you support all three OSes X-Plane runs on?
That is certainly one of our objectives, but this will depend on whether we can
get hold of a sufficient number of testers for the different platforms.
Particularly Linux could prove to be difficult to be supported due to the high
number of flavours, coming all with different versions of the Python
interpreter.

#### Will X-Plane 11 be supported?
Indeed, PIX is being develped mainly for X-Plane 11. Concerning X-Plane 10
compatibility, we currently don't see massive obstacles that would prevent us
from maintaining also an X-Plane 10 compatible version. This may however change
at some point in the future, should the X-Plane API and SDK change
significantly.

#### When will it be ready?
For the time being, we cannot tell. PIX is being developed by volunteers in
their leisure time, so the resources we can dedicate to this project are
limited. On top of that, the main target platform for PIX is X-Plane 11. So
don't expect a too soon release, as we will have to wait for XP11 becoming a
final release before we can think about finishing our work on PIX.
