#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

const unsigned int DEFAULT_SIZE = 100;

// constants used in the multiplicative string hashing method hash()
const unsigned int STRING_HASH_CONSTANT = 5381;
const unsigned int STRING_HASH_MULTIPLIER = 33;

struct Course {
	string courseName;
	string courseId;
	vector<string> preRequisites;
};

// Custom comparison function for alphanumeric sorting with std::sort
bool alphanumericCompare(const Course& a, const Course& b) {
	return a.courseId < b.courseId; // alphanumeric comparison is done by ascii code of each value in the string
}

//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */
class HashTable {

private:
	// Define structures to hold course data
	struct Node {
		Course course;
		unsigned int key;
		Node* next;

		// default constructor
		Node() {
			key = UINT_MAX;
			next = nullptr;
		}

		// initialize with a course
		Node(Course aCourse) : Node() {
			course = aCourse;
		}

		// initialize with a course and a key
		Node(Course aCourse, unsigned int aKey) : Node(aCourse) {
			key = aKey;
		}
	};

	vector<Node> nodes;

	unsigned int tableSize = DEFAULT_SIZE;

	unsigned int hash(string key);

public:
	HashTable();
	HashTable(unsigned int size);
	virtual ~HashTable();
	void Insert(Course course);
	void Remove(string courseId);
	Course Search(string courseId);
	void PrintAllSorted();
	// size_t Size(); FIXME: Don't need?
};

/**
 * Default constructor
 */
HashTable::HashTable() {
	// Initalize node structure by resizing tableSize
	nodes.resize(tableSize);
}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
	// invoke local tableSize to size with this->
	this->tableSize = size;
	// resize nodes size
	nodes.resize(size);
}

/**
 * Destructor
 */
