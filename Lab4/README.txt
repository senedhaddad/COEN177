Procedure: I wrote two different programs − one for reading in a random pattern and one for reading in a sequential pattern. The random function uses the fseek function for randomization.

Conclusion: Randomized was noticeably slower than the sequential program. The time it takes to read a file using a specific reading pattern grows proportionally to the size of the file. I included a graph with the times and the text file sizes as well. The times show that sequential is faster than random, and the time grows proportionally to the size of the text file.s
