from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
  """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
  """
  def __init__(self):
    self.lastPositions = []
    self.dc = None


  def getAction(self, gameState):
    """
    getAction chooses among the best options according to the evaluation function.

    getAction takes a GameState and returns some Directions.X for some X in the set {North, South, West, East, Stop}
    ------------------------------------------------------------------------------
    Description of GameState and helper functions:

    A GameState specifies the full game state, including the food, capsules,
    agent configurations and score changes. In this function, the |gameState| argument 
    is an object of GameState class. Following are a few of the helper methods that you 
    can use to query a GameState object to gather information about the present state 
    of Pac-Man, the ghosts and the maze.
    
    gameState.getLegalActions(): 
        Returns the legal actions for the agent specified. Returns Pac-Man's legal moves by default.

    gameState.generateSuccessor(agentIndex, action): 
        Returns the successor state after the specified agent takes the action. 
        Pac-Man is always agent 0.

    gameState.getPacmanState():
        Returns an AgentState object for pacman (in game.py)
        state.pos gives the current position
        state.direction gives the travel vector

    gameState.getGhostStates():
        Returns list of AgentState objects for the ghosts

    gameState.getNumAgents():
        Returns the total number of agents in the game

    
    The GameState class is defined in pacman.py and you might want to look into that for 
    other helper methods, though you don't need to.
    """
    # Collect legal moves and successor states
    legalMoves = gameState.getLegalActions()

    # Choose one of the best actions
    scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
    bestScore = max(scores)
    bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
    chosenIndex = random.choice(bestIndices) # Pick randomly among the best




    return legalMoves[chosenIndex]

  def evaluationFunction(self, currentGameState, action):
    """
    The evaluation function takes in the current and proposed successor
    GameStates (pacman.py) and returns a number, where higher numbers are better.

    The code below extracts some useful information from the state, like the
    remaining food (oldFood) and Pacman position after moving (newPos).
    newScaredTimes holds the number of moves that each ghost will remain
    scared because of Pacman having eaten a power pellet.
    """
    # Useful information you can extract from a GameState (pacman.py)
    successorGameState = currentGameState.generatePacmanSuccessor(action)
    newPos = successorGameState.getPacmanPosition()
    oldFood = currentGameState.getFood()
    newGhostStates = successorGameState.getGhostStates()
    newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]


    return successorGameState.getScore()


def scoreEvaluationFunction(currentGameState):
  """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
  """
  return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
  """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
  """

  def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
    self.index = 0 # Pacman is always agent index 0
    self.evaluationFunction = util.lookup(evalFn, globals())
    self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
  """
    Your minimax agent (problem 1)
  """

  def getAction(self, gameState):
    """
      Returns the minimax action from the current gameState using self.depth
      and self.evaluationFunction. Terminal states can be found by one of the following: 
      pacman won, pacman lost or there are no legal moves. 

      Here are some method calls that might be useful when implementing minimax.

      gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

      Directions.STOP:
        The stop direction, which is always legal

      gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

      gameState.getNumAgents():
        Returns the total number of agents in the game
	
      gameState.isWin():
        Returns True if it's a winning state
	
      gameState.isLose():
        Returns True if it's a losing state

      self.depth:
        The depth to which search should continue
    """

    # BEGIN_YOUR_CODE (around 68 lines of code expected)
    
    # Collect legal moves and successor states
    legalMoves = gameState.getLegalActions()
    n_agents = gameState.getNumAgents()
    step_depth = n_agents*self.depth
    player = 0#pacman starts playing

    reachable_values =[self.MinMaxEvaluate(
          gameState.generateSuccessor(player, action),player,step_depth
                                    ) for action in legalMoves]
    best_value = max(reachable_values)
    bestIndices = [index for index in range(len(reachable_values)) 
                                if reachable_values[index] == best_value]
    chosenIndex = random.choice(bestIndices) # Pick randomly in case of tie

    return legalMoves[chosenIndex]

  def MinMaxEvaluate(self, state, player, d):
    #initialize some variables 
    legalMoves = state.getLegalActions(player)
    next_player = (player + 1)%state.getNumAgents()
    leaf_case = state.isLose() or state.isWin() or len(legalMoves) is True
    #compute
    if  leaf_case or (d == 0):
      return self.evaluationFunction(state) 
    elif player > 0:#case min player
      scores = [self.MinMaxEvaluate(
        state.generateSuccessor(player, action), next_player, d-1
                                      ) for action in legalMoves]
      return min(scores)
    else:#case max player
      scores = [self.MinMaxEvaluate(
        state.generateSuccessor(player, action), next_player, d-1
                                      ) for action in legalMoves]
      return max(scores)
  
    # END_YOUR_CODE

