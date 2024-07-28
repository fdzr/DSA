def permutations(input):
    perms = []
    solution = []

    def backtrack():
        if len(input) == len(solution):
            perms.append(solution[:])
            print(perms)
            return

        for num in input:
            if not num in solution:
                solution.append(num)
                backtrack()
                solution.pop()

    return backtrack()


permutations([1, 2, 3])
