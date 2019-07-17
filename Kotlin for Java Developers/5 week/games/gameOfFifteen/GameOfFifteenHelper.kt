package games.gameOfFifteen

/*
 * This function should return the parity of the permutation.
 * true - the permutation is even
 * false - the permutation is odd
 * https://en.wikipedia.org/wiki/Parity_of_a_permutation

 * If the game of fifteen is started with the wrong parity, you can't get the correct result
 *   (numbers sorted in the right order, empty cell at last).
 * Thus the initial permutation should be correct.
 */
fun isEven(permutation: List<Int>): Boolean {
    var list = permutation.toMutableList()
    var count = 0
    for (i in 1 until list.size) {
        var prevIndex = i - 1
        var value = list[i]
        while (prevIndex >= 0 && list[prevIndex] > value) {
            list[prevIndex + 1] = list[prevIndex]
            count++
            prevIndex--
        }
        list[prevIndex + 1] = value
    }
    return count % 2 == 0
}