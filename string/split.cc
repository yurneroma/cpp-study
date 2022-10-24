#include <iostream>
#include <map>

using namespace std;

const static map<string, string> path_to_plugin_name = {
  {"libuv_event_sink_plugin.so", "uvSinkPlugin"}
};

string getname() {
  const string path="/root/libuv_event_sink_pugin.so";
  auto const pos=path.find_last_of('/');
  const auto leaf=path.substr(pos+1);
  cout << leaf << endl; 

  auto search =  path_to_plugin_name.find(leaf);
  if (search != path_to_plugin_name.end()) {
    return search->second;
  } else {
    return "";
  }
}

int main() {

  auto name = getname();
  cout << "name size " << name.size() << endl;
  cout << "name " << name << endl;
  if (name == "") {
    cout << "name is empty" << endl;
  }
  // string s("");
  // auto pluginName1 =  path_to_plugin_name.at(s);
}