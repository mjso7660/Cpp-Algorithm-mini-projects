# mini-projects
mini-projects from CodeCon

## 1. Volleyball rotations
Players between 7 and 26 people on my team. Every rotation, one of the sidelines players will come into the court at position 1 while
one player will eave the court at position 2 and join the sideline at the back of the line

-------------------
|  4  |  3  |  2 -|->
|-----------------|
|  5  |  6  |  1 <|--
-------------------
Setter will always be in the starting lineup and will not be rotated off the court
Input specification:
1. # of rotations
2. name of the setter
3. The starting lineup
4. The players on the sidelines
Find: the lineup after the N number of rotations ordering them based on they will end up
INPUT(example):
3
A
A B C D E F 
4 G H I J
OUTPUT:
I E F A G H

## #2 Sum Sum Cryptography
B sends A a positive int N as the message and A decoes each message by solving x^2+y^2+z^2=N.
 Input Specs:
 3<=N<=3000000
 Output:
 Sum of all components of all unique (x,y,z) tuples

## #3 Dependency Gambit
 Given a list of libs & their dependencies, and a target library we want to build, print out the perfect linkline according to the rules listed in the Output Specs
  Input Specs:
  1. Target lib
  2. # of libs and dependencies
  3 ~ [lib-name] [Q] [dep-1] [dep-2]
  (example):
  lib-x
  3
  lib-x 2 lib-a lib-b
  lib-a 1 lib-b
  lib-b 0
  Output:
  The linkline for the target library
  (example):
  lib-a lib-b lib-c lib-x
  
  ## #4 Halloween Candy
  Find the max cost path within given # of path from the source to the target
