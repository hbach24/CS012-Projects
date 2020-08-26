#include <iostream>
#include "Topic.h"

using namespace std;

Topic::Topic() : Message() {}

Topic::Topic(const string & athr, const string & sbjct, const string & bdy, unsigned i) : Message(athr, sbjct, bdy, i) {}

bool Topic::isReply() const {
    return false;
}

	/* to_formatted_string writes the contents of the Topic to a 
	* string in the following format:
	
	<begin_topic>
	:id: 4
	:subject: single line
	:from: author
	:children: 5 6 [this line should not be printed if there are no children.]
	:body: multiple lines - line 1
	line 2
	line 3
	<end>
	
	* line starting with :children: has the id's of all children 
	* (See file specifcations for details)
	* This function should not assume the last character in body is a newline.
	* In other words, this function must manually add a newline after the last    
	* line of the body (line 3 in the above example).
	* Also, the last character in the string must be a newline.
	*/
string Topic::toFormattedString() const {
    string topic;
    
    topic = "<begin_topic>\n";
    topic += Message::toFormattedString();
    
    return topic;
    
    
}