package games.gameOfFifteen

import board.Cell
import board.Direction
import board.createGameBoard
import games.game.Game

/*
 * Implement the Game of Fifteen (https://en.wikipedia.org/wiki/15_puzzle).
 * When you finish, you can play the game by executing 'PlayGameOfFifteen'.
 */
fun newGameOfFifteen(initializer: GameOfFifteenInitializer = RandomGameInitializer()): Game =
    GameOfFifteen(initializer)

class GameOfFifteen(private val initializer: GameOfFifteenInitializer) : Game {
    private var _board = createGameBoard<Int?>(4)

    override fun initialize() {
        initializer.initialPermutation.forEachIndexed { index, value ->
            _board[_board.getCell(index / 4 + 1, index % 4 + 1)] = value
        }
    }

    override fun get(i: Int, j: Int): Int? {
        return _board.run { get(getCell(i, j)) }
    }

    override fun canMove(): Boolean {
        return true
    }

    override fun hasWon(): Boolean {
        return get(4, 4) == null && _board
                .getAllCells().mapNotNull { _board[it] } == (1..15).toList()
    }

    override fun processMove(direction: Direction) {
        val emptyCell: Cell = _board.getAllCells().filter { get(it.i, it.j) == null }[0]

        fun swapWith(cell: Cell) {
            _board[emptyCell] = _board[cell]
            _board[cell] = null
        }

        when (direction) {
            Direction.LEFT -> {
                if (emptyCell.j != _board.width) {
                    swapWith(_board.getCell(emptyCell.i, emptyCell.j + 1))
                }
            }
            Direction.RIGHT -> {
                if (emptyCell.j != 1) {
                    swapWith(_board.getCell(emptyCell.i, emptyCell.j - 1))
                }
            }
            Direction.UP -> {
                if (emptyCell.i != _board.width) {
                    swapWith(_board.getCell(emptyCell.i + 1, emptyCell.j))
                }
            }
            Direction.DOWN -> {
                if (emptyCell.i != 1) {
                    swapWith(_board.getCell(emptyCell.i - 1, emptyCell.j))
                }
            }
        }
    }
}

