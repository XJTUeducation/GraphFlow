#ifndef __MODULE_H__
#define __MODULE_H__

#include <string>
#include <map>
#include <vector>
#include <functional>

namespace GraphFlow {

class Link;
class Graph;

class Module {
public:
    Module(std::string name, int logLevel=0);
    virtual ~Module();

    virtual int init(); 
    virtual void unInit();

    virtual std::string &getName() final;
    int setGraph(Graph *graph);
    Graph *getGraph();
 
    // build graph
    virtual Link *TO(Module *destModule, std::string inputName = "") final;
    virtual std::vector<Link *> &getOutputLinks() final;

    // master processor
    virtual void RUN() final;
    virtual void PROCESS() = 0;

    virtual spMessage getInputMessage(std::string name) final;
    virtual void putOutputMessage(spMessage message) final;

private:

    virtual int preProcess() final;
    virtual int postProcess() final;

    std::string mName;
    int mLogLevel;

    std::vector<Link *> mOutputLinks;
    std::map<std::string, Link *> mInputLinks;

    spMessage mOutputMessage; // user used
    std::map<std::string, spMessage> mInputMessages; // user used

    Graph *mGraph;
};

};

#endif

