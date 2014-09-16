% Tutorium 11
% Florian Weber
% 2. Juli 1014

Kürzeste Wege
=============

Kürzeste Wege auf DAGs
----------------------

* Erzeuge eine topologische Sortierung $S$ der Knoten
	* $\forall uv \in E$: $u$ kommt vor $v$
* Initialisiere alle Distanzen auf $\infty$
* Führe eine Runde Bellman-Ford aus (Knoten in Reihenfolge $S$!)

* Laufzeit: $O(|E|)$


Minimale Spannbäume
===================

Übersicht
---------

* Baum $\rightarrow$ zusammenhängend, nur ein Pfad zwischen zwei Knoten
* Minimal $\rightarrow$ leichtester Baum der alle Knoten verbindet
* Nur auf ungerichteten Graphen sinnvoll und primär auf gewichteten interessant

Der Jarník-Prim-Algorithmus
---------------------------

* Entdeckt von Jarník (1930), Prim (1957) und Dijkstra (1959)
* Fast identisch mit Dijkstras Algorithmus (kürzeste Wege):

 . . .

* $R := \{ \mathrm{Startknoten} \}$, $M := \emptyset$
* Solange $|R| \ne |V|$:
	* Wähle leichteste Kante $e$, die von $R$ nach $\overline{R}$ geht
	* Füge den nicht in $R$ liegenden Knoten von $e$ zu $R$ hinzu
	* $M := M \cup \{e\}$
* $M =$ Kanten des MST

. . .

* Benötigt: Prioritätsliste von $\overline{R}$, sortiert nach Kosten den Knoten hinzuzufügen
* Mit Binary-Heap: $O((|E| + |V|) \log |V|)$
* Mit Fibonacci-Heap: $O(|E| + |V| \log |V|)$

Algorithmus von Kruskal
-----------------------

* Nächste Woche
* Idee: Nehme solange die kürzeste Kante des Graphen die keinen Kreis mit bisherigen
  Kanten bildet bis diese Kanten einen MST bilden.


Nachbesprechung Mittsemesterklausur
===================================

