# solutions-paths-for-NFA
This is a school assigment that i want to share, it has limitations and areas to be improved but as far as i know it works. Let me know how I can improve it, thanks :).

This program is capable of printing all the solution paths for a given non deterministic finite automata, the automaton must be written in .txt file 
with the next format in order to work as intended:

0,1,2     //these are the states

a,b       //these are the edges

0         //initial state

2,0      //final states

0,a,0    //the connections between states, where the first element is the current state, second the connector/edge and third the resulting state. f1(2)=3

0,a,1

0,b,0

1,b,2

1,a,2

note that each element must be separated by comas and must be only one character long.
