//
// Created by Alexandru Pestritu on 18.11.2024.
//

#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(const std::string& message) = 0;
};

#endif //OBSERVER_H