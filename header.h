#ifndef AWK_PARSER_H
#define AWK_PARSER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

enum class Operation {
  AND,
  OR,
  NONE
};

// Should take a string lhs, and some template type of RHS, and compare them
// For example, if T is an int, and the string is "5", then check if rhs == 5
template <typename T>
bool compare_op(const std::string &lhs, const T &rhs, const std::string &op) {
  std::stringstream ss(lhs);
}

class FileParser {
public:
  FileParser(std::string &&filename, char delimiter = ' ');
  const std::vector<std::vector<std::string>> &get_parsed() const;

private:
  std::vector<std::vector<std::string>> parsed;
};

class PatternParser {
public:
  PatternParser(const std::string &str);
  bool check_pattern(const std::vector<std::string> &tokens, int row_num);
  const std::vector<std::string> &get_pattern() const;

private:
  std::vector<std::string> vect_patterns;
  Operation op_type = Operation::AND;
};

class Stmt {
public:
  virtual void run(const std::vector<std::string> &tokens) = 0;
};

class PrintStmt : public Stmt {
public:
  PrintStmt(std::string::const_iterator &it, const std::string &input);
  void run(const std::vector<std::string> &tokens);

private:
  std::vector<int> fields;
};

class ActionParser {
public:
  ActionParser(const std::string &input);
  void run(const std::vector<std::string> &tokens);

private:
  std::vector<Stmt *> stmts;
};

#endif