class AlphaBetaAgent(MultiAgentSearchAgent):
  """
    Your minimax agent with alpha-beta pruning (problem 2)
  """

  def getAction(self, gameState):
    """
      Returns the minimax action using self.depth and self.evaluationFunction
    """

    # Collect legal moves and successor states
    legalMoves = gameState.getLegalActions()
    n_agents = gameState.getNumAgents()
    step_depth = n_agents*self.depth
    player = 0#pacman starts playing

    #find alpha-beta value and the corresponding index
    alpha_beta_v, values = self.AlphaBetaEvaluate(gameState,player,step_depth,float("-infinity"), float("infinity"))

    abIndices = [index for index in range(len(values)) 
                                if values[index] == alpha_beta_v]
    chosenIndex = random.choice(abIndices) # Pick randomly in case of tie

    return legalMoves[chosenIndex]

    # BEGIN_YOUR_CODE (around 69 lines of code expected)
  def AlphaBetaEvaluate(self, state, player, d, alpha, beta):
    #initialize some variables 
    legalMoves = state.getLegalActions(player)
    values  = [-1 for n in range(len(legalMoves))] 
    next_player = (player + 1)%state.getNumAgents()
    leaf_case = state.isLose() or state.isWin() or len(legalMoves) is True
    #compute
    if  leaf_case or (d == 0):
      return self.evaluationFunction(state),values 
    elif player > 0:#case min player
      v = float("infinity")
      for i,action in enumerate(legalMoves):
        act_value,trash = self.AlphaBetaEvaluate(state.generateSuccessor(player, action), next_player, d-1, alpha, beta) 
        values[i] = act_value
        v = min(v,act_value) 
        if v <= alpha:
          return v,values
        beta = min(beta, v)
      return v,values
    else:#case max player
      v = float("-infinity")
      for i,action in enumerate(legalMoves):
        act_value,trash =self.AlphaBetaEvaluate(state.generateSuccessor(player, action), next_player, d-1, alpha, beta)
        values[i] = act_value
        v = max(v, act_value) 
        if v >= beta:
          return v,values
        alpha = max(alpha, v)
      return v,values
    # END_YOUR_CODE
class ExpectimaxAgent(MultiAgentSearchAgent):
  """
    Your expectimax agent (problem 3)
  """

  def getAction(self, gameState):
    """
      Returns the expectimax action using self.depth and self.evaluationFunction

      All ghosts should be modeled as choosing uniformly at random from their
      legal moves.
    """
    # Collect legal moves and successor states
    legalMoves = gameState.getLegalActions()
    n_agents = gameState.getNumAgents()
    step_depth = n_agents*self.depth
    player = 0#pacman starts playing

    reachable_values =[self.ExpectimaxEvaluate(
          gameState.generateSuccessor(player, action),player,step_depth
                                    ) for action in legalMoves]
    best_value = max(reachable_values)
    bestIndices = [index for index in range(len(reachable_values)) 
                                if reachable_values[index] == best_value]
    chosenIndex = random.choice(bestIndices) # Pick randomly in case of tie

    return legalMoves[chosenIndex]

    # BEGIN_YOUR_CODE (around 70 lines of code expected)

  def ExpectimaxEvaluate(self, state, player, d):
    #initialize some variables 
    legalMoves = state.getLegalActions(player)
    next_player = (player + 1)%state.getNumAgents()
    leaf_case = state.isLose() or state.isWin() or len(legalMoves) is True
    #compute
    if  leaf_case or (d == 0):
      return self.evaluationFunction(state) 
    elif player > 0:#case chance player
      prob = 1.0/len(legalMoves)
      score = sum(prob*self.ExpectimaxEvaluate(
        state.generateSuccessor(player, action), next_player, d-1
                                      ) for action in legalMoves)
      return score
    else:#case max player
      scores = [self.ExpectimaxEvaluate(
        state.generateSuccessor(player, action), next_player, d-1
                                      ) for action in legalMoves]
      return max(scores)

    # END_YOUR_CODE

