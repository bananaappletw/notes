class Parent {
public:
    virtual void Foo() {}
    virtual void FooNotOverridden() {}
};

class Derived : public Parent {
public:
    void Foo() override {}
};
