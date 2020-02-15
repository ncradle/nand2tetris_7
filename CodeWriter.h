#include <fstream>
#include <string>

class CodeWriter {
 private:
  std::ofstream *ofp;

 public:
  CodeWriter(std::ofstream *fp);
  void setFileName(std::string fileName);
  void writeArithemetic(std::string command);
  void wtirePushPop(std::string comannd, std::string segment, int index);
  void close();
};