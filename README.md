# 21_push_swap
Algorithmic project to understanding the quicksort algorithm

## Goal of push_swap project

The goal is to sort array of integers using two staks.

## How to Run this

`./push_swap [array_of_int]` - show you commands for sorting array.

         `[array_of_int]` - input array.
    
`[comands] ./checker [-c][-v][array_of_int]` - return result `OK` or `KO` if they sorting input array.

         `[array_of_int]` - input array.
         `[comands]` - array of commands from stdin for sorting input array.
         `-c` - show in colours the last operation.
         `-v` - display the stack’s status after each operation.



## Running examples

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker -c $ARG

<img src="demos/flag c.png" alt="Ants ways" width="720px">

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker -vc $ARG

<img src="demos/flag vc.png" alt="Ants ways" width="720px">

## Explanation of commands

| Operation  | Description  |
| ---------- | ------------ |
**sa (sb)**| swap a(b) - swap the first 2 elements at the top of stack a(b).
**ss**| **sa** and **sb** at the same time.
**pa (pb)**| push a(b) - take the first element at the top of b(a) and put it at the top of a(b).
**ra (rb)**| rotate a(b) - shift up all elements of stack a by 1. The first element becomes the last one.
**rr**| **ra** and **rb** at the same time.
**rra (rrb)**| reverse rotate a(b) - shift down all elements of stack a by 1. The last element becomes the first one.
**rrr** | **rra** and **rrb** at the same time.

## Rebiuld the programs

Run `make`, an executables called `push_swap` and `checker`. 

