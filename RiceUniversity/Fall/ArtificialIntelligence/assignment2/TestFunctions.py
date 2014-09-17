"""
I save here functions that were built during the 
develpment stage. That is, that were importante for
the project but that were subtracted to make the
final result clean
"""

------------------------------------------------------
The following functions were on MinMaxAgent
------------------------------------------------------
  def MinMaxValue(self, state, depth):
    """
      returns the minimax-value of a node on a limited deep search 
      -the depth argument is the number of rounds to be searched, that is, if we
      have n agents then each one will play depth times.
    """
    n_agents = state.getNumAgents()
    step_depth = n_agents*depth
    player = 0#pacman starts playing
    return self.MMValue_procedure(state, player, step_depth)

  """
      this function is the one that actually does the computation.
      I divided the problem becouse the difference in the definition
      of the depth of search. Here, one depth in the tree corresponds
      to the play of one player.
    """
  def MMValue_procedure(self, state, player,d):
    #initialize some variables
    is_player_min = False
    if player > 0:
      is_player_min = True 
    legalMoves = state.getLegalActions(player)
    next_player = (player + 1)%state.getNumAgents()
    state_leaf_case = self.is_state_end(state)
    #compute
    if  state_leaf_case or d == 0:
      return self.evaluationFunction(state) 
    elif is_player_min:
      scores = [self.MMValue_procedure(
        state.generateSuccessor(player, action), next_player, d-1
                                      ) for action in legalMoves]
      min_score = min(scores)
      return min(scores)
    else:#case player is max
      scores = [self.MMValue_procedure(
        state.generateSuccessor(player, action), next_player, d-1
                                      ) for action in legalMoves]
      max_score = max(scores)
      return max_score
      
  def is_state_end(self, state):
    if state.isLose() or state.isWin():
      return True
    elif len(state.getLegalActions(0)) == 0:
      return True
    else:
      return False

------------------------------------------------------
------------------------------------------------------

