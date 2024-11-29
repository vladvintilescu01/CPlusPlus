#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Message {
public:
    // Default constructor
    Message() : index(0) {}

    // Setter for text and index
    void set_text(const string& text, int idx) {
        this->text = text;
        this->index = idx;
    }

    // Getter for text
    const string& get_text() const {
        return text;
    }

    // Overload < operator to sort by index instead of text
    bool operator<(const Message& other) const {
        return this->index < other.index;
    }

private:
    string text;
    int index;  // Stores the order in which the message was created
};

class MessageFactory {
public:
    MessageFactory() : current_index(0) {}

    // Creates a Message object with an incremental index
    Message create_message(const string& text) {
        Message mess;
        mess.set_text(text, current_index++);
        return mess;
    }

private:
    int current_index;  // Tracks the order of created messages
};


class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
