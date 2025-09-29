
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
