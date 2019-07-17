package games.game2048

/*
 * This function moves all the non-null elements to the beginning of the list
 * (by removing nulls) and merges equal elements.
 * The parameter 'merge' specifies the way how to merge equal elements:
 * it returns a new element that should be present in the resulting list
 * instead of two merged elements.
 *
 * If the function 'merge("a")' returns "aa",
 * then the function 'moveAndMergeEqual' transforms the input in the following way:
 *   a, a, b -> aa, b
 *   a, null -> a
 *   b, null, a, a -> b, aa
 *   a, a, null, a -> aa, a
 *   a, null, a, a -> aa, a
 *
 * You can find more examples in 'TestGame2048Helper'.
*/
fun <T : Any> List<T?>.moveAndMergeEqual(merge: (T) -> T): List<T> {
    val notNullList = filterNotNull()
    if (notNullList.isEmpty()) {
        return notNullList
    }

    val result: MutableList<T> = mutableListOf(notNullList[0])
    for (i in 1 until notNullList.size) {
        val cur = notNullList[i]
        if (cur == result[result.size - 1]) {
            result[result.size - 1] = merge(cur)
        } else {
            result.add(cur)
        }
    }
    return result
}


