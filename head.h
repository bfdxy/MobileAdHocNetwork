#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
class Node
{
private:
    int X;
    int Y;
    int x;
    int y;
    char name;
public:
    Node()
    {
        x=X=0;
        y=Y=0;
        name='a';
    }
    Node1(int m,int n)
    {
        srand((unsigned)time(NULL));
        X=x=(rand()%m);
        srand((unsigned)time(NULL));
        Y=y=(rand()%n);
        name='a';
    }
    ~Node(){};
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    char GetName()
    {
        return name;
    }
    void Move();
    void SetName(char a);
};


#endif // HEAD_H_INCLUDED
