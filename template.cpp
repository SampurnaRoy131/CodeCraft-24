#include "header.h"

FileParser::FileParser(std::string &&filename, char delimiter) {
  std::ifstream fin(filename);

  if (!fin) {
    std::cerr << "Error opening file" << std::endl;
    exit(0);
  }

  std::string line;
  while (std::getline(fin, line)) {
      // line has each line in a std::string format
      // parsed should contain each line as a vector of words, words are
      // separated by the delimiter, default is space eg: "abc def ghi" ->
      // {"abc", "def", "ghi"}
  }
}


  // Should return the parsed data structure
const std::vector<std::vector<std::string>> &FileParser::get_parsed() const {
}


// When the constructor is called, the input string is parsed and the patterns
// are stored in a vector The op_type should be set to 0 if all patterns are
// ANDed, 1 if all patterns are ORed The patterns are stored in a vector of
// strings eg: "1" -> {"1"}, "NR>1 && NR<4" -> {"NR>1", "NR<4"}, "/substr/" ->
// {"/substr/"}
PatternParser::PatternParser(const std::string &str) {
  std::string def_pattern = "1"; // Default Pattern
}


// When provided with a line, it should take the line and row number and
// return true if the line matches the pattern The row number is 1-indexed If
// the pattern is /./, it should return true for all lines /substr/ means that
// substr should be a substring in one of the words of the line
// NR is the row number, so NR>1 means everything after the first row.
// NF is number of fields/columns, so NF>2 means morethan 2 columnds
// Other patterns include $1 == hello
// $3 > 2.5
// $4 == 3
bool PatternParser::check_pattern(const std::vector<std::string> &tokens, int row_num) {
}


// Return the vector of patterns
const std::vector<std::string> &PatternParser::get_pattern() const {
}


// Only supports fields at the moment ($0, $1 etc.)
// Always adds a delimiter of space whether or not comma was present b/w fields
// Should parse the print statement and store all the fields given in a vector
// print $1 $3 should store 1 and 3 in the vactor
PrintStmt::PrintStmt(std::string::const_iterator &it, const std::string &input) {
}


// Should print the fields given in the vector for the given line
// If no fields are given, print the entire line
void PrintStmt::run(const std::vector<std::string> &tokens) {
}


// Should parse the action string and store all the statements in a vector
// Here Stmt is a parent class which can later support all types of statement
// statements are delimited by ;
ActionParser::ActionParser(const std::string &input) {
}


// Should print the fields given in the vector for the given line
// If no fields are given, print the entire line
void ActionParser::run(const std::vector<std::string> &tokens) {
}
