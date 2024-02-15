from services.ComputerPlayer import ComputerPlayer
from services.GameService import GameService
from domain.gameboard import GameBoard
import unittest


class Test(unittest.TestCase):

    def test_get_board_score(self):
        self.game_board = GameBoard()
        self.computer_player = ComputerPlayer(self.game_board)

        self.assertEqual(self.computer_player._get_board_score(self.game_board, self.computer_player._AI), 0)

    def test_is_full(self):
        game_board = GameBoard()
        computer_player = ComputerPlayer(game_board)

        self.assertFalse(computer_player.is_full(game_board))

    def test_obstruct_after_a_move(self):
        test_game_board = GameBoard()
        computer_player = ComputerPlayer(test_game_board)

        self.assertEqual(computer_player._obstruct_after_a_move(test_game_board, 0, 0).board[0][1], "*")
        self.assertEqual(computer_player._obstruct_after_a_move(test_game_board, 0, 0).board[1][1], "*")
        self.assertEqual(computer_player._obstruct_after_a_move(test_game_board, 0, 0).board[1][0], "*")

    def test_switch_turn(self):
        game_board = GameBoard()
        game_service = GameService(game_board)
        game_service.switch_turn()
        self.assertEqual(game_service.get_turn, 1)

    def test_object_can_be_placed_on_given_position(self):
        game_board = GameBoard()
        game_service = GameService(game_board)
        game_board.board[0][0] = "*"

        self.assertFalse(game_service.object_can_be_placed_on_given_position(0, 0))
        self.assertTrue(game_service.object_can_be_placed_on_given_position(0, 3))
        self.assertTrue(game_service.object_can_be_placed_on_given_position(3, 0))
        self.assertTrue(game_service.object_can_be_placed_on_given_position(3, 3))
        self.assertFalse(game_service.object_can_be_placed_on_given_position(-1, 0))
        self.assertFalse(game_service.object_can_be_placed_on_given_position(0, -1))
        self.assertFalse(game_service.object_can_be_placed_on_given_position(-1, -1))
        self.assertFalse(game_service.object_can_be_placed_on_given_position(-1, 3))
        self.assertFalse(game_service.object_can_be_placed_on_given_position(3, -1))

    def test_decide_playing_character(self):
        game_board = GameBoard()
        game_service = GameService(game_board)

        self.assertEqual(game_service.decide_playing_character(), "X")
        game_service.switch_turn()
        self.assertEqual(game_service.decide_playing_character(), "O")
        game_service.make_move(0, 0)
        self.assertEqual(game_service.decide_playing_character(), "X")
