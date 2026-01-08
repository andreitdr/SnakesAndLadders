# **Snakes and Ladders**

A cross-platform implementation of the classic Snakes and Ladders board game, featuring a C++ server and a Qt-based frontend.


## **Project Structure**

The project is organized into several modules:

* **server/**: The main server application that handles HTTP requests and routing.  
* **server\_lib/**: Core game logic, object management (Lobbies, Players, Games), and infrastructure components used by the server.  
* **frontend/**: The client-side application built with Qt.  
* **Tests/ServerTests/**: Unit and integration tests for server-side logic.

## **Requirements**

* **CMake** (Version 3.10 or higher)  
* **C++ Compiler** (built for C++ 17)  
* **Qt6 Framework** (for the frontend)

## **Building the Project**

To build the entire project, run the following commands from the root directory:
```bash
mkdir build  
cd build  
cmake ..  
cmake \--build .
```
## **API Documentation**

The server provides the following RESTful endpoints for lobby and game management.

### **Lobby Management**

| Endpoint | Method | Description |
| :---- | :---- | :---- |
| /lobby/create | POST | Creates a new lobby with an admin player. |
| /lobby/status | GET | Retrieves the current state of a lobby (players, map type, etc.). |
| /lobby/join | POST | Allows a player to join an existing lobby. |
| /lobby/update | POST | Updates lobby settings like maxPlayers or mapType (Admin only). |
| /lobby/leave | POST | Removes a player from a lobby. |
| /lobby/start-game | POST | Transitions the lobby into an active game state. |

### **Game Logic**

| Endpoint | Method | Description |
| :---- | :---- | :---- |
| /game/status | POST | Gets real-time status, including player positions and turn info. |
| /game/roll-dice | POST | Triggers a dice roll for the current player. |
| /game/leave | POST | Allows a player to exit an active game. |
| /game/stats | POST | Returns end-of-game statistics like duration and final positions. |

### **Example Request (/lobby/create)**
```json
{  
    "adminUsername": "player1",  
    "mapType": 1,  
    "maxPlayers": 4  
}
```
### **Example Response (/game/status)**
```json
{  
  "success": true,  
  "game": {  
    "gameId": 1,  
    "playerTurnIndex": 0,  
    "players": [  
      {  
        "username": "player1",  
        "playerColor": 1,  
        "isLobbyAdmin": true,  
        "currentBoardPosition": 12  
      }  
    ],  
    "turnTime": { "current": 10, "max": 20 },  
    "latestDiceValue": 6  
  }  
}
```
