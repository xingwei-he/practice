#include <iostream>
#include <string>

#include "jsoncpp-master/include/json/reader.h"
#include "jsoncpp-master/include/json/writer.h"
#include "jsoncpp-master/include/json/value.h"

using namespace std;

int main() {
  Json::Value val;
  val["name_cn"] = Json::Value("星爷");
  val["name_en"] = Json::Value("xingye");
  val["id"] = Json::Value("1234567890");

  Json::FastWriter fast_writer;
  string fast_writer_res =  fast_writer.write(val);
  Json::StyledWriter styled_writer;
  string styled_writer_res = styled_writer.write(val);
  //Json::StyledStreamWriter styled_stream_writer;
  //string styled_stream_writer_res = styled_stream_writer.write(val);

  cout << fast_writer_res << endl;
  cout << styled_writer_res << endl;
  //cout << styled_stream_writer_res << endl;

  Json::Reader reader;
  Json::Value root;
  if (reader.parse(fast_writer_res, root)) {
    cout << root["name_cn"].asString() << endl;
    cout << root["name_en"].asString() << endl;
    cout << root["id"].asString() << endl;
  }

  return 0;
}
