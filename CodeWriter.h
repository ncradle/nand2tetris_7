#include <fstream>
#include <string>

class CodeWriter {
 private:
  std::ofstream *ofp;

 public:
  CodeWriter(std::ofstream *fp);
  std::string setFileName(std::string fileName);
  std::string writeArithemetic(std::string command);
  std::string wtirePushPop(std::string comannd, std::string segment, int index);
  void close();
};