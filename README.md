# push_swap

Push swap is a project about coding a sorting algorithm that sorts a set of integers using stack operations.<br><br>
You're given 2 stacks:<br>
- one of them has an integer set to be sorted (stack_a)<br>
- and the other one is empty at the beginning (stack b).<br>

I've taken inspiration from [@alx-sch](https://github.com/alx-sch)'s [Enhanced Turk Algorithm](https://github.com/alx-sch/42_push_swap) for the algorithm.<br>
But of course, the code is entirely my own.
## operations

| push | swap | rotate | reverse rotate
|----|----|----|----|
|pa:<br>pushes the first element of stack_b to the top of stack_a<br><br>pb:<br>pushes the first element of stack_a to the top of stack_b|sa:<br>swaps the first two elements in stack_a<br><br>sb:<br>swaps the first two elements in stack_b|ra: shifts all the elements in stack_a up for one position. The first element is now the last element.<br><br>rb: shifts all the elements in stack_b up for one position. The first element is now the last element.<br><br>rr: rotates stack_a and stack_b at the same time.|rra: shifts all the elements in stack_a down for one position. The last element is now the first element.<br><br>rrb: shifts all the elements in stack_b down for one position. The last element is now the first element.<br><br>rrr: reverse rotates stack_a and stack_b at the same time.|

## Usage

`make` to compile push_swap<br>

- Push_swap takes a set of integers as arguments.<br>
- It accepts integers and integer sets isolated in double quotes as arguments, with optional signs and leading zeros.<br>
- It then prints the operations it uses to sort the stack in order, separated by newlines.<br>

### example usage:
`./push_swap -3 12 +5 "0042 -15" -0 "34"`<br>

## Checker usage

`make bonus` to compile checker<br><br>
- Checker takes arguments in the same format that push_swap does.<br>
- The checker will be given a set of integers, after which it wait for user input.<br>
- If any of the valid operations is given as input, the checker will perform it.<br>
- It will stop taking input after EOF is reached.<br>
- It outputs 'OK' or 'KO' depending on if the stack_a is sorted or not as a result.
