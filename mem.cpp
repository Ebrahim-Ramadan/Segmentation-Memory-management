#include <iostream>
#include "mem.hpp"
using namespace std;

// Return the allocated segment. If no place found, return nullptr
Segment* allocate(Segment** head, unsigned int pid, unsigned int size) {
	Segment* H = *head;
	int The_Memory(50), start(50), totalsize(50);
	while (H->next != nullptr)
	{
		H = H->next;
	}
	if (H->prev == NULL)
	{
		H->start = 0;
		if (int(size) > totalsize)
		{
			return nullptr;
		}
	}
	else if (size > H->size)
	{
		return nullptr;
	}
	H->pid = pid;
	H->size = size;
	Segment* segm2 = new Segment;
	H->next = segm2;
	segm2->next = nullptr;
	segm2->prev = H;
	start = H->start + size;
	The_Memory = totalsize - start;
	segm2->pid = -1;//means empty
	segm2->start = start;
	segm2->size = The_Memory;

	return *head;
}

// Free all segments allocated to process
void deallocate(Segment* head, unsigned int pid) {
	Segment* H = head;
	while (head->next != nullptr)
	{
		if (head->pid == (int)pid)
		{
			head->pid = -1;
		}
		head = head->next;
	}
	while (H->next != nullptr)
	{
		while (H->pid == H->next->pid)
		{
			H->size += H->next->size;
			H->next = H->next->next;
		}
		H = H->next;
	}
}

// For debugging/testing
// You can use this to print a list as follow: dump(std::cout, list_head)
//
// DO NOT EDIT
void dump(std::ostream& o, Segment* head) {
	while (head != nullptr) {
		o << "(" << ((head->pid == -1) ? "H" : "P") << ", " << head->start << ", " << head->size << ") " << "--> ";
		head = head->next;
	}
	o << "NULL";
}

#ifndef GRADING // Don't delete
int main() {
	// You don't need to write anything here, but you can use it to try out your program
	cout << "hello world";
	return 0;
}

#endif // Don't delete
