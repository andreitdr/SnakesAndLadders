//
// Created by Alexandru Pestritu on 19.11.2024.
//
#include "ViewManager.h"


ViewManager::ViewManager(QObject* parent) : QObject{ parent },
    m_homeView{ std::make_unique<HomeView>()},
    m_createGameView{std::make_unique<CreateGameView>()},
    m_joinGameView{std::make_unique<JoinGameView>()},
    m_lobbyView(std::make_unique<LobbyView>()),
    m_gameView(std::make_unique<GameView>()),
    m_statsView(std::make_unique<StatsView>())
{
    setupConnections();
}

void ViewManager::setupConnections() {

    //HomeView connections
    connect(m_homeView.get(), &HomeView::goToCreateGameView, this, &ViewManager::showCreateGameView);
    connect(m_homeView.get(), &HomeView::goToJoinGameView, this, &ViewManager::showJoinGameView);
    connect(m_homeView.get(), &HomeView::windowPositionChanged, this, &ViewManager::onWindowHidden);

    //CreateGameView connections
    connect(m_createGameView.get(), &CreateGameView::goToLobbyView, this, &ViewManager::showLobbyView);
    connect(m_createGameView.get(), &CreateGameView::goToHomeView, this, &ViewManager::showHomeView);
    connect(m_createGameView.get(), &CreateGameView::windowPositionChanged, this, &ViewManager::onWindowHidden);

    //JoinGameView connections
    connect(m_joinGameView.get(), &JoinGameView::goToLobbyView, this, &ViewManager::showLobbyView);
    connect(m_joinGameView.get(), &JoinGameView::goToHomeView, this, &ViewManager::showHomeView);
    connect(m_joinGameView.get(), &JoinGameView::windowPositionChanged, this, &ViewManager::onWindowHidden);

    //LobbyView connections
    connect(m_lobbyView.get(), &LobbyView::goToHomeView, this, &ViewManager::showHomeView);
    connect(m_lobbyView.get(), &LobbyView::goToGameView, this, &ViewManager::showGameView);
    connect(m_lobbyView.get(), &LobbyView::windowPositionChanged, this, &ViewManager::onWindowHidden);

    //GameView connections
    connect(m_gameView.get(), &GameView::goToHomeView, this, &ViewManager::showHomeView);
    connect(m_gameView.get(), &GameView::goToStatsView, this, &ViewManager::showStatsView);
    connect(m_gameView.get(), &GameView::windowPositionChanged, this, &ViewManager::onWindowHidden);

    //StatsView connections
    connect(m_statsView.get(), &StatsView::goToHomeView, this, &ViewManager::showHomeView);
    connect(m_statsView.get(), &StatsView::windowPositionChanged, this, &ViewManager::onWindowHidden);
}

void ViewManager::showHomeView() {
    setWindowPosition(m_homeView.get());
    m_homeView->show();
}

void ViewManager::showCreateGameView() {
    setWindowPosition(m_createGameView.get());
    m_createGameView->show();
}

void ViewManager::showJoinGameView() {
    setWindowPosition(m_joinGameView.get());
    m_joinGameView->show();
}

void ViewManager::showLobbyView() {
    setWindowPosition(m_lobbyView.get());
    m_lobbyView->show();
}

void ViewManager::showGameView() {
    setWindowPosition(m_gameView.get());
    m_gameView->show();
}

void ViewManager::showStatsView() {
    setWindowPosition(m_statsView.get());
    m_statsView->show();
}

void ViewManager::onWindowHidden(const QPoint &position) {
    lastWindowPosition = position;
}

void ViewManager::setWindowPosition(QWidget *window) {
    if (!lastWindowPosition.isNull()) {
        window->move(lastWindowPosition);
    }
}
