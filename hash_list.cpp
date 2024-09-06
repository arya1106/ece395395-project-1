#include "hash_list.h"

hash_list::hash_list() {
    size = 0;
    head = nullptr;
    iter_ptr = nullptr;
};

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {
    node *iter = head;
    for (int i = 0; i < (int) size; i++) {
        if (iter -> key == key) {
            iter -> value = value;
            return;
        }
        iter = iter -> next;
    }
    iter = new node{key, value, head};
    head = iter;
    size++;
}

std::optional<float> hash_list::get_value(int key) const {
    node *iter = head;
    for (int i = 0; i < (int) size; i++) {
        if (iter -> key == key) {
            return iter -> value;
        }
        iter = iter -> next;
    }
    return std::nullopt;
}

bool hash_list::remove(int key) {
    node *iter = head;
    if (head && head -> key == key) {
        head = head -> next;
        delete iter;
        size--;
        return true;
    }
    for (int i = 0; i < (int) size - 1; i++) {
        if (iter -> next -> key == key) {
            node *temp = iter -> next;
            iter -> next = iter -> next -> next;
            delete temp;
            size--;
            return true;
        }
        iter = iter -> next;
    }
    return false;
}

size_t hash_list::get_size() const {
    return size;
}

hash_list::~hash_list() {
    node *iter;
    for (int i = 0; i < (int) size; i++) {
        iter = head;
        head = head -> next;
        delete iter;
    }
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {
    node* prev;
    node* curr;

    node* ocurr = other.head;
    size = other.size;
    if (size > 0) {
        head = new node{other.head->key, other.head->value, nullptr};
        prev = head;
    }
    reset_iter();
    for (int i = 0; i < (int) size - 1; i++) {
        ocurr = ocurr->next;
        curr = new node{ocurr->key, ocurr->value, nullptr};
        prev->next = curr;
        prev = curr;
        if (other.iter_ptr->key != iter_ptr->key) {
            increment_iter();
        }
    }
}

hash_list &hash_list::operator=(const hash_list &other) {
    if (this == &other) return *this;
    hash_list co = other;
    std::swap(size, co.size);
    std::swap(head, co.head);
    std::swap(iter_ptr, co.iter_ptr);
    return *this;
}

void hash_list::reset_iter() {
    if ((int) size == 0) {
        iter_ptr = NULL;
    }
    iter_ptr = head;
}

void hash_list::increment_iter() {
    if (iter_ptr) {
        iter_ptr = iter_ptr -> next;
    }
}

std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() {
    if (iter_ptr) {
        return std::make_pair(&(iter_ptr->key), &(iter_ptr->value));
    }
    return std::nullopt;
}

bool hash_list::iter_at_end() {
    return iter_ptr == NULL;
}

/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
