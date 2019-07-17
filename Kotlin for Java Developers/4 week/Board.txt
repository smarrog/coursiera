package board

fun createSquareBoard(width: Int): SquareBoard = CustomSquareBoard(width)
fun <T> createGameBoard(width: Int): GameBoard<T> = CustomGameBoard(width)

open class CustomSquareBoard(final override val width: Int) : SquareBoard {
    private val _cells: MutableList<MutableList<Cell>> = mutableListOf(mutableListOf())

    init {
        for (i in 1..width) {
            _cells.add(mutableListOf())
           for (j in 1..width) {
                _cells[i - 1].add(Cell(i, j))
           }
        }
    }

    override fun getCellOrNull(i: Int, j: Int): Cell? {
        if (i < 1 || j < 1 || i > width || j > width) {
            return null
        }
        return _cells[i - 1][j - 1]
    }

    override fun getCell(i: Int, j: Int): Cell {
        return _cells[i - 1][j - 1]
    }

    override fun getAllCells(): Collection<Cell> {
        return _cells.flatten()
    }

    override fun getRow(i: Int, jRange: IntProgression): List<Cell> {
        val res = getAllCells()
                .filter { it.i == i && it.j in jRange }
                .toList()
        if (jRange.first > jRange.last) {
            return res.reversed()
        }
        return res
    }

    override fun getColumn(iRange: IntProgression, j: Int): List<Cell> {
        val res = getAllCells()
                .filter { it.j == j && it.i in iRange }
                .toList()
        if (iRange.first > iRange.last) {
            return res.reversed()
        }
        return res
    }

    override fun Cell.getNeighbour(direction: Direction): Cell? {
        return when (direction) {
            Direction.UP -> getCellOrNull(i - 1, j)
            Direction.RIGHT -> getCellOrNull(i, j + 1)
            Direction.DOWN -> getCellOrNull(i + 1, j)
            Direction.LEFT -> getCellOrNull(i, j - 1)
        }
    }
}

class CustomGameBoard<T>(width: Int) : CustomSquareBoard(width), GameBoard<T> {
    private var _cells: MutableMap<Cell, T?> = mutableMapOf()

    init {
        getAllCells().forEach{ cell -> set(cell, null) }
    }

    override fun get(cell: Cell): T? {
        return if (_cells.containsKey(cell)) _cells[cell] else null
    }

    override fun set(cell: Cell, value: T?) {
        _cells[cell] = value
    }

    override fun filter(predicate: (T?) -> Boolean): Collection<Cell> {
        return _cells
                .asSequence()
                .filter { predicate(it.value) }
                .map{ it.key }
                .toList()
    }

    override fun find(predicate: (T?) -> Boolean): Cell? {
        return _cells
                .asSequence()
                .filter { predicate(it.value) }
                .firstOrNull()?.key
    }

    override fun any(predicate: (T?) -> Boolean): Boolean {
        return _cells.any { predicate(it.value) }
    }

    override fun all(predicate: (T?) -> Boolean): Boolean {
        return _cells.all { predicate(it.value) }
    }
}

