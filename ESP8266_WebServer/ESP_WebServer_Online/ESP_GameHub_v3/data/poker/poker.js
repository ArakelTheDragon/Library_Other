let deck = [];
let flop = [], turn = '', river = '';
// communityRound: 0 = pre-flop, 1 = flop, 2 = turn, 3 = river revealed.
let communityRound = 0;
let pot = 0;

// Each player starts with 1000 simulated WorkTokens.
let player = { name: 'You', hand: [], active: true, balance: 1000 };
let bob    = { name: 'Bob', hand: [], active: true, balance: 1000 };
let mob    = { name: 'Mob', hand: [], active: true, balance: 1000 };

function createCard(content = '🂠') {
  const card = document.createElement('div');
  card.className = 'card';
  card.textContent = content;
  return card;
}

function shuffleDeck() {
  const suits = ['♠', '♥', '♦', '♣'];
  const ranks = ['2','3','4','5','6','7','8','9','10','J','Q','K','A'];
  let fullDeck = [];
  suits.forEach(suit => ranks.forEach(rank => fullDeck.push(`${rank}${suit}`)));
  for (let i = fullDeck.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [fullDeck[i], fullDeck[j]] = [fullDeck[j], fullDeck[i]];
  }
  return fullDeck;
}

function startGame() {
  deck = shuffleDeck();
  communityRound = 0;
  pot = 0;
  logMessage("New game started!");
  
  // Reset players’ statuses for a new hand.
  [player, bob, mob].forEach(p => {
    p.active = true;
    // Deal two hole cards.
    p.hand = [deck.pop(), deck.pop()];
  });
  
  // Prepare community cards.
  flop = [deck.pop(), deck.pop(), deck.pop()];
  turn = deck.pop();
  river = deck.pop();
  
  renderHands();
  updatePlayerInfo();
  updatePotDisplay();
  startBettingRound(); // Begin with a pre-flop betting round.
}

function renderHands(showAll = false) {
  // Render your hand.
  const playerCardsEl = document.getElementById('player-cards');
  playerCardsEl.innerHTML = 'Your Cards';
  player.hand.forEach(card => playerCardsEl.appendChild(createCard(card)));
  
  // Render Bob's hand (face-down unless showdown).
  const bobCardsEl = document.getElementById('bob-cards');
  bobCardsEl.innerHTML = "Bob's Cards";
  bob.hand.forEach(card => {
    const cardEl = createCard(bob.active && showAll ? card : '🂠');
    bobCardsEl.appendChild(cardEl);
  });
  
  // Render Mob's hand (face-down unless showdown).
  const mobCardsEl = document.getElementById('mob-cards');
  mobCardsEl.innerHTML = "Mob's Cards";
  mob.hand.forEach(card => {
    const cardEl = createCard(mob.active && showAll ? card : '🂠');
    mobCardsEl.appendChild(cardEl);
  });
  
  // Render community (house) cards.
  const houseEl = document.getElementById('house-cards');
  houseEl.innerHTML = 'House Cards';
  if (communityRound >= 1) {
    flop.forEach(card => houseEl.appendChild(createCard(card)));
  }
  if (communityRound >= 2) {
    houseEl.appendChild(createCard(turn));
  }
  if (communityRound >= 3) {
    houseEl.appendChild(createCard(river));
  }
}

function startBettingRound() {
  logMessage("Betting round started.");
  document.getElementById('bet-controls').style.display = 'block';
}

