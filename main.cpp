#include "header.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <pattern { action }> <filename>"
              << std::endl;
    return 1;
  }

  FileParser file(std::move(argv[2]));
  PatternParser pattern(argv[1]);
  ActionParser action(argv[1]);

  for (int i = 0; i < file.get_parsed().size(); ++i) {
    if (!pattern.check_pattern(file.get_parsed()[i], i + 1))
      continue;
    action.run(file.get_parsed()[i]);
    std::cout << std::endl;
  }

  return 0;
}
