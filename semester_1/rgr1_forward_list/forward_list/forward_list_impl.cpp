#include "Header1.h"
#include <initializer_list>
#include <stdexcept>

ForwardList::ForwardList() : head_(nullptr), size_(0) {
}

ForwardList::ForwardList(const ForwardList& rhs) : head_(nullptr), size_(rhs.size_) {
    if (rhs.head_ == nullptr) {
        throw std::exception("Error: Empty list\n!"); // ДОДЕЛАТЬ ИСКЛЮЧЕНИЯ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    head_ = new Node(rhs.head_->value_);
    Node* current = head_;
    Node* rhs_current = rhs.head_->next_;

    while (rhs_current != nullptr) {
        current->next_ = new Node(rhs_current->value_);
        current = current->next_;
        rhs_current = rhs_current->next_;
    }
}

ForwardList::ForwardList(size_t count, int32_t value) : head_(nullptr), size_(count) {
    if (count == 0) {
        throw std::exception(); // ДОДЕЛАТЬ ИСКЛЮЧЕНИЯ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    head_ = new Node(value);
    Node* current = head_;

    for (size_t i = 1; i < count; ++i) {
        current->next_ = new Node(value);
        current = current->next_;
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) : head_(nullptr), size_(init.size()) {
    if (init.size() == 0) {
        throw std::exception("Error: Empty initializer_list!\n"); // ДОДЕЛАТЬ ИСКЛЮЧЕНИЯ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    auto it = init.begin();
    head_ = new Node(*it);
    Node* current = head_;
    ++it;

    while (it != init.end()) {
        current->next_ = new Node(*it);
        current = current->next_;
        ++it;
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs) {
        return *this;
    }

    Clear();

    size_ = rhs.size_;
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
        return *this;
    }

    head_ = new Node(rhs.head_->value_);
    Node* current = head_;
    Node* rhs_current = rhs.head_->next_;

    while (rhs_current != nullptr) {
        current->next_ = new Node(rhs_current->value_);
        current = current->next_;
        rhs_current = rhs_current->next_;
    }

    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t value) {
    Node* new_node = new Node(value);
    new_node->next_ = head_;
    head_ = new_node;
    ++size_;
}

void ForwardList::PopFront() {
    if (head_ == nullptr) {
        throw std::exception("Error: can't do PopFront!\n"); // ДОДЕЛАТЬ ИСКЛЮЧЕНИЯ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    Node* tmp = head_;
    head_ = head_->next_;
    delete tmp;
    --size_;
}

void ForwardList::Remove(int32_t value) {

    while (head_ != nullptr && head_->value_ == value) {
        Node* tmp = head_;
        head_ = head_->next_;
        delete tmp;
        --size_;
    }

    if (head_ == nullptr) {
        throw std::exception("Error: already empty!\n"); // ДОДЕЛАТЬ ИСКЛЮЧЕНИЯ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    Node* current = head_;
    while (current->next_ != nullptr) {
        if (current->next_->value_ == value) {
            Node* to_delete = current->next_;
            current->next_ = to_delete->next_;
            delete to_delete;
            --size_;
        }
        else {
            current = current->next_;
        }
    }
}


void ForwardList::Clear() {
    while (head_ != nullptr) {
        Node* tmp = head_;
        head_ = head_->next_;
        delete tmp;
    }
    size_ = 0;
}

bool ForwardList::FindByValue(int32_t value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = current->next_;
    }
    return false;
}


void ForwardList::Print(std::ostream& out) {
    Node* current = head_;
    while (current != nullptr) {
        out << current->value_ << " ";
        current = current->next_;
    }
}



int32_t ForwardList::Front() const {
    return head_->value_;
}



size_t ForwardList::Size() const {
    return size_;
}
