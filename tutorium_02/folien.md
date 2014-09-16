Übungsblatt 1
=============

Korrektur
---------

* Hashmaps bitte sein lassen. (diesmal kein Abzug)
* $2^n - 1 \in O(1)$ zuindest streitbar; gesucht war leftshift (mit Erklärung: -1, sonst -2)
* Partnerarbeit = cool

Plagiate - Fallbeispiel der Biologen
------------------------------------

* Protokoll im Praktikum Tierphysiologie zu viert/fünft/…
* Vor vier (?) Jahren: Gruppe bestehend aus fünf Leuten plagiiert
* Zwangsexmatrikulation der gesammten Gruppe angedacht aber dann doch noch vom Dekan haarscharf abgewandt
* Eintrag in Studienakte
* Für den Rest des Praktikums: Alle Mitglieder müssen individuelles Protokoll erstellen
* Seitdem: Unterschreiben der Regeln guter wissenschaftlicher Praxis des KIT obligatorisch
* Klare Ansage, dass nicht nochmal so gnädig verfahren werden wird.


IMO sehr gute Regelung: Das KIT ist eine Universität, keine Schule


O-Kalkül
========

Aufgaben
--------

Beweise oder Widerlege:

$$f(n) + g(n) \in O\left(\max(f(n), g(n)\right)$$

Aufgaben
--------

Beweise oder Widerlege:

$$2^n \in O\left(3^n\right)$$

Aufgaben
--------

Beweise oder Widerlege:

$$-3n^2 \in O\left(n^2\right)$$

Aufgaben
--------

Beweise oder Widerlege:

$$-3n^2 \in O\left(n^2\right)$$

Aufgaben
--------

Beweise oder Widerlege:

$$\sqrt{n} \in O\left(\log n\right)$$

Mastertheorem
-------------
Sei $T(n)$ wie folgt definiert:

$$T(n) = \begin{cases} a &\mbox{falls } n = 1\\cn + dT\left(\frac{n}{b}\right) &\mbox{sonst }\end{cases}$$

Dann gilt:

$$T(n) = \begin{cases}
	\Theta(n) &\mbox{falls } d < b\\
	\Theta(n \log n) &\mbox{falls } d = b\\
	\Theta\left(n^{\log_b d} \right) &\mbox{falls } d > b
\end{cases}$$

Diese Formel ist **WICHTIG** und **KLAUSURRELEVANT!**

Beispiele
---------

$$f(n) = n + 2 \cdot f\left(\frac{n}{3}\right)$$
$$2 < 3 \Rightarrow \Theta(n)$$


$$f(n) = n + 3 \cdot f\left(\frac{n}{3}\right)$$
$$3 = 3 \Rightarrow \Theta(n \log n)$$


$$f(n) = n + 4 \cdot f\left(\frac{n}{3}\right)$$
$$4 > 3 \Rightarrow \Theta(n^{\log_3 4}) \subset \Theta\left(n^{1,262}\right)$$

Aufgaben
--------

$$f(n) = 2.718\cdot n + \pi \cdot f\left(\frac{n}{4}\right)$$


Aufgaben
--------

$$f(n) =  2 \cdot \left(5n + 3\cdot f\left(\frac{n}{5}\right)\right) + 3$$

Korrektheitsbeweis
==================

Kreativaufgabe
--------------

* Seien A und B zwei sortierte Arrays
* Bilde ein sortiertes Array, das alle Elemente aus A und B enthält
* Beweise die Laufzeit des Algorithmus
* Beweise die Korrektheit des Algorithmus mit invarianten, pre- und postconditions