function placeBet() {
  const betInput = document.getElementById('bet-amount');
  let betValue = parseInt(betInput.value);
  if (isNaN(betValue) || betValue < 0) {
    logMessage("Invalid bet amount.");
    return;
  }
  if (!player.active) {
    logMessage("You have already folded.");
    document.getElementById('bet-controls').style.display = 'none';
    return;
  }
  if (betValue > player.balance) {
    logMessage("You do not have enough WorkTokens.");
    return;
  }
  
  // Process your bet.
  player.balance -= betValue;
  pot += betValue;
  logMessage(`You bet ${betValue} WorkTokens.`);
  
  // Simulate AI decisions for Bob and Mob.
  [bob, mob].forEach(p => {
    if (p.active) {
      let decision = Math.random();
      // 20% chance to fold; otherwise they call.
      if (decision < 0.2) {
        p.active = false;
        logMessage(`${p.name} folds in this round.`);
      } else {
        let callAmount = betValue;
        if (callAmount > p.balance) {
          callAmount = p.balance; // Bet what they can.
        }
        p.balance -= callAmount;
        pot += callAmount;
        logMessage(`${p.name} calls with ${callAmount} WorkTokens.`);
      }
    }
  });
  
  updatePlayerInfo();
  updatePotDisplay();
  // End of betting round.
  document.getElementById('bet-controls').style.display = 'none';
}

function playerFold() {
  if (player.active) {
    player.active = false;
    logMessage("You folded this round.");
  }
  document.getElementById('bet-controls').style.display = 'none';
  updatePlayerInfo();
}

function revealNext() {
  // Do not allow community reveal until betting round is finished.
  if (document.getElementById('bet-controls').style.display !== 'none') {
    logMessage("Please complete the betting round first.");
    return;
  }
  // Reveal next set of community cards.
  if (communityRound < 3) {
    communityRound++;
    if (communityRound === 1) {
      logMessage("Flop dealt.");
    } else if (communityRound === 2) {
      logMessage("Turn dealt.");
    } else if (communityRound === 3) {
      logMessage("River dealt.");
    }
    renderHands();
    startBettingRound();
  } else {
    // Final betting round is over, trigger showdown.
    showdown();
  }
}

function showdown() {
  // Reveal all cards.
  renderHands(true);
  let activePlayers = [player, bob, mob].filter(p => p.active);
  
  if (activePlayers.length === 0) {
    logMessage("All players folded. No winner this hand.");
  } else if (activePlayers.length === 1) {
    let winner = activePlayers[0];
    logMessage(`${winner.name} wins the pot of ${pot} WorkTokens by default!`);
    winner.balance += pot;
  } else {
    // Placeholder: randomly choose a winner among active players.
    let winner = activePlayers[Math.floor(Math.random() * activePlayers.length)];
    logMessage(`Showdown! ${winner.name} wins the pot of ${pot} WorkTokens!`);
    winner.balance += pot;
  }
  pot = 0;
  updatePlayerInfo();
  updatePotDisplay();
}

function updatePlayerInfo() {
  document.getElementById('player-info').textContent = `${player.name}: ${player.balance} WorkTokens`;
  document.getElementById('bob-info').textContent    = `${bob.name}: ${bob.balance} WorkTokens`;
  document.getElementById('mob-info').textContent    = `${mob.name}: ${mob.balance} WorkTokens`;
}

function updatePotDisplay() {
  document.getElementById('pot-display').textContent = `Pot: ${pot} WorkTokens`;
}

function resetGame() {
  // Reset tokens and statuses.
  player.balance = 1000;
  bob.balance = 1000;
  mob.balance = 1000;
  [player, bob, mob].forEach(p => {
    p.active = true;
    p.hand = [];
  });
  
  deck = [];
  flop = [];
  turn = '';
  river = '';
  communityRound = 0;
  pot = 0;
  
  document.getElementById('house-cards').innerHTML = 'House Cards';
  document.getElementById('bob-cards').innerHTML   = "Bob's Cards";
  document.getElementById('mob-cards').innerHTML   = "Mob's Cards";
  document.getElementById('player-cards').innerHTML = 'Your Cards';
  document.getElementById('log').innerHTML = '';
  document.getElementById('bet-controls').style.display = 'none';
  updatePlayerInfo();
  updatePotDisplay();
  logMessage("Game reset.");
}

function logMessage(msg) {
  const logDiv = document.getElementById('log');
  const p = document.createElement('p');
  p.textContent = msg;
  logDiv.appendChild(p);
}

