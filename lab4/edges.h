#ifndef EDGES_H
#define EDGES_H

class Edge
{
public:
    Edge () {}
    ~Edge() {}

    Edge(int begin, int end);

    void set_begin(const int begin);
    void set_end(const int end);

    int get_begin() const;
    int get_end() const;

private:
    int begin;
    int end;
};

#endif // EDGES_H