def betterEvaluationFunction(currentGameState):
  """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (problem 4).

    DESCRIPTION: <write something here so we know what you did>
  idea:
    My simple evaluation function is based on three features:
      -total time of scared ghosts 
      -sum of distances* to ghosts 
      -sum of distances* to food
      -scores
    *by distances I mean manhatan distances. This was chosen to make the 
    evaluation function cheap and it alsos representes the way pacman moves.

    There are some details: if the ghosts are near packman, than he needs
    to stop whathever he is doing to run away. This is made by atribuing
    a stupid negative value to that condition so he'll aways be running
    from this situation.

    Finally, the weight associated to each feature were set based on intuition
    and tryal and error

  results:

    I's says the results obtained are impressive for such a simple approach. On a 50
    times run on the smallClassic stage the winning ratio was of 43/50 (0.86) 
    and the average pontuation was 1290.86

    IMPORTANT: after tests on other stages it is noted that the values of the
    constants weights assigned to each feature must be calibrated to each
    stage. This code will run fine(with the promised >0.8 winning ratio)
    on the smallClassic but it is not guaranteed to do good on every stage.
    In fact, for classicMinimax it looses every time.

  """

  # BEGIN_YOUR_CODE (around 71 lines of code expected)
  # definig variables for feature measurement
  n_features = 4
  F = [-1 for x in range(n_features)] #array for features value
  A = [ 0 for x in range(n_features)] #array for features weights

  #useful information for measuring fetures
  pacman_position     = currentGameState.getPacmanPosition()
  xp,yp = pacman_position
  
  #Feature 1 - scared time - pacman loves to kill his enemies
  ghost_states        = currentGameState.getGhostStates()
  scaredTimes         = [ghostState.scaredTimer for ghostState in ghost_states]
  F[0]                = sum(scaredTimes)

  #Feature 2 - distances to ghosts - pacman wants to live long
  ghost_positions     = currentGameState.getGhostPositions()
  total_distance2ghs  = 0
  for gh in ghost_positions:
    x,y = gh
    current_distance = abs(xp-x)+abs(yp-y)
    total_distance2ghs += current_distance #manhatan distance is used to make it fast
    if current_distance in (0,1):
      total_distance2ghs = -100#you definitly dont want to die
      break
  F[1] = total_distance2ghs

  #Feature 3 - distances to food - pacman wants to eat it all as long as he's alive
  food_position       = currentGameState.getFood().asList()#return boolean grid
  total_distance2food = 0
  for food_point in food_position:
    x,y = food_point
    total_distance2food += abs(xp-x)+abs(yp-y)#manhatan distance is used to make it fast
  F[2] = -1*total_distance2food

  #Feature 4 - score - pacman wants to win the game eventually
  F[3] = currentGameState.getScore()

  #weight definition
  A[0]= 20.0#killing ghosts is really awesome
  A[1]= 10.0#unless, of course, they kill you. Better stay away.
  A[2]= 8.0#while running from ghost, why don't eat something?
  A[3]= 5.0#sometimes it's good to remember your final goal

  final_value = sum(A[i]*F[i] for i in range(n_features))
  return final_value
  # END_YOUR_CODE
# Abbreviation
better = betterEvaluationFunction


