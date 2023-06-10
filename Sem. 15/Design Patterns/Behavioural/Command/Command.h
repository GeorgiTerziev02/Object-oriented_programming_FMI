#pragma once

#include <string>
#include <iostream>

class Command {
public:
  virtual ~Command() = default;
  virtual void execute() const = 0;
};

class SimpleCommand : public Command {
private:
  std::string data;
public:
  explicit SimpleCommand(std::string data) : data(data) { }
  
  void execute() const override {
    std::cout << "SimpleCommand: See, I can do simple things like printing (" << data << ")\n";
  }
};

// The Receiver classes contain some important/complex business logic. 
class Receiver {
 public:
  void doSomething(const std::string& a) {
    std::cout << "Receiver: Working on (" << a << ".)\n";
  }
  void doSomethingElse(const std::string& b) {
    std::cout << "Receiver: Also working on (" << b << ".)\n";
  }
};

// Commands can delegate complex operations to receivers
class ComplexCommand : public Command {
private:
  Receiver *receiver_; // pointer to a receiver
  std::string a;
  std::string b;
 public:
  ComplexCommand(Receiver *receiver, std::string a, std::string b) : receiver_(receiver), a(a), b(b) { }
  
  void execute() const override {
    std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
    receiver_->doSomething(a);
    receiver_->doSomethingElse(b);
  }
};

// The Invoker is associated with one or several commands. It sends a request to the command.
class Invoker {
private:
  Command *onStart;
  Command *onFinish;
 public:
  Invoker() = default;
  // you can have the following functions if needed
  Invoker(const Invoker& other) = delete;
  Invoker& operator=(const Invoker& other) = delete;
  ~Invoker() {
    delete onStart;
    delete onFinish;
  }

  void setOnStart(Command *command) { onStart = command; }
  void setOnFinish(Command *command) { onFinish = command; }
  
  void doSomethingImportant() {
    std::cout << "Invoker: Does anybody want something done before I begin?\n";
    if (onStart) {
      onStart->execute();
    }
    std::cout << "Invoker: ...doing something really important...\n";
    std::cout << "Invoker: Does anybody want something done after I finish?\n";
    if (onFinish) {
      onFinish->execute();
    }
  }
};

int testFunc() {
  Invoker *invoker = new Invoker();
  invoker->setOnStart(new SimpleCommand("Say Hi!"));
  Receiver *receiver = new Receiver;
  invoker->setOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
  invoker->doSomethingImportant();

  delete invoker;
  delete receiver;

  return 0;
}
