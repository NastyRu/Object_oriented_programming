#ifndef WAIT_LIST_H
#define WAIT_LIST_H

class wait_list {
public:
    wait_list();
    wait_list(int kol);
    wait_list(const wait_list &);
    ~wait_list();
    bool is_empty();
    void add(int el);
    int pop();
    void del(int el);

private:
    int *elem;
    int init;
    int n;
};

#endif // WAIT_LIST_H
