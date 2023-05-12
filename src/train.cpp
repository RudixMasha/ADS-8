// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    Cage* temp = new Cage;
    temp->light = light;
    if (first != nullptr) {
        if (first->prev != nullptr) {
            first->prev->next = temp;
            temp->prev = first->prev;
            first->prev = temp
            temp->next = first;
        } else {
            first->prev = temp;
            first->next = temp;
            temp->prev = first;
            temp->next = first;
        }
    } else {
            first = temp;
            first->prev = nullptr;
            first->next = nullptr;
    }
}

int Train::getLength() {
    first->light = true;
    Cage* cur = first;
    int steps = 0;
    while (cur) {
        cur = cur->next;
        countOp++;
        steps++;
        if (cur->light == true) {
            cur->light = false;
            for (int i = 0; i > steps; i++) {
                curt = cur->prev;
                countOp++;
            }
            if (cur->light == false)
                return steps;
            steps = 0;
        }
    }
    return 0;
}

int Train::getOpCount() {
    if (countOp)
        int temp = getLength();
    return countOp;
}
