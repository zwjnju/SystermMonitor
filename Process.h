#include <string>

using namespace std;
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
private:
    string pid;
    string user;
    string cmd;
    string cpu;
    string mem;
    string upTime;

public:
    Process(string pid){
        this->pid = pid;
        this->user = ProcessParser::getProcUser(pid);
        //TODOs:
        //complete for mem
        //complete for cmd
        //complete for upTime
        //complete for cpu
        this->cmd = ProcessParser::getCmd(pid);
        this->cpu = ProcessParser::getCpuPercent(pid);
        this->mem = ProcessParser::getVmSize(pid);
        this->upTime = ProcessParser::getProcUpTime(pid);
    }
    void setPid(int pid);
    string getPid()const;
    string getUser()const;
    string getCmd()const;
    int getCpu()const;
    int getMem()const;
    string getUpTime()const;
    string getProcess();
};
void Process::setPid(int pid){
    this->pid = pid;
}
string Process::getPid()const {
    return this->pid;
}
string Process::getProcess(){
    if(!ProcessParser::isPidExisting(this->pid))
        return "";
    this->mem = ProcessParser::getVmSize(this->pid);
    this->upTime = ProcessParser::getProcUpTime(this->pid);
    this->cpu = ProcessParser::getCpuPercent(this->pid);

    //TODO: finish the string! this->user + "   "+ mem...cpu...upTime...;
    return (this->pid + "   " + this->user + " " + this->mem + " " + this->cpu + " " + this->upTime + " " + this->cmd);
}

string Process::getUser()const {
    return this->user;
}

string Process::getCmd()const {
    return this->cmd;
}

int Process::getCpu()const {
    return stoi(this->cpu);
}

int Process::getMem()const {
    return stoi(this->mem);
}

string Process::getUpTime()const {
    return this->upTime;
}