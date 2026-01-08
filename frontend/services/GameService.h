//
// Created by Alexandru Pestritu on 27.11.2024.
//

#ifndef GAMESERVICE_H
#define GAMESERVICE_H



#include <string>
#include <functional>
#include <qstring.h>
#include <nlohmann/json.hpp>
#include "../models/Game.h"
#include "../models/GameStats.h"
#include "../core/BaseResponse.h"
#include "../core/BaseService.h"
#include "../core/ApiEndpoints.h"

class GameService : public BaseService {
public:
    GameService();
    ~GameService();

    Game getGameStatus(int gameId);
    void getGameStatusAsync(int gameId, std::function<void(bool, const QString&, const Game&)> callback);
    void leaveGame(int gameId, const std::string& playerUsername);
    GameStats getGameStats(int gameId);
    void rollDice(int gameId, const std::string& playerUsername);
};

#endif //GAMESERVICE_H