HashTable::~HashTable() {
	// erase nodes beginning
	nodes.clear();
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(string key) {
	unsigned int final_hash;

	// use multiplicative string hashing
	for (int i = 0; i < key.size(); ++i) {
		final_hash = (STRING_HASH_CONSTANT * STRING_HASH_MULTIPLIER) + static_cast<int>(key[i]);
	}

	// Ensure the hash is positive
	if (final_hash < 0) {
		final_hash = final_hash * -1;
	}
	// return key tableSize
	return final_hash % tableSize;
}

/**
 * Insert a course
 *
 * @param course The course to insert
 */
void HashTable::Insert(Course course) {
	// create the key for the given course
	unsigned int key = hash(course.courseId);
	// retrieve node using key
	Node* node = &nodes.at(key);

	// if node is an empty default node, fill it out
	if (node->key == UINT_MAX) {
		// assign old node key to UNIT_MAX, set to key, set old node to course and old node next to null pointer
		node->key = key;
		node->course = course;
		node->next = nullptr;
	}
	else { // add a new node to the end of the list
		// traverse to the last node in the list
		while (node->next != nullptr) {
			node = node->next;
		}
		// add new newNode to end
		node->next = new Node(course, key);
	}
}

/**
 * Print all courses sorted alphanumerically
 */
void HashTable::PrintAllSorted() {
	vector<Course> courses;
	// for node begin to end iterate
	for (int i = 0; i < nodes.size(); ++i) {
		Node* current = &(nodes.at(i));
		// if key not equal to UINT_MAX
		if (current->key != UINT_MAX) {
			// copy head node to vector
			courses.push_back(current->course);
			// node is equal to next iter
			current = current->next;
			// while node not equal to nullptr
			while (current != nullptr) {
				// add next course node to vector
				courses.push_back(current->course);
				// node is equal to next node
				current = current->next;
			}
		}
	}

	// sort the extracted values in the vector
	sort(courses.begin(), courses.end(), alphanumericCompare);

	// output the sorted course names and numbers
	for (int i = 0; i < courses.size(); ++i) {
		cout << courses.at(i).courseId << ", " << courses.at(i).courseName << endl;
	}
}

/**
 * Remove a course
 *
 * @param course The course id to search for
 */
void HashTable::Remove(string courseId) {
	// set key equal to hashed courseId
	unsigned int key = hash(courseId);
	// start at index = key
	Node* current = &(nodes.at(key));

	// if the first node is an empty default node, no course is at this key
	if (current->key == UINT_MAX) {
		return;
	}

	// special case for head node
	if (current->course.courseId == courseId) {
		// if the head node matches the course id, reset the bucket
		if (current->next == nullptr) {
			// It's the only node in the chain, reset the node to default
			*current = Node();
		}
		else {
			// Copy next node’s data into the current node, then delete the next node
			Node* temp = current->next;
			*current = *temp;  // Copy data
			delete temp;       // Free the old next node
		}
		return;
	}

	// general case where course exists in the middle or end of the list
	// store current node in prev, set current to the second node
	Node* prev = current;
	current = current->next;

	// traverse the list
	while (current != nullptr) {
		// if the current node matches the course
		if (current->course.courseId == courseId) {
			prev->next = current->next;  // Remove from chain
			delete current; // delete the node
			return;
		}
		// traverse to the next node, storing current as previous
		prev = current;
		current = current->next;
	}
}

/**
 * Search for the specified courseId
 *
 * @param courseId The course id to search for
 */
Course HashTable::Search(string courseId) {
	// create an empty course
	Course course;

	// create the key for the given course
	unsigned int key = hash(courseId);

	Node* node = &(nodes.at(key));
	// if no entry found for the key
	// return course
	if (node == nullptr || node->key == UINT_MAX) {
		return course;
	}
	// traverse the list
	while (node != nullptr) {
		// if the current node matches, return it
		if (node != nullptr && node->key != UINT_MAX && node->course.courseId.compare(courseId) == 0) {
			//return node course
			return node->course;
		}
		// traverse to the next node
		node = node->next;
	}
	// if no course was found, return the empty course
	return course;
}

void ParseCSV(string csvPath, HashTable* ht) {
	// set input file stream with path
	ifstream file(csvPath);

	// if file loading fails, error and exit the program
	if (!file.is_open()) {
		cerr << "Could not open file" << endl;
		// exit if the file can't be loaded
		exit(1);
	}

	// set variables for parsing
	string line;
	vector<string> lineFields;

	int lineNumber = 0;
	// loop through csv file line by line
	while (getline(file, line)) {
		lineNumber++;
		// create a course to parse data into
		Course course;
		// create a stringsteam and field var to parse lines by comma
		stringstream ss(line);
		string field;

		// loop throug all commas in line, parsing into fields
		while (getline(ss, field, ',')) {
			// add each field data to the fields vector
			lineFields.push_back(field);
		}

		// first field is course at, set in course.courseId
		course.courseId = lineFields.at(0);
		// second field is course name, set in course.courseName
		course.courseName = lineFields.at(1);

		// if the next field after courseName is empty there are no preReqs
		if (!(lineFields.at(2) == "")) {
			// loop through fields after name/number to get preReqs
			for (int i = 2; i < lineFields.size(); ++i) {
				// add preReqs to the course.preRequisites vector
				course.preRequisites.push_back(lineFields.at(i));
			}
		}

		// inser the course into the hash table
		ht->Insert(course);

		// Clear lineFields for next iteration
		lineFields.clear();
	}

	// Close file
	file.close();

	std::cout << "File processed successfully!" << std::endl;
}

string PromptForCSVPath() {
	// set path var
	string path;

	// prompt user for path
	cout << "Enter path to csv file: " << endl;
	cin.ignore();
	// get the whole line in case path has spaces in it
	getline(cin, path);

	// Check if the path starts and ends with quotes
	if (!path.empty() && path.front() == '"' && path.back() == '"') {
		// Remove the quotes
		path = path.substr(1, path.size() - 2);
	}

	// return the path
	return path;
}

string PromptForCourseId() {
	// set id var
	string courseId;

	// prompt user for a course id
	cout << "Enter a course id to search: ";
	cin >> courseId;

	// always make the courseId characters upper case
	transform(courseId.begin(), courseId.end(), courseId.begin(),
		toupper);

	// return the courseId
	return courseId;
}

int main(int argc, char* argv[]) {
	// setup data structure
	HashTable* courseTable;
	Course course;
	courseTable = new HashTable();

	// variables for menu
	string csvPath;
	string courseId;

	// Define a timer variable
	clock_t ticks;

	// setup menu loop
	int choice = 0;
	while (choice != 9) {
		cout << "Menu:" << endl;
		cout << "  1. Load Course Data" << endl;
		cout << "  2. Display All Courses Sorted Alphanumerically" << endl;
		cout << "  3. Find Course" << endl;
		cout << "  9. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			// prompt user to get csv path
			csvPath = PromptForCSVPath();

			// Initialize a timer variable before loading courses
			ticks = clock();

			// Complete the method call to load the courses
			ParseCSV(csvPath, courseTable);

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;

		case 2:
			courseTable->PrintAllSorted();
			break;

		case 3:
			ticks = clock();

			courseId = PromptForCourseId();

			course = courseTable->Search(courseId);

			ticks = clock() - ticks; // current clock ticks minus starting clock ticks

			// if the returned value courseId is not empty
			if (!course.courseId.empty()) {
				// output the course id (number) and the course title (name)
				cout << "Course Id: " << course.courseId << " found." << endl;
				cout << "Course Title: " << course.courseName << ", ";				

				// if the size of the prereqs vector is 0 (there are no preqreqs), output there are no preqreqs
				if (course.preRequisites.size() == 0) {
					cout << "No prerequisite courses." << endl;
				} else { // otherwise, loop through the vector and output all of the preReqs
					for (int i = 0; i < course.preRequisites.size(); ++i) {
						// if we're at the last entry, skip the output trailing space/comma
						if (i == (course.preRequisites.size() - 1)) {
							cout << "Prerequisite courses: " << course.preRequisites.at(i);
						}
						else {  // otherwise add a comma between preReqs.
							cout << "Prerequisite courses: " << course.preRequisites.at(i) << ", ";
						}
					}
					cout << endl;
				}
			}
			else {
				cout << "Course Id " << courseId << " not found." << endl;
			}

			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;
		
		// default case handles invalid inputs
		default:
			cout << "Invalid selection: " << choice << endl;
		}
	}

	cout << "Good bye." << endl;

	return 0;
}