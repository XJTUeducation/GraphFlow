#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <map>
#include <thread>

namespace GraphFlow {

class Link;
class Module;

class Graph {
public:
    virtual ~Graph();

    virtual int ADD_MODULE(Module *module) final;
    virtual void DEL_MODULE(Module *module) final;
    virtual int RUN() final;
    virtual void STOP() final;

    virtual bool needStop() final;
    virtual void dumpLinks() final;

    static Graph *mInstance;
    static Graph *getInstance();

private:
    Graph() {};

    bool mNeedStop = false;
    std::vector<Link *> mLinks;
    std::vector<Module *> mModules;
    std::map<std::thread *, Module *> mMap;
};


};

#endif
