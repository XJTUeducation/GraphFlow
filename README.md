# GraphFlow
A light library of multi-thread workflow

This library contains several abstract concepts: Graph, Module, Link and Message.
Graph: A graph is a container that contains modules and links.
Module: A module is an executable that shoule be implemented by user.
Link: A link is a connector between modules.
Message: Information that flows via link from one module to another.

# example: 
  If we want to implement expression a + b = ? We may do it like this below:
  Create three modules, one module named "a" with default value 10, another module named "b" with default value 20, and the last module named "add" that prints out result of a+b.
  
##  1, Define message type IntMessage:

    class IntMessage: public Message {
    public:
      IntMessage(int value): mValue(value) {}
      virtual ~IntMessage() {}

      int getValue() {
        return mValue;
      }

    private:
      int mValue;
    };

##   2, Define Module Add, a and b:

   class AddModule: public Module {
    public:
      AddModule(): Module(std::string("add")) {}
      ~AddModule() {}

      // user implemented
      virtual void PROCESS() {
        int a = getInputMessage("a")->getValue();
        int b = getInputMessage("b")->getValue();
        
        LOG("a + b = %d", a + b);
        std::cout << "a + b = " << a + b << std::endl;
      }

    private:
    };

    class ModuleA: public Module {
    public:
      ModuleA(): Module("a") {}
      ~ModuleA() {}

      // user implemented
      virtual void PROCESS() {
        spMessage message(new IntMessage(10));
        putOutputMessage(message);
      }
    };

    class ModuleB: public Module {
    public:
      ModuleB(): Module("b") {}
      ~ModuleB() {}

      // user implemented
      virtual void PROCESS() {
        spMessage message(new IntMessage(20));
        putOutputMessage(message);
      }
    };
    
##  3, start to build graph, run & stop

  int main() {
    Graph *g = Graph::getInstance();  // get default graph instance

    // create module a, b & add
    Module *a = new ModuleA();
    Module *b = new ModuleB();
    Module *add = new AddModule();

    // Add modules into graph
    g->ADD_MODULE(a);
    g->ADD_MODULE(b);
    g->ADD_MODULE(add);

    // Link modules
    a->TO(add)->setLimit(1);
    b->TO(add)->setLimit(1);

    // run
    if (g->RUN() < 0) {
       std::cout << "RUN failed!" << std::endl;
       return 0;
    }

    // stop
    g->STOP();
    return 0;
  }

##  4, Finally, we build graph like this:
 ![image](https://github.com/yepanl/GraphFlow/blob/master/examples/ADDITION/add.png)
                                            
##  5, You can use this framework properly anywhere you want, and please contact me via liyepan@126.com if any question.
