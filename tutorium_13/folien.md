% Tutorium 13 (das letzte)
% Florian Weber
% 16. Juli 2014

generische Optimierungsansätze
==============================

Übersicht
---------

* (Ganzzahlige) Lineare Programmierung
* Greedy-Algorithmen
	* Dijkstra, Jarník-Prim, Kruskal, (Selection-Sort), …
* Dynamische Programmierung
* Systematische Suche
	* Alle (sinnvollen) Möglichkeiten durchprobieren
* Lokale Suche
	* brauchbare Lösung suchen und dann zunehmend verbessern
* Evolutionäre Algorithmen
	* „Lokale Suche auf Steroiden“

Dynamische Programmierung
-------------------------

* Idee: Optimale Lösung besteht aus optimalen Lösungen für Teilprobleme
* Was sind die Teilprobleme?
* Wie setzt sich die optimale Lösung zusammen?

. . .

* Kurzfassung: Schwer!

Beispiel: Knappsack
-------------------

* Siehe Folien und Aufzeichnung der Vorlesung

Beispiel: Levenshtein
---------------------

* Editierdistanz zwischen zwei Zeichenketten $s_1, s_2$: Wie viele Zeichen müssen bei $s_1$ gelöscht,
  ersetzt, oder ergänzt werden um $s_2$ zu erhalten?
* Erstelle Matrix $D$ der benötigten Änderungen um von jeder beliebigen Teilsequenz zu jeder anderen zu kommen:

$$D_{0, 0} = 0, D_{i, 0} = i, D_{0, j} = j$$

$$
D_{i, j} = \min \begin{cases}
D_{i - 1, j - 1}&+ 0 \ {\rm falls}\ u_i = v_j\\
D_{i - 1, j - 1}&+ 1 \ {\rm(Ersetzung)} \\
D_{i, j - 1}&+ 1 \ {\rm(Einfügung)} \\
D_{i - 1, j}&+ 1 \ {\rm(Löschung)}_\_
\end{cases}
$$



Beispiel: Levenshtein
---------------------

 \\        $\epsilon$  T o r
---------- ----------  - - -
$\epsilon$ 0           1 2 3
T          1
i          2
e          3
r          4

([Quelle: https://de.wikipedia.org/wiki/Levenshtein-Distanz](https://de.wikipedia.org/wiki/Levenshtein-Distanz))

Beispiel: Levenshtein
---------------------

 \\        $\epsilon$  T o r
---------- ----------  - - -
$\epsilon$ 0           1 2 3
T          1           0 1 2
i          2
e          3
r          4

([Quelle: https://de.wikipedia.org/wiki/Levenshtein-Distanz](https://de.wikipedia.org/wiki/Levenshtein-Distanz))

Beispiel: Levenshtein
---------------------

 \\        $\epsilon$  T o r
---------- ----------  - - -
$\epsilon$ 0           1 2 3
T          1           0 1 2
i          2           1 1 2
e          3
r          4

([Quelle: https://de.wikipedia.org/wiki/Levenshtein-Distanz](https://de.wikipedia.org/wiki/Levenshtein-Distanz))

Beispiel: Levenshtein
---------------------

 \\        $\epsilon$  T o r
---------- ----------  - - -
$\epsilon$ 0           1 2 3
T          1           0 1 2
i          2           1 1 2
e          3           2 2 2
r          4

([Quelle: https://de.wikipedia.org/wiki/Levenshtein-Distanz](https://de.wikipedia.org/wiki/Levenshtein-Distanz))


Beispiel: Levenshtein
---------------------

 \\        $\epsilon$  T o r
---------- ----------  - - -
$\epsilon$ 0           1 2 3
T          1           0 1 2
i          2           1 1 2
e          3           2 2 2
r          4           3 3 **2**

([Quelle: https://de.wikipedia.org/wiki/Levenshtein-Distanz](https://de.wikipedia.org/wiki/Levenshtein-Distanz))


Beispiel: Unabhängige Mengen (Klausur SS10)
-------------------------------------------

* Gegeben ein ungerichteter, „linearer“ Graph $G = (V, E)$ mit „Knotengewichten“
* Finde eine Menge von Knoten $U \subset V$, so dass
	* $\nexists u_1, u_2 \in U$, so dass $(u, v) \in E$
	* es keine derartige Menge mit höherer „Knotengewichtssumme“ gibt
* $\left|U\right| = n$, $U_i := \{u_1, u_2, ..., u_i\}$

. . .

* Lösung für $U_0 = \emptyset$
* Lösung für $U_1 = \{u_1\}$
* Lösung für $U_i = \mathrm{max}(U_{i-1},U_{i-2} \cup \{u_i\})$

Zusammenfassung
---------------

* Ekliges Thema
* Klausurrelevant
* Sollte man als Informatiker mal gehört haben
* **Vorlesungsfolien oder Buch durcharbeiten!**\
  (Bei Unverständlichkeit (wahrscheinlich): Vorlesung auf Youtube anschauen)


Wiederholung
============


---

![](brace_yourself.jpg)
