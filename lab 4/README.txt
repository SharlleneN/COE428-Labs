The file runs fine, most features work however the garbage collection was persistently giving me an error and not giving the correct output. The garbage collection kept saying "no garbage detected". This was persistent however everything else worked correctly. 

Most of the code was done fairly early on, but the garbage detection took me a lot of time and I kept getting errors when I tried coding it intuitively. Instead, I ended up coming across DFS and BFS algorithms and chose to use DFS since I already had a Boolean array created that I could work with. The function to mark all the reachable states was recursive and took the current state index and had a Boolean array which kept track of all the states that are reachable. 

