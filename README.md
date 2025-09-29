
## water meter simulator

A water flow meter simulator fictionally meant for the
water utility company [CAGEPA][1], as a supporting tool for other
software systems to consume without relying on actual video footage
from a working installed water meter.

The meter needs to function continuously, updating
its image when the cubic meter counter changes or at an interval
specified in a configuration file.

The overall motivation for it is to serve as an initial experience
with requirement analysis, before starting the study of design patterns.
It's anticipated that after knowing about them, the student immediately
recalls from this project a possible practical application.

To make the [class diagram][4] ([source][5]), [planttext][2] was used, using the
[PlantUML language][3].

Water meter [image][7] background was screenshot from [How to use your water
meter][6] (PDF in brazilian portuguese) from Grupo Águas do Brasil,
accessed monday, 2025-09-29.

[1]: https://www.cagepa.pb.gov.br/
[2]: https://planttext.com
[3]: https://plantuml.com
[4]: docs/class-diagram.pdf
[5]: docs/class-diagram.puml
[6]: https://www.grupoaguasdobrasil.com.br/wp-content/uploads/2018/04/como-usar-seu-hidrometro.pdf
[7]: meter_bg.png

## how to build on Windows 10

Dependencies:
- raylib
- Git Bash (for cloning, optional)

First install raylib locally through this [page][8], it
has an installer that you can run and just wait while
it creates and configures a new mingw environment
under `C:\raylib` (default path).
A new shell environment should be available at
`C:\raylib\w64devkit\w64devkit.exe` it's a MinGW
instance.

Clone this git repository using Git Bash
(it doesn't come with raylib) or simply extract
it on a folder if you don't plan on using git.

Launch that .exe we reffered above. It should leave
you at your home directory (`C:\Users\<username>\`);
from there `cd` to this project's folder
and run `make`; if all went well you should have
the simulator executable at the same folder,
under `meter-sim.exe`.  Now you can run it using
`./meter-sim.exe` or double click it through
File Explorer and the simulation starts.

It takes about 5 seconds to see the count change, as it's
hard-coded at the moment at an exaggerated flow
of 2 L/s.  You can change that editing [water_meter.cpp][9]
at both Pipe's instantiations in the constructor,
first value is flow in L/s, the second is maximum flow.

[8]: https://raysan5.itch.io/raylib
[9]: src/water_meter.cpp
