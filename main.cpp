#include "header.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <pattern { action }> <filename>"
              << std::endl;
    return 1;
  }

  FileParser file(
      std::move(argv[2])); // This is move semantics, if you are interested you
                           // can learn more by reading up on std::move
  PatternParser pattern(argv[1]);
  ActionParser action(argv[1]);

  // Print the required output by running the action on each parsed line,
  // depending on if the pattern is satisfied

  return 0;
}
