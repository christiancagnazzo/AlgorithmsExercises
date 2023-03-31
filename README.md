# Laboratory of algorithms and data structures
Exercises carried out for the laboratory course of algorithms and data structures at the University of Turin

### Exercise 1

#### Programming Language: C

Implement a library that offers the following sorting algorithms:

- __Insertion Sort__
- __Quicksort__

The code that implements each algorithm must be _generic_. Furthermore, each algorithm must allow to specify (that is, it must accept as input) the criterion according to which to sort the data.

### Exercise 2

#### Programming Language: Java

Consider the problem of determining the edit distance between two strings (Edit distance): given two strings s1 and s2, not necessarily of the same length, determine the minimum number of operations necessary to transform the string s2 into s1. Assume that the available operations are: deletion and insertion. Examples:

- "_casa_" and "_cassa_" have an edit distance of 1 (1 deletion);
- "_casa_" and "_cara_" have an edit distance of 2 (1 deletion + 1 insertion);
- "_vinaio_" and "_vino_" have edit distance=2 (2 entries);
- "_tassa_" and "_passato_" have an edit distance of 4 (3 cancellations + 1 insertion);
- "_pioppo_" and "_pioppo_" have an edit distance of 0.


1. Implement a recursive version of the edit\_distance function based on the following observations (we indicate with $|s|$ the length of $s$ and with $\mathrm{rest}(s)$ the substring of $s$ obtained ignoring the first character of $s$):

- if $|s1|$ = 0, then $\mathrm{edit\_distance}(s1,s2) = |s2|$;
- if $|s2|$ = 0, then $\mathrm{edit\_distance}(s1,s2) = |s1|$;
- otherwise, if:
  - $d_{\mathrm{no-op}} =
        \begin{cases}
        \mathrm{edit\_distance}(\mathrm{rest}(s1),\mathrm{rest}(s2)) & \mathrm{se\ } s1[0]=s2[0] \\
        \infty & \mathrm{otherwise}
        \end{cases}$
  - $d_{\mathrm{canc}} = 1+ \mathrm{edit\_distance}(s1,\mathrm{rest}(s2))$
  - $d_{\mathrm{ins}} = 1+ \mathrm{edit\_distance}(\mathrm{rest}(s1),s2)$

We have: $\mathrm{edit\_distance}(s1,s2)=\min\{d_{\mathrm{no-op}},d_{\mathrm{canc}},d_{\mathrm{ins}}\}$

2. Implement a second edit\_distance\_dyn version of the function, adopting a dynamic programming strategy. This version must also be recursive (in particular, it can be easily obtained starting from the implementation requested in the previous point).

*Note*: The above definitions do not correspond to the usual way of defining the edit distance. However, they are completely sufficient to solve the exercise and they are the ones on which the product code will have to be based.

Implement an application that uses the edit\_distance\_dyn function to determine, for each word w in correctme.txt, the list of words in dictionary.txt with minimum edit distance from w. Test the functioning of the application and report the results of the experiments in a short report (about one page).


### Esercizio 3

#### Programming Language: C

Implement a library for the Hash Map data structure, taking into account the following indications:

- A Hash Map represents a set of associations of the type `<K,V>`, where K is a key and V is the value associated with it;
- in a Hash Map, there cannot be repeated keys;
- the implementation exploits a hashing mechanism;
- Your implementation must offer the following operations:
   - creation of an empty Hash Map;
   - destruction of a Hash Map (with consequent deallocation of the associated memory);
   - check if a Hash Map is empty;
   - recovery of the number of associations present in a Hash Map;
   - cancellation of all the associations of a Hash Map;
   - check if the specified key is present in a Hash Map;
   - insertion in a Hash Map of an association of type `<K,V>`;
   - recovery from a Hash Map of any value associated with the specified key
   - cancellation from a Hash Map of any association with a specified key
   - recovery of the set of keys present in a Hash Map
- The code implementing the Hash Map must be generic (in the sense that it must allow the insertion of `<K,V>` associations of which neither the type of the key K nor that of the value V is known at compile time) and must not assume any maximum cardinality for the set of associations that can be hosted in the Hash Map.

### Exercise 4

#### Programming Language: Java

Consider a connected graph with $N$ nodes and $N-1$ bidirectional edges weighted with an integer weight $W$. The problem arises of finding an efficient algorithm to answer $Q$ distinct queries.

A query consists of a new arc weighted $q$. The algorithm must answer `YES` if $q$ allows to reduce the overall weight of the graph, `NO` otherwise. The arc $q$ satisfies this condition if there exists an arc $e$ such that it is possible to substitute $q$ for $e$ while leaving the graph connected and decreasing its overall weight. The execution of the single query must not modify the graph (i.e., the starting graph is always the same).

The input files start with a line containing the number $N$ of nodes of the graph followed by $N-1$ lines containing the arcs. Each line specifying an arc contains `3` integers separated by spaces: the source node, the destination node and the weight of the arc.

The files continue with a line containing the $Q$ number of queries to answer. This is followed by $Q$ lines containing the queries. Each query is in the same format used to describe arcs.

The program output must consist of exactly $Q$ lines containing `YES` or `NO` depending on whether the answer to the corresponding query is positive (the arc object of the query reduces the weight of the graph) or negative (vice versa) .

You can assume the following:

- $1 \leq N \leq 100\,000$
- $1 \leq Q \leq 100\,000$
- the nodes are integers that assume values in the range $[1, 100\,000]$
- for each edge $(u,v,w): u \neq v \wedge w \in [1, 1\,000\,000\,000]$.

### Example:

#### Input:
```
6
1 2 2
1 3 3
3 4 5
3 5 4
2 6 4
4
1 4 4
4 5 6
2 3 8
1 6 3
```

#### Output:

```
YES
NO
NO
YES
```



