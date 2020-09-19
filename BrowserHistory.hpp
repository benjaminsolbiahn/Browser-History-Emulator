#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include "Websites.hpp"
// std::next, std::prev

using std::string;

class BrowserHistory {
public:
BrowserHistory();

void visitSite(string url, size_t filesize);
void backButton();
void forwardButton();

void readFile(string fileName);

string currentUrl();
size_t currentPageSize();
size_t getHistoryLength();

private:
	std::list<Websites> webn; 
	std::list<Websites>::iterator n; 
};

BrowserHistory::BrowserHistory(){ 
	Websites temp; 
	webn.push_back(temp); 
	n = webn.begin(); 
}

void BrowserHistory::visitSite(string url, size_t filesize){
	size_t counter = 1; 
	size_t holder= webn.size(); 
	for(std::list<Websites> :: iterator i = webn.begin(); i->Websites_name!=n->Websites_name;++i){ 
	counter++; //incrementing the counter for each loop
}
if(counter < holder){ 
	for(size_t i = counter; i < holder;i++){ 
	webn.pop_back();
}
	Websites temp; 
	temp.Websites_name = url; 
	temp.size = filesize; 
	webn.push_back(temp); 
	++n; 
}

else if(n->Websites_name==""){ 
	Websites temp; 
	temp.Websites_name = url; 
	temp.size = filesize; 
	webn.push_back(temp); 
	webn.pop_front(); 
	n = webn.begin(); 
}
else { 
	Websites temp; 
	temp.Websites_name = url; 
	temp.size = filesize; 
	webn.push_back(temp); 
	++n;
}
}

void BrowserHistory::backButton(){ 
	if(n->Websites_name == webn.front().Websites_name) return; 
	--n;
}

void BrowserHistory::forwardButton(){
	if(n->Websites_name == webn.back().Websites_name) return;
	++n;
}

void BrowserHistory::readFile(string fileName){
	std::ifstream myfile(fileName); 
	string holder1; 
	size_t holder2; 
	while(myfile >> holder1){ 
	if(holder1 =="visit"){ 
	myfile >> holder1; 
	myfile >> holder2; 
	visitSite(holder1, holder2);
}
else if(holder1=="back"){ 
	backButton(); 
}
else{
	forwardButton(); 
}
}
}

string BrowserHistory::currentUrl(){
	if(webn.empty()) return ""; 
	return n->Websites_name; 
}

size_t BrowserHistory::currentPageSize(){
	if(webn.empty()) return 0; 
	return n->size; 
}

size_t BrowserHistory::getHistoryLength(){
	return webn.size();
}