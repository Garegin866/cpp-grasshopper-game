#pragma once
#include "controller.h"
#include "model.h"
#include "view.h"

// Мок для класса Model.
// Класс содержит те же методы, что и оригинальный,
// но работа одного из них изменена.
// Для тестирования будем считать, 
// что кузнечик ловит каждую мушку с первой попытки.
// Другие методы вызывают аналогичные из оригинальной модели.
class MockModel {
public:
    MockModel(unsigned int seed, int size = 10) : model_(seed, size) {}

    int GetHopperPosition() const {
        return model_.GetHopperPosition();
    }

    int GetFlyPosition() const {
        return model_.GetFlyPosition();
    }

    void SetFlyPosition() {
        model_.SetFlyPosition();
    }

    void SetGrasshopperPosition(int hops) {
        model_.SetGrasshopperPosition(hops);
    }

    bool CheckCatch() {
        return true;
    }

    int GetBoardSize() const {
        return model_.GetBoardSize();
    }

private:
    Model model_;
};

// Мок для класса View.
// Класс содержит те же методы, что и оригинальный,
// но вместо вывода на экран они увеличивают счётчик вызовов.
class MockView {
public:
    void ShowScore(int) {
        counter_["ShowScore"]++;
    }

    void PrintBoard(int, int, int) {
        counter_["PrintBoard"]++;
    }

    int GetUserInput() {
        counter_["GetUserInput"]++;
        return 1;
    }

    void ShowWinMessage() {
        counter_["ShowWinMessage"]++;
    }

    const std::map<std::string, int>& GetCounter() const {
        return counter_;
    }

private:
    std::map<std::string, int> counter_ = {
        {"ShowScore", 0},
        {"PrintBoard", 0},
        {"GetUserInput", 0},
        {"ShowWinMessage", 0}
    };
};