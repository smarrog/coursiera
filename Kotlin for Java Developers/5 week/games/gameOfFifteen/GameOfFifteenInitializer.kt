package games.gameOfFifteen

interface GameOfFifteenInitializer {
    /*
     * Even permutation of numbers 1..15
     * used to initialized the first 15 cells on a board.
     * The last cell is empty.
     */
    val initialPermutation: List<Int>
}

class RandomGameInitializer : GameOfFifteenInitializer {
    /*
     * Generate a random permutation from 1 to 15.
     * `shuffled()` function might be helpful.
     * If the permutation is not even, make it even (for instance,
     * by swapping two numbers).
     */
    override val initialPermutation by lazy {
        val list = (1..15).toMutableList()
        list.shuffle()
        if (!isEven(list)) {
            for (i in 1 until list.size) {
                if (list[i] < list[i - 1]) {
                    list[i] = list[i - 1].also { list[i - 1] = list[i] }
                    break
                }
            }
        }
        list
    }
}

