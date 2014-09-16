Organisatorisches
=================

Blatt 4
-------

* Unsauberer Code $\Longrightarrow$ strengere Korrektur
* Abgabe zu zweit: Nur ein Partner gibt ab, der andere steht in einem Kommentar

Vorrechnen Hase-Igel-Algorithmus
--------------------------------

* In Zukunft: Wenn ihr die Lösung online findet: Hinschreiben das dies der Fall ist und
  demonstrieren, dass ihr sie auch wirklich verstanden habt. Sollte nicht zur Regel werden.

Hashing
=======

Hashing mit verlinkten Listen
-----------------------------

* Wurde schon letztes mal besprochen.
* Fragen?

Hashing mit linearer Suche
--------------------------

* Keine zusätzlichen Allokationen
* Cache-effizient
* keine referentielle Integrität
* schlechter bei hohem Füllstand

. . .

* Abwägungungssache: Laufzeiten an sich vergleichbar

Beispiele
---------

* 13 Slots
* `hash(n: uint) = n mod 13`
* Füge ein: 17, 4, 3, 5, 11, 8, 6, 23, 42, 37, 18
* Entferne: 3

Kreativaufgabe
==============

Kreativaufgabe
--------------

* SparseArray
* Platz in $O(n)$
* Erzeugen in $O(1)$
* `get()` und `set()` in $O(1)$
* Reset in $O(1)$
* Allozieren von uninitialisiertem Speicher in $O(1)$

Deamortisierung
===============

