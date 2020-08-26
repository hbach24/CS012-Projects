#ifndef __BBOARD_H__
#define __BBOARD_H__

#include <string>
#include <vector>
using namespace std;

#include "Message.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"

class BBoard {
 private:
   string title;
	vector<User> userList;
	const User * currentUser;
	vector<Message *> messageList;
    const User * getUser(const string &name, const string &pw) const; //done
    void display() const; //Major change!
    void addTopic(); //New !!!
    void addReply(); //New !!!
    void addUser(const string &name, const string &pass);
 public:
	BBoard();
	BBoard(const string &);
	~BBoard(); //done
	bool loadUsers(const string &); //done
	bool loadMessages(const string &);
	bool saveMessages(const string &);
	void login(); 
	void run();
};

#endif